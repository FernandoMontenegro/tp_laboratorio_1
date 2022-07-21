#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "parser.h"
#include "Inputs.h"
#include "string.h"
#include "ctype.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno;

	retorno = -1;
	pFile = fopen(path,"r");// Al hacer que auxfile apunte a el path del archivo

	if(pFile != NULL)
	{
		if(parser_PassengerFromText(pFile, pArrayListPassenger) == 0)
		{
			retorno = 0;
		}
		fclose(pFile); // a la hora de cerrarlo tenemos que pasarle el parametro del archivo al cual apuntamos cuando lo abrimos
	}


    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno;

	retorno = -1;

	if(pArrayListPassenger != NULL && path != NULL)
	{
		pFile = fopen(path,"rb");

		if(pFile != NULL && parser_PassengerFromBinary(pFile, pArrayListPassenger) == 0)
		{
			retorno = 0;
		}

		fclose(pFile);
	}

    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, char* path)
{
	Passenger* aux;
	int id;
	int retorno = -1;
	int verificacion;

	retorno = -1;

	controller_leerID(path,&id);

	aux = Passenger_newAlta(id);

	Passenger_printOne(aux);

	utn_getNumero(&verificacion, "¿Está seguro que desea crear este nuevo pasajero?\n1. Si\n2. No\n", "Opcion invalida...\n", 1, 2, 5);

	if(verificacion == 1)
	{
		ll_add(pArrayListPassenger, aux);
		retorno = 0;
		id++;
		controller_guardarID(path, id);
	}
	else
	{
		Passenger_delete(aux);
	}

	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* this;
	int retorno = -1;
	int index;
	int verificacion;

	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);

		index = Passenger_validarID(pArrayListPassenger, "Ingrese un ID de la lista para modificar: ");

		this = (Passenger*) ll_get(pArrayListPassenger, index);

		Passenger_printOne(this);

		utn_getNumero(&verificacion, "¿Está seguro que desea modificar este pasajero?\n1. Si\n2. No\n", "Opcion invalida...\n", 1, 2, 5);

		if(verificacion == 1)
		{
			if(Passenger_newEdit(this) == 0)
			{
				retorno = 0;
			}

		}
		else
		{
			retorno = 1;
		}

	}

	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	Passenger* this;
	int retorno = -1;
	int index;
	int verificacion;


	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);

		index = Passenger_validarID(pArrayListPassenger, "Ingrese un ID de la lista para eliminar: ");

		this = (Passenger*) ll_get(pArrayListPassenger, index);

		Passenger_printOne(this);

		utn_getNumero(&verificacion, "¿Está seguro que desea eliminar este pasajero?\n1. Si\n2. No\n", "Opcion invalida...\n", 1, 2, 5);

		if(verificacion == 1)
		{
			ll_remove(pArrayListPassenger, index);
			retorno = 0;
		}
		else
		{
			retorno = 1;
		}
	}

	return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* this;
	int size;
	int retorno;

	retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		size = ll_len(pArrayListPassenger);

		if(size > 0)
		{
			for(int i=0; i<size; i++)
			{
				this = (Passenger*) ll_get(pArrayListPassenger, i);
				Passenger_printOne(this);
			}
			retorno = 0;
		}
	}

	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int validarSort;
	int criterioID;
	int criterioName;
	int criterioLastName;
	int criterioPrice;
	int retorno;

	retorno = -1;

	printf("\n¿Como le gustaria ordenar a los pasajeros?\n");

    do
    {

    	validarSort = showMenuSort();

		switch(validarSort)
		{
		case 1:
			criterioID = criterioOrdenamiento();
			printf("\n==================================================\n");
			printf("Por favor espere... su lista esta siendo ordenada.");
			printf("\n==================================================\n");
			if(ll_sort(pArrayListPassenger, Passenger_compareById, criterioID) == 0)
			{
				printf("\nSe han ordenado los pasajeros satisfactoriamente\n\n");
				validarSort = 5;
				retorno = 0;
				printf("Volviendo al menu principal...\n");
			}
			else
			{
				printf("\nNo se ha podido ordenar la lista.\n");
			}
			break;
		case 2:
			criterioName = criterioOrdenamiento();
			printf("\n==================================================\n");
			printf("Por favor espere... su lista esta siendo ordenada.");
			printf("\n==================================================\n");
			if(ll_sort(pArrayListPassenger, Passenger_compareByName, criterioName) == 0)
			{
				printf("\nSe han ordenado los pasajeros satisfactoriamente\n\n");
				validarSort = 5;
				retorno = 0;
				printf("Volviendo al menu principal...\n");
			}
			else
			{
				printf("\nNo se ha podido ordenar la lista.\n");
			}
			break;
		case 3:
			criterioLastName = criterioOrdenamiento();
			printf("\n==================================================\n");
			printf("Por favor espere... su lista esta siendo ordenada.");
			printf("\n==================================================\n");
			if(ll_sort(pArrayListPassenger, Passenger_compareByLastName, criterioLastName) == 0)
			{
				printf("\nSe han ordenado los pasajeros satisfactoriamente\n\n");
				validarSort = 5;
				retorno = 0;
				printf("Volviendo al menu principal...\n");
			}
			else
			{
				printf("\nNo se ha podido ordenar la lista.\n");
			}
			break;
		case 4:
			criterioPrice = criterioOrdenamiento();
			printf("\n==================================================\n");
			printf("Por favor espere... su lista esta siendo ordenada.");
			printf("\n==================================================\n");
			if(ll_sort(pArrayListPassenger, Passenger_compareByPrice, criterioPrice) == 0)
			{
				printf("\nSe han ordenado los pasajeros satisfactoriamente\n\n");
				validarSort = 5;
				retorno = 0;
				printf("Volviendo al menu principal...\n");
			}
			else
			{
				printf("\nNo se ha podido ordenar la lista.\n");
			}
			break;
		case 5:
			printf("Volviendo al menu principal...\n\n");
			break;
		}
    }while(validarSort != 5);

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno;

	retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL && parser_PassengerSaveText(pFile, pArrayListPassenger) == 0)
		{
			retorno = 0;
		}
		fclose(pFile);
	}

	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno;

	retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"wb");

		if(pFile != NULL && parser_PassengerSaveBinary(pFile, pArrayListPassenger) == 0)
		{
			retorno = 0;
		}
			fclose(pFile);
	}

    return retorno;
}
int controller_leerID(char* path, int* id)
{
	FILE* auxFile;
	int retorno;

	retorno = -1;

	if(path != NULL && id != NULL)
	{
		auxFile = fopen(path,"r");

		fread(id,sizeof(int),1,auxFile);

		fclose(auxFile);

		retorno = 0;
	}

	return retorno;
}

/// @fn int controller_saveIdToFile(char*, int)
/// @brief guarda el id obtenido despues de haber leido el archivo.
///
/// @param path
/// @param id
/// @return devuelve -1 si no pudo guarda el id y 0 si lo pudo hacer.
int controller_guardarID(char* path, int id)
{
	FILE* auxFile;
	int retorno;

	retorno = -1;

	if(path != NULL)
	{
		auxFile = fopen(path,"w");

		fwrite(&id,sizeof(int),1,auxFile);

		fclose(auxFile);

		retorno = 0;
	}

	return retorno;
}
