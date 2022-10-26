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


int inicializarAuto(eAuto vec[], int tam)
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


int buscarLibreAuto(int* pIndice, eAuto vec[], int tam)
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

int buscarAuto(int* pIndice, int id, eAuto vec[], int tam)
{


    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if( !vec[i].isEmpty && vec[i].id == id )
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

int altaAuto(int* pId, eAuto vec[], int tam,eMarca marca[],int tam_m,eColor colores[],int tam_c)
{

    int todoOk = 0;
    int indice;
    eAuto auxAuto;

    if(pId != NULL && vec != NULL && tam > 0)
    {

        system("cls");

        printf("**** Alta autos ****\n\n");

        buscarLibreAuto(&indice, vec, tam);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            cargarAuto(&auxAuto,marca,colores,tam_m,tam_c);

            auxAuto.id = *pId;

            *pId = *pId + 1;

            vec[indice] = auxAuto;
            todoOk = 1;
        }
    }
    return todoOk;
}


int cargarAuto(eAuto* pAuto,eMarca* marca,eColor* colores,int tam_m,int tam_c)
{

    int todoOk = 0;
    int idMarca;
    int idColor;
    char caja;

    if(pAuto != NULL)
    {

    	mostrarMarcas(marca,tam_m);

    	printf("Ingrese el id de la marca: ");
		scanf("%d",&idMarca);

		while(!validarIdMarcas(idMarca,marca,tam_m))
		{
			printf("id invalido,reingrese el id de la marca: ");
			scanf("%d",&idMarca);
		}

		pAuto->idMarca= idMarca;

        mostrarColores(colores,tam_c);

        printf("Ingrese el id del color: ");
        scanf("%d",&idColor);

        while(!validarIdColores(idColor,colores,tam_c))
        {
        	printf("id invalido,reingrese el id del color: ");
        	scanf("%d",&idColor);
        }

        pAuto->idColor= idColor;

        printf("Ingrese el tipo de caja del auto m (manual) o a(automatica): ");
        fflush(stdin);
        scanf("%c", &caja);
        while(caja != 'm' && caja != 'a')
        {
        	 printf("caja invalida,reIngrese el tipo de caja:");
        	 fflush(stdin);
        	 scanf("%c",&caja);
        }
        pAuto->caja= caja;



        pAuto->isEmpty = 0;

        todoOk = 1;
    }



    return todoOk;
}
int modificarAuto( eAuto vec[], int tam,eColor colores[], int tam_c,eMarca marcas[],int tam_m)
{

    int todoOk = 0;
    int id;
    int indice;
    int opcion;
    char seguir='s';
    char confirma;
    int nuevaMarca;
    int nuevoColor;

    do{
		if(vec != NULL && tam > 0)
		{
			system("cls");
			printf("**** Modificar auto ****\n\n");

			if(mostrarAutos(vec, tam, 0,marcas,colores,tam_m,tam_c))
			{
				printf("Ingrese el id del auto a modificar: ");
				scanf("%d", &id);
				buscarAuto(&indice, id, vec, tam);
			}
			else
			{
				printf("no hay autos que modificar");
			}
			if(indice == -1)
			{
				printf("No existe un auto con id: %d\n", id);
			}
			else
			{
				mostrarAuto(vec[indice],marcas,colores,tam_m,tam_c);
				opcion=subMenuModificarAutos();
				switch(opcion)
				{
				case 1:
				mostrarMarcas(marcas,tam_m);
				printf("ingrese el id de la nueva marca");
				scanf("%d",&nuevaMarca);
				while(!validarIdMarcas(nuevaMarca,marcas,tam_m))
				{
					printf("id invalido,reingrese el id de la marca del auto: ");
					scanf("%d",&nuevaMarca);
				}
				printf("Confirma modificacion?: s/n");
				fflush(stdin);
				confirma = getchar();
				if(confirma == 's')
				{
					vec[indice].idMarca= nuevaMarca;
					printf("Modificacion exitosa.\n");
				}
				else
				{
					printf("Se ha cancelado la modificacion.\n");
				}
					break;
				case 2:
					mostrarColores(colores,tam_c);
					printf("ingrese el id del nuevo color");
					scanf("%d",&nuevoColor);
					while(!validarIdColores(nuevoColor,colores,tam_c))
					{
						printf("id invalido,reingrese el id del color del auto: ");
						scanf("%d",&nuevoColor);
					}
					printf("Confirma modificacion?: s/n");
					fflush(stdin);
					confirma = getchar();
					if(confirma == 's')
					{
						vec[indice].idColor= nuevoColor;
						printf("Modificacion exitosa.\n");
					}
					else
					{
						printf("Se ha cancelado la modificacion.\n");
					}
					break;
				default:
					printf("opcion invalida./n");
					break;
				}

			}
			todoOk = 1;
			printf("desea continuar modificando autos? s/n");
			fflush(stdin);
			seguir = getchar();
		}
	}while(seguir == 's');

    return todoOk;
}

int bajaAuto(eAuto vec[], int tam,eMarca marcas[],eColor colores[],int tam_m,int tam_c)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma;

    if(vec != NULL && tam > 0)
    {

        system("cls");
        printf("**** Baja autos ****\n\n");

        mostrarAutos(vec, tam, 0,marcas,colores,tam_m,tam_c);

        printf("Ingrese id a dar de baja: ");
        scanf("%d", &id);

        buscarAuto(&indice, id, vec, tam);
        if(indice == -1)
        {

            printf("No existe un auto con id: %d\n", id);

        }
        else
        {

        	mostrarAuto(vec[indice],marcas,colores,tam_m,tam_c);
            printf("Confirma baja?:s/n ");
            fflush(stdin);
            confirma = getchar();

            if(confirma == 's')
            {
                vec[indice].isEmpty = 1;
                printf("Baja exitosa.\n");
            }
            else
            {
                printf("Se ha cancelado la baja.\n");
            }
        }
        todoOk = 1;
    }

    return todoOk;
}
int ordenarAutos(eAuto vec[], int tam,eMarca marca [],int tam_m)
{
    int todoOk = 0;
    eAuto aux;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam  - 1 ; i++)
        {

            for(int j = i + 1 ; j < tam ; j++)
            {

                if((vec[i].idMarca > vec[j].idMarca) || (vec[i].idMarca == vec[j].idMarca && vec[i].caja > vec[j].caja))
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
