/*	Trabajo Practico 3
	TP_3
	Montenegro Fernando Thomas DIV C //TERMINADO
*/
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Inputs.h"

int main()
{
	setbuf(stdout,NULL);

    int option = 0;
    int contadorCsvTxt = 0;
    int contadorBin = 0;
    int verificacion;
    int verificacionRemove;
    int saveTxt = 0;
    int saveBin = 0;
    int len;
    LinkedList* listaPasajeros = ll_newLinkedList();

    //UNA ACLARACION: EL SORT DE APELLIDO FUNCIONA BIEN PERO MEZCLA LOS APELLIDOS POR LAS TILDES QUE TIENE EL ARCHIVO
    //POR QUE LAS TILDES NO ESTAN EN EL ASCIIs

    do{

    	len = ll_len(listaPasajeros);
    	controller_guardarID("lastId.txt", len+1);
    	option = showMenu();

        switch(option)
        {
            case 1:
            	if(contadorCsvTxt == 0)
            	{
            		controller_loadFromText("data.csv",listaPasajeros);
					printf("\nSe ha cargado la lista correctamente\n\n");
					ll_sort(listaPasajeros, Passenger_compareById, 1);
					contadorCsvTxt = 1;

            	}
				else
				{
					printf("Ya se han cargado los datos...\n\n");
				}
			break;

            case 2:
            	if(contadorBin == 0)
            	{
            		controller_loadFromBinary("data.bin",listaPasajeros);
            		ll_sort(listaPasajeros, Passenger_compareById, 1);
					printf("\nSe ha cargado la lista correctamente\n\n");
					contadorBin = 1;

            	}
				else
				{
					printf("Ya se han cargado los datos...\n\n");
				}
			break;

            case 3:
            	if(controller_addPassenger(listaPasajeros, "lastId.txt") == 0)
            	{
            		printf("Se agrego un nuevo pasajero con exito.\n");
            	}
            	else
            	{
            		printf("Ha ocurrido un error y no se ha podido añadir el pasajero.\n");//sas/as
            	}
            break;
            case 4:
            	if(ll_isEmpty(listaPasajeros) == 0)
            	{
            		verificacion = controller_editPassenger(listaPasajeros);
            		if(verificacion == 0)
					{
						printf("Pasajero modificado con exito...\n");
					}
					else
					{
						if(verificacion == 1)
						{
							printf("Modificacion de pasajero cancelada...\n");
						}
						else
						{
							printf("Hubo un problema y no se puede modificar el pasajero...\n");
						}
					}
            	}
            	else
            	{
            		printf("\nNo hay pasajeros cargados...\n");
            	}
            	break;
            case 5:
            	if(ll_isEmpty(listaPasajeros) == 0)
            	{
					verificacionRemove = controller_removePassenger(listaPasajeros);
					if(verificacionRemove == 0)
					{
						printf("Pasajero dado de baja con exito...\n");
					}
					else
					{
						if(verificacionRemove == 1)
						{
							printf("Baja de pasajero cancelada...\n");
						}
						else
						{
							printf("Hubo un problema y no se puede dar de baja el pasajero...\n");
						}
					}
            	}
            	else
            	{
            		printf("\nNo hay pasajeros cargados...\n");
            	}
            	break;
            case 6:
            	if(ll_isEmpty(listaPasajeros) == 0)
            	{
            		if(controller_ListPassenger(listaPasajeros) == 0)
            		{
            			printf("\nLista de pasajeros cargada con exito...\n\n");
            		}
            	}
            	else
            	{
            		printf("\nNo hay pasajeros cargados para mostrarlos...\n");
            	}
            break;
            case 7:
                /*UNA ACLARACION: EL SORT DE APELLIDO FUNCIONA BIEN PERO MEZCLA LOS APELLIDOS
            		POR LAS TILDES QUE TIENE EL ARCHIVO
                	POR QUE LAS TILDES NO ESTAN EN EL ASCII*/
            	if(ll_isEmpty(listaPasajeros) == 0)
            	{
            		controller_sortPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("No hay pasajeros cargados...\n");
            	}
            break;
            case 8:
            	if(ll_isEmpty(listaPasajeros) == 0 && contadorCsvTxt == 1)
            	{
            		if(controller_saveAsText("data.csv", listaPasajeros) == 0)
            		{
            			printf("\nDatos guardados correctamente...\n\n");
            			saveTxt = 1;
            		}
            	}
            	else
            	{
            		printf("\nHubo un problema y no se ha podido guardar los datos\n");
            		printf("por los siguientes motivos...\n");
            		printf("No hay pasajeros cargados o esta intentando guardar un archivo .bin en .csv\n");
            		printf("Por favor intente guardar los datos correctamente.\n\n");

            	}
            	break;
            case 9:
            	if(ll_isEmpty(listaPasajeros) == 0 && contadorBin == 1)
            	{
            		if(controller_saveAsBinary("data.bin", listaPasajeros) == 0)
            		{
						printf("\nDatos guardados correctamente...\n\n");
						saveBin = 1;
            		}
            	}
            	else
            	{
            		printf("\nHubo un problema y no se ha podido guardar los datos\n");
            		printf("por los siguientes motivos...\n");
            		printf("No hay pasajeros cargados o esta intentando guardar un archivo .csv en .bin\n");
            		printf("Por favor intente guardar los datos correctamente.\n\n");
            	}
            	break;
            case 10:
            	if(saveTxt == 1 || saveBin == 1)
            	{
            		printf("\n\nPrograma finalizado...\n\n");
            	}
            	else
            	{
            		printf("\n\nNo hay datos guardados antes de salir\n\n");
            		option = 11;
            	}
            break;
        }
    }while(option != 10);

    return 0;
}

