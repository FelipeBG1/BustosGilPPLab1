#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include <string.h>
#include <ctype.h>
#include "Bicicletas.h"
#include "Trabajos.h"
#define TAMSERV 4
#define TAMTIP 4
#define TAMCOL 5
#define TAMBIC 4
#define TAMROD 4
#define TAMTRAB 10


char mostrarMenu();



int main()
{
    char confirma;
    char seguir='s';
    int proximoidTrabajo=1;
    int proximoidBicicleta=1;
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
                if(altaBicicleta(proximoidBicicleta,bicicletas,TAMBIC,tipos,TAMTIP,colores,TAMCOL))
                {
                    proximoidBicicleta++;
                    flagIngresoBici=1;
                }

                break;
            case 'B':
                if(flagIngresoBici)
                {
                   modificarBicicleta(bicicletas,TAMBIC,tipos,TAMTIP,colores,TAMCOL);
                }
                else
                {
                    printf("\n\nNo hay biciclectas que modificar\n\n");
                }

                break;
            case 'C':
                 if(flagIngresoBici)
                {
                   bajaBicicleta(bicicletas,TAMBIC,tipos,TAMTIP,colores,TAMCOL);
                }
                else
                {
                    printf("\n\nNo hay bicicletas a las cuales hacerle la baja\n\n");
                }

                break;
            case 'D':
                if(flagIngresoBici)
                {
                   ordenarBicicletas(bicicletas,TAMBIC,tipos,TAMTIP,colores,TAMCOL);
                }
                else
                {
                    printf("\n\nNo hay bicicletas para listar\n\n");
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
                if(flagIngresoBici)
                {
                    if(altaTrabajo(proximoidTrabajo,bicicletas,TAMBIC,tipos,TAMTIP,colores,TAMCOL,trabajos,TAMTRAB,servicios,TAMSERV))
                    {
                        proximoidTrabajo++;
                        flagIngresoTrabajo=1;
                    }
                }
                else
                {
                    printf("\nDebe dar de alta una bicicleta para dar de alta un trabajo\n\n");
                }
                break;
            case 'I':
                if(flagIngresoTrabajo)
                {
                    mostrarTrabajos(trabajos,TAMTRAB,servicios,TAMSERV,bicicletas,TAMBIC);
                }
                else
                {
                    printf("\n\nNo hay trabajos para listar\n\n");
                }

                break;
            case 'J':
                printf("\nIngrese s para confirmar la salida: ");
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
    printf("\n\nIndique la opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);

    opcion=toupper(opcion);

    return opcion;
}












