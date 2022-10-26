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

//Mostrar autos del color seleccionado por el usuario. funca
int mostrarAutosDeColor(int* idColor,int tam_c,eAuto vec[],int tam,eColor colores[],eMarca marcas[],int tam_m)
{

    int flag = 0;

    mostrarColores(colores,tam_c);

    printf("Ingrese el id del color: ");
    scanf("%d",idColor);

	while(!validarIdColores(*idColor,colores,tam_c))
	{
		printf("id invalido,reingrese el id del color: ");
		scanf("%d",idColor);
	}
	printf("****** lista de autos de ese color ****** \n");
	printf("id   marca   color   caja  \n");
	for(int i=0;i < tam;i++)
	{
		if(vec[i].idColor == *idColor)
		{
			mostrarAuto(vec[i],marcas,colores,tam_m,tam_c);
			flag=1;
		}
	}


    return flag;
}

//Mostrar autos de una marca seleccionada. funca
int mostrarAutosMarca(int* idMarcas,int tam_c,eAuto vec[],int tam,eColor colores[],eMarca marcas[],int tam_m)
{

    int flag = 0;

    mostrarMarcas(marcas,tam_m);

    printf("Ingrese el id del marcas: ");
    scanf("%d",idMarcas);

	while(!validarIdMarcas(*idMarcas,marcas,tam_m))
	{
		printf("id invalido,reingrese el id del marcas: ");
		scanf("%d",idMarcas);
	}
	printf("****** lista de autos de esa marca ****** \n");
	printf("id   marca   color   caja  \n");
	for(int i=0;i < tam;i++)
	{
		if(vec[i].idMarca == *idMarcas)
		{
			mostrarAuto(vec[i],marcas,colores,tam_m,tam_c);
			flag=1;
		}
	}


    return flag;
}
// Informar porcentaje de autos con caja manual y promedio de autos con caja automática
int informarPorcentajePorCaja(eAuto vec[],int tam,int* contadorAutos)
{
	int todoOk=0;
	int porcentajeManual;
	int porcentajeAutomatica;
	int contadorManual=0;
	int contadorAutomatica=0;

	if(vec != NULL && tam > 0)
	{
		for(int i=0;i< tam;i++)
		{
			if(vec[i].isEmpty == 0)
			{
				if(vec[i].caja == 'm')
				{
					contadorManual++;
					todoOk = 1;
				}
			}
		}
		porcentajeManual = contadorManual * 100 / *contadorAutos;
		for(int i=0;i < tam;i++)
		{
			if(vec[i].caja == 'a' && vec[i].isEmpty == 0)
			{
				contadorAutomatica++;
				todoOk = 1;
			}

		}
		porcentajeAutomatica = contadorAutomatica * 100 / *contadorAutos;
	}

	printf("el porcentaje de autos con caja manual es del %d porciento \n",porcentajeManual);
	printf("el porcentaje de autos con caja automatica es del %d porciento \n",porcentajeAutomatica);
	return todoOk;
}

//Mostrar un listado de los autos separados por caja. funca

int informarAutosPorCaja(eAuto vec[],eMarca marcas[],eColor colores[],int tam,int tam_m,int tam_c)
{
	int todoOk=0;
	char auxColor[25];
	char auxMarca[25];

	cargarDescripcionColores(vec->idColor, auxColor, colores, tam_c);
	cargarDescripcionMarcas(vec->idMarca, auxMarca, marcas, tam_m);
	if(vec != NULL && marcas != NULL)
	{
		printf("autos de caja manual: \n");
		printf("**** Lista de autos ****\n");
		printf("|id   |color | marca  |   caja   |\n");
		for(int i=0;i< tam;i++)
		{
			if(vec[i].isEmpty == 0)
			{
				if(vec[i].caja == 'm')
				{
					printf("|%2d  |%6s   |  %6s   |   %c     |\n",vec[i].id,auxColor,auxMarca,vec[i].caja);
					todoOk = 1;
				}
			}
		}
		printf("autos de caja automatica: \n");
		printf("**** Lista de autos ****\n");
		printf("|id   |color | marca  |   caja   |\n");
		for(int i=0;i < tam;i++)
		{
			if(vec[i].caja == 'a')
			{
				printf("|%2d  |%6s   |  %6s   |   %c     |\n",vec[i].id,auxColor,auxMarca,vec[i].caja);
				todoOk = 1;
			}

		}
	}
	return todoOk;
}
//Elegir un color y una marca y contar cuantos autos hay de ese color y esa marca. funca
int mostrarAutosDeColorYMarca(int* idColor,int* idMarcas,int tam_c,eAuto vec[],int tam,eColor colores[],eMarca marcas[],int tam_m,int* contadorMarcaYColor)
{

    int flag = 0;
    char auxMarca[20];
    char auxColor[20];
    *contadorMarcaYColor=0;

    cargarDescripcionMarcas(vec->idMarca, auxMarca, marcas, tam_m);
    cargarDescripcionColores(vec->idColor, auxColor, colores, tam_c);

    mostrarColores(colores,tam_c);

    printf("Ingrese el id del color: ");
    scanf("%d",idColor);

	while(!validarIdColores(*idColor,colores,tam_c))
	{
		printf("id invalido,reingrese el id del color: ");
		scanf("%d",idColor);
	}

	 mostrarMarcas(marcas,tam_m);

	printf("Ingrese el id del marcas: ");
	scanf("%d",idMarcas);

	while(!validarIdMarcas(*idMarcas,marcas,tam_m))
	{
		printf("id invalido,reingrese el id del marcas: ");
		scanf("%d",idMarcas);
	}
	for(int i=0;i < tam;i++)
	{
		if(vec[i].idColor == *idColor && vec[i].idMarca == *idMarcas)
		{
			(*contadorMarcaYColor)++;
			flag=1;
		}
	}
	printf("hay %d autos con la marca %s y el color %s \n",*contadorMarcaYColor,auxMarca,auxColor);

    return flag;
}

//Mostrar la o las marcas más elegidas por los clientes. funca
int contadorAutosMarca(eAuto* autos,int indice,int tam,int* contador)
{
    int todoOk=0;
    if(autos != NULL)
    {
        *contador = 0;
        for(int i = 0; i<tam;i++)
        {
            if(autos[i].isEmpty == 0)
            {
                if(autos[i].idMarca == indice)
                {
                    contador =contador +1;
                    todoOk=1;
                }
            }

        }
    }
    return todoOk;
}

int informarMarcaMasElegida(eAuto* autos, eMarca* marcas, int tam,int tam_m)
{
    int todoOk = 0;
    int contador = 0;
    int indice = -1;
    int flag = 0;
    int mayor;
    if(autos != NULL && marcas != NULL)
    {
        for(int i=0;i<tam_m;i++)
        {

        	contadorAutosMarca(autos,i,tam ,&contador);
            if(flag == 0 || contador > mayor)
            {
                mayor = contador;
                flag = 1;
                indice = i;
            }
        }
        printf("\nLa marca con mas autos es: %s \n",marcas[indice].descripcion);


        todoOk = 1;
    }
    return todoOk;
}

//Pedir un auto y mostrar todos los trabajos que se le hicieron al mismo. funca

int mostrarTrabajosEnAuto(int* idAuto,eTrabajo pTrabajo[],eAuto autos[],eServicio servicios[],int tam,int tam_s,eMarca marca[],int tam_m,eColor colores[],int tam_c,int tam_t)
{
	int todoOk = 0;

	if(autos != NULL && marca != NULL && pTrabajo != NULL && colores != NULL && tam > 0 && tam_s > 0 && tam_m > 0 && tam_s > 0)
	{
		mostrarAutos(autos,tam,0,marca,colores,tam_m,tam_c);

		printf("Ingrese el id del auto: ");
		scanf("%d",idAuto);

		while(!validarIdAutos(*idAuto,autos,tam))
		{
			printf("id invalido,reingrese el id del auto: ");
			scanf("%d",idAuto);
		}
		printf("****** lista de trabajos ****** \n");
		printf("id   idAuto   servicio   fecha  \n");
		for(int i=0;i < tam_t;i++)
		{
			if(pTrabajo[i].isEmpty == 0 && pTrabajo[i].idAuto == *idAuto)
			{
				mostrarTrabajo(pTrabajo[i],servicios,tam_s);
				todoOk=1;
			}
			else
			{
				printf("ese auto no tiene trabajos cargados\n");
				break;
			}
		}

	}

	return todoOk;
}

//Pedir un auto e informar la suma de los importes que se le hicieron al mismo.funca

int acumularImportes(int* idAuto,eTrabajo pTrabajo[],eAuto autos[],eServicio servicios[],int tam,int tam_s,eMarca marca[],int tam_m,eColor colores[],int tam_c,int tam_t)
{
	int todoOk=0;
	float auxImportes=0;

	if(autos != NULL && marca != NULL && pTrabajo != NULL && colores != NULL && tam > 0 && tam_c > 0 && tam_m > 0 && tam_s > 0)
	{
		mostrarAutos(autos,tam,0,marca,colores,tam_m,tam_c);

		printf("Ingrese el id del auto: ");
		scanf("%d",idAuto);

		while(!validarIdAutos(*idAuto,autos,tam))
		{
			printf("id invalido,reingrese el id del auto: ");
			scanf("%d",idAuto);
		}
			for(int i = 0; i< tam_t;i++)
			{
				for(int j=0;j < tam_s;j++)
				{
					if(pTrabajo[i].isEmpty == 0 && pTrabajo[i].idAuto == *idAuto && pTrabajo[i].idServicio == servicios[j].id)
					{
						auxImportes += servicios[j].precio;
						todoOk=1;
					}
				}
			}
		printf("el importe total de los servicios en el auto seleccionado es de %.2f \n",auxImportes);
	}

	return todoOk;
}
//Pedir un servicio y mostrar los autos a los que se realizo ese servicio y la fecha.funca masomenos
int informarServiciosEnAutos(eTrabajo pTrabajo[],eAuto autos[],eServicio servicios[],int tam,int tam_s,eMarca marca[],int tam_m,eColor colores[],int tam_c,int tam_t)
{
	int todoOk=0;
	int idServicio;
        if(autos != NULL && marca != NULL && colores != NULL && tam > 0 && tam_c > 0 && tam_m > 0 && tam_s > 0)
        {
        	mostrarServicios(servicios,tam_s);

        	printf("Ingrese el id del servicio: ");
        	scanf("%d",&idServicio);

        	while(!validarIdServicios(idServicio,servicios,tam_s))
        	{
        		printf("id invalido,reingrese el id del servicio: ");
        		scanf("%d",&idServicio);
        	}
        	for(int i = 0; i< tam_t;i++)
        	{
        		for(int j=0; j < tam;j++)
        		if(pTrabajo[i].idServicio == idServicio && pTrabajo[i].isEmpty == 0 && pTrabajo[i].idAuto == autos[j].id)
        		{
        			printf("******trabajos*******\n");
        			mostrarTrabajo(pTrabajo[i],servicios,tam_s);
        			printf("****** autos ****** \n");
        			printf("id   marca   color   caja  \n");
        			mostrarAuto(autos[j],marca,colores,tam_m,tam_c);
        		}
        	}
        }
	return todoOk;
}

// Pedir una fecha y mostrar todos los servicios realizados en la misma. funca ponele

int informarServiciosEnFecha(eTrabajo pTrabajo[],eServicio servicios[],int tam_s,int tam_t,int tam)
{
	int todoOk=0;
	int dia;
	int mes;
	int anio;
	if(pTrabajo != NULL && tam_s > 0 && servicios != NULL && tam_t > 0)
	{
		mostrarTrabajos(pTrabajo,tam,1,servicios,tam_s);
		printf("Ingrese la fecha del servicio: \n");
		printf("Ingrese dia ");
		scanf("%d",&dia);
		while(dia > 31 || dia <1)
		{
			printf("dia invalido,reIngrese dia");
			scanf("%d",&dia);
		}
		printf("Ingrese mes ");
		scanf("%d",&mes);
		while(mes > 12 || mes <1)
		{
			printf("mes invalido,reIngrese mes");
			scanf("%d",&mes);
		}
		printf("Ingrese año ");
	   scanf("%d",&anio);
	   while(anio > 10000 || anio <1)
		{
			printf("año invalido,reIngrese año");
			scanf("%d",&anio);
		}
		for(int i = 0; i< tam_t;i++)
		{
			if(pTrabajo[i].isEmpty == 0 && pTrabajo[i].fecha.dia == dia && pTrabajo[i].fecha.mes == mes && pTrabajo[i].fecha.anio == anio)
			{
				printf("****** trabajos y servicios *******\n");
				printf("id   idauto   servicio   fecha  \n");
				mostrarTrabajo(pTrabajo[i],servicios,tam_s);
			}
			else
			{
				printf("no hay trabajos o servicios con esa fecha \n");
				break;
			}
		}
	}
	return todoOk;
}
