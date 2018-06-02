#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "funciones.h"


int main()
{
    char seguir = 's';
    int opcion = 0;
    EMovie movie[TAM_MOVIE];
    EMovie pelicula;
    char pagina[30];

    while (seguir == 's')
    {
        muestraMenu();
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                // cargarDatos(&movie);
                // Ingreso datos
                printf("\nIngreso de pelicula\n\n");
                ingresarDatos(&pelicula);

                if (agregarPelicula(pelicula) == 0)
                {
                    printf("Error al ingresar pelicula\n");
                }
                system("pause");
                system("cls");
                break;
            case 2:
                printf("\nBorrar pelicula\n\n");
                printf("Titulo: ");
                fflush(stdin);
                gets(pelicula.titulo);
                if (borrarPelicula(pelicula) == 0)
                {
                    printf("Error al borrar pelicula\n");
                }
                system("pause");
                system("cls");
                break;
            case 3:
                printf("\nModificar pelicula\n\n");
                ingresarDatos(&pelicula);
                if (modificarPelicula(pelicula) == 0)
                {
                    printf("Error al ingresar pelicula\n");
                }
                system("pause");
                system("cls");
               break;
            case 4:
                printf("\nGenera reporte de peliculas\n\n");
                printf("Nombre del archivo: ");
                fflush(stdin);
                gets(pagina);
                inicializaMovies(movie);
                cargarMovies(movie);
                generarPagina(movie, pagina);
                system("pause");
                system("cls");
               break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
