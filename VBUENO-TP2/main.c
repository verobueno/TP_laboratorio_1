#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char opcion;
    ePersona persona[TAM_LISTA];

    InicializarPersona(persona);

    do
    {
        MostrarMenu();
        opcion = getc(stdin);

        switch (opcion)
        {
        case '1':   // Alta de personas
                    AgregarPersona(persona);
                    system("pause");
                    break;
        case '2':   // Borrar una perssona de la lista
                    BorrarPersona(persona);
                    system("pause");
                    break;
        case '3':   // Imprimir la lista de personas por orden alfabetico
                    ImprimirListaPersonas(persona);
                    system("pause");
                    break;
        case '4':   // Ingreso de Automovil
                    GraficarEdades(persona);
                    system("pause");
                    break;
        }
    } while (opcion != 's' && opcion != 'S');
    return 0;
}
