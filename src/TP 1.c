/*
 Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.

Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z) (usar char)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir

Jonathan Maiuolo TP1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Fun.h"
int main(void)
{
	setbuf(stdout, NULL);

	int opcion; //para el menu.
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



	do{
		printf("ingrese la opcion que quiera\n");
		printf("1 ingresar km \n");
		printf("2 ingresar Precio de Vuelos:\n");
		printf("3 calcular costos\n");
		printf("4 informe de resultados\n");
		printf("5 carga forzada de datos\n");
		printf("6 salir \n");
		scanf("%d",&opcion);


		switch(opcion)
		{
		case 1:
				km=pedirKm("ingrese los km \n");// Se utiliza para pedir los kilometros que se utilizaran
		break;
		case 2:
				y=pedirY("ingrese precio aerolineas\n");//Se utiliza para pedir los precio para las aerolineas
				z=pedirZ("ingrese precio latam\n");// Se utiliza para pedir el precio para latam
		break;
		case 3:
			if(y==0 || km==0)
			{
				printf("no se ingreso ningun dato,porfavor ingrese km y precios.\n");
			}
			else
			{
				TarjetaDebY=TarDebito(y); //Muestra el valor de la tarjeta de debito
				TarjetaCreditoY=TarCredito(y); //Muestra el valor de la tarjeta de credito
				bitcoinY=Bitcoin(y); //Muestra el valor de los bitcoins ingresados
				PrecioUnitarioY=PrecioUnitario(y,km);//Muestra el precio de la divison entre los kilometros y el precio
			}
			if(z == 0 || km == 0)
			{
				printf("no s e ingreso ningun dato,porfavor ingrese km y precios.\n");
			}
			else
			{
				TarjetaDebZ=TarDebito(z); //Calcula el valor de la tarjeta de debito
				TarjertaCreaditoZ=TarCredito(z); //Calcula el valor de la tarjeta de credito
				bitcoinZ=Bitcoin(z); //Calcula el valor de los bitcoins ingresados
				PrecioUnitarioZ=PrecioUnitario(z,km); //Calcula el precio de la divison entre los kilometros y el precio ingresado
			}
			diferencia=Diferencia(y,z);

		break;
		case 4:
			if(y==0 || z==0 || km==0)
			{
				printf("no se ingresaron km o precios, ingreselos e intente nuevamente\n");
			}
			else
			{
				printf("los precios de aerolineas son:\n");
				printf("en debito: %.2f \n",TarjetaDebY);// Muestra el resultado de la tarjeta de debito
				printf("en credito: %.2f \n",TarjetaCreditoY); // Muestra el resultado de la tarjeta de
				printf("en bitcoin: %.2f \n",bitcoinY); // Muestra el resultado de los bitcoins ingresados
				printf("el precio unitario es %.2f \n",PrecioUnitarioY);// Muestra el resultado de la divison entre los kilometros y el precio ingresado
				printf("los precios de Latam son: \n");
				printf("en debito: %.2f \n",TarjetaDebZ);// Muestra el resultado de la tarjeta de debito
				printf("en credito: %.2f \n",TarjertaCreaditoZ);// Muestra el resultado de la tarjeta de
				printf("en bitcoin: %.2f \n",bitcoinZ);// Muestra el resultado de los bitcoins ingresados
				printf("el precio unitario es %.2f \n\n",PrecioUnitarioZ);// Muestra el resultado de la divison entre los kilometros y el precio ingresado
				printf("la diferencia de precios entre aerolineas y latam es: %.2f \n",diferencia);
			}
		break;
		case 5:
			   cargaForzada();
		break;
		case 6:
				printf("Programa finalizado , Gracias por usarlo ;D \n");
		break;
		default:
				printf("ingrese una opcion correcta\n");
		break;
			}
				}while(opcion != 6);

	return 0;
}
