#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "Inputs.h"
#include "Funciones.h"

int eliminarPasajero(Passenger* lista, int lenLista, TypePassenger* listaTipos, int lenTipos, StatusFlight* listaStatus, int lenStatus)
{
	int retorno = -1;
	int id;
	int rtnPrint;
	int verificacion;
	int index;

	if(lista != NULL && listaTipos != NULL && listaStatus != NULL)
	{
		rtnPrint = printPassenger(lista, lenLista, listaTipos, lenTipos, listaStatus, lenStatus);
		if(rtnPrint == 1)
		{
			utn_getNumero(&id, "Ingrese un ID de la lista para eliminar: ", "\nEse ID no existe.\n", 0, 1000000, 5);
			index = findPassengerById(lista, lenLista, id);

			while(index == -1)
			{
				printf("Ese ID no existe.\n");
				utn_getNumero(&id, "Ingrese un ID de la lista para eliminar: ", "\nEse ID no existe.\n", 0, 1000000, 5);
				index = findPassengerById(lista, lenLista, id);
			}

			print_UnPasajero(lista, index);

			utn_getNumero(&verificacion, "¿Está seguro que desea eliminar este pasajero?\n1. Si\n2. No\n", "Opcion invalida...\n", 1, 2, 5);

			if(verificacion == 1)
			{
				removePassenger(lista, lenLista, id);
				retorno = 0;
			}
			else
			{
				retorno = 1;
			}
		}
		else
		{
			retorno = 2;
		}

	}

	return retorno;
}

void HardcodeoPasajeros(Passenger pasajeros[], int* id)
{
    int index;
    char nombre[TAM_HARDCODEO][51]={"Fernando", "Taiel", "Sebastian","Alexis","German"};
    char apellido[TAM_HARDCODEO][51]={"Montenegro", "Vazquez", "Battaglia","Rodriguez","Scarafilo"};
    float precio[TAM_HARDCODEO]={8250,7620,5020,4070,8520};
    char flyCode[TAM_HARDCODEO][10]={"GH1PZ", "AABPQ", "AABPQ","1LHMZ","ZPQF2"};
    int typePassenger[TAM_HARDCODEO]={3,1,2,3,2};
    int statusFlight[TAM_HARDCODEO]={3,1,2,2,3};

    for (int i=0 ;i < TAM_HARDCODEO; i++)
    {
    	index = BuscarLibre(pasajeros,TAM);
    	if(index != -1)
    	{
			pasajeros[index].idPasajero = *id;
			*id = *id + 1;
			strcpy(pasajeros[index].name,nombre[i]);
			strcpy(pasajeros[index].lastName,apellido[i]);
			pasajeros[index].price = precio[i];
			strcpy(pasajeros[index].flycode,flyCode[i]);
			pasajeros[index].idTypePassenger=typePassenger[i];
			pasajeros[index].idStatusFlight=statusFlight[i];
			pasajeros[index].isEmpty = LLENO;
     	}
    }
}
int sortList(Passenger* listaPasajeros, int lenPasajeros, TypePassenger* tipoPasajeros, int lenTipo, StatusFlight* tipoEstado, int lenStatus)
{
	int opcion;
	int order;
	int retorno = -1;;

	do
	{
		opcion = menuSort();

		switch(opcion)
		{
			case 1:
				order = criterioOrdenamiento();
				if(sortPassengers(listaPasajeros, TAM, order, tipoPasajeros, TAM_TYPE, tipoEstado, TAM_STATUS) == 0)
				{
					printPassenger(listaPasajeros, TAM, tipoPasajeros, TAM_TYPE, tipoEstado, TAM_STATUS);
					retorno = 0;
				}
				break;
			case 2:
				printTotal_Promedio(listaPasajeros, TAM);
				printf("Datos mostrados correctamente...\n");
				retorno = 0;
				break;
			case 3:
				order = criterioOrdenamiento();
				if(sortPassengersByCode(listaPasajeros, TAM, order, tipoPasajeros, TAM_TYPE, tipoEstado, TAM_STATUS) == 0)
				{
					printPassenger(listaPasajeros, TAM, tipoPasajeros, TAM_TYPE, tipoEstado, TAM_STATUS);
					retorno = 0;
				}
				break;
			case 4:
				printf("Volviendo al menu principal...\n");
				break;
		}
	}while(opcion != 4);


	return retorno;
}
int menuSort()
{
	int opcion;

	utn_getNumero(&opcion,"LISTADOS: \n"
						  "1-Pasajeros por Apellido y Tipo de pasajero.\n"
						  "2-Total y promedio de los precios, y cuantos superan el promedio de precios.\n"
						  "3-Pasajeros por Código de vuelo y ‘ACTIVO’\n"
						  "4-Volver al menu principal.\n"
						  "Elija una opcion: ", "No es una opcion valida.\n", 1, 4, 5);

	return opcion;
}
int criterioOrdenamiento()
{
	int opcion;

	printf("\n¿Como quiere ordenar?\n"
	"0. Ordenar en ASCENDENTE\n"
	"1. Ordenar en DESCENDENTE\n\n");

	utn_getNumero(&opcion, "Elija una opcion: ", "\nOpcion invalida...\n", 0, 1, 5);

	return opcion;
}
int pasajeros_overAverage(Passenger lista[],int tamPasajeros, float promedio)
{
	int cantidadPasajeros;

	cantidadPasajeros = 0;

	for(int i = 0;i < tamPasajeros; i++)
	{
		if(lista[i].isEmpty == LLENO)
		{
			if(lista[i].price > promedio)
			{
				cantidadPasajeros++;
			}
		}
	}

	return cantidadPasajeros;
}
int CargarUnPasajero(Passenger lista[], int len, TypePassenger listaTipos[], int lenTipos, StatusFlight listaStatus[], int lenStatus, int* id)
{
	int retorno = -1;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int idtypePassenger;
	int idProximo;
	int idStatusFlight;

	idProximo = *id;
	*id = *id + 1;
	utn_getNombre(name, 51, "Ingrese su nombre: \n", "Nombre incorrecto...\n", 5);
	strlwr(name);
	name[0] = toupper(name[0]);

	utn_getNombre(lastName, 51, "Ingrese su Apellido: \n", "Apellido incorrecto...\n", 5);
	strlwr(lastName);
	lastName[0] = toupper(lastName[0]);

	utn_getNumeroFlotante(&price, "Ingrese el precio del vuelo: \n", "Error.\n", 0, 1000000, 5);

	utn_getAlphaNumeric(flyCode, 10, "Ingrese el codigo del vuelo: \n", "Codigo incorrecto...\n",5);

	printf("Tipos de pasajeros: \n");
	for(int i=0; i<lenTipos; i++)
	{
		printf("ID:%-5d TIPO: %-10s\n", listaTipos[i].idTypePassenger, listaTipos[i].typePassenger);
	}
	utn_getNumero(&idtypePassenger, "Elija una opcion: ", "No es una opcion valida.\n", 1, 3, 5);

	printf("Estados de vuelos actualmente: \n");
	for(int i=0; i<lenStatus; i++)
	{
		printf("ID:%-5d TIPO: %-10s\n", listaStatus[i].idStatusFlight, listaStatus[i].statusFlight);
	}
	utn_getNumero(&idStatusFlight, "Elija un estado de vuelo: ", "No es una opcion valida.\n", 1, 3, 5);

	printf("\nSu ID es el numero %d.\n",idProximo);

	retorno = addPassenger(lista, len, idProximo, name, lastName, price, idtypePassenger, flyCode, idStatusFlight);

	return retorno;
}
int Modificacion(Passenger* lista, int lenLista, TypePassenger* listaTipos, int lenTipos, StatusFlight* listaStatus, int lenStatus)
{
	int retorno = -1;
	int idEdit;
	int index;
	int rtnPrint;
	int verificacion;
	Passenger auxiliar;


	rtnPrint = printPassenger(lista, lenLista, listaTipos, lenTipos, listaStatus, lenStatus);

	if(rtnPrint == 1)
	{
		utn_getNumero(&idEdit, "Ingrese un ID de la lista para eliminar: ", "\nEse ID no existe.\n", 0, 1000000, 5);
		index = findPassengerById(lista, lenLista, idEdit);

		while(index == -1)
		{
			printf("Ese ID no existe.\n");
			utn_getNumero(&idEdit, "Ingrese un ID de la lista para eliminar: ", "\nEse ID no existe.\n", 0, 1000000, 5);
			index = findPassengerById(lista, lenLista, idEdit);
		}

		print_UnPasajero(lista, index);

		utn_getNumero(&verificacion, "\n¿Está seguro que desea modificar este pasajero?\n1. Si\n2. No\n", "Opcion invalida...\n", 1, 2, 5);

		if(verificacion == 1)
		{
			auxiliar = Passenger_modifyOne(lista[index], listaTipos, lenTipos);
			lista[index] = auxiliar;
			retorno = 0;
		}
		else
		{
			retorno = 1;
		}
	}
	else
	{
		retorno = 2;
	}

	return retorno;
}
Passenger Passenger_modifyOne(Passenger lista, TypePassenger* listaTipos, int lenTipos)
{
	Passenger auxiliar = lista;

	int opcion;

	do
	{
		utn_getNumero(&opcion, "MENU DE OPCIONES A MODIFICAR:\n"
				"1.Nombre\n"
				"2.Apellido\n"
				"3.Precio\n"
				"4.Tipo de pasajero\n"
				"5.Codigo de vuelo\n"
				"6.Volver al menu principal\n", "No es una opcion valida.\n", 1, 6, 5);

		switch(opcion)
		{
		case 1:
			utn_getNombre(auxiliar.name, 51, "Ingrese el nuevo nombre: \n", "Nombre incorrecto...\n", 5);
			strlwr(auxiliar.name);
			auxiliar.name[0] = toupper(auxiliar.name[0]);
			printf("\nNuevo nombre modificado con exito.\n");
			opcion = 6;
			printf("Volviendo al menu principal...\n");
			break;
		case 2:
			utn_getNombre(auxiliar.lastName, 51, "Ingrese el nuevo apellido: \n", "Nombre incorrecto...\n", 5);
			strlwr(auxiliar.lastName);
			auxiliar.lastName[0] = toupper(auxiliar.lastName[0]);
			printf("\nNuevo apellido modificado con exito.\n");
			opcion = 6;
			printf("Volviendo al menu principal...\n");
			break;
		case 3:
			utn_getNumeroFlotante(&auxiliar.price, "Ingrese el nuevo precio del vuelo: \n", "Error.\n", 0, 1000000, 5);
			printf("\nNuevo precio modificado con exito.\n");
			opcion = 6;
			printf("Volviendo al menu principal...\n");
			break;
		case 4:
			printf("Tipos de pasajeros: \n");
			for(int i=0; i<lenTipos; i++)
			{
				printf("ID:%-5d TIPO: %-10s\n", listaTipos[i].idTypePassenger, listaTipos[i].typePassenger);
			}
			utn_getNumero(&auxiliar.idTypePassenger, "Seleccione un nuevo tipo de pasajero: \n", "No es una opcion valida.\n", 1, 3, 5);
			printf("\nNuevo tipo de pasajero modificado con exito.\n");
			opcion = 6;
			printf("Volviendo al menu principal...\n");
			break;
		case 5:
			utn_getAlphaNumeric(auxiliar.flycode, 10, "Ingrese el codigo del vuelo: \n", "Codigo incorrecto...\n",5);
			printf("\nNuevo codigo de vuelo modificado con exito.\n");
			opcion = 6;
			printf("Volviendo al menu principal...\n");
			break;
		case 6:
			printf("\nVolviendo al menú principal...\n");
			break;

		}
	}while(opcion != 6);

	return auxiliar;
}
void printTotal_Promedio(Passenger* list, int len)
{
	float acumuladorPrecio;
	float promedio;
	int contador;
	int contadorPrecio;

	contador = 0;
	acumuladorPrecio = 0;
	contadorPrecio = 0;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == LLENO)
			{
				acumuladorPrecio = acumuladorPrecio + list[i].price;
				contador++;
			}
		}
		promedio = (float)(acumuladorPrecio / contador);


		contadorPrecio = pasajeros_overAverage(list, TAM, promedio);

		printf("\n================================================================");
		printf("\nEl total de los precios de los pasajes es: $%.2f\n", acumuladorPrecio);
		printf("================================================================\n");
		printf("El promedio es de los precios de los pasajes es: $%.2f\n", promedio);
		printf("================================================================\n");
		printf("La cantidad de pasajeros que superan el precio promedio es de: %d\n", contadorPrecio);
		printf("================================================================\n\n");
	}
}

