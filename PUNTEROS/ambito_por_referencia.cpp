/**************************************************************************************
* Programa: ambito_por_referencia.cpp
* Objetivo: Ejemplificar el paso de variables por referencia, en ambito local y global.
* Fecha: 19 de febrero del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
***************************************************************************************/

#include <iostream>

using namespace std;

void cambiar_valor(int &); // El parametro de la funcion recibe una direccion de memoria de una variable de cierto tipo

int main() {

    int *puntero = new int; // Variable que almacena direcciones de memoria (en hexadecimal) para variables de un cierto tipo
    //                         se almacena en una direccion de memoria también por lo que se inicializa un espacio de memoria de tipo 'int' con 'new'
    int a; // Se puede declarar junto al puntero de las formas: 'int *puntero, a;' o 'int* puntero, a;' (solo el primero es puntero)

    a = 100;

    *puntero = a; // con '*' accedemos al valor dentro de la direccion de memoria del puntero, para reasignar o obtener su valor

    cout << "\nEl valor dentro del puntero (paso por valor) es: " << *puntero << endl;

    cout << "\nEl valor de 'a' es: " << a; 

    cambiar_valor(a); // Mandamos 'a' para obtener su direccion de memoria en la funcion

    cout << "\nEl nuevo valor de 'a' es: " << a << endl;

    // Para asignarle un valor directamente a un puntero debemos asignarle direcciones de memoria con '&'

    int b = 200;

    puntero = &b; // Almacenamos la direccion de 'b' en 'puntero', pudiendo obtener su valor o cambiarlo sin usar copias sino el original

    cout << "\nEl valor dentro del puntero (paso por referencia) es: " << *puntero;
    cout << "\nLa direccion de memoria dentro del puntero es: " << &(*puntero); // O simplemente 'puntero'
    cout << "\nLa direccion de memoria de b es: " << &b;
    cout << "\nLa direccion de memoria del puntero es: " << &puntero << endl;

    // Como 'puntero' tiene la direccion de 'b', lo que se cambie en 'puntero' se cambia en 'b'

    *puntero = 500; // Accedemos al valor dentro del 'puntero', en este caso el valor dentro de la direccion de 'b'

    cout << "\nEl nuevo valor de b es: " << b << endl;

    cout << endl;

    delete puntero; // Limpiamos el espacio de memoria asignado para el puntero luego de usarlo (no es realmente necesario en estos casos)

    return 0;
}

// OBS: los arreglos 'a[MAX]' ya se pasan por referencia (al declarar uno se crean espacios de memoria pero todos asigandos a una direccion incial)
//      por lo que todo lo que se cambie de un arreglo en una funcion se cambia en otra que la llama
void cambiar_valor(int &a) {

    a = 300; // Cambiamos el valor dentro de la direccion de memoria recibida
}
