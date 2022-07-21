#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define VACIO 0
#define LLENO 1
#define TAM 2000
#define TAM_TYPE 3
#define TAM_STATUS 3
#define TAM_HARDCODEO 5

typedef struct
{
	int idTypePassenger;
	char typePassenger[51];

}TypePassenger;

typedef struct
{
	int idStatusFlight;
	char statusFlight[51];

}StatusFlight;

typedef struct
{
	int idPasajero;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int idTypePassenger;
	int idStatusFlight;
	int isEmpty;
}Passenger;
/// @brief Inicializa todas las posiciones del array en VACIO
///
/// @param lista Passenger* lista, puntero a la lista de pasajeros
/// @param len, tamaño de la lista de pasajeros
/// @return retorna 0 si todas las posiciones del array estan en VACIO
/// 		retorna -1 si hubo un error y no pudo inicializar el array
int initPassengers(Passenger* lista, int len);
/// @brief añade un pasajero a la lista.
///
/// @param list, puntero a la lista de pasajeros
/// @param len, tamaño de la lista de pasajeros
/// @param id, recibe el id
/// @param name, una cadena de caracteres para el nombre
/// @param lastName, una cadena de caracteres para el apellido
/// @param price, le paso el precio float
/// @param typePassenger, le paso el ID del tipo de pasajero
/// @param flycode, le paso el codigo en cadena de caracteres
/// @param statusFlight, le paso el ID del estado del pasajero
/// @return retorna 0 si pudo encontrar un espacio libre y añadir el pasajero
/// 		retorna -1 si no pudo entonctrar espacio libre
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);
/// @brief ordena la lista de pasajeros por codigo de vuelo y estado de vuelo ACTIVO
///
/// @param list, puntero a la lista de pasajeros
/// @param len, tamaño de la lista de pasajeros
/// @param order, le paso el order, 0 o 1, 0 para ASCENDENTE  y 1 para DESCENDENTE
/// @param listaTipos, puntero a la lista de tipos de pasajeros
/// @param lenTipos, tamaño de la lista de tipos de pasajeros
/// @param listaStatus, puntero a la lista de estados de pasajeros
/// @param lenStatus, tamaño de la lista de tipos de estado
/// @return retorna 0 si pudo ordenar correctamente el array
/// 		retorna -1 s ino pudo ordenar.
int sortPassengersByCode(Passenger* list, int len, int order, TypePassenger* listaTipos, int lenTipos, StatusFlight* listaStatus, int lenStatus);
/// @brief ordena la lista de pasajeros por apellido y tipo de pasajero
///
/// @param list, puntero a la lista de pasajeros
/// @param len, tamaño de la lista de pasajeros
/// @param order, le paso el order, 0 o 1, 0 para ASCENDENTE  y 1 para DESCENDENTE
/// @param listaTipos, puntero a la lista de tipos de pasajeros
/// @param lenTipos, tamaño de la lista de tipos de pasajeros
/// @param listaStatus, puntero a la lista de estados de pasajeros
/// @param lenStatus, tamaño de la lista de tipos de estado
/// @return retorna 0 si pudo ordenar correctamente el array
/// 		retorna -1 s ino pudo ordenar
int sortPassengers(Passenger* list, int len, int order, TypePassenger* listaTipos, int lenTipos, StatusFlight* listaStatus, int lenStatus);
/// @brief elimina un pasajero del array, recorre la lista y cambia el estado a VACIO
///
/// @param list, puntero a la lista de pasajeros
/// @param len, tamaño de la lista de pasajeros
/// @param idAux le paso el id que deseo eliminar
/// @return	retorna 0 si pudo eliminarlo
/// 		retorna -1 si no pudo eliminarlo
int removePassenger(Passenger list[], int len, int idAux);
/// @brief recorre el array de pasajeros hasta coincidir con el ID pasado
///
/// @param list, puntero a la lista de pasajeros
/// @param len, tamaño de la lista de pasajeros
/// @param id le paso el id que quiero encontrar
/// @return retorna la posicion del array que quiero encontrar por ID
/// 		retorna -1 si no pudo encontrar el ID
int findPassengerById(Passenger* list, int len,int id);
/// @brief recorre el array e imprime el array de pasajeros
///
/// @param list, puntero a la lista de pasajeros
/// @param len, tamaño de la lista de pasajeros
/// @param listaTipos, puntero a la lista de tipos de pasajeros
/// @param lenTipos, tamaño de la lista de tipos de pasajeros
/// @param listaStatus, puntero a la lista de estados de pasajeros
/// @param lenStatus, tamaño de la lista de tipos de estado
/// @return	retorna 1 si pudo mostrar al menos 1 pasajero
/// 		retorna 0 si no pudo motrar ningun pasajero
int printPassenger(Passenger* list, int length, TypePassenger* listaTipos, int lenTipos, StatusFlight* listaStatus, int lenStatus);
/// @brief busca una posicion libre del array y la devuelve
///
/// @param list, puntero a la lista de pasajeros
/// @param len, tamaño de la lista de pasajeros
/// @return retorna la primera posicion VACIO que encuentre
/// 		retorna -1 si no hay posiciones libres
int BuscarLibre(Passenger* array, int len);
/// @brief imprime un solo pasajero para usarlo en la funcion printPassenger
///
/// @param list, puntero a la lista de pasajeros
/// @param listaTipos, puntero a la lista de tipos de pasajeros
/// @param listaStatus, puntero a la lista de estados de pasajeros
void MostrarUnPasajero(Passenger lista, TypePassenger listaTipos, StatusFlight listaStatus);
/// @brief imprime un solo pasajero para usarlo para mostrar el pasajero cuando se quiera
/// ELIMINAR O MODIFICAR un pasajero
/// @param list, puntero a la lista de pasajeros
/// @param index, es el indice que quiero imprimir para mostrarlo.
void print_UnPasajero(Passenger lista[], int index);
#endif
