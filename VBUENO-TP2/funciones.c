#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


void MostrarMenu(void)
{
    system("cls");
    printf("\tDistribucion por Edades - Menu de Opciones\n\n");
    printf("1 - Alta de Persona\n");
    printf("2 - Borrar Persona\n");
    printf("3 - Imprimir Lista de Personas\n");
    printf("4 - Graficar Edades\n\n");
    printf("S - Salir\n\n");
    printf("Ingrese Opcion: ");
}



void InicializarPersona(ePersona persona[])
{
    int i;

    for (i = 0; i < TAM_LISTA; i++)
    {
        persona[i].estado = LIBRE;
    }
    strcpy(persona[0].nombre, "Martin");
    persona[0].estado = OCUPADO;
    persona[0].dni = 28357239;
    persona[0].edad = 48;
    strcpy(persona[3].nombre, "Veronica");
    persona[3].estado = OCUPADO;
    persona[3].dni = 23570504;
    persona[3].edad = 44;
    strcpy(persona[10].nombre, "Dolores");
    persona[10].estado = OCUPADO;
    persona[10].dni = 53532523;
    persona[10].edad = 37;
    strcpy(persona[6].nombre, "Zoe");
    persona[6].estado = OCUPADO;
    persona[6].dni = 2523225;
    persona[6].edad = 16;
    strcpy(persona[19].nombre, "Teresa");
    persona[19].estado = OCUPADO;
    persona[19].dni = 5559322;
    persona[19].edad = 78;
    strcpy(persona[2].nombre, "Juan");
    persona[2].estado = OCUPADO;
    persona[2].dni = 6436434;
    persona[2].edad = 12;
    strcpy(persona[9].nombre, "Pedro");
    persona[9].estado = OCUPADO;
    persona[9].dni = 232666;
    persona[9].edad = 33;
    strcpy(persona[1].nombre, "Jeremias");
    persona[1].estado = OCUPADO;
    persona[1].dni = 385235;
    persona[1].edad = 22;
    strcpy(persona[4].nombre, "Irene");
    persona[4].estado = OCUPADO;
    persona[4].dni = 66433;
    persona[4].edad = 55;
    strcpy(persona[5].nombre, "Alison");
    persona[5].estado = OCUPADO;
    persona[5].dni = 853259;
    persona[5].edad = 3;
    strcpy(persona[7].nombre, "Kevin");
    persona[7].estado = OCUPADO;
    persona[7].dni = 353232;
    persona[7].edad = 17;
    strcpy(persona[8].nombre, "Santiago");
    persona[8].estado = OCUPADO;
    persona[8].dni = 5825322;
    persona[8].edad = 37;
    strcpy(persona[11].nombre, "Paloma");
    persona[11].estado = OCUPADO;
    persona[11].dni = 532532;
    persona[11].edad = 25;
    strcpy(persona[12].nombre, "Ema");
    persona[12].estado = OCUPADO;
    persona[12].dni = 66364322;
    persona[12].edad = 28;
    strcpy(persona[18].nombre, "Mateo");
    persona[18].estado = OCUPADO;
    persona[18].dni = 3323252;
    persona[18].edad = 21;
    strcpy(persona[17].nombre, "Agustin");
    persona[17].estado = OCUPADO;
    persona[17].dni = 653222;
    persona[17].edad = 25;
    strcpy(persona[16].nombre, "Dante");
    persona[16].estado = OCUPADO;
    persona[16].dni = 76543245;
    persona[16].edad = 19;
    strcpy(persona[15].nombre, "Matilde");
    persona[15].estado = OCUPADO;
    persona[15].dni = 4446645;
    persona[15].edad = 34;
}

int BuscarLugarLibre(ePersona persona[])
{
    int i;
    int posicion = -1;

    for (i = 0; i < TAM_LISTA; i++)
    {
        if (persona[i].estado == LIBRE)
        {
            posicion = i;
            break;
        }
    }
    return posicion;

}



void AgregarPersona(ePersona persona[])
{
    int posicion;

    posicion = BuscarLugarLibre(persona);
    if (posicion >= 0)
    {
        printf("Introduzca los datos de la Persona\n");
        persona[posicion].estado = OCUPADO;
        printf("Nombre: ");
        scanf("%s", persona[posicion].nombre);
        printf("DNI: ");
        scanf("%d", &persona[posicion].dni);
        printf("Edad: ");
        scanf("%d", &persona[posicion].edad);
    }
    else
    {
        printf("La lista de Personas esta completa\n");
    }
    printf("\n");
}


void BorrarPersona(ePersona persona[])
{
    int i;
    char nombre[TAM_NOMBRE];
    char respuesta;

    printf("Ingrese el nombre de la persona a eliminar\n");
    printf("Nombre: ");
    scanf("%s", nombre);

    for (i = 0; i < TAM_LISTA; i++)
    {
        if (persona[i].estado == OCUPADO && strcmp(nombre, persona[i].nombre) == 0)
        {
            printf("Esta seguro que desea borrar a %s? (s/n): ", persona[i].nombre);
            respuesta=getch();

            if (respuesta == 's')
            {
                persona[i].estado = LIBRE;
                printf("\nPersona eliminada\n\n");
                break;
            }
            else
            {
                printf("\nNo se borro a %s\n ", persona[i].nombre);
            }

        }
    }
}

void Intercambiar(ePersona persona[], int i, int j)
{
    ePersona auxiliar;

    auxiliar.estado = persona[i].estado;
    auxiliar.edad = persona[i].edad;
    auxiliar.dni = persona[i].dni;
    strcpy(auxiliar.nombre, persona[i].nombre);

    persona[i].estado = persona[j].estado;
    persona[i].edad = persona[j].edad;
    persona[i].dni = persona[j].dni;
    strcpy(persona[i].nombre, persona[j].nombre);

    persona[j].estado = auxiliar.estado;
    persona[j].edad = auxiliar.edad;
    persona[j].dni = auxiliar.dni;
    strcpy(persona[j].nombre, auxiliar.nombre);
}

void OrdenarPersonas(ePersona persona[])
{
    int i;
    int j;

    // Ordeno la lista aunque este LIBRE ya que es mas sencillo
    for (i = 0; i < TAM_LISTA - 1; i++)
    {
        for (j = i + 1; j < TAM_LISTA; j++)
        {
            if (strcmp(persona[i].nombre, persona[j].nombre) > 0)
            {
                Intercambiar(persona, i, j);
            }
        }
    }
}

void ImprimirListaPersonas(ePersona persona[])
{
    int i;

    OrdenarPersonas(persona);
    for (i = 0; i < TAM_LISTA; i++)
    {
        if (persona[i].estado == OCUPADO)
        {
            printf("%30s  -  DNI: %8d\tEdad: %3d\n", persona[i].nombre, persona[i].dni, persona[i].edad);
        }
    }
    printf("\n");
}

void GraficarEdades(ePersona persona[])
{
    char rango[CANT_BARRAS][TAM_LISTA];
    int i;
    int max = 0;
    int ninos = 0;
    int jovenes = 0;
    int adultos = 0;

    // vacio las barras
    for (i = 0; i < TAM_LISTA; i++)
    {
        rango[NINOS][i] = ' ';
        rango[JOVENES][i] = ' ';
        rango[ADULTOS][i] = ' ';
    }

    // Armo la matriz con ' ' o '*'
    for (i = 0; i < TAM_LISTA; i++)
    {
        //valido que este dado de alta
        if (persona[i].estado == OCUPADO)
        {
            if (persona[i].edad < 19)
            {
                rango[NINOS][ninos] = '*';
                ninos++;
                if (max < ninos)
                {
                    max = ninos;
                }
            }
            else if (persona[i].edad < 36)
            {
                rango[JOVENES][jovenes] = '*';
                jovenes++;
                if (max < jovenes)
                {
                    max = jovenes;
                }
            }
            else
            {
                rango[ADULTOS][adultos] = '*';
                adultos++;
                if (max < adultos)
                {
                    max = adultos;
                }
            }
        }
    }

    printf("\n\n\tGrafico de Distribucion por Edades\n");
    for (i = max; i >= 0; i--)
    {
        printf("\t%c\t\t%c\t\t%c\n", rango[NINOS][i], rango[JOVENES][i], rango[ADULTOS][i]);

    }
    printf("Menores de 19\tEntre 19 y 35\tMayores de 35\n\n");

}

