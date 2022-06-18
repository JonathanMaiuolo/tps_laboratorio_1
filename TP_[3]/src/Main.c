#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"

/**********************************************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
**********************************************************************************/
int main()
{

	setbuf(stdout,NULL);
    int option = 0;
    int id= 1000;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	menu();
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                break;
            case 2:
            	controller_loadFromBinary("data.bin", listaPasajeros);
            	break;
            case 3:
            	validatorWithMessageError(controller_addPassenger(listaPasajeros),"Perfecto se ha logrado agregar un  pasajero", "ERROR. No se ha podido agregar el pasajero");
            	break;
            case 4:
            	validatorWithMessageError(controller_editPassenger(listaPasajeros),"Perfecto se ha logrado modificar un pasajero", "ERROR. No se ha podido modificar el pasajero");
            	break;
			case 5:
            	validatorWithMessageError(controller_removePassenger(listaPasajeros),"Perfecto se ha logrado eliminar un pasajero", "ERROR. No se ha podido eliminar el pasajero");
            	break;
            case 6:
            	controller_ListPassenger(listaPasajeros);
            	break;
            case 8:
            	controller_saveAsText("data2.csv", listaPasajeros);
            	break;
            case 7:
            	controller_sortPassenger(listaPasajeros);
            	break;
            case 9:
            	controller_saveAsBinary("data.bin", listaPasajeros);
            	break;
        	break;
        }
    }while(option != 10);

    return 0;
}


