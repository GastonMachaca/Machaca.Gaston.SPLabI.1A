#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Menu.h"



int menu(void)
{
    int option;

    printf(" \n Menu:\n");
    printf(" \n  1. Cargar archivo.");
    printf(" \n  2. Imprimir Lista.");
    printf(" \n  3. Asignar Tiempos.");
    printf(" \n  4. Filtrar por tipo.");
    printf(" \n  5. Mostrar posiciones.");
    printf(" \n  6. Guardar Posiciones.");
    printf(" \n  7. Salir.");

    printf("\n \n Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d",&option);


    while(option<1 || option >7 || isalpha(option)!=0)
    {
        printf("\nERROR!!!\n Vuelva a ingresar una opcion: ");
        fflush(stdin);
        scanf("%d",&option);
    }

    return option;
}
