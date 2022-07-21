#ifndef FUNCIONUTN_H_
#define FUNCIONUTN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int esNumerica(char* cadena, int limite);
int getInt(int* pResultado);
int esFlotante(char* cadena, int limite);
int getFloat(float* pResultado);
int getString(char* cadena, int longitud);

#endif /* FUNCIONUTN_H_ */

