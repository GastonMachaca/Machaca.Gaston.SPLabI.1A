#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Bicicleta.h"
//#include "LinkedList.h"

eBicicleta* nueva_Bicicleta()
{
    eBicicleta* auxBici = NULL;

    auxBici = (eBicicleta*) malloc (sizeof(eBicicleta));

    return auxBici;
}

eBicicleta* nuevaBicicleta_Paramemetros(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr)
{
    int flag=0;

    eBicicleta* auxBici = NULL;

    auxBici = nueva_Bicicleta();

    if(auxBici != NULL)
	{
		if(setID_Bicicleta(auxBici,atoi(idStr))==0)
		{
			if(set_NombreBici(auxBici,nombreStr)==0)
			{
				if(set_TipoBici(auxBici,tipoStr)==0)
				{
                    if(set_TiempoBicicleta(auxBici,atoi(tiempoStr))==0)
                    {
                        flag=1;
                    }
				}
			}
		}
		if(flag==0)
		{
			borrar_Bicicleta(auxBici);
			auxBici=NULL;
		}
	}
	return auxBici;
}

int setID_Bicicleta(eBicicleta* this,int id)
{
    int error = -1;

    if( this != NULL && id > 0)
    {
        this->id_bicicleta = id;
        error = 0;
    }

    return error;
}

int set_NombreBici(eBicicleta* this,char* nombre)
{
    int error = -1;

    if( this != NULL && nombre != NULL)
    {
        if(validNombre_Bicicleta(nombre,strlen(nombre)))
        {
            strcpy(this->nombre,nombre);
            error = 0;
        }
    }
    return error;
}

int set_TipoBici(eBicicleta* this,char* tipo)
{
    int error = -1;

    if( this != NULL && tipo != NULL)
    {
        if(validNombre_Bicicleta(tipo,strlen(tipo)))
        {
            strcpy(this->tipo,tipo);
            error = 0;
        }
    }
    return error;
}

int set_TiempoBicicleta(eBicicleta* this,int tiempo)
{
    int error = -1;

    if(this!=NULL && tiempo>=0)
    {
        this->tiempo=tiempo;
        error = 0;
    }

    return error;
}

void borrar_Bicicleta(eBicicleta* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int validNombre_Bicicleta(char* cadena,int longitud)
{
	int i=0;
	int error = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				error = 0;
				break;
			}
		}
	}
	return error;
}

int cargarArchivo_Bicicletas(char* path , LinkedList* pArrayListBicis)
{
    int error = -1;

    FILE* pFile;

    if(path != NULL && pArrayListBicis != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            parser_Bicicletas(pFile, pArrayListBicis);
            error = 1;
            printf("Cargado con exito.\n");
        }
        fclose(pFile);
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
        error = 0;
    }

    return error;
}

int parser_Bicicletas(FILE* pFile , LinkedList* pArrayListBicis)
{
    int error = -1;
    char auxId[128];
    char auxNombre[128];
    char auxTipos[128];
    char auxTiempo[128];

    int r=0;

    eBicicleta* auxBici;

    do
    {
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxTipos,auxTiempo)== 4)
        {
            auxBici = nuevaBicicleta_Paramemetros(auxId,auxNombre,auxTipos,auxTiempo);

            if(auxBici != NULL)
            {
                r = ll_add(pArrayListBicis,auxBici);

                if(r>=ll_len(pArrayListBicis))
                {
                    break;
                }
            }

        }
        else
        {
            break;
        }


    }while(feof(pFile)== 0);

    fclose(pFile);

    error = r;

    return error;
}

int listar_Bicicletas(LinkedList* pArrayListBicis)
{
    int error = -1;
    int i;
    int tam = ll_len(pArrayListBicis);

    eBicicleta* auxBici;


    if(pArrayListBicis != NULL && ll_isEmpty(pArrayListBicis)== 0)
    {

        system("cls");
        printf("                         ***LISTA DE BICICLETAS***                            \n\n");

        printf("\n     ID     |        NOMBRE        |         TIPO         |      TIEMPO  \n");
        printf("--------------------------------------------------------------------------------\n");


        for(i=0;i<tam;i++)
        {
            auxBici = (eBicicleta*) ll_get(pArrayListBicis,i);
            if( auxBici != NULL)
            {
                ver_Bicicleta( auxBici );
                error=1;
                auxBici = NULL;
            }
        }
    }
    else
    {
        printf("\n No hay empleados cargados\n\n");
        error = 0;
    }

    return error;
}

void ver_Bicicleta (eBicicleta* bici)
{
    if(bici != NULL)
    {
        printf(" %10d | %20s | %20s | %20d \n",bici->id_bicicleta,bici->nombre,bici->tipo,bici->tiempo);
    }
}

int agregar_Tiempos(LinkedList* pArrayListBicis)
{
    int error = -1;

    LinkedList* auxlistaTiempos = NULL;

    if(pArrayListBicis != NULL && ll_isEmpty(pArrayListBicis)== 0)
    {
        auxlistaTiempos = ll_map(pArrayListBicis,datosAleatorios);
        listar_Bicicletas(auxlistaTiempos);
        error=0;
    }
    else
    {
        error = 1;
    }

    return error;
}

int datosAleatorios(void* aleatorios)
{
    int error = 0;
    int aleatorio;

    if(aleatorios != NULL)
    {
        eBicicleta* pBici = (eBicicleta*)aleatorios;
        aleatorio = rand()%(71)+50;
        pBici->tiempo = aleatorio;
        error = 1;
    }
    return error;
}

int ordenarBici_tiempo (LinkedList * lista)
{
    int retorno = 0;
    if(lista != NULL )
    {
        ll_sort (lista, ordenarTiempo, 1 );
        retorno = 1 ;
    }

    return retorno;
}

int  ordenarTiempo ( void * a, void * b)
{
    int retorno = 0 ;
    eBicicleta* p1;
    eBicicleta* p2;

    if (a!= NULL && b!= NULL )
    {
        p1 = (eBicicleta *) a;
        p2 = (eBicicleta *) b;

         if (p1->tiempo > p2-> tiempo )
         {
             retorno = 1 ;
         }
         else if(p1-> tiempo < p2-> tiempo )
         {
             retorno = - 1 ;
         }

    }
    return retorno;
}
