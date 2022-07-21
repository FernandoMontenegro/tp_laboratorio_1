/*	Trabajo Practico 1
	TP_1
	Montenegro Fernando Thomas DIV C //TERMINADO
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Funciones.h"
#include "Inputs.h"

int main(void)
{
	setbuf(stdout,NULL);

	int opcion;
	float opcionUno;
	float opcionAerolineas;
	float opcionLatam;
	int validarkm = 0;

	do
	{
		printf("Menu de opciones\n\n");

		utn_getNumero(&opcion,"1. Ingresar Kilometros: \n"
							"2. Ingresar Precios de Vuelos: \n"
							"3. Calcular todos los costos: \n"
							"4. Informar Resultados\n"
							"5. Carga forzada de datos \n"
							"6. Salir\n"
							"Seleccione una opcion: ","\nNo es una opcion valida.\n",1, 6, 2);

		switch(opcion)
		{
			case 1:
				opcionUno = IngresarKilometros();
				printf("Los kilometros ingresados son: %.2f KM\n\n",opcionUno);
				validarkm = 1;
			break;
			case 2:
				if(validarkm == 1)
				{
					opcionAerolineas = IngresarPrecioVuelosAerolineas();
					opcionLatam = IngresarPrecioVuelosLatam();
					validarkm = 2;
				}
				else
				{
					printf("\nPrimero debe ingresar kilometros...\n\n");
				}
			break;
			case 3:
				if(validarkm == 2)
				{
					CalcularPreciosLatam(opcionUno, opcionLatam);
					CalcularPreciosAerolineas(opcionUno, opcionAerolineas);
					validarkm = 3;
				}
				else
				{
					printf("\nNo se puede calcular sin datos...\n\n");
				}

			break;
			case 4:
				if(validarkm == 3)
				{
					mostrarDatos(opcionLatam, opcionAerolineas, opcionUno);
				}
				else
				{
					printf("\nNo se pueden mostrar los datos sin antes haberlos calculados...\n\n");
				}
			break;
			case 5:
				mostrarDatos(159339, 162965, 7090);
			break;
			case 6:
				printf("Aplicacion cerrada con exito...");
			break;
		}
	}while(opcion != 6);

	return 0;
}
