#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED

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


#endif // BICICLETAS_H_INCLUDED
/** \brief muestra un menu con opciones a modificar
 *
 * \return la opcion elegida por el usuario
 *
 */
char menuModificar();

/** \brief busca un espacio vacio en un vector de bicicletas y le carga los datos si el usuario ingresa bien todos los campos
 *
 * \param id autoincremental
 * \param vector de bicicletas
 * \param tamaño del vector de bicicletas
 * \param vector de tipos
 * \param tamaño del vector de tipos
 * \param vector de tipo colores
 * \param tamaño del vector de colores
 * \return 1 si se cargaron bien los datos, sino 0
 *
 */
int altaBicicleta(int idX,eBicicleta bicicletas[], int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol);



/** \brief busca en un vector de bicicletas si hay un espacio con isEmpty=1
 *
 * \param vector de bicicletas
 * \param tamaño del vector de bicicletas
 * \return -1 si no encuentra espacio vacio,sino el indice del espacio vacio encontrado
 *
 */
int buscarLibreBicicleta(eBicicleta bicicletas[],int tamBic);

/** \brief realiza la modificacion de los datos de una bicicleta
 *
 * \param vector de bicicletas
 * \param tamaño del vector de bicicletas
 * \param vector de tipo tipos
 * \param tamaño del vector de tipos
 * \param vector de tipo colores
 * \param tamaño del vector de colores
 *
 */
void modificarBicicleta(eBicicleta bicicletas[],int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol);

/** \brief busca una bicicleta a partir de un id
 *
 * \param id de la bicicleta a buscar
 * \param vector de bicicletas
 * \param tamaño del vector de bicicletas
 * \return -1 si no encontro ninguna bicicleta con ese id, sino devuelve la posicion de esa bicicleta
 *
 */
int buscarBicicleta(int id, eBicicleta bicicletas[], int tam);

/** \brief muestra una bicicleta del vector de bicicletas
 *
 * \param Una bicicleta del vector
 * \param vector de tipos
 * \param tamaño del vector de tipos
 * \param vector de colores
 * \param tamaño del vector de colores
 *
 */
void mostrarBicicleta(eBicicleta x,eTipo tipos[],int tamTip,eColor colores[],int tamCol);

/** \brief muestra todas las bicicletas del vector de bicicletas
 *
 * \param vector de bicicletas
 * \param tamaño del vector de bicicletas
 * \param vector de tipos
 * \param tamaño del vector de tipos
 * \param vector de colores
 * \param tamaño del vector de colores
 *
 */
void mostrarBicicletas(eBicicleta vec[],int tam,eTipo tipos[],int tamTip,eColor colores[],int tamCol);

/** \brief realiza la baja logica de una bicicleta
 *
 * \param vector de bicicletas
 * \param tamaño del vector de bicicletas
 * \param vector de tipos
 * \param tamaño del vector de tipos
 * \param vector de colores
 * \param tamaño del vector de colores
 *
 */
void bajaBicicleta(eBicicleta bicicletas[],int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol);

/** \brief le da valor 1 al campo isEmpty de cada bicicleta
 *
 * \param vector de bicicletas
 * \param tamaño del vector de bicicletas
 *
 */
void inicializarBicicletas(eBicicleta vec[],int tam);

/** \brief carga la descripcion de un tipo de bicicleta en una variable pasada por parametro
 *
 * \param variable donde se cargara la descripcion
 * \param id del tipo a buscar
 * \param vector de tipos
 * \param tamaño del vector de tipos
 * \return 1 si logra cargar la descripcion, sino 0
 *
 */
int cargarDescripcionTipo(char tipo[], int id, eTipo tipos[], int tamTip);

/** \brief muestra todos los tipos del vector tipos
 *
 * \param vector de tipos
 * \param tamaño del vector de tipos
 *
 */
void mostrarTipos(eTipo tipos[],int tamTip);

/** \brief carga la descripcion de un tipo de bicicleta en una variable pasada por parametro
 *
 * \param variable donde se va a cargar la descripcion
 * \param id del color a buscar
 * \param vector de colores
 * \param tamaño del vector de colores
 * \return 1 si logra cargar la descripcion, sino 0
 *
 */
int cargarNombreColor(char color[], int id,eColor colores[], int tamCol);

/** \brief muestra todos los colores del vector de colores
 *
 * \param vector de colores
 * \param tamaño del vector de colores
 *
 */
void mostrarColores(eColor colores[],int tamCol);

/** \brief ordena el vector de bicicletas segun un parametro
 *
 * \param vector de bicicletas
 * \param tamaño del vector de bicicletas
 * \param vector de tipos
 * \param tamaño del vector de tipos
 * \param vector de colores
 * \param tamaño del vector de colores
 *
 */
void ordenarBicicletas(eBicicleta vec[], int tam,eTipo tipos[],int tamTip,eColor colores[],int tamCol);
