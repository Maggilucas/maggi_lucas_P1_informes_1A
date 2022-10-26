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

int validarIdMarcas(int id,eMarca marcas[],int tam)
{
	int todoOk =0;

	if(marcas != NULL && tam > 0 && id > 0)
	{
		for(int i =0;i<tam;i++)
		{
			if(marcas[i].id == id)
			{
				todoOk =1;
				break;
			}
		}

	}
	return todoOk;
}

int validarIdColores(int id,eColor colores[],int tam)
{
	int todoOk =0;

	if(colores != NULL && tam > 0 && id > 0)
	{
		for(int i =0;i<tam;i++)
		{
			if(colores[i].id == id)
			{
				todoOk =1;
				break;
			}
		}

	}
	return todoOk;
}

int validarIdServicios(int id,eServicio servicios[],int tam)
{
	int todoOk =0;

	if(servicios != NULL && tam > 0 && id > 0)
	{
		for(int i =0;i<tam;i++)
		{
			if(servicios[i].id == id)
			{
				todoOk =1;
				break;
			}
		}

	}
	return todoOk;
}

int cargarDescripcionMarcas(int id, char descripcion[], eMarca marcas[], int tam_m)
{
 int retorno = 0;

 if(descripcion != NULL && marcas != NULL && tam_m > 0)
 {
    for(int i = 0 ; i < tam_m ; i++)
    {
        if(marcas[i].id == id)
        {
            strcpy(descripcion, marcas[i].descripcion);
            break;
        }
    }

   retorno = 1;
 }

return retorno;
}

int cargarDescripcionColores(int id, char descripcion[], eColor colores[], int tam_c)
{
 int retorno = 0;

 if(descripcion != NULL && colores != NULL && tam_c > 0)
 {
    for(int i = 0 ; i < tam_c ; i++)
    {
        if(colores[i].id == id)
        {
            strcpy(descripcion, colores[i].descripcion);
            break;
        }
    }

   retorno = 1;
 }

return retorno;
}

int cargarDescripcionServicios(int id, char descripcion[], eServicio servicios[], int tam_s)
{
 int retorno = 0;

 if(descripcion != NULL && servicios != NULL && tam_s > 0)
 {
    for(int i = 0 ; i < tam_s ; i++)
    {
        if(servicios[i].id == id)
        {
            strcpy(descripcion, servicios[i].descripcion);
            break;
        }
    }

   retorno = 1;
 }

return retorno;
}

int confirmarSalida(char* pVariable, char confirma, char rechaza)
{

    int todoOk = 0;
    char rta;

    if(pVariable != NULL)
    {
        printf("Esta seguro de que desea salir?: ");
        fflush(stdin);
        scanf("%c", &rta);

        if(rta == 's')
        {
            *pVariable = confirma;
        }
        else
        {
            *pVariable = rechaza;
        }
        todoOk = 1;

    }
    return todoOk;
}

int validarIdAutos(int id,eAuto autos[],int tam)
{
	int todoOk =0;

	if(autos != NULL && tam > 0 && id > 0)
	{
		for(int i =0;i<tam;i++)
		{
			if(autos[i].id == id)
			{
				todoOk =1;
				break;
			}
		}

	}
	return todoOk;
}
