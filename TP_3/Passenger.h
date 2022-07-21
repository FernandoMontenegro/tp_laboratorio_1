#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	char statusFlight[40];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr,char* codigoVueloStr, char* tipoPasajeroStr, char* statusFlightStr);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this, char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this, char* statusFlight);
int Passenger_getEstadoVuelo(Passenger* this, char* statusFlight);

int setTipoTexto(int tipoPasajero, char* tipoPasajerostr);
void Passenger_setFlightStatusStr(int flightStatus, char* statusFlightStr);

void Passenger_printOne(Passenger* this);

int Passenger_validarID(LinkedList* listaPasajeros, char* editOrRemove);
int Passenger_findID(LinkedList* listaPasajeros, int editID);

int Passenger_compareById(void* idUno, void* idDos);
int Passenger_compareByName(void* elemento1 ,void* elemento2);
int Passenger_compareByLastName(void* elemento1 ,void* elemento2);
int Passenger_compareByPrice(void* elemento1 ,void* elemento2);

Passenger* Passenger_newAlta(int id);
int Passenger_newEdit(Passenger* this);

#endif /* PASSENGER_H_ */
