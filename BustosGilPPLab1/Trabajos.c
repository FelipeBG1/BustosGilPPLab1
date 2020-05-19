#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include <string.h>
#include <ctype.h>
#include "Bicicletas.h"
#include "Trabajos.h"


void mostrarTrabajos(eTrabajo vec[], int tamTrab,eServicio servicios[],int tamServ,eBicicleta bicicletas[],int tamBic)
{
    int flag=0;
    printf("\n****Listado de Trabajos****\n\n");
    printf("id        Servicio     id Bicicleta    Fecha \n");
    for(int i=0;i<tamTrab;i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarTrabajo(vec[i],servicios,tamServ,bicicletas,tamBic);
            flag=1;
        }
    }
    if(flag==0)
        {
            printf("\nNo hay trabajos que listar\n\n");
        }

}

void mostrarTrabajo(eTrabajo x,eServicio servicios[],int tamServ,eBicicleta bicicletas[],int tamBic)
{

    char nombreServicio[25];
    cargarNombreServicio(nombreServicio,x.idServicio,servicios,tamServ);

    printf("%d       %10s         %d          %d/%d/%d \n", x.id, nombreServicio, x.idBicicleta, x.fecha.dia, x.fecha.mes, x.fecha.anio);

}

void inicializarTrabajos(eTrabajo vec[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        vec[i].isEmpty = 1;
    }
}



void mostrarServicios(eServicio servicios[],int tamServ)
{

    printf("\n****Listado de servicios****\n");
    printf("id        Descripcion      Precio\n");

    for(int i=0;i<tamServ;i++)
    {
        printf("%d      %10s       $%d\n",servicios[i].id, servicios[i].descripcion, servicios[i].precio);
    }

}














int cargarNombreServicio(char servicio[], int id,eServicio servicios[], int tamServ)
{
    int todoOK=0;
    for(int i=0;i<tamServ;i++)
    {
        if(servicios[i].id == id)
        {
            strcpy(servicio, servicios[i].descripcion);
            todoOK = 1;
        }
    }
    return todoOK;
}



int altaTrabajo(int idX,eBicicleta bicicletas[], int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol,eTrabajo trabajos[],int tam,eServicio servicios[],int tamServ)
{
    int todoOK = -1;
    int indice=buscarLibreTrabajo(trabajos,tam);
    int auxInt;


    eTrabajo auxTrabajo;
    system("cls");

    printf("****Alta Trabajo****\n");
    if(indice== -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        while(todoOK==-1)
        {
            mostrarBicicletas(bicicletas,tamBic,tipos,tamTip,colores,tamCol);
            if((utn_getEntero(&auxInt,2,"\nIngrese el id de la bicicleta: ","\nError reingrese el id: ",1,1000))==0)
            {
            if((buscarBicicleta(auxInt,bicicletas,tamBic))!= -1)
            {
                        auxTrabajo.idBicicleta=auxInt;
            }
            else
            {
                printf("\nNo hay ninguna bicicleta con ese id\n\n");

            }

            }
            else
            {
                printf("\nTe quedaste sin intentos\n\n");
                todoOK=0;
                break;
            }


            mostrarServicios(servicios,tamServ);
           if((utn_getEntero(&auxInt,2,"\nIngrese el id del servicio: ","\nError reingrese el id: ",20000,20004))==0)
           {
                auxTrabajo.idServicio=auxInt;

           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
                todoOK=0;
                break;
           }


            if((utn_getEntero(&auxInt,2,"\nIngrese el dia del trabajo: ","\nError reingrese el dia: ",1,31))==0)
           {
              auxTrabajo.fecha.dia=auxInt;

           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
                todoOK=0;
                break;
           }

             if((utn_getEntero(&auxInt,2,"\nIngrese el mes del trabajo: ","\nError reingrese el mes: ",1,12))==0)
           {
              auxTrabajo.fecha.mes=auxInt;

           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
                todoOK=0;
                break;
           }

           if((utn_getEntero(&auxInt,2,"\nIngrese el anio del trabajo: ","\nError reingrese el anio: ",1950,2020))==0)
           {
              auxTrabajo.fecha.anio=auxInt;
              todoOK=1;

           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
                todoOK=0;
                break;
           }
        }

        if(todoOK==1)
        {
            auxTrabajo.id=idX;
            auxTrabajo.isEmpty=0;
            trabajos[indice]= auxTrabajo;
            printf("\nEl id asignado a este trabajo es %d\n\n",auxTrabajo.id);

        }


    }
    return todoOK;
}




int buscarLibreTrabajo(eTrabajo trabajos[],int tam)
{
    int indice = -1;

    for(int i=0;i<tam;i++)
    {
       if(trabajos[i].isEmpty == 1)
       {
           indice = i;
           break;
       }
    }
    return indice;
}

