#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Inputs.h"
#include "string.h"
#include "ctype.h"
#define FirstClass 1
#define ExecutiveClass 2
#define EconomyClass 3

Passenger* Passenger_new()
{
	Passenger* this;

	this = (Passenger*) malloc(sizeof(Passenger));

	return this;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* estadoVueloStr)
{
	Passenger* this;
	int id;
	float precio;
	int tipoPasajero;

	this = Passenger_new(); //ASIGNO ESPACIO EN MEMORIA DINAMICA.

	id = atoi(idStr);

	precio = atof(precioStr);

	if(strcmp(tipoPasajeroStr, "FirstClass") == 0)
	{
		tipoPasajero = 1;
	}
	else
	{
		if(strcmp(tipoPasajeroStr, "ExecutiveClass") == 0)
		{
			tipoPasajero = 2;
		}
		else
		{
			if (strcmp(tipoPasajeroStr, "EconomyClass") == 0)
			{
				tipoPasajero = 3;
			}
		}
	}

	if (this != NULL)
	{
		if(Passenger_setId(this, id) == -1 ||
		   Passenger_setNombre(this, nombreStr) == -1 ||
		   Passenger_setApellido(this, apellidoStr) == -1 ||
		   Passenger_setPrecio(this, precio) == -1 ||
		   Passenger_setTipoPasajero(this, tipoPasajero) == -1 ||
		   Passenger_setCodigoVuelo(this, codigoVueloStr) == -1 ||
		   Passenger_setEstadoVuelo(this, estadoVueloStr) == -1)
		{
			Passenger_delete(this);
			this = NULL;
		}
	}

	return this;
}
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
int Passenger_setId(Passenger* this,int id)
{
	int retorno;

	retorno = -1;

	if (this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno;

	retorno = -1;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno = -1;

	if (this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno = -1;

	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno = -1;

	if (this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno = -1;

	if (this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 0;
	}

	return retorno;
}
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno = -1;

	if (this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno = -1;

	if (this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}

	return retorno;
}
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno;

	retorno = -1;

	if (this != NULL && tipoPasajero > 0)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno;

	retorno = -1;

	if (this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}

	return retorno;
}
int Passenger_setPrecio(Passenger* this, float precio)
{
	int retorno;

	retorno = -1;

	if (this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getPrecio(Passenger* this, float* precio)
{
	int retorno;

	retorno = -1;

	if (this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno;

	retorno = -1;

	if (this != NULL && estadoVuelo != NULL)
	{
		strcpy(this->statusFlight, estadoVuelo);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno;

	retorno = -1;

	if (this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo, this->statusFlight);
		retorno = 0;
	}

	return retorno;
}
int setTipoTexto(int tipoPasajero, char* tipoPasajeroStr)
{
	int retorno = -1;

	if(tipoPasajeroStr != NULL)
	{
		if(tipoPasajero == 1)
		{
			strcpy(tipoPasajeroStr, "FirstClass");
			retorno = 0;
		}
		else
		{
			if(tipoPasajero == 2)
			{
				strcpy(tipoPasajeroStr, "ExecutiveClass");
				retorno = 0;
			}
			else
			{
				if(tipoPasajero == 3)
				{
					strcpy(tipoPasajeroStr, "EconomyClass");
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}
void Passenger_printOne(Passenger* this)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	char estadoVuelo[40];
	char tipoPasajeroStr[20];

	Passenger_getId(this, &id);
	Passenger_getNombre(this, nombre);
	Passenger_getApellido(this, apellido);
	Passenger_getPrecio(this, &precio);
	Passenger_getCodigoVuelo(this, codigoVuelo);
	Passenger_getTipoPasajero(this, &tipoPasajero);
	Passenger_getEstadoVuelo(this, estadoVuelo);
	setTipoTexto(tipoPasajero, tipoPasajeroStr);

	printf("|%-10d | %-16s | %-18s | %-12.2f | %-8s | %-15s | %-10s |\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajeroStr, estadoVuelo);

}
void Passenger_setFlightStatusStr(int flightStatus, char* statusFlightStr)
{
	switch(flightStatus)
	{
		case 1:
			strcpy(statusFlightStr,"Aterrizado");
			break;
		case 2:
			strcpy(statusFlightStr,"En Horario");
			break;
		case 3:
			strcpy(statusFlightStr,"En vuelo");
			break;
		case 4:
			strcpy(statusFlightStr,"Demorado");
			break;
	}
}
int Passenger_compareById(void* idUno, void* idDos)
{
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	int id1;
	int id2;
	int retorno;

	if(idUno != NULL && idDos != NULL)
	{
		retorno = 0;

		pasajeroUno = (Passenger*) idUno;
		pasajeroDos = (Passenger*) idDos;

		Passenger_getId(pasajeroUno, &id1);
		Passenger_getId(pasajeroDos, &id2);

		if(id1 > id2)
		{
			retorno = 1;
		}
		else
		{
			if(id1 < id2)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}
int Passenger_compareByName(void* elemento1 ,void* elemento2)
{
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	char nombre[50];
	char nombre2[50];
	int retorno;

	if(elemento1 != NULL && elemento2 != NULL)
	{
		pasajeroUno = (Passenger*) elemento1;
		pasajeroDos = (Passenger*) elemento2;

		Passenger_getNombre(pasajeroUno, nombre);
		Passenger_getNombre(pasajeroDos, nombre2);

		retorno = strcmpi(nombre,nombre2);
	}

	return retorno;
}
int Passenger_compareByLastName(void* elemento1 ,void* elemento2)
{
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	char apellido[50];
	char apellido2[50];
	int retorno;

	if(elemento1 != NULL && elemento2 != NULL)
	{
		pasajeroUno = (Passenger*) elemento1;
		pasajeroDos = (Passenger*) elemento2;

		Passenger_getApellido(pasajeroUno, apellido);
		Passenger_getApellido(pasajeroDos, apellido2);

		retorno = strcmpi(apellido, apellido2);
	}

	return retorno;
}
int Passenger_compareByPrice(void* elemento1 ,void* elemento2)
{
	Passenger* empleadoUno;
	Passenger* empleadoDos;
	float precio1;
	float precio2;
	int retorno;

	if(elemento1 != NULL && elemento2 != NULL)
	{
		retorno = 0;

		empleadoUno = (Passenger*) elemento1;
		empleadoDos = (Passenger*) elemento2;

		Passenger_getPrecio(empleadoUno, &precio1);
		Passenger_getPrecio(empleadoDos, &precio2);

		if(precio1 > precio2)
		{
			retorno = 1;
		}
		else
		{
			if(precio1 < precio2)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}
int Passenger_findID(LinkedList* listaPasajeros, int editID)
{
	Passenger* this;
	int index;
	int retorno = -1;
	int len;
	int idAux;

	if(listaPasajeros != NULL)
	{
		len = ll_len(listaPasajeros);

		if(len > 0)
		{
			for(int i=0; i<len; i++)
			{
				this = (Passenger*) ll_get(listaPasajeros, i);
				Passenger_getId(this, &idAux);
				if(idAux == editID)
				{
					index = i;
					return index;
					retorno = 0;
					break;
				}
			}
		}
	}

	return retorno;
}
int Passenger_validarID(LinkedList* listaPasajeros, char* editOrRemove)
{
	int idEdit;
	int index;

	if(listaPasajeros != NULL)
	{
		utn_getNumero(&idEdit, editOrRemove, "\nEse ID no existe.\n", 0, 1000000, 5);
		index = Passenger_findID(listaPasajeros, idEdit);

		while(index == -1)
		{
			printf("Ese ID no existe.\n");
			utn_getNumero(&idEdit, editOrRemove, "\nEse ID no existe.\n", 0, 1000000, 5);
			index = Passenger_findID(listaPasajeros, idEdit);
		}
	}

	return index;
}
Passenger* Passenger_newAlta(int id)
{
	Passenger* This;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char tipoPasajeroStr[20];
	char codigoVuelo[7];
	char estadoVuelo[20];
	int estadoVueloAux;

	This = Passenger_new();

	utn_getNombre(nombre, 50, "Ingrese su nombre: ", "\nEso no es un nombre...\n",5);
	strlwr(nombre);
	nombre[0] = toupper(nombre[0]);

	utn_getNombre(apellido, 50, "Ingrese su apellido: ", "\nEso no es un apellido...\n",5);
	strlwr(apellido);
	apellido[0] = toupper(apellido[0]);

	utn_getNumeroFlotante(&precio, "Ingrese el precio: ", "\nPrecio no valido...\n", 0, 100000, 5);

	printf("Lista de tipos de pasajeros\n");
	printf("1. FirstClass \n2. ExecutiveClass \n3. EconomyClass \n");
	utn_getNumero(&tipoPasajero, "Ingrese el tipo: ", "\nOpcion invalida...\n", 1, 3, 5);
	setTipoTexto(tipoPasajero, tipoPasajeroStr);

	utn_getAlphaNumeric(codigoVuelo, 8, "Ingrese el codigo de vuelo: ", "\nError...[7 caracteres MAX]\n", 5);

	printf("Lista de estados de vuelos\n1. Aterrizado\n2. En Horario\n3. En vuelo\n4. Demorado\n");
	utn_getNumero(&estadoVueloAux, "Ingrese el estado: ", "\nOpcion invalida...\n", 1, 4, 5);
	Passenger_setFlightStatusStr(estadoVueloAux, estadoVuelo);

	Passenger_setId(This, id);
	Passenger_setNombre(This, nombre);
	Passenger_setApellido(This, apellido);
	Passenger_setPrecio(This, precio);
	Passenger_setTipoPasajero(This, tipoPasajero);
	Passenger_setCodigoVuelo(This, codigoVuelo);
	Passenger_setEstadoVuelo(This, estadoVuelo);

	return This;
}
int Passenger_newEdit(Passenger* this)
{
	int opcion;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char tipoPasajeroStr[20];
	char codigoVuelo[7];
	char estadoVuelo[20];
	int estadoVueloAux;
	int retorno = -1;

	do
	{
		opcion = showMenuEdit();

		switch(opcion)
		{
		case 1:
			utn_getNombre(nombre, 50, "Ingrese el nuevo nombre: ", "\nEso no es un nombre...\n",5);
			strlwr(nombre);
			nombre[0] = toupper(nombre[0]);
			if(Passenger_setNombre(this, nombre) == 1)
			{
				printf("\nNuevo nombre modificado con exito...\n\n");
				retorno = 0;
			}
			break;
		case 2:
			utn_getNombre(apellido, 50, "Ingrese el nuevo apellido: ", "\nEso no es un apellido...\n",5);
			strlwr(apellido);
			apellido[0] = toupper(apellido[0]);
			if(Passenger_setApellido(this, apellido) == 1)
			{
				printf("\nNuevo apellido modificado con exito...\n\n");
				retorno = 0;
			}
			break;
		case 3:
			utn_getNumeroFlotante(&precio, "Ingrese el nuevo precio: ", "\nPrecio no valido...\n", 0, 100000, 5);
			if(Passenger_setPrecio(this, precio) == 1)
			{
				printf("\nNuevo precio modificado con exito...\n\n");
				retorno = 0;
			}
			break;
		case 4:
			printf("Lista de tipos de pasajeros\n");
			printf("1. FirstClass \n2. ExecutiveClass \n3. EconomyClass \n");
			utn_getNumero(&tipoPasajero, "Ingrese el nuevo tipo: ", "\nOpcion invalida...\n", 1, 3, 5);
			setTipoTexto(tipoPasajero, tipoPasajeroStr);
			if(Passenger_setTipoPasajero(this, tipoPasajero) == 1)
			{
				printf("\nNuevo tipo de pasajero modificado con exito...\n\n");
				retorno = 0;
			}
			break;
		case 5:
			utn_getAlphaNumeric(codigoVuelo, 8, "Ingrese el codigo de vuelo: ", "\nError...[7 caracteres MAX]\n", 5);
			if(Passenger_setCodigoVuelo(this, codigoVuelo) == 1)
			{
				printf("\nNuevo codigo de vuelo modificado con exito...\n\n");
				retorno = 0;
			}
			break;
		case 6:
			printf("Lista de estados de vuelos\n1. Aterrizado\n2. En Horario\n3. En vuelo\n4. Demorado\n");
			utn_getNumero(&estadoVueloAux, "Ingrese el nuevo estado: ", "\nOpcion invalida...\n", 1, 4, 5);
			Passenger_setFlightStatusStr(estadoVueloAux, estadoVuelo);
			if(Passenger_setEstadoVuelo(this, estadoVuelo) == 1)
			{
				printf("\nNuevo estado de vuelo modificado con exito...\n\n");
				retorno = 0;
			}
			break;
		case 7:
			printf("Volviendo al menu principal...\n");
			retorno = 0;
			break;
		}

	}while(opcion != 7);

	return retorno;
}

