#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include <string.h>
#define TAMSERV 4
#define TAMTIP 4
#define TAMCOL 5
#define TAMBIC 4
#define TAMROD 4
#define TAMTRAB 10
typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    char descripcion[20];
    int isEmpty;

}eTipo;

typedef struct
{
    int id;
    char nombreColor[20];
    int isEmpty;

}eColor;

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;
    int isEmpty;

}eBicicleta;

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
    int isEmpty;

}eServicio;

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;


char mostrarMenu();
int altaBicicleta(eBicicleta bicicletas[], int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol);
int buscarLibreBicicleta(eBicicleta bicicletas[],int tamBic);
void modificarBicicleta(eBicicleta bicicletas[],int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol);
int buscarBicicleta(int id, eBicicleta bicicletas[], int tam);
void mostrarBicicleta(eBicicleta x,eTipo tipos[],int tamTip,eColor colores[],int tamCol);
void mostrarBicicletas(eBicicleta vec[],int tam,eTipo tipos[],int tamTip,eColor colores[],int tamCol);
char menuModificar();
void bajaBicicleta(eBicicleta bicicletas[],int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol);
void inicializarBicicletas(eBicicleta vec[],int tam);
int cargarDescripcionTipo(char tipo[], int id, eTipo tipos[], int tamTip);
void mostrarTipos(eTipo tipos[],int tamTip);
int buscarTipo(int id, eTipo tipos[], int tam);
int cargarNombreColor(char color[], int id,eColor colores[], int tamCol);
void mostrarColores(eColor colores[],int tamCol);
int buscarColor(int id, eColor colores[], int tam);
void ordenarBicicletas(eBicicleta vec[], int tam,eTipo tipos[],int tamTip,eColor colores[],int tamCol);
void mostrarServicios(eServicio servicios[],int tamSerb);
int buscarServicio(int id, eServicio servicios[], int tam);
int buscarLibreTrabajo(eTrabajo trabajos[],int tam);
void inicializarTrabajos(eTrabajo vec[],int tam);
int altaTrabajo(int idX,eBicicleta bicicletas[], int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol,eTrabajo trabajos[],int tam,eServicio servicios[],int tamServ);
void mostrarTrabajos(eTrabajo vec[],int tamTrab,eServicio servicios[],int tamServ,eBicicleta bicicletas[],int tamBic);
int cargarNombreServicio(char servicio[], int id,eServicio servicios[], int tamServ);
void mostrarTrabajo(eTrabajo x,eServicio servicios[],int tamServ,eBicicleta bicicletas[],int tamBic);

int main()
{
    char confirma;
    char seguir='s';
    int proximoidTrabajo=1;
    int flagIngresoBici=0;
    int flagIngresoTrabajo=0;
    eServicio servicios[TAMSERV]={{20000,"Limpieza", 250},{20001, "Parche",300},{20002, "Centrado", 400},{20003,"Cadena",350}};
    eTipo tipos[TAMTIP]={{1000, "Rutera"}, {1001, "Carrera"}, {1002, "Mountain"},{1003, "BMX"}};
    eColor colores[TAMCOL]={{5000, "Gris"}, {5001, "Negro"}, {5002, "Blanco"},{5003, "Azul"},{5004, "Rojo"}};

    eBicicleta bicicletas[TAMBIC];
    eTrabajo trabajos[TAMTRAB];


    inicializarBicicletas(bicicletas,TAMBIC);
    inicializarTrabajos(trabajos,TAMTRAB);



    do
    {
       switch(mostrarMenu())
       {
            case 'A':
                altaBicicleta(bicicletas,TAMBIC,tipos,TAMTIP,colores,TAMCOL);
                flagIngresoBici=1;
                break;
            case 'B':
                if(flagIngresoBici)
                {
                   modificarBicicleta(bicicletas,TAMBIC,tipos,TAMTIP,colores,TAMCOL);
                }
                else
                {
                    printf("NO hay bici que modificar");
                }

                break;
            case 'C':
                 if(flagIngresoBici)
                {
                   bajaBicicleta(bicicletas,TAMBIC,tipos,TAMTIP,colores,TAMCOL);
                }
                else
                {
                    printf("NO hay bicis a la cual hacerle la baja");
                }

                break;
            case 'D':
                if(flagIngresoBici)
                {
                   ordenarBicicletas(bicicletas,TAMBIC,tipos,TAMTIP,colores,TAMCOL);
                }
                else
                {
                    printf("NO hay bicis cuales ordenar");
                }

                break;
            case 'E':
                mostrarTipos(tipos,TAMTIP);

                break;
            case 'F':
                mostrarColores(colores,TAMCOL);
                break;
            case 'G':
                mostrarServicios(servicios,TAMSERV);
                break;
            case 'H':
                if(altaTrabajo(proximoidTrabajo,bicicletas,TAMBIC,tipos,TAMTIP,colores,TAMCOL,trabajos,TAMTRAB,servicios,TAMSERV))
                {
                    proximoidTrabajo++;
                }
                flagIngresoTrabajo=1;
                break;
            case 'I':
                if(flagIngresoTrabajo)
                {
                    mostrarTrabajos(trabajos,TAMTRAB,servicios,TAMSERV,bicicletas,TAMBIC);
                }
                else
                {
                    printf("NO hay trabajos cuales ordenar");
                }

                break;
            case 'J':
                printf("\nIngrese s para confirmar: ");
                fflush(stdin);
                scanf("%c",&confirma);
                if(confirma=='s')
                {
                    seguir='n';
                }
                break;

       }
    system("pause");
    }
    while(seguir=='s');


    return 0;
}

int altaBicicleta(eBicicleta bicicletas[], int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol)
{
    int todoOK = 0;
    int indice = buscarLibreBicicleta(bicicletas,tamBic);
    char auxChar[51];
    int auxInt;
    float auxFloat;

    eBicicleta auxBicicleta;
    system("cls");

    printf("****Alta Bicicleta****");

    if(indice == -1) // hay lugar?
    {
        printf("Sistema completo\n\n");
    }
    else
    {

           if((utn_getEntero(&auxInt,2,"\nIngrese el id: ","\nError reingrese el id: ",1,1000))==0)
           {
               auxBicicleta.id=auxInt;
           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
           }



           if((utn_getCadena(auxChar,51,2,"\nIngrese la marca: ","\nError reingrese la marca: "))==0)
           {
               strcpy(auxBicicleta.marca,auxChar);
           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
           }


            mostrarTipos(tipos,tamTip);
           if((utn_getEntero(&auxInt,2,"\nIngrese el tipo: ","\nError reingrese el tipo: ",1000,1003))==0)
           {
               if((buscarTipo(auxInt,tipos,tamTip))!= -1)
                    {
                        auxBicicleta.idTipo=auxInt;
                    }
                    else
                    {
                        printf("\nNo hay ningun cliente con ese id\n\n");
                    }

           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
           }

            mostrarColores(colores,tamCol);
           if((utn_getEntero(&auxInt,2,"\nIngrese el color: ","\nError reingrese el color: ",5000,5004))==0)
           {
               if((buscarColor(auxInt,colores,tamCol))!= -1)
                    {
                        auxBicicleta.idColor=auxInt;
                    }
                    else
                    {
                        printf("\nNo hay ningun cliente con ese id\n\n");
                    }

           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
           }

           if((utn_getFlotante(&auxFloat,2,"\nIngrese el rodado: ","\nError reingrese el rodado: ",20,29))==0)
                {
                    auxBicicleta.rodado=auxFloat;
                }
                else
                {
                    printf("\nTe quedaste sin intentos\n\n");
                }


            auxBicicleta.isEmpty=0;
            bicicletas[indice] = auxBicicleta;
            todoOK = 1;
        }
    return todoOK;
}

char mostrarMenu()
{
    char opcion;
    system("cls");
    printf("**** Menu de opciones ****\n\n");
    printf("A- Alta bicicleta\n");
    printf("B- Modificar bicicleta\n");
    printf("C- Baja bicicleta\n");
    printf("D- Listar bicicletas\n");
    printf("E- Listar tipos\n");
    printf("F- Listar colores\n");
    printf("G- Listar servicios\n");
    printf("H- Alta trabajo\n");
    printf("I- Listar trabajos\n");
    printf("J- Salir\n");
    printf("Indique la opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
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


     if((utn_getEntero(&auxInt,2,"\nIngrese el id: ","\nError reingrese el id: ",1,4))==0)
       {
           id=auxInt;
       }
       else
       {
            printf("\nTe quedaste sin intentos\n\n");
       }

    indice = buscarBicicleta(id,bicicletas,tamBic);

    if(indice== -1)
    {
        printf("No hay registro de algun cliente con el id: %d\n", id);
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
                        if((buscarTipo(auxInt,tipos,tamTip))!= -1)
                        {
                            bicicletas[indice].idTipo=auxInt;
                        }
                        else
                        {
                        printf("\nNo hay ningun cliente con ese id\n\n");
                        }

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
                    printf("La opcion no es valida");
                    break;

            }
        }
        else
        {
            printf("Se cancelo la operacion\n\n");
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
    printf("id   Marca     Tipo      Color      Rodado \n");
    printf("%d     %s       %s        %s         %.2f \n", x.id,x.marca,nombreTipo, nombreColor, x.rodado);

}
void mostrarBicicletas(eBicicleta vec[],int tam,eTipo tipos[],int tamTip,eColor colores[],int tamCol)
{
    int flag=0;
    printf("\n****Listado de Bicicletas****\n");

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


void mostrarTrabajos(eTrabajo vec[], int tamTrab,eServicio servicios[],int tamServ,eBicicleta bicicletas[],int tamBic)
{
    int flag=0;
    printf("\n****Listado de Trabajos****\n");

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
    printf("id   servicio    id Bicicleta     fecha \n");
    printf("%d     %s             %d         %d/%d/%d \n", x.id,nombreServicio,x.idBicicleta,x.fecha.dia,x.fecha.mes,x.fecha.anio);

}


char menuModificar()
{
    char opcion;
    printf("\n***Menu Modificar***\n");
    printf("a-Modificar tipo\n");
    printf("b-Modificar rodado\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}

void bajaBicicleta(eBicicleta bicicletas[],int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol)
{
    int indice;
    int id;
    char confirma;
    int auxInt;

    system("cls");
    printf("****Baja cliente****\n\n");

    if((utn_getEntero(&auxInt,2,"\nIngrese el id: ","\nError reingrese el id: ",1,4))==0)
    {
        id=auxInt;
    }
    else
    {
        printf("\nTe quedaste sin intentos\n\n");
    }

    indice = buscarBicicleta(id,bicicletas,tamBic);

    if(indice== -1)
    {
        printf("No hay registro de alguna bicicleta con el id: %d\n", id);
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

void inicializarTrabajos(eTrabajo vec[],int tam)
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
    printf("id     Descripcion\n");

    for(int i=0;i<tamTip;i++)
    {
        printf("%d      %10s\n",tipos[i].id,tipos[i].descripcion);
    }

}

void mostrarServicios(eServicio servicios[],int tamServ)
{

    printf("\n****Listado de servicios****\n");
    printf("id     Descripcion\n");

    for(int i=0;i<tamServ;i++)
    {
        printf("%d      %10s   %.2f\n",servicios[i].id,servicios[i].descripcion,servicios[i].precio);
    }

}



void mostrarColores(eColor colores[],int tamCol)
{

    printf("\n****Listado de colores****\n");
    printf("id     Nombre del color\n");

    for(int i=0;i<tamCol;i++)
    {
        printf("%d      %10s\n",colores[i].id,colores[i].nombreColor);
    }

}





int buscarTipo(int id, eTipo tipos[], int tam)
{
   int indice = -1;

    for(int i=0;i<tam;i++)
    {
       if(tipos[i].id == id && tipos[i].isEmpty == 0)
       {
           indice = i;
           break;
       }
    }

    return indice;

}

int buscarColor(int id, eColor colores[], int tam)
{
   int indice = -1;

    for(int i=0;i<tam;i++)
    {
       if(colores[i].id == id && colores[i].isEmpty == 0)
       {
           indice = i;
           break;
       }
    }

    return indice;

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

int altaTrabajo(int idX,eBicicleta bicicletas[], int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol,eTrabajo trabajos[],int tam,eServicio servicios[],int tamServ)
{
    int todoOK = 0;
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
        mostrarBicicletas(bicicletas,tamBic,tipos,tamTip,colores,tamCol);
        if((utn_getEntero(&auxInt,2,"\nIngrese el id de la bicicleta: ","\nError reingrese el id: ",1,1000))==0)
        {
               if((buscarBicicleta(auxInt,bicicletas,tamBic))!= -1)
                    {
                        auxTrabajo.idBicicleta=auxInt;
                    }
                    else
                    {
                        printf("\nNo hay ningun cliente con ese id\n\n");
                    }

        }
        else
        {
                printf("\nTe quedaste sin intentos\n\n");
        }


            mostrarServicios(servicios,tamServ);
           if((utn_getEntero(&auxInt,2,"\nIngrese el id del servivio: ","\nError reingrese el id: ",20000,20004))==0)
           {
               if((buscarServicio(auxInt,servicios,tamServ))!= -1)
                    {
                        auxTrabajo.idServicio=auxInt;
                    }
                    else
                    {
                        printf("\nNo hay ningun cliente con ese id\n\n");
                    }

           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
           }


            printf("\nIngrese fecha de ingreso dd/mm/aaaa: ");
            scanf("%d/%d/%d",&auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);


            auxTrabajo.isEmpty=0;
             trabajos[indice]= auxTrabajo;
            todoOK = 1;
    }
    return todoOK;
}



int buscarServicio(int id, eServicio servicios[], int tam)
{
   int indice = -1;

    for(int i=0;i<tam;i++)
    {
       if(servicios[i].id == id && servicios[i].isEmpty == 0)
       {
           indice = i;
           break;
       }
    }

    return indice;

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


