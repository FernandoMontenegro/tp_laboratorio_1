#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* this;
	int leido;
	char auxId[50];
	char auxNombre[50];
	char auxApellido[50];
	char auxPrecio[30];
	char auxCodigoVuelo[50];
	char auxTipoPasajero[50];
	char auxEstadoVuelo[50];
	int retorno;

	retorno = 0;

	if (pFile == NULL && pArrayListPassenger == NULL)
	{
		printf("NO EXISTE EL ARCHIVO");
		exit(1);
	}

	while(!feof(pFile))
	{
		leido = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
				auxId,
				auxNombre,
				auxApellido,
				auxPrecio,
				auxCodigoVuelo,
				auxTipoPasajero,
				auxEstadoVuelo);

		if (leido == 7)
		{
			this = Passenger_newParametros(auxId, auxNombre, auxApellido, auxPrecio, auxTipoPasajero, auxCodigoVuelo, auxEstadoVuelo);
			if (this != NULL)
			{
				ll_add(pArrayListPassenger, this);
				retorno = 0;
			}
			else
			{
				printf("[ERROR] - NO HAY ESPACIO EN MEMORIA");
				Passenger_delete(this);
			}
		}
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;
	Passenger* aux;

	retorno = -1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			aux = Passenger_new();

			fread(aux, sizeof(Passenger), 1, pFile);

			if(feof(pFile))
			{
				break;
			}
			else
			{
				ll_add(pArrayListPassenger, aux);
				retorno = 0;
			}
		}
	}

    return retorno;
}
int parser_PassengerSaveText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* this;
	int len;
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	int auxTipoPasajero;
	char auxTipoPasajeroStr[50];
	char auxCodigoVuelo[8];
	char auxEstadoVuelo[40];
	int retorno;

	retorno = -1;

	len = ll_len(pArrayListPassenger);

	if(len > 0 && pFile != NULL && pArrayListPassenger != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			this = (Passenger*) ll_get(pArrayListPassenger, i);

			if(this != NULL)
			{
				Passenger_getId(this, &auxId);
				Passenger_getNombre(this, auxNombre);
				Passenger_getApellido(this, auxApellido);
				Passenger_getPrecio(this, &auxPrecio);
				Passenger_getCodigoVuelo(this, auxCodigoVuelo);
				Passenger_getTipoPasajero(this, &auxTipoPasajero);
				Passenger_getEstadoVuelo(this, auxEstadoVuelo);

				if(auxTipoPasajero == 1)
					{
						strcpy(auxTipoPasajeroStr, "FirstClass");
					}
					else
					{
						if(auxTipoPasajero == 2)
						{
							strcpy(auxTipoPasajeroStr, "ExecutiveClass");
						}
						else
						{
							strcpy(auxTipoPasajeroStr, "EconomyClass");
						}
					}

				fprintf(pFile, "%d,%s,%s,%f,%s,%s,%s\n", auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajeroStr, auxEstadoVuelo);

				retorno = 0;
			}
		}
	}

	return retorno;

}
int parser_PassengerSaveBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;
	Passenger* aux;
	int workersQty;

	retorno = -1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		workersQty = ll_len(pArrayListPassenger);

		for(int i = 0; i < workersQty; i++)
		{
			aux = ll_get(pArrayListPassenger, i);

			fwrite(aux,sizeof(Passenger),1,pFile);
		}

		retorno = 0;
	}

	return retorno;
}




