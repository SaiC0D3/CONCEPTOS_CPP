/**************************************************************************************
* Programa: funciones_de_punteros.cpp
* Objetivo: Ejemplificar el uso de punteros como parametro o retornos de funciones.
* Fecha: 19 de febrero del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
***************************************************************************************/

#include <iostream>

using namespace std;

int* cambiar_direccion(int *); // La funcion es de tipo puntero 'int', es decir retorna una direccion de memoria para el tipo 'int' (4 bytes)

int main() {

    int *p = new int; // Al inicializar el puntero, el valor dentro de su direccion de meoria es una direccion aleatoria con un valor aleatorio

    cout << "\nEl valor dentro del puntero inicializado es: " << *p << ", en la direccion: " << p << endl; 

    *p = 100;

    cout << "\nEl valor dentro del puntero asignado es: " << *p << ", en la misma direccion: " << p << endl; 

    p = cambiar_direccion(p); // Se guarda en 'p' la direccion retornada por la funcion

    cout << "\nEl nuevo valor dentro del puntero es: " << *p << ", en la nueva direccion (de a): " << p << endl; 
    
    delete p;

    return 0;
}

int* cambiar_direccion(int *p) {

    int *a = new int;

    *a = 200; // Valor dentro del puntero 'a'

    return a; // Se retorna la direccion de memoria de 'a' (= &(*a))
}