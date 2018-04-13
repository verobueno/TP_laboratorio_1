#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Muestra en pantalla un menu de opciones
*\param recibe un entero primer operando para mostrarlo en el print del menu
*\param recibe un entero segundo operando para mostrarlo en el print del menu
*\param recibe un entero de flag para validar el ingreso primer operando
*\param recibe un entero de flag para validar el ingreso segundo operando
*\return no devuelve valor
*/
void mostrarMenu(int, int,int,int);


/** \brief Funcion que permite al usuario ingresar un numero
*\param no recibe valor
*\return retorna un entero con el valor ingresado por el usuario
*/
int ingresarOperando(void);


/** \brief Funcion que suma dos numeros
*\param recibe un entero primer sumando
*\param recibe un entero segundo sumando
*\return retorna un entero con el resultado de la suma de los dos enteros recibidos
*/
int calcularSuma(int, int);


/**\brief Funcion que resta dos numeros
*\param recibe un entero
*\param recibe un entero sustraendo
*\return retorna un entero con el resultado de la resta de los dos enteros recibidos
*/
int calcularResta(int , int );


/** \brief Funcion que divide dos numeros
*\param recibe un entero dividendo
*\param recibe un entero divisor
*\return retorna un flotante con el resultado de la divison de los dos enteros recibidos
*/
float calcularDivision(int ,int );


/** \brief Funcion que multiplica dos numeros
*\param recibe un entero
*\param recibe un entero
*\return retorna un entero con el resultado de la multiplicacion de los dos enteros recibidos
*/
int calcularMultiplicacion(int ,int);



/** \brief Funcion que calcula el factorial de un numero
*\param recibe un entero
*\return retorna un entero resultado del factorial del numero ingresado
*/
int calcularFactorial(int);


#endif // FUNCIONES_H_INCLUDED
