#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "Inputs.h"
#include "Funciones.h"

int initPassengers(Passenger* lista, int len)
{
	int retorno;

	retorno = -1;

	if(lista != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			retorno = 0;
			lista[i].isEmpty = VACIO;
		}
	}

	return retorno;
}
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
	int retorno = -1;
	int index;

	if(list != NULL && len > 0)
	{
		index = BuscarLibre(list, len);

		if(index != -1)
		{
			list[index].idPasajero = id;
			strcpy(list[index].name,name);
			strcpy(list[index].lastName, lastName);
			list[index].price = price;
			strcpy(list[index].flycode,flycode);
			list[index].idTypePassenger = typePassenger;
			list[index].idStatusFlight = statusFlight;
			list[index].isEmpty = LLENO;
			retorno = 0;
		}
	}

	return retorno;
}
int BuscarLibre(Passenger* array, int len)
{
	int index;

	index = -1;

	for(int i = 0; i < len; i++)
	{
		if(array[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}
int printPassenger(Passenger* list, int length, TypePassenger* listaTipos, int lenTipos, StatusFlight* listaStatus, int lenStatus)
{
	int retorno = 0;
	int cantidad = 0;

	if(list != NULL && listaTipos != NULL && listaStatus != NULL && length > 0)
	{
		for(int i=0; i<length; i++)
		{
			for(int j=0; j<lenTipos; j++)
			{
				for(int k=0; k<lenStatus; k++)
				{
					if(list[i].isEmpty == LLENO && (list[i].idTypePassenger == listaTipos[j].idTypePassenger) && (list[i].idStatusFlight == listaStatus[k].idStatusFlight))
					{
						MostrarUnPasajero(list[i], listaTipos[j], listaStatus[k]);
						printf("-------------------------------------------------------------------------------------------------------\n");
						cantidad++;
					}
				}

			}
		}
	}
	if (cantidad > 0)
	{
		retorno = 1;
	}

	return retorno;
}
void MostrarUnPasajero(Passenger lista, TypePassenger listaTipos, StatusFlight listaStatus)
{

	printf("|%-10d|%-16s |%-18s | %-12.2f |%-8s | %-15s | %-10s |\n",lista.idPasajero ,lista.name, lista.lastName,
													   lista.price, lista.flycode,
													   listaTipos.typePassenger,
													   listaStatus.statusFlight);


}
int findPassengerById(Passenger* list, int len, int id)
{
	int retorno;

	retorno = -1;

	if (list != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == LLENO && list[i].idPasajero == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
int removePassenger(Passenger list[], int len, int idAux)
{
	int retorno = -1;

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == LLENO && list[i].idPasajero == idAux)
		{
			list[i].isEmpty = VACIO;
			retorno = 0;
			break;
		}
	}


	return retorno;

}
int sortPassengers(Passenger* list, int len, int order, TypePassenger* listaTipos, int lenTipos, StatusFlight* listaStatus, int lenStatus)
{
	int retorno = -1;
	Passenger aux;

	if(list != NULL && len > 0)
	{
		switch (order)
		{
		//ASCENDENTE
		case 0:
			for(int i = 0; i < len - 1; i++)
			{
				for(int j = i + 1; j < len; j++)
				{
					if(list[i].isEmpty == LLENO && list[j].isEmpty == LLENO)
					{
						if(strcmp(list[i].lastName,list[j].lastName) > 0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
						if(strcmp(list[i].lastName,list[j].lastName) == 0)
						{
							if(list[i].idTypePassenger > list[j].idTypePassenger)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
			retorno = 0;
			break;
		//DESCENDIENTE
		case 1:
			for(int i = 0; i < len - 1; i++)
			{
				for(int j = i + 1; j < len; j++)
				{
					if(list[i].isEmpty == LLENO && list[j].isEmpty == LLENO)
					{
						if (strcmp(list[i].lastName,list[j].lastName) < 0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
						if(strcmp(list[i].lastName,list[j].lastName) == 0)
						{
							if(list[i].idTypePassenger < list[j].idTypePassenger)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
			retorno = 0;
			break;
		}
	}
	return retorno;
}
int sortPassengersByCode(Passenger* list, int len, int order, TypePassenger* listaTipos, int lenTipos, StatusFlight* listaStatus, int lenStatus)
{
	int retorno = -1;
	Passenger aux;

	if (list != NULL && len > 0)
	{
		switch (order)
		{
		case 0:
			for (int i = 0; i < len - 1; i++)
			{
				for (int j = i + 1; j < len; j++)
				{
					if (list[i].isEmpty == LLENO && list[j].isEmpty == LLENO)
					{
						if(strcmp(list[i].flycode,list[j].flycode) > 0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
						if(strcmp(list[i].flycode,list[j].flycode) == 0)
						{
							if(list[i].idStatusFlight > list[j].idStatusFlight)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
			retorno = 0;
			break;
		case 1:
			for (int i = 0; i < len - 1; i++)
			{
				for (int j = i + 1; j < len; j++)
				{
					if (list[i].isEmpty == LLENO && list[j].isEmpty == LLENO)
					{
						if(strcmp(list[i].flycode,list[j].flycode) < 0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
						if(strcmp(list[i].flycode,list[j].flycode) == 0)
						{
							if(list[i].idStatusFlight < list[j].idStatusFlight)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
			retorno = 0;
			break;
		}
	}

	return retorno;
}
void print_UnPasajero(Passenger lista[], int index)
{

	printf("|%-10d|%-16s |%-18s | %-12.2f |%-8s|\n",lista[index].idPasajero ,lista[index].name, lista[index].lastName,
													   lista[index].price, lista[index].flycode);


}
