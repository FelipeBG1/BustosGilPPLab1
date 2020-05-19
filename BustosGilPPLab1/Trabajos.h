#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;


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


#endif // TRABAJOS_H_INCLUDED

/** \brief muestra todos los servicios del vector de servicios
 *
 * \param vector de servicios
 * \param tamaño del vector de servicios
 *
 */
void mostrarServicios(eServicio servicios[],int tamSerb);

/** \brief busca un espacio libre dentro del vector de trabajos
 *
 * \param vector de trabajos
 * \param tamaño del vector de trabajos
 * \return -1 si no encontro,sino la posicion del espacio libre encontrado
 *
 */
int buscarLibreTrabajo(eTrabajo trabajos[],int tam);

/** \brief le da valor 1 al campo isEmpty de cada trabajo
 *
 * \param vector de trabajos
 * \param tamaño del vector de trabajos
 *
 */
void inicializarTrabajos(eTrabajo vec[],int tam);

/** \brief busca un espacio vacio en un vector de trabajos y le carga los datos si el usuario ingresa bien todos los campos
 *
 * \param id autoincremental
 * \param vector de bicicletas
 * \param tamaño del vector de bicicletas
 * \param vector de tipos
 * \param tamaño del vector de tipos
 * \param vector de tipo colores
 * \param tamaño del vector de colores
 * \param vector de trabajos
 * \param tamaño del vector de trabajos
 * \param vector de servicios
 * \param tamaño del vector de servicios
 * \return 1 si se cargaron bien los datos, sino 0
 *
 */
int altaTrabajo(int idX,eBicicleta bicicletas[], int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol,eTrabajo trabajos[],int tam,eServicio servicios[],int tamServ);

/** \brief muestra todos los trabajos del vector de trabajos
 *
 * \param vector de trabajos
 * \param tamaño del vector de trabajos
 * \param vector de servicios
 * \param tamaño del vector de servicios
 * \param vector de bicicletas
 * \param tamaño del vector de bicicletas
 *
 */
void mostrarTrabajos(eTrabajo vec[],int tamTrab,eServicio servicios[],int tamServ,eBicicleta bicicletas[],int tamBic);

/** \brief carga la descripcion de un servicio en una variable pasada por parametro
 *
 * \param variable donde se cargara la descripcion
 * \param id del servicio a buscar
 * \param vector de servicios
 * \param tamaño del vector de servicios
 * \return 1 si logra cargar la descripcion, sino 0
 *
 */
int cargarNombreServicio(char servicio[], int id,eServicio servicios[], int tamServ);

/** \brief muestra un trabajo del vector de trabajos
 *
 * \param Un trabajo del vector
 * \param vector de servicios
 * \param tamaño del vector de servicios
 * \param vector de bicicletas
 * \param tamaño del vector de bicicletas
 *
 */
void mostrarTrabajo(eTrabajo x,eServicio servicios[],int tamServ,eBicicleta bicicletas[],int tamBic);
