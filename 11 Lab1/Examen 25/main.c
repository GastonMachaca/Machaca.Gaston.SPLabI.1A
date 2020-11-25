#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#include "LinkedList.h"
#include "Bicicleta.h"
#include "Menu.h"


int main()
{
    srand(time(NULL));

    int option;
    int flag=0;

    LinkedList* listaBicicletas = ll_newLinkedList();
    do
    {
        option = menu();

        switch(option)
        {
            case 1:
                if(flag== 0)
                {
                   cargarArchivo_Bicicletas("bicicletas.csv",listaBicicletas);
                   flag=1;
                }
                else
                {
                    printf("\nYa se cargo las bicicletas.");
                }
                break;
            case 2:
                listar_Bicicletas(listaBicicletas); // LISTAR BICICLETAS
                break;
            case 3:
                if(agregar_Tiempos(listaBicicletas)==0) // ASIGNAR TIEMPOS.
                {
                    printf("Exito");
                }
                else
                {
                    printf("Ocurrio un inconveniente.");
                }
                break;
            case 4:
                // FILTRAR POR TIPO
                break;
            case 5:
                system("cls");
                if(ordenarBici_tiempo(listaBicicletas))
                {
                    printf("Bicicletas ordenadas con exito\n");
                    listar_Bicicletas(listaBicicletas);
                }
                else
                {
                    printf ("Error al ordenar\n");
                }// MOSTRAR POSICIONES

                break;
            case 6:


                // GUARDAR POSICIONES
                break;
        }
        system("pause");
        system("cls");

    }while(option != 7);

    return 0;
}
