/***********************************************************************************
* Programa: ambito_por_valor.cpp
* Objetivo: Ejemplificar el paso de variables por valor, en ambito local y global.
* Fecha: 19 de febrero del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
************************************************************************************/

#include <iostream>

using namespace std;

int var_global = 0; // El alcance de esta variable es dentro de todo el programa

// En el prototipo no hace falta darle identificador a los parametros, solo es necesario el tipo
void cambiar_valor(int); // El parametro de la funcion recibe un valor de tipo entero, mas no la direccion de una variable
int reemplazar_valor();

int main() {

    int var_local = 100; // El alcance de esta variable es dentro de 'main' unicamente

    cout << "\nEl valor de la variable global es: " << var_global << endl;

    cambiar_valor(var_local); // Se manda una copia del valor de 'var_local', mas no la direccion real de la variable

    cout << "\nEl valor de la variable en 'main' es: " << var_local << endl;

    // Para cambiar el valor de una variable local, se puede reasignar un valor retornado por una funcion (se hacen copias entre las variables)

    var_local = reemplazar_valor(); // Se copia el valor retornado por la funcion en 'var_local', logrando camibiar su valor al reasignarlo uno nuevo 

    cout << "\nEl nuevo valor de la variable en 'main' es: " << var_local << endl;

    // Las variables globales pueden ser reasignadas en cualquier funcion

    cout << "\nEl nuevo valor de la variable global es: " << var_global << endl; // El valor cambio luego de llamar la funcion 'cambiar_valor'
    cout << endl;

    return 0;
}

void cambiar_valor(int a) { // El parametro 'a' es una variable distinta (otra dir. en la RAM) que copia el valor pasado en su llamada

    a = 200;
    var_global = 1; // No hace falta declararla dentro de la funcion al ser global

    cout << "\nEl valor de la variable en la funcion es: " << a << endl;
}

int reemplazar_valor() {

    int a = 200;

    return a;
}