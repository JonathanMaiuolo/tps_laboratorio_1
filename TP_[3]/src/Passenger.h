/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#define VACIO 0
typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int estadoVuelo;
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, char* codigoVuelo, int tipoPasajero, int estadoVuelo);

Passenger* Passenger_newParametrosStr(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char*codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);

void Passenger_delete(Passenger* pasajeros);

//Setters
/*||------------------------------------------------------------------------------------------------------------------------------------||*/

int Passenger_setId(Passenger* this,int id);
int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);
int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);
//Getters
/*||------------------------------------------------------------------------------------------------------------------------------------||*/

int Passenger_getId(Passenger* this,int* id);
int Passenger_getNombre(Passenger* this,char* nombre);
int Passenger_getApellido(Passenger* this,char* apellido);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);
int Passenger_getPrecio(Passenger* this,float* precio);
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo);

/*||------------------------------------------------------------------------------------------------------------------------------------||*/

int Passenger_CompararPorID(void* pasajero1,void* pasajero2);
int Passenger_CompararPorNombre(void* pasajero1,void* pasajero2);
int Passenger_compareByLastName(void* passenger, void* passenger2);
int Passenger_CompararPrecioPorVuelo(void* pasajero1,void* pasajero2);
int buscarPasajeroId(LinkedList* pArrayListPassenger);

/*||------------------------------------------------------------------------------------------------------------------------------------||*/
int CargaDatos(Passenger* pasajero,LinkedList* pArrayListPassenger);
int Passenger_tipoStrToInt(char* tipoPasajeroStr, int* tipoPasajero);
int Definir_tipoIntToStr(char* tipoPasajeroStr, int* tipoPasajero);
int Passenger_estadoStrToInt(char* estadoVueloStr, int* estadoVuelo);
int Passenger_estadoIntToStr(char* estadoVueloStr, int* estadoVuelo);
int Passenger_printAll(LinkedList* listaPasajeros);
int Passenger_printOne(Passenger* passenger);
void printTipoPasajero(void);
int Passenger_getMaxId(FILE* pFile,LinkedList* pArrayListPassenger);

void printEstadoVuelo(void);


#endif /* PASSENGER_H_ */
