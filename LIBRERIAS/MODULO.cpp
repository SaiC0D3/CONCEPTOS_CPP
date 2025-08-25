/***********************************************************************************************
* Programa: MODULO.cpp ("segunda parte" del archivo cabecera ISPRIME.h)
* Objetivo: Determinar si un numero ingresado es primo o no utilizando funciones externas
* Fecha: 24 de agosto del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
************************************************************************************************/

#include <iostream>
#include "ISPRIME.h" // Se obtienen todas las lineas de codigo del programa entre comillas

using namespace std;

int main() {
    int num;

    cout << "Ingrese un numero entero: "; cin >> num;

    if (!esPrimo(num)) { // Se llama a la funcion definida en el archivo cabecera como si fuera del propio programa
        cout << "\nEl numero " << num << " no es primo" << endl;
    } else {
        cout << "\nEl numero " << num << " si es primo" << endl;
    }

    return 0;
}