#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include <string.h>
#include <ctype.h>
#include "Bicicletas.h"


char menuModificar()
{
    char opcion;
    system("cls");
    printf("\n***Menu Modificar***\n");
    printf("a-Modificar tipo\n");
    printf("b-Modificar rodado\n");
    printf("\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    opcion=tolower(opcion);

    return opcion;
}


int altaBicicleta(int idX,eBicicleta bicicletas[], int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol)
{
    int todoOK = -1;
    int indice = buscarLibreBicicleta(bicicletas,tamBic);
    char auxChar[51];
    int auxInt;
    float auxFloat;

    eBicicleta auxBicicleta;
    system("cls");

    printf("****Alta Bicicleta****");

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        while(todoOK==-1)
        {
           if((utn_getCadena(auxChar,51,2,"\nIngrese la marca: ","\nError reingrese la marca: "))==0)
           {
               strcpy(auxBicicleta.marca,auxChar);
           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
                todoOK=0;
                break;
           }


            mostrarTipos(tipos,tamTip);
           if((utn_getEntero(&auxInt,2,"\nIngrese el tipo: ","\nError reingrese el tipo: ",1000,1003))==0)
           {
                auxBicicleta.idTipo=auxInt;

           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
                todoOK=0;
                break;
           }

            mostrarColores(colores,tamCol);
           if((utn_getEntero(&auxInt,2,"\nIngrese el color: ","\nError reingrese el color: ",5000,5004))==0)
           {
              auxBicicleta.idColor=auxInt;
           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
                todoOK=0;
                break;
           }



           if((utn_getFlotante(&auxFloat,2,"\nIngrese el rodado: ","\nError reingrese el rodado: ",20,29))==0)
                {
                    auxBicicleta.rodado=auxFloat;
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
            auxBicicleta.id=idX;
            auxBicicleta.isEmpty=0;
            bicicletas[indice] = auxBicicleta;
            printf("\nEl id asignado a esta bicicleta es %d\n\n",auxBicicleta.id);
        }


    }
    return todoOK;
}

int buscarLibreBicicleta(eBicicleta bicicletas[],int tamBic)
{
    int indice = -1;

    for(int i=0;i<tamBic;i++)
    {
       if(bicicletas[i].isEmpty == 1)
       {
           indice = i;
           break;
       }
    }
    return indice;
}

void modificarBicicleta(eBicicleta bicicletas[],int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol)
{
    int indice;
    int id;
    char confirma;
    int auxInt;
    float auxFloat;


    system("cls");
    printf("****Modificar bicicleta****\n\n");

    mostrarBicicletas(bicicletas,tamBic,tipos,tamTip,colores,tamCol);


      if((utn_getEntero(&auxInt,2,"\nIngrese el id: ","\nError reingrese el id: ",1,1000))==0)
    {
    	id=auxInt;
    }
    else
    {
    	printf("\nTe quedaste sin intentos\n\n");
    	id = -1;
    }

    indice = buscarBicicleta(id,bicicletas,tamBic);

    if(indice== -1)
    {
        if(id==-1)
    	{
    		printf("\nSe cancelo la operacion\n\n");
    	}
    	else
    	{
    		printf("No hay registro de alguna bicicleta con el id: %d\n", id);
    	}
    }
    else
    {
        system("cls");
        mostrarBicicleta(bicicletas[indice],tipos,tamTip,colores,tamCol);
        printf("\nQuiere modificar esta bicicleta: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            switch(menuModificar())
            {
                case 'a':
                    mostrarTipos(tipos,tamTip);
                    if((utn_getEntero(&auxInt,2,"\nIngrese el nuevo tipo: ","\nError reingrese el tipo: ",1000,1004))==0)
                    {


                    }
                    else
                    {
                            printf("\nTe quedaste sin intentos\n\n");
                    }

                    break;

                case 'b':
                    if((utn_getFlotante(&auxFloat,2,"\nIngrese el nuevo rodado: ","\nError reingrese el rodado: ",20.0,29.0))==0)
                    {
                       bicicletas[indice].rodado=auxFloat;
                    }
                    else
                    {
                        printf("\nTe quedaste sin intentos\n\n");
                    }
                    break;


                default:
                    printf("\nLa opcion no es valida\n\n");
                    break;

            }
        }
        else
        {
            printf("\nSe cancelo la operacion\n\n");
        }

    }
}

int buscarBicicleta(int id, eBicicleta bicicletas[], int tam)
{
   int indice = -1;

    for(int i=0;i<tam;i++)
    {
       if(bicicletas[i].id == id && bicicletas[i].isEmpty == 0)
       {
           indice = i;
           break;
       }
    }

    return indice;

}

void mostrarBicicleta(eBicicleta x,eTipo tipos[],int tamTip,eColor colores[],int tamCol)
{
    char nombreTipo[20];
    char nombreColor[20];
    cargarDescripcionTipo(nombreTipo,x.idTipo,tipos,tamTip);
    cargarNombreColor(nombreColor,x.idColor,colores,tamCol);

    printf("%d     %10s       %10s        %10s         %.2f \n", x.id,x.marca,nombreTipo, nombreColor, x.rodado);

}
void mostrarBicicletas(eBicicleta vec[],int tam,eTipo tipos[],int tamTip,eColor colores[],int tamCol)
{
    int flag=0;

    printf("\n****Listado de Bicicletas****\n");
    printf("id          Marca           Tipo               Color        Rodado \n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarBicicleta(vec[i],tipos,tamTip,colores,tamCol);
            flag=1;
        }
    }
    if(flag==0)
        {
            printf("\nNo hay bicicletas que listar\n\n");
        }

}

void bajaBicicleta(eBicicleta bicicletas[],int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol)
{
    int indice;
    int id;
    char confirma;
    int auxInt;

    system("cls");
    printf("****Baja Bicicleta****\n\n");

    mostrarBicicletas(bicicletas,tamBic,tipos,tamTip,colores,tamCol);

    if((utn_getEntero(&auxInt,2,"\nIngrese el id: ","\nError reingrese el id: ",1,4))==0)
    {
        id=auxInt;
    }
    else
    {
        printf("\nTe quedaste sin intentos\n\n");
        id = -1;
    }

    indice = buscarBicicleta(id,bicicletas,tamBic);

    if(indice== -1)
    {
        if(id==-1)
    	{
    		printf("\nSe cancelo la operacion\n\n");
    	}
    	else
    	{
    		printf("No hay registro de alguna bicicleta con el id: %d\n", id);
    	}

    }
    else
    {
        mostrarBicicleta(bicicletas[indice],tipos,tamTip,colores,tamCol); ///////-------------------------------
        printf("Confirma la baja? : ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            bicicletas[indice].isEmpty=1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se cancelo la operacion\n\n");
        }

    }

}
void inicializarBicicletas(eBicicleta vec[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        vec[i].isEmpty = 1;
    }
}

int cargarDescripcionTipo(char tipo[], int id, eTipo tipos[], int tamTip)
{
    int todoOK=0;
    for(int i=0;i<tamTip;i++)
    {
        if(tipos[i].id == id)
        {
            strcpy(tipo, tipos[i].descripcion);
            todoOK = 1;
        }
    }
    return todoOK;
}

void mostrarTipos(eTipo tipos[],int tamTip)
{

    printf("\n****Listado de tipos****\n");
    printf("id         Descripcion\n");

    for(int i=0;i<tamTip;i++)
    {
        printf("%d      %10s\n",tipos[i].id,tipos[i].descripcion);
    }

}

void mostrarColores(eColor colores[],int tamCol)
{

    printf("\n****Listado de colores****\n");
    printf("id       Nombre del color\n");

    for(int i=0;i<tamCol;i++)
    {
        printf("%d      %10s\n",colores[i].id,colores[i].nombreColor);
    }

}

int cargarNombreColor(char color[], int id,eColor colores[], int tamCol)
{
    int todoOK=0;
    for(int i=0;i<tamCol;i++)
    {
        if(colores[i].id == id)
        {
            strcpy(color, colores[i].nombreColor);
            todoOK = 1;
        }
    }
    return todoOK;
}

void ordenarBicicletas(eBicicleta vec[], int tam,eTipo tipos[],int tamTip,eColor colores[],int tamCol)
{
    eBicicleta auxBicicleta;
    int orden;

    printf("\nIngrese 1 para ordenar de forma ascendente o 0 para que sea descendente: ");
    scanf("%d",&orden);

     for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(orden==1)
            {
                if(vec[i].isEmpty==0 && vec[i].idTipo<vec[j].idTipo)
                {
                    auxBicicleta=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxBicicleta;
                }
                else
                {
                    if(vec[i].isEmpty==0 && vec[i].idTipo==vec[j].idTipo && vec[i].rodado>vec[j].rodado)
                    {
                        auxBicicleta=vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxBicicleta;
                    }
                }
            }
            else
            {
                if(vec[i].isEmpty==0 && vec[i].idTipo>vec[j].idTipo)
                {
                    auxBicicleta=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxBicicleta;
                }
                else
                {
                    if(vec[i].isEmpty==0 && vec[i].idTipo==vec[j].idTipo && vec[i].rodado<vec[j].rodado)
                    {
                        auxBicicleta=vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxBicicleta;
                    }
                }
            }
        }
    }
    mostrarBicicletas(vec,tam,tipos,tamTip,colores,tamCol);
}
