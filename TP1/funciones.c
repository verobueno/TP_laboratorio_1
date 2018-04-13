#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int ingresarOperando(int numero)
{
    int number;
    printf("Ingresar Operando: ");
    scanf("%d",&number);
    return number;
}

int calcularSuma(int a, int b)
{
    int suma;

    suma=a+b;

    return suma;
}

int calcularResta(int a, int b)
{
    int resta=0;

    resta=a-b;

    return resta;
}
float calcularDivision(int a,int b)
{
    float division;

    division=a/(float)b;

    return division;
}
int calcularMultiplicacion(int a,int b)
{
    int multiplicacion=0;

    multiplicacion=a*b;

    return multiplicacion;
}

int calcularFactorial(int a)
{
    int retorno=1;
    int i;
    if ( a <= 0)
    {
        printf("error- solo admite positivos");
    }
    else
    {
        for(i=a; i>1; i--)
        {
            retorno=retorno*i;
        }
    }

    return retorno;
}

void mostrarMenu(int a, int b,int flagA,int flagB)
{
    system("cls");
    if (flagA == 1)
    {
        printf("1- Ingresar 1er operando (A = %d)\n", a);
    }
    else
    {
        printf("1- Ingresar 1er operando (A = x)\n");
    }
    if ( flagB == 1)
    {
        printf("2- Ingresar 2do operando (B = %d)\n", b);
    }
    else
    {
        printf("2- Ingresar 2do operando (B = y)\n");
    }
    printf("3- Calcular la suma (A+B)\n");
    printf("4- Calcular la resta (A-B)\n");
    printf("5- Calcular la division (A/B)\n");
    printf("6- Calcular la multiplicacion (A*B)\n");
    printf("7- Calcular el factorial (A!)\n");
    printf("8- Calcular todas las operaciones\n");
    printf("9- Salir\n");
    printf("Ingrese opcion:");

}
