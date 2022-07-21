/*	Trabajo Practico 2
	TP_2
	Montenegro Fernando Thomas DIV C //TERMINADO
*/
#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "Inputs.h"
#include "Funciones.h"

int main(void)
{
	setbuf(stdout,NULL);

	int auxInt;
	int rtnRemove;
	int rtnModify;
	int rtnAdd;
	int id = 1000;
	int rtnHardCode = 0;

	Passenger listaPasajeros[TAM];

	TypePassenger tipoPasajeros[TAM_TYPE] = {{1,"ClaseEjecutiva"},{2,"ClaseTurista"},{3,"PrimeraClase"}};

	StatusFlight tipoEstado[TAM_STATUS] = {{1,"Activo"},{2,"Retrasado"},{3,"Suspendido"}};

	if(initPassengers(listaPasajeros, TAM) == 0)
	{
		printf("\nTodos los lugares estan correctamente inicializados y vacios.\n\n");

		do
		{
			utn_getNumero(&auxInt,"1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.HARDCODEO\n6.SALIR\n\nSeleccione una opcion: ",
					"No es una opcion valida.\n",1, 6, 2);

			switch(auxInt)
			{
				case 1:
					rtnAdd = CargarUnPasajero(listaPasajeros, TAM, tipoPasajeros, TAM_TYPE, tipoEstado, TAM_STATUS,  &id);
					if(rtnAdd == 0)
					{
						printf("\nPASAJERO CARGADO EXITOSAMENTE\n\n");
					}
					else
					{
						printf("\nNO HAY MAS VUELOS DISPONIBLES\n\n");
					}
					break;
				case 2:
					rtnModify = Modificacion(listaPasajeros, TAM, tipoPasajeros, TAM_TYPE, tipoEstado, TAM_STATUS);
					if(rtnModify == 0)
					{
						printf("\nMODIFICACION DE PASAJERO EXITOSA\n\n");

					}
					else
					{
						if(rtnModify == 1)
						{
							printf("\nMODIFICACION DE PASAJERO CANCELADA\n\n");
						}
						else
						{
							printf("\nNO SE HA CARGADO NINGUN PASAJERO.\n\n");
						}
					}
					break;
				case 3:
					rtnRemove = eliminarPasajero(listaPasajeros, TAM, tipoPasajeros, TAM_TYPE, tipoEstado, TAM_STATUS);
					if(rtnRemove == 0)
					{
						printf("\nBAJA DE PASAJERO EXITOSA\n\n");
					}
					else
					{
						if(rtnRemove == 1)
						{
							printf("\nBAJA DE PASAJERO CANCELADA\n\n");
						}
						else
						{
							printf("\nNO SE HA CARGADO NINGUN PASAJERO.\n\n");
						}
					}
					break;
				case 4:
					if(sortList(listaPasajeros, TAM, tipoPasajeros, TAM_TYPE, tipoEstado, TAM_STATUS) == 0)
					{
						printf("\nMenu de ordenamiento y listado mostrado correctamente...\n\n");
					}
					else
					{
						printf("Ha ocurrido un error...\n");
					}
					//printPassenger(listaPasajeros, TAM, tipoPasajeros, TAM_TYPE, tipoEstado, TAM_STATUS);
					break;
				case 5:
					if(rtnHardCode == 0)
					{
						HardcodeoPasajeros(listaPasajeros, &id);
						if(printPassenger(listaPasajeros, TAM, tipoPasajeros, TAM_TYPE, tipoEstado, TAM_STATUS) == 1)
						{
							printf("\nHardcodeo cargado....\n\n");
							rtnHardCode = 1;
						}
					}
					else
					{
						printf("\nYa se cargo el hardcodeo una vez...\n\n");
					}
					break;
				case 6:
					printf("Programa finalizado...\n");
					break;
				}
		}while(auxInt != 6);
	}
	else
	{
		printf("\nHubo un problema al inicializar los pasajeros.\n\n");
	}

	return 0;
}
