#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @brief Se ingresa y se validan los kilometros ingresados
///
/// @return retorna los kilometros ingresados en FLOAT
float IngresarKilometros();
/// @brief Se ingresa y se valida el precio ingresado de Aerolineas
///
/// @return retorna el precio en forma de FLOAT
float IngresarPrecioVuelosAerolineas();
/// @brief Se ingresa y se valida el precio ingresado de Latam
///
/// @return retorna el precio en forma de FLOAT
float IngresarPrecioVuelosLatam();
/// @brief Se calculan los precios de Aerolineas con los datos ingresados anteriormente
///
/// @param IngresarKilometros, le paso por los kilometros ingresados antes para hace los calculos
/// @param IngresarPrecioVuelosAerolineas, le paso el precio ingresado de Aerolineas para hacer los calculos
void CalcularPreciosAerolineas(float IngresarKilometros, float IngresarPrecioVuelosAerolineas);
/// @brief Se calculan los precios de Latam con los datos ingresados anteriormente
///
/// @param IngresarKilometros, le paso por los kilometros ingresados antes para hace los calculos
/// @param IngresarPrecioVuelosAerolineas, le paso el precio ingresado de Latam para hacer los calculos
void CalcularPreciosLatam(float IngresarKilometros, float IngresarPrecioVuelosLatam);
/// @brief calcula la diferencia de precio entre Latam y Aerolineas (x-y)
///
/// @param IngresarPrecioVuelosLatam, le paso el precio de Latam para hacer el calculo
/// @param IngresarPrecioVuelosAerolineas, le paso el precio de Aerolineas para hacer el calculo
/// @return retorna la diferencia de precio entre los dos precios
float CalcularDiferenciaDePrecio(float IngresarPrecioVuelosLatam, float IngresarPrecioVuelosAerolineas);
/// @brief Muestra los datos ya calculados usando las funciones anteriores
///
/// @param precioLatam, le paso el precio de Latam
/// @param precioAerolineas, le paso el precio de Aerolineas
/// @param kilometros, le paso los kilometros
/// estos 3 parametros para poder hacer todos los calculos y mostrarlos
void mostrarDatos(float precioLatam, float precioAerolineas, float kilometros);
#endif
