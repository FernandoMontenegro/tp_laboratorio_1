#include <stdio.h>
#include <ctype.h>
#include "Funciones.h"
#include "Inputs.h"

float IngresarKilometros()
{
	float kilometros;

	utn_getNumeroFlotante(&kilometros, "\nIngrese los kilometros: ", "\nError...reingrese bien los kilometros.\n", 1, 500000, 5);

	return kilometros;
}
float IngresarPrecioVuelosAerolineas()
{
	float precioAerolineas;

	utn_getNumeroFlotante(&precioAerolineas, "Ingresar Precio de Vuelo Aerolineas: ",
			"\nError...reingrese bien el precio.\n", 1, 50000000, 5);

	printf("El precio de Aerolineas es: $%.2f\n\n",precioAerolineas);

	return precioAerolineas;

}
float IngresarPrecioVuelosLatam()
{
	float precioLatam;

	utn_getNumeroFlotante(&precioLatam, "Ingresar Precio de Vuelo Latam: ",
			"\nError...reingrese bien el precio.\n", 0, 50000000, 5);

	printf("El precio de Latam es: $%.2f\n\n",precioLatam);

	return precioLatam;
}
void CalcularPreciosAerolineas(float IngresarKilometros, float IngresarPrecioVuelosAerolineas)
{
	float tarjetaDebitoDescuento;
	float tarjetaCreditoInteres;
	float precioBitcoin;
	float precioUnitarioPorKM;

	if(IngresarKilometros < 1 || IngresarPrecioVuelosAerolineas <1)
	{
		printf("\nNo hay suficientes datos para calcular precios de Aerolineas,\npor favor reingrese los datos: \n\n");
	}
	else
	{
		tarjetaDebitoDescuento = IngresarPrecioVuelosAerolineas * 0.90;
		tarjetaCreditoInteres = IngresarPrecioVuelosAerolineas * 1.25;
		precioBitcoin = IngresarPrecioVuelosAerolineas / 4606954.55;
		precioUnitarioPorKM = (float)IngresarPrecioVuelosAerolineas / IngresarKilometros;

		printf("Precio Aerolineas: %.2f\n",IngresarPrecioVuelosAerolineas);
		printf("a) El precio del vuelo Aerolineas con tarjeta de debito es: $%.2f \n",tarjetaDebitoDescuento);
		printf("b) El precio del vuelo Aerolineas con tarjeta de credito es: $%.2f \n",tarjetaCreditoInteres);
		printf("c) El precio del vuelo Aerolineas con BITCOIN es de: %.2f BTC\n",precioBitcoin);
		printf("d) El precio unitario del vuelo de Aerolineas es: $%.2f \n\n",precioUnitarioPorKM);
	}

}
void CalcularPreciosLatam(float IngresarKilometros, float IngresarPrecioVuelosLatam)
{
	float tarjetaDebitoDescuento;
	float tarjetaCreditoInteres;
	float precioBitcoin;
	float precioUnitarioPorKM;

	if(IngresarKilometros < 1 || IngresarPrecioVuelosLatam < 1)
	{
		printf("No hay suficientes datos para calcular precios de Latam,\npor favor reingrese los datos: \n\n");
	}
	else
	{
		tarjetaDebitoDescuento = IngresarPrecioVuelosLatam * 0.90;
		tarjetaCreditoInteres = IngresarPrecioVuelosLatam * 1.25;
		precioBitcoin = IngresarPrecioVuelosLatam / 4606954.55;
		precioUnitarioPorKM = (float)IngresarPrecioVuelosLatam / IngresarKilometros;

		printf("Precio Latam: %.2f\n",IngresarPrecioVuelosLatam);
		printf("a) El precio del vuelo Latam con tarjeta de debito es: $%.2f \n",tarjetaDebitoDescuento);
		printf("b) El precio del vuelo Latam con tarjeta de credito es: $%.2f \n",tarjetaCreditoInteres);
		printf("c) El precio del vuelo Latam con BITCOIN es de: %.2f BTC\n",precioBitcoin);
		printf("d) El precio unitario del vuelo de Latam es: $%.2f \n\n",precioUnitarioPorKM);
	}

}
float CalcularDiferenciaDePrecio(float IngresarPrecioVuelosLatam, float IngresarPrecioVuelosAerolineas)
{
	float diferenciaPrecio;

	if(IngresarPrecioVuelosAerolineas < 1 || IngresarPrecioVuelosLatam <1)
	{
		printf("No hay suficientes datos para calcular la diferencia de precio,\npor favor reingrese los datos: \n\n");
	}
	else
	{
		if(IngresarPrecioVuelosAerolineas>IngresarPrecioVuelosLatam)
		{
			diferenciaPrecio = IngresarPrecioVuelosAerolineas - IngresarPrecioVuelosLatam;
			printf("La diferencia de precio es: $%.2f\n\n",diferenciaPrecio);
		}
		else
		{
			diferenciaPrecio = IngresarPrecioVuelosLatam - IngresarPrecioVuelosAerolineas;
			printf("La diferencia de precio es: $%.2f\n\n",diferenciaPrecio);
		}
	}

	return diferenciaPrecio;
}
void mostrarDatos(float precioLatam, float precioAerolineas, float kilometros)
{

	printf("KMs Ingresados: %.2f km\n\n",kilometros);
	CalcularPreciosLatam(kilometros, precioLatam);
	CalcularPreciosAerolineas(kilometros, precioAerolineas);
	CalcularDiferenciaDePrecio(precioLatam, precioAerolineas);
}





