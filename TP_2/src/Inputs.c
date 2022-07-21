#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include <string.h>
#include <ctype.h>

int getInt(int* pResultado)
{
	int retorno;
	char buffer[4096];

	retorno = -1;

	if(pResultado != NULL && getString(buffer, sizeof(buffer)) == 0 && esNumerica(buffer, sizeof(buffer)))
	{
		retorno = 0;
		*pResultado =  atoi(buffer);
	}

	return retorno;
}

int getString(char* cadena, int longitud)
{
	int retorno;
	char buffer[4096];

	retorno = -1;

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);

		if(fgets(buffer, sizeof(buffer), stdin) != NULL)
		{
			if(buffer[strnlen(buffer, sizeof(buffer))-1] == '\n')
			{
				buffer[strnlen(buffer, sizeof(buffer))-1] = '\0';
			}
			if(strnlen(buffer, sizeof(buffer)) <= longitud)
			{
				strncpy(cadena, buffer, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int esNumerica(char* cadena, int limite)
{
	int retorno;
	int i;

	retorno = -1;

	for(i=0; i<limite && cadena[i] != '\0'; i++)
	{
		retorno = 1;
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	int buffer;

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar >= minimo && bufferChar <= maximo)
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}

		}while(reintentos >= 0);

	}

	return retorno;
}
int getFloat(float* pResultado)
{
	int retorno;
	char buffer[64];

	retorno = -1;

	if(pResultado != NULL)
	{
		if(getString(buffer, sizeof(buffer)) == 0 && esFlotante(buffer, sizeof(buffer)))
		{
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}

	return retorno;
}
int esFlotante(char* cadena, int limite)
{
	int retorno;
	int i;
	int contadorPuntos;

	retorno = -1;
	contadorPuntos = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0; i<limite && cadena[i] != '\0'; i++)
		{
			retorno = 1;
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}

			}
		}
	}

	return retorno;
}
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno;
	float buffer;

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getFloat(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
int getNombre(char* pResultado, int longitud)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(getString(buffer, sizeof(buffer)) == 0 &&
			esNombre(buffer, sizeof(buffer)) &&
			strnlen(buffer, sizeof(buffer))<longitud)
		{
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}

	return retorno;
}
int esNombre(char* cadena, int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z'))
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;

	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}

	return retorno;
}
int getDescripcion(char* pResultado, int longitud)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(getString(buffer, sizeof(buffer)) == 0 &&
			esDescripcion(buffer, sizeof(buffer)) &&
			strnlen(buffer, sizeof(buffer)) < longitud)
		{
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}

	return retorno;
}
int esDescripcion(char* cadena, int longitud)
{
	int i = 0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z') &&  (cadena[i] < 'a' || cadena[i] > 'z'))
			{
				retorno = 0;
				break;
			}
		}

	}

	return retorno;
}
int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;

	while(reintentos >= 0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getDescripcion(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}

	return retorno;
}
int getAlphaNumeric(char* pResultado, int longitud)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(getString(buffer, sizeof(buffer)) == 0 &&
			esAlphaNumeric(buffer, sizeof(buffer)) &&
			strnlen(buffer, sizeof(buffer)) < longitud)
		{
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;

}
int esAlphaNumeric(char* cadena, int longitud)
{
	int i = 0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[0] != '\n' || cadena[0] != ' ') && (cadena[i] > '9' || cadena[i] < '0') && (cadena[i] < 'A' || cadena[i] > 'Z') &&  (cadena[i] < 'a' || cadena[i] > 'z'))
			{
				retorno = 0;
				break;
			}
		}

	}
	return retorno;

}
int utn_getAlphaNumeric(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{

	char bufferString[4096];
	int retorno = -1;

	while(reintentos >= 0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getAlphaNumeric(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}

	return retorno;
}





