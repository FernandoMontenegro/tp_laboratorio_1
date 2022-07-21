#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @brief elimina el pasajero junto con la funcion passenger_Remove
///
/// @param lista, puntero a la lista de pasajeros
/// @param lenLista, tamaño de la lista de pasajeros
/// @param listaTipos, puntero a la lista de tipos de pasajeros
/// @param lenTipos, tamaño de la lista de tipos de pasajeros
/// @param listaStatus, puntero a la lista de estados de pasajeros
/// @param lenStatus, tamaño de la lista de tipos de estado
/// @return retorna 0 si se confirma la eliminacion del pasajero
/// 		retorna 1 si se cancela la confirmacion de la eliminacion del pasajero
/// 		retorna 2 si no hay pasajeros cargados.
int eliminarPasajero(Passenger* lista, int lenLista, TypePassenger* listaTipos, int lenTipos, StatusFlight* listaStatus, int lenStatus);
/// @brief pasajeros hardcodeado para testear el programa y no tener que cargar pasajeros cada rato
///
/// @param pasajeros, puntero a la lista de pasajeros
/// @param tiposPasajeros, puntero a la lista de tipos de pasajeros
/// @param estadosVuelo, puntero a la lista de estados de pasajeros
void HardcodeoPasajeros(Passenger pasajeros[], int* id);
/// @brief funcion con el menu de opciones de listado
///
/// @param lista, puntero a la lista de pasajeros
/// @param lenLista, tamaño de la lista de pasajeros
/// @param listaTipos, puntero a la lista de tipos de pasajeros
/// @param lenTipos, tamaño de la lista de tipos de pasajeros
/// @param listaStatus, puntero a la lista de estados de pasajeros
/// @param lenStatus, tamaño de la lista de tipos de estado
/// @return retorna 0 si se pudo mostrar la lista en algunas de las 3 opciones
/// 		retorna -1 si no se pudo mostrar ningun listado
int sortList(Passenger* listaPasajeros, int lenPasajeros, TypePassenger* tipoPasajeros, int lenTipo, StatusFlight* tipoEstado, int lenStatus);
/// @brief menu de la listados
///
/// @return retorna la opcion elegida, 1, 2, 3, o 4.
int menuSort();
/// @brief criterio de ordenamiento ASCENDENTE O DESCENDENTE para ordenar el array
///
/// @return retorna 0 si se ordena ASCENDENTE
/// 		retorna 1 si se ordena DESCENDENTE
int criterioOrdenamiento();
/// @brief funciones para calcular cuantos precios de pasajeros superan el promedio de precios
///
/// @param pasajeros, puntero a la lista de pasajeros
/// @param tamPasajeros, tamaño del array de pasajeros
/// @param promedio, le paso el promedio de precios FLOAT
/// @return retorna la cantidad de pasajeros superan el promedio
/// 		retorna -1 si no se pudo calcular
int pasajeros_overAverage(Passenger pasajeros[],int tamPasajeros,float promedio);
/// @brief carga un pasajero en la lista con la funcion addPassengers
///
/// @param lista, puntero a la lista de pasajeros
/// @param lenLista, tamaño de la lista de pasajeros
/// @param listaTipos, puntero a la lista de tipos de pasajeros
/// @param lenTipos, tamaño de la lista de tipos de pasajeros
/// @param listaStatus, puntero a la lista de estados de pasajeros
/// @param lenStatus, tamaño de la lista de tipos de estado
/// @return retorna 0 si se cargó el pasajero
/// 		retorna -1 si no se pudo cargar
int CargarUnPasajero(Passenger lista[], int len, TypePassenger listaTipos[], int lenTipos, StatusFlight listaStatus[], int lenStatus, int* id);
/// @brief hace las verificaciones necesarias para la modificacion del personaje con la funcion Passenger_modifyOne
///
/// @param lista, puntero a la lista de pasajeros
/// @param lenLista, tamaño de la lista de pasajeros
/// @param listaTipos, puntero a la lista de tipos de pasajeros
/// @param lenTipos, tamaño de la lista de tipos de pasajeros
/// @param listaStatus, puntero a la lista de estados de pasajeros
/// @param lenStatus, tamaño de la lista de tipos de estado
/// @return retorna 0 si se pudo modificar
/// 		retorna 1 si se canceló la modificacion
/// 		retorna 2 si no hay pasajeros cargados
int Modificacion(Passenger* lista, int lenLista, TypePassenger* listaTipos, int lenTipos, StatusFlight* listaStatus, int lenStatus);
/// @brief muestra un menu con opciones para poder modificar lo que el pasajero quiera
///
/// @param lista, puntero a la lista de pasajeros
/// @param listaTipos, puntero a la lista de tipos de pasajeros
/// @param lenTipos, tamaño de la lista de tipos de pasajeros
/// @return retorna el auxiliar de un pasajero
Passenger Passenger_modifyOne(Passenger lista, TypePassenger* listaTipos, int lenTipos);
/// @brief calcula el total y promedio de los precios y los imprime junto con la funcion pasajeros_overAverage
///
/// @param list, puntero a la lista de pasajeros
/// @param len, tamaño de la lista de pasajeros
void printTotal_Promedio(Passenger* list, int len);

#endif
