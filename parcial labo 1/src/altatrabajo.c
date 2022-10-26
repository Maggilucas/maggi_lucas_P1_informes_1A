#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estructura.h"
#include "mostrar.h"
#include "validaciones.h"
#include "hardcodeo.h"
#include "altatrabajo.h"
#include "informes.h"

int altaTrabajo(int* pId, eAuto vec[], int tam,eTrabajo trabajo[],int tam_t,eServicio servicio[],int tam_s,eFecha fecha,eColor colores[],int tam_c,eMarca marca[],int tam_m)
{

    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;

    if(pId != NULL && trabajo != NULL && tam > 0)
    {

        system("cls");

        printf("**** Alta trabajo ****\n\n");

        buscarLibreTrabajo(&indice, trabajo, tam_t);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            cargarTrabajo(&auxTrabajo,vec,servicio,tam,tam_s,marca,tam_m,colores,tam_c,fecha);

            auxTrabajo.id = *pId;

            *pId = *pId + 1;

            trabajo[indice] = auxTrabajo;
            todoOk = 1;
        }
    }
    return todoOk;
}

int buscarLibreTrabajo(int* pIndice, eTrabajo vec[], int tam)
{
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if( vec[i].isEmpty)
            {

                indice = i;
                break;
            }
        }
        *pIndice = indice;
        todoOk = 1;
    }
    return todoOk;
}

int inicializarTrabajo(eTrabajo vec[], int tam)
{
    int todoOk = 0;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarTrabajo(eTrabajo* pTrabajo,eAuto* autos,eServicio* servicios,int tam,int tam_s,eMarca marca[],int tam_m,eColor colores[],int tam_c,eFecha fecha)
{

    int todoOk = 0;
    int idAuto;
    int idServicio;
    int dia;
    int mes;
    int anio;

    if(pTrabajo != NULL)
    {

    	mostrarAutos(autos,tam,0,marca,colores,tam_m,tam_c);

    	printf("Ingrese el id del auto: ");
		scanf("%d",&idAuto);

		while(!validarIdAutos(idAuto,autos,tam))
		{
			printf("id invalido,reingrese el id del auto: ");
			scanf("%d",&idAuto);
		}

		pTrabajo->idAuto= idAuto;

        mostrarServicios(servicios,tam_s);

        printf("Ingrese el id del servicio: ");
        scanf("%d",&idServicio);

        while(!validarIdServicios(idServicio,servicios,tam_s))
        {
        	printf("id invalido,reingrese el id del servicio: ");
        	scanf("%d",&idServicio);
        }

        pTrabajo->idServicio= idServicio;

        printf("Ingrese la fecha del servicio: \n");
        printf("Ingrese dia ");
        scanf("%d",&dia);
        while(dia > 31 || dia <1)
        {
            printf("dia invalido,reIngrese dia");
            scanf("%d",&dia);
        }
        pTrabajo->fecha.dia=dia;
        printf("Ingrese mes ");
        scanf("%d",&mes);
        while(mes > 12 || mes <1)
		{
			printf("mes invalido,reIngrese mes");
			scanf("%d",&mes);
		}
        pTrabajo->fecha.mes=mes;
        printf("Ingrese año ");
	   scanf("%d",&anio);
	   while(anio > 10000 || anio <1)
		{
			printf("año invalido,reIngrese año");
			scanf("%d",&anio);
		}
		   pTrabajo->fecha.anio=anio;



        pTrabajo->isEmpty = 0;

        todoOk = 1;
    }



    return todoOk;
}

int buscarTrabajo(int* pIndice, int id, eTrabajo vec[], int tam)
{


    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if(!vec[i].isEmpty && vec[i].id == id )
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
        todoOk = 1;
    }
    return todoOk;
}
