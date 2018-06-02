#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define ARCH "movies.db"
#define ARCH_TMP "movies.tmp"
#define TAM_MOVIE 100
#define ENTRADA 0

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
} EMovie;

/**
 *  Muestra el menu en pantalla
 *  @param no recibe parametros
 *  @return no devuelve ningun valor
 */
void muestraMenu(void);

/**
 *  Devuelve un entero ingresado por teclado
 *  @param no recibe parametros
 *  @return retorna el entero ingresado
 */
int entrarEntero(char *texto, int min, int max);

/**
 *  Toma los datos de la pelicula a agregar
 *  @param movie el puntero a la estructura donde se cargan los datos
 */
void ingresarDatos(EMovie *movie);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Modifica los atributos de una pelicula en el archivo binario
 *  @param movie la estructura a ser modificada en el archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */
int modificarPelicula(EMovie movie);

/**
 *  Agrega el archivo pasado como parametro en el html generado como reporte
 *  @param origen es el nombre del archivo a copiar en el reporte html
 *  @return no retorna valor
 */
void copiarArchivo(char *origen);

/**
 *  Escribe en el archivo pasado como parametro la cabecera de la pagina web a generar
 *  @param puntero al archivo html a generar
 *  @return no retorna valor
 */
void generarCabeceraWebPage(FILE *web);

/**
 *  Escribe en el archivo pasado como parametro el final de la pagina web a generar
 *  @param puntero al archivo html a generar
 *  @return no retorna valor
 */
void generarPieWebPage(FILE *web);

/**
 *  Borra los titulos del vector de peliculas
 *  @param la lista de peliculas
 *  @return no retorna valor
 */
void inicializaMovies(EMovie movie[]);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @return 1 si puede cargar el vector, 0 si hay error de lectura de archivo
 */
int cargarMovies(EMovie movie[]);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie movie[], char nombre[]);

#endif // FUNCIONES_H_INCLUDED
