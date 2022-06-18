/*
 * Jona.h
 *
 *  Created on: 11 jun. 2022
 *      Author: User
 */

#ifndef JONA_H_
#define JONA_H_
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"


int EsDigit(char* cadena);
int EsLetra(char* cadena);
int EsFloat(char* cadena);
int VerificaNoNumeros(char* cadena);
int RangoInt(int* numero, int minimo, int maximo, char* mensaje, char* mensajeError);
int SetNum(int* numero, char* mensaje, char* mensajeError);
int setRangeIntentos(int* numero, int minimo, int maximo, char* mensaje, char* mensajeError, int intentos);
int setFloat(float* numero, char* mensaje, char* mensajeError);
int setFloatRange(float* numero, float minimo, float maximo, char* mensaje, char* mensajeError);
int getCadena(char* string, int size, char* mensaje, char* mensajeError);
void Validacion(int numero, char* mensaje);
void ValidacionConError(int numero, char* mensaje, char* mensajeError);


int setName(char* string, int size, char* mensaje, char* mensajeError);


#endif /* JONA_H_ */
