#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int a=0;
    int b=0;
    int numero=0;
    int flagA=0;
    int flagB=0;

    while(seguir=='s')
    {
        mostrarMenu(a,b,flagA,flagB);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            a=ingresarOperando(numero);
            flagA=1;
            break;
        case 2:
            b=ingresarOperando(numero);
            flagB=1;
            break;
        case 3:
            if (flagA ==1 && flagB==1)
            {
                printf("La suma A y B es: %d\n",calcularSuma(a,b));
            }
            else
            {
                printf("Faltan datos para realizar la operacion");
            }
            break;
        case 4:
            if (flagA ==1 && flagB==1)
            {
                printf("La resta de A y B es: %d\n",calcularResta(a,b));
            }
            else
            {
                printf("Faltan datos para realizar la operacion");
            }
            break;
        case 5:
            if (flagA ==1 && flagB==1)
            {
                if ( b == 0)
                {
                    printf("Error- no se puede dividir por 0\n");
                }
                else
                {
                    printf("La division de A y B es %.2f\n", calcularDivision(a,b));
                }
            }
            else
            {
                printf("Faltan datos para realizar la operacion");
            }
            break;
        case 6:
            if (flagA ==1 && flagB==1)
            {
                printf("El producto de A y B es: %d\n",calcularMultiplicacion(a,b));
            }
            else
            {
                printf("Faltan datos para realizar la operacion\n");
            }
            break;
        case 7:
            if (flagA ==1)
            {
                printf("El factorial de A es: %d\n", calcularFactorial(a));
            }
            else
            {
                printf("Faltan datos para realizar la operacion\n");
            }
            break;
        case 8:
            if (flagA ==1 && flagB ==1)
            {
                printf("La suma de A y B es: %d\n",calcularSuma(a,b));
                printf("La resta de A y B es: %d\n",calcularResta(a,b));
                printf("El producto de A y B es: %d\n",calcularMultiplicacion(a,b));
                if(b==0)
                {
                    printf("Error- no se puede dividir por 0\n");
                }
                else
                {
                    printf("La division de A y B es %.2f\n", calcularDivision(a,b));
                }
                printf("El factorial de A! es %d\n", calcularFactorial(a));
            }
            else
            {
                printf("Faltan datos para realizar la operacion");
            }
            break;
        case 9:
            seguir = 'n';
            break;
        }
        system("pause");
    }
    return 0;
}
