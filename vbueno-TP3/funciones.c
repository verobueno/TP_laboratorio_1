#include "funciones.h"

void muestraMenu()
{
    printf("\tCatalogo de Peliculas\n\n");
    printf("1- Agregar pelicula\n");
    printf("2- Borrar pelicula\n");
    printf("3- Modificar pelicula\n");
    printf("4- Generar pagina web\n");
    printf("5- Salir\n\n");
    printf("Opcion: ");
}

int entrarEntero(char * texto, int min, int max)
{
    int entero;

    do
    {
        printf("%s", texto);
        fflush(stdin);
        if (!scanf("%d", &entero))
            entero = -1;
    } while (entero == -1 || entero < min || entero > max);


    return entero;
}

void ingresarDatos(EMovie *movie)
{
    printf("\nIngrese los datos de la pelicula\n\n");
    printf("Titulo: ");
    fflush(stdin);
    gets(movie->titulo);
    printf("Genero: ");
    fflush(stdin);
    gets(movie->genero);
    movie->duracion = entrarEntero("Duracion (0 - 300 min): ", 0, 300);
    printf("Descripcion: ");
    fflush(stdin);
    gets(movie->descripcion);
    movie->puntaje = entrarEntero("Puntaje (0 - 100): ", 0, 100);
    printf("Enlace a imagen: ");
    fflush(stdin);
    gets(movie->linkImagen);
}

int agregarPelicula(EMovie movie)
{
    FILE *arch_movies;
    EMovie pelicula;
    int retorno = 1;

    if ((arch_movies = fopen(ARCH, "r+b")) == NULL)
    {
        retorno = 0;
    }
    else
    {
        while (fread(&pelicula, sizeof(EMovie), 1, arch_movies) != 0)
        {
            if (strcmp (pelicula.titulo, movie.titulo) == 0) {
                printf("\nLa pelicula ya esta ingresada.\n");
                retorno = 0;
                break;
            }
        }
        if (retorno == 1) // Si no encontro la pelicula en el archivo, la escribe
        {
            fwrite(&movie, sizeof(EMovie), 1, arch_movies);
            fclose(arch_movies);
        }
    }

    return retorno;
}

int borrarPelicula(EMovie movie)
{
	FILE *arch_movies;
	FILE *arch_tmp;
	int encontrado = 0;
	EMovie pelicula;

	arch_movies = fopen(ARCH, "rb");
	if (!arch_movies) {
		printf("No se puede abrir el archivo %s", ARCH);
		return 0;
	}
	arch_tmp = fopen(ARCH_TMP, "wb");
	if (!arch_tmp) {
		printf("No se puede abrir el archivo temporal.");
		return 0;
	}

	while (fread(&pelicula, sizeof(EMovie), 1, arch_movies) != 0)
    {
		if (strcmp (pelicula.titulo, movie.titulo) == 0) {
			printf("Se borro la pelicula en el archivo.\n\n");
			encontrado = 1;
		}
        else
		{
			fwrite(&pelicula, sizeof(EMovie), 1, arch_tmp);
		}
	}
	if (!encontrado)
    {
		printf("No se encontro la pelicula: %s\n\n", movie.titulo);
	}

	fclose(arch_movies);
	fclose(arch_tmp);

	remove(ARCH);
	rename(ARCH_TMP, ARCH);

	return 1;
}

int modificarPelicula(EMovie movie)
{
	FILE *arch_movies;
	FILE *arch_tmp;
	int encontrado = 0;
	EMovie pelicula;

	arch_movies = fopen(ARCH, "rb");
	if (!arch_movies) {
		printf("No se puede abrir el archivo %s", ARCH);
		return 0;
	}
	arch_tmp = fopen(ARCH_TMP, "wb");
	if (!arch_tmp) {
		printf("No se puede abrir el archivo temporal.");
		return 0;
	}

	while (fread(&pelicula, sizeof(EMovie), 1, arch_movies) != 0)
    {
		if (strcmp (pelicula.titulo, movie.titulo) == 0)
        {
			encontrado = 1;
			fwrite(&movie, sizeof(EMovie), 1, arch_tmp);
		}
		else
        {
            fwrite(&pelicula, sizeof(EMovie), 1, arch_tmp);
        }
	}
	if (!encontrado)
    {
		printf("No se encontro la pelicula: %s\n\n", movie.titulo);
	}

	fclose(arch_movies);
	fclose(arch_tmp);

	remove(ARCH);
	rename(ARCH_TMP, ARCH);

	return 1;
}

void generarCabeceraWebPage(FILE *web)
{
    fprintf(web, "<!DOCTYPE html>");
    fprintf(web, "<!-- Template by Quackit.com -->");
    fprintf(web, "<html lang='en'>");
    fprintf(web, "<head>");
    fprintf(web, "<meta charset='utf-8'>");
    fprintf(web, "<meta http-equiv='X-UA-Compatible' content='IE=edge'>");
    fprintf(web, "<meta name='viewport' content='width=device-width, initial-scale=1'>");
    fprintf(web, "<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->");
    fprintf(web, "<title>Lista peliculas</title>");
    fprintf(web, "<!-- Bootstrap Core CSS -->");
    fprintf(web, "<link href='css/bootstrap.min.css' rel='stylesheet'>");
    fprintf(web, "<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->");
    fprintf(web, "<link href='css/custom.css' rel='stylesheet'>");
    fprintf(web, "<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->");
    fprintf(web, "<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->");
    fprintf(web, "<!--[if lt IE 9]>");
    fprintf(web, "<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>");
    fprintf(web, "<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>");
    fprintf(web, "<![endif]-->");
    fprintf(web, "</head>");
    fprintf(web, "<body>");
    fprintf(web, "<div class='container'>");
    fprintf(web, "<div class='row'>");
}

void generarPieWebPage(FILE *web)
{
    fprintf(web, "</div>");
    fprintf(web, "<!-- /.row -->");
    fprintf(web, "</div>");
    fprintf(web, "<!-- /.container -->");
    fprintf(web, "<!-- jQuery -->");
    fprintf(web, "<script src='js/jquery-1.11.3.min.js'></script>");
    fprintf(web, "<!-- Bootstrap Core JavaScript -->");
    fprintf(web, "<script src='js/bootstrap.min.js'></script>");
    fprintf(web, "<!-- IE10 viewport bug workaround -->");
    fprintf(web, "<script src='js/ie10-viewport-bug-workaround.js'></script>");
    fprintf(web, "<!-- Placeholder Images -->");
    fprintf(web, "<script src='js/holder.min.js'></script>");
    fprintf(web, "</body>");
    fprintf(web, "</html>");
}

void inicializaMovies(EMovie movie[])
{
    int i;

    for (i = 0; i < TAM_MOVIE; i++)
    {
        strcpy(movie[i].titulo, "-");
    }
}

int cargarMovies(EMovie movie[])
{
    FILE *arch;
    int i = 0;


	arch = fopen(ARCH, "r");
	if (!arch)
    {
		printf("No se puede abrir el archivo %s", ARCH);
		return 0;
	}

	while (fread(&movie[i++], sizeof(EMovie), 1, arch) != 0);
	fclose(arch);
	return 1;
}

void generarPagina(EMovie movie[], char nombre[])
{
    FILE *web;
    int i;


	web = fopen(nombre, "w");
	if (!web)
    {
		printf("No se puede abrir el archivo %s", nombre);
	}

    generarCabeceraWebPage(web);

	for (i = 0; i < TAM_MOVIE && strcmp(movie[i].titulo, "-") != 0; i++)
    {
        fprintf(web, "<article class='col-md-4 article-intro'>\n");
        fprintf(web, "<a href='#'>\n");
        fprintf(web, "<img class='img-responsive img-rounded' src='%s' alt=''>", movie[i].linkImagen);
        fprintf(web, "</a>\n");
        fprintf(web, "<h3>\n");
        fprintf(web, "<a href='#'>%s</a>", movie[i].titulo);
        fprintf(web, "</h3>\n");
        fprintf(web, "<ul>\n");
        fprintf(web, "<li>G&eacute;nero: %s</li>\n", movie[i].genero);
        fprintf(web, "<li>Puntaje: %d</li>\n", movie[i].puntaje);
        fprintf(web, "<li>Duraci&oacute;n (min): %d</li>\n", movie[i].duracion);
        fprintf(web, "</ul>\n");
        fprintf(web, "<p>%s</p>\n", movie[i].descripcion);
        fprintf(web, "</article>\n");
    }

    generarPieWebPage(web);
    fclose(web);
}
