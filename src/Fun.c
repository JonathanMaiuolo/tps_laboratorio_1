#include <stdio.h>
#include <stdlib.h>
#include "Fun.h"

float pedirKm(char mensaje [])
{
	float cantidadKilometros;
	printf("%s",mensaje);
	scanf("%f",&cantidadKilometros);
	while(cantidadKilometros < 1)
	{
		printf("ingrese una cantidad de km valida");
		scanf("%f",&cantidadKilometros);
	}
	return cantidadKilometros;
}
float pedirY(char mensaje [])
{
	float precioY;
	printf("%s",mensaje);
	scanf("%f",&precioY);
	while(precioY < 1)
	{
		printf("ingrese una cantidad de km valida");
		scanf("%f",&precioY);
	}
	return precioY;
}

float pedirZ(char mensaje [])
{
	float precioZ;
	printf("%s",mensaje);
	scanf("%f",&precioZ);
	while(precioZ < 1)
	{
		printf("ingrese una cantidad de km valida");
		scanf("%f",&precioZ);
	}
	return precioZ;
}

float TarDebito (float precio)
{
	float descuento;
	descuento=precio-(precio*10/100);

	return descuento;
}

float TarCredito(float precio)
{
	float aumento;
	aumento=precio+(precio*25/100);

	return aumento;
}

float Bitcoin(float precio)
{
	float valor;
	valor=precio/4606954.55;
	return valor;
}
float PrecioUnitario(float precio, float km)
{
	float unitario;
	unitario= precio / km;
	return unitario;
}

float Diferencia(float y,float z)
{
	float diferencia;
	if(y > z)
	{
		diferencia=y-z;
	}
	else
	{
		diferencia=y-z;
	}

	return diferencia;
}
void cargaForzada (void)
{
	float km;
	float y;//aerolineas
	float z;//latam
	/////////////////////
	//VARIABLES AEROLINEAS
	float TarjetaDebY;//variable para tarjeta de debito
	float TarjetaCreditoY;//variable para tarjeta de credito
	float bitcoinY;//variable para precio bitcoin
	float PrecioUnitarioY;// es la variable que divide los km mas el precio
	//VARIABLES LATAM
	float TarjetaDebZ;//variable para tarjeta de debito
	float TarjertaCreaditoZ;//variable para tarjeta de credito
	float bitcoinZ;//variable para precio bitcoin
	float PrecioUnitarioZ;//precio viaje /km;
	////////////////////////
	float diferencia;// diferencia de precios;
	//queria dejar registrado que el que pone la opcion 5 es un hdp

		km=7090;
		y=162965;
		z=159339;

		TarjetaDebY=TarDebito(y); //Muestra el valor de la tarjeta de debito
		TarjetaCreditoY=TarCredito(y); //Muestra el valor de la tarjeta de credito
		bitcoinY=Bitcoin(y); //Muestra el valor de los bitcoins ingresados
		PrecioUnitarioY=PrecioUnitario(y,km);//Muestra el precio de la divison entre los kilometros y el precio
		TarjetaDebZ=TarDebito(z); //Calcula el valor de la tarjeta de debito
		TarjertaCreaditoZ=TarCredito(z); //Calcula el valor de la tarjeta de credito
		bitcoinZ=Bitcoin(z); //Calcula el valor de los bitcoins ingresados
		PrecioUnitarioZ=PrecioUnitario(z,km); //Calcula el precio de la divison entre los kilometros y el precio ingresado
		diferencia=Diferencia(y,z);

		printf("los precios de aerolineas son:\n");
		printf("en debito: %.2f \n",TarjetaDebY);
		printf("en credito: %.2f \n",TarjetaCreditoY);
		printf("en bitcoin: %.2f \n",bitcoinY);
		printf("el precio unitario es %.2f \n",PrecioUnitarioY);
		printf("los precios de Latam son: \n");
		printf("en debito: %.2f \n",TarjetaDebZ);
		printf("en credito: %.2f \n",TarjertaCreaditoZ);
		printf("en bitcoin: %.2f \n",bitcoinZ);
		printf("el precio unitario es %.2f \n\n",PrecioUnitarioZ);
		printf("la diferencia de precios entre aerolineas y latam es: %.2f \n",diferencia);
}
