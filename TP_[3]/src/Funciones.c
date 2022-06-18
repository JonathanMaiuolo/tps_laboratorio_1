#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int EsDigit(char* cadena)
{
	int isDigit;
	int size;
	size = strlen(cadena);
	isDigit = -1;

	for(int i = 0; i <size; i++)
	{
		if((cadena[i] <=  '9' && cadena[i] >= '0')||(cadena[i] == '-' && i == 0))
		{
			isDigit = 1;
		}
		else
		{
			isDigit = 0;
			break;
		}
	}

	return isDigit;
}

int EsLetra(char* cadena)
{
	int EsLetra;
	int len;
	EsLetra = -1;

	if(cadena != NULL)
	{
		len = strlen(cadena);
		char auxStr[len+1];

		strcpy(auxStr,strlwr(cadena));

		EsLetra = 1;

		for(int i = 0; i < len-1; i++)
		{
			if(auxStr[i]<'a' || auxStr[i]>'z')
			{
				EsLetra = -1;
				break;
			}
		}
	}
	return EsLetra;
}

int VerificaNoNumeros(char* cadena)
{
	int retorno;
	int size;
	size = strlen(cadena);
	retorno = -1;

	for(int i = 0; i < size; i++)
	{
		if(cadena[i] <=  '9' && cadena[i] >= '0')
		{
			retorno = 0;
			break;
		}
		else
		{
			retorno = 1;
		}
	}
	return retorno;
}

int EsFloat(char* cadena)
{
	int isDigit;
	int comma;
	int banderaSign;
	int size;

	isDigit = -1;
	comma = 0;
	banderaSign = 0;
	size = strlen(cadena);

	for(int i = 0; i < size; i++)
	{
		if((cadena[i] <=  '9' && cadena[i] >= '0') || (cadena[i] == '.' && comma == 0 && i != banderaSign) || (cadena[i] == '-' && i == 0))
		{
			if(cadena[i] == '.')
			{
				comma++;
			}
			if(cadena[i] == '-')
			{
				banderaSign++;
			}
			isDigit = 1;
		}
		else
		{
			isDigit = 0;
			break;
		}
	}
	return isDigit;
}

int RangoInt(int* numero, int minimo, int maximo, char* mensaje, char* mensajeError)
{
	int auxRtn;
	int banderaError;
	char auxnumero[40];
	int isDigit;
	int auxNumero;

	banderaError = 0;
	auxRtn = -1;
	isDigit = 0;

	if(mensaje!= NULL && mensajeError != NULL && numero != NULL && minimo <= maximo)
	{
		do{

			if(banderaError == 0)
			{
				printf("%s", mensaje);
				fflush(stdin);
				scanf("%40[^\n]", auxnumero);
			}
			else
			{
				printf("%s", mensajeError);
				fflush(stdin);
				scanf("%40[^\n]", auxnumero);
			}

			isDigit = EsDigit(auxnumero);

			if(isDigit == 1)
			{
				auxNumero = atoi(auxnumero);
				if(auxNumero >= minimo && auxNumero <= maximo)
				{
					*numero = auxNumero;
					auxRtn = 1;
				}
				else
				{
					banderaError = 1;
				}
			}
			else
			{
				banderaError = 1;
			}
		}while(auxRtn == -1);
	}
	return auxRtn;
}

int SetNum(int* numero, char* mensaje, char* mensajeError)
{
	int auxRtn;
	int banderaError;
	char auxnumero[40];
	int isDigit;

	banderaError = 0;
	auxRtn = -1;


	if(mensaje!= NULL && mensajeError != NULL && numero != NULL)
	{
		do{
			int isDigit = 0;

			if(banderaError == 0)
			{
				printf("%s", mensaje);
				fflush(stdin);
				scanf("%40[^\n]", auxnumero);
			}
			else
			{
				printf("%s", mensajeError);
				fflush(stdin);
				scanf("%40[^\n]", auxnumero);
			}

			isDigit = EsDigit(auxnumero);

			if(isDigit == 1)
			{
				*numero = atoi(auxnumero);
			}
			else
			{
				banderaError = 1;
			}
		}while(auxRtn == -1);
	}
	return auxRtn;
}

int setRangeIntentos(int* numero, int minimo, int maximo, char* mensaje, char* mensajeError, int intentos)
{
	int auxRtn;
	int banderaError;
	char auxnumero[40];
	int isDigit;
	int auxNumero;

	banderaError = 0;
	auxRtn = -1;
	isDigit = 0;

	if(mensaje!= NULL && mensajeError != NULL && numero != NULL && minimo <= maximo && intentos >= 1)
	{
		do{
			if(banderaError == 0)
			{
				printf("%s", mensaje);
				fflush(stdin);
				scanf("%40[^\n]", auxnumero);
			}
			else
			{
				printf("(%d more try) %s", intentos, mensajeError);
				fflush(stdin);
				scanf("%40[^\n]", auxnumero);
			}

			isDigit = EsDigit(auxnumero);

			if(isDigit == 1)
			{
				auxNumero = atoi(auxnumero);
				if(auxNumero >= minimo && auxNumero <= maximo)
				{
					*numero = auxNumero;
					auxRtn = 1;
				}
				else
				{
					banderaError = 1;
				}
			}
			else
			{
				banderaError = 1;
			}
			intentos--;
		}while(auxRtn == -1  && intentos > 0);
	}

	if(intentos == 0 && auxRtn == -1)
	{
		auxRtn = 0;
	}
	return auxRtn;
}

int setFloatRange(float* numero, float minimo, float maximo, char* mensaje, char* mensajeError)
{
	int auxRtn;
	int banderaError;
	char auxnumero[40];
	int isDigit;
	int comma;
	float auxnumeroFloat;

	auxRtn = -1;
	banderaError = 0;
	isDigit = 0;
	comma = 0;

	if(mensaje!= NULL && mensajeError != NULL && numero != NULL && minimo <= maximo)
	{
		do{

			if(banderaError == 0)
			{
				printf("%s", mensaje);
				fflush(stdin);
				scanf("%40[^\n]", auxnumero);
			}
			else
			{
				printf("%s", mensajeError);
				fflush(stdin);
				scanf("%40[^\n]", auxnumero);
			}

			if((isDigit = EsFloat(auxnumero)) == 1)
			{
				auxnumeroFloat = atof(auxnumero);
				if(auxnumeroFloat >= minimo && auxnumeroFloat <= maximo && (comma == 0 || comma == 1))
				{
					*numero = auxnumeroFloat;
					auxRtn = 1;
				}
				else
				{
					banderaError = 1;
				}
			}
			else
			{
				banderaError = 1;
			}
		}while(auxRtn == -1);
	}

	return auxRtn;
}

int setFloat(float* numero, char* mensaje, char* mensajeError)
{
	int auxRtn = -1;
	int banderaError = 0;
	char auxnumero[40];

	if(mensaje!= NULL && mensajeError != NULL && numero != NULL)
	{
		do{
			int isDigit = 0;

			if(banderaError == 0)
			{
				printf("%s", mensaje);
				fflush(stdin);
				scanf("%40[^\n]", auxnumero);
			}
			else
			{
				printf("%s", mensajeError);
				fflush(stdin);
				scanf("%40[^\n]", auxnumero);
			}

			if((isDigit = EsFloat(auxnumero)) == 1)
			{
				*numero = atof(auxnumero);
				auxRtn = 1;
			}
			else
			{
				banderaError = 1;
			}
		}while(auxRtn == -1);
	}
		return auxRtn;
}

int getCadena(char* string, int size, char* mensaje, char* mensajeError)
{
	int returnAux;
	int x;
	int bandera;
	bandera = 0;
	returnAux = -1;
	x = 0;

	if(string != NULL && size > 0 && mensaje != NULL && mensajeError != NULL)
	{
		char auxString[size + 100];

		do{
			if(bandera == 0)
			{
				printf("%s", mensaje);
				fflush(stdin);
				fgets(auxString,size,stdin);
			}
			else
			{
				printf("%s", mensajeError);
				fflush(stdin);
				fgets(auxString,size,stdin);
			}

			x = strlen(auxString);
			bandera = 1;

		}while(x > size || auxString[0] == '\n');

		auxString[x-1] = '\0';

		strcpy(string, auxString);
		returnAux = 1;
	}
	return returnAux;
}

int setStringintentos(char* string, int size, int intentos, char* mensaje, char* mensajeError)
{
	int returnAux;
	int x;
	int bandera;
	bandera = 0;
	returnAux = -1;
	x = 0;

	if(string != NULL && size > 0 && intentos > 0 && mensaje != NULL && mensajeError != NULL)
	{
		char auxString[size + 200];

		do{
			if(bandera == 0)
			{
				printf("%s", mensaje);
				fflush(stdin);
				fgets(auxString,size,stdin);
			}
			else
			{
				printf("%s", mensajeError);
				fflush(stdin);
				fgets(auxString,size,stdin);
			}
			x = strlen(auxString);
			bandera = 1;
			intentos --;

		}while((x > size || auxString[0] == '\n') && intentos < 0);


		if(strlen(auxString) < size)
		{
			auxString[x-1] = '\0';
			strcpy(string, auxString);
			returnAux = 1;
		}
	}
	return returnAux;
}

int setName(char* string, int size, char* mensaje, char* mensajeError)
{
	int rtn;
	int x;
	int bandera;
	int isLetter;
	bandera = 0;
	rtn = -1;
	x = 0;


	if(string != NULL && size > 0 && mensaje != NULL && mensajeError != NULL)
	{
		char auxString[size];

		do{
			if(bandera == 0)
			{
				printf("%s", mensaje);
				fflush(stdin);
				fgets(auxString,size+1,stdin);
			}else
			{
				printf("%s", mensajeError);
				fflush(stdin);
				fgets(auxString,size+1,stdin);
			}
			x = strlen(auxString);
			bandera = 1;
			isLetter = EsLetra(auxString);

		}while(x >= size || auxString[0] == '\n' || isLetter == -1);

		rtn = 1;
		strcpy(string,strlwr(auxString));
		string[0] = toupper(string[0]);
		string[(strlen(string)-1)] = '\0';
	}
	return rtn;
}

void Validacion(int numero, char* mensaje)
{
	if(numero == 1)
	{
		printf("\nEXITO AL %s.\n\n", mensaje);
	}
	else
	if(numero == 0)
	{
		printf("\nSE HA CANCELADO %s.\n\n", mensaje);
	}
	else
	{
		printf("\nERROR AL %s.\n\n", mensaje);
	}
	system("pause");
	fflush(stdin);
}

void ValidacionConError(int numero, char* mensaje, char* mensajeError)
{
	if(numero >= 1)
	{
			printf("\nEXITO AL %s.\n\n", mensaje);
		}
		else
		if(numero == 0)
		{
			printf("\nSE HA CANCELADO %s.\n\n", mensaje);
		}
		else
		{
			printf("\n%s.\n\n", mensajeError);
		}

		system("pause");
}
