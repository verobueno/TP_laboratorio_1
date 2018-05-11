#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


#define TAM_LISTA 20
#define TAM_NOMBRE 30
#define LIBRE 0
#define OCUPADO 1
#define CANT_BARRAS 3
#define NINOS 0
#define JOVENES 1
#define ADULTOS 2



typedef struct {
    int estado;
    char nombre[TAM_LISTA];
    int dni;
    int edad;
} ePersona;


/** Brief
* Carga hardcodeada de personas
* recibe el vector persona del tipo ePersona
* no retorna valor
**/
void InicializarPersona(ePersona persona[]);

/** Brief
* Imprime el menu en pantalla
* no recibe ni retorna valor
**/
void MostrarMenu(void);



/** Brief
* Funcion que busca espacio libre en el vector
* recibe el vector persona del tipo ePersona
* no retorna valor
**/
int BuscarLugarLibre(ePersona persona[]);


/** Brief
* Carga los datos de una persona
* recibe el vector persona del tipo ePersona
* no retorna valor
**/
void AgregarPersona(ePersona persona[]);



/** Brief
* Realiza el pivoteo del ordenamiento del vector para
* poder imprimir luego la lista de personas ordenadas
* recibe el vector persona del tipo ePersona y dos enteros i y j
* no retorna valor
**/
void Intercambiar(ePersona persona[], int i, int j);

/** Brief
* Ordena los datos de las personas
* recibe el vector persona del tipo ePersona
* no retorna valor
**/
void OrdenarPersonas(ePersona persona[]);


/** Brief
* Borra los datos de la persona
* recibe el vector persona del tipo ePersona
* no retorna valor
**/
void BorrarPersona(ePersona persona[]);




/** Brief
* Imprime la lista completa de personas
* recibe el vector de personas del tipo ePersona
* no retorna valor
**/
void ImprimirListaPersonas(ePersona persona[]);

/** Brief
* Realiza el grafico de barras agrupado por edades
* recibe el vector persona del tipo ePersona
* no retorna valor
**/
void GraficarEdades(ePersona persona[]);



#endif // FUNCIONES_H_INCLUDED
