#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id_bicicleta;
    char nombre[20];
    char tipo[20];
    int tiempo;

}eBicicleta;

eBicicleta* nueva_Bicicleta();

eBicicleta* nuevaBicicleta_Paramemetros(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr);

int setID_Bicicleta(eBicicleta* this,int id);

int set_NombreBici(eBicicleta* this,char* nombre);

int set_TipoBici(eBicicleta* this,char* tipo);

int set_TiempoBicicleta(eBicicleta* this,int tiempo);

void borrar_Bicicleta(eBicicleta* this);

int validNombre_Bicicleta(char* cadena,int longitud);

int cargarArchivo_Bicicletas(char* path , LinkedList* pArrayListBicis);

int parser_Bicicletas(FILE* pFile , LinkedList* pArrayListBicis);

int listar_Bicicletas(LinkedList* pArrayListBicis);

void ver_Bicicleta (eBicicleta* bici);

int agregar_Tiempos(LinkedList* pArrayListBicis);

int datosAleatorios(void* aleatorios);

int ordenarBici_tiempo(LinkedList * lista);

int ordenarTiempo(void* a,void* b);


#endif // BICICLETA_H_INCLUDED
