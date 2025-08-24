/******************************************************************************************
* Programa: redefinir_tipos.cpp
* Objetivo: Ejemplificar el uso de 'typedef' para construir estructuras y tipos redefinidos.
* Fecha: 21 de febrero del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
*******************************************************************************************/

#include <iostream>
#include <cstring>
#define MAX 30

using namespace std;

struct PERSONA { // La estructura es un tipo abstracto de dato que contiene varias memorias de distitnos tipos de datos agrupados segun un objeto
    char nombre[MAX];
    int edad;
};

typedef int Entero; // Ahora podemos declarar una variable de tipo 'Entero' que seria de tipo 'int'
typedef char Arreglo[MAX]; // En este caso podemos declarar una variable de tipo 'Arreglo' que seria de tipo 'char' con 'MAX' elementos
typedef struct PERSONA person; // Asi podemos declarar variables tipo PERSONA sin tanta palabra reservada

int main() {

    Entero numero = 10;

    cout << "\nLa variable de valor " << numero << " es de tipo 'int' con " << sizeof(Entero) << " bytes" << endl;

    Arreglo cadena; // Solo se pueden asignar un maximo de 10 caracteres

    int ASCII = 65; // 'A' en codigo ascii

    for (int i = 0; i < MAX; i++) {
        cadena[i] = ASCII;
        cout << "\nCaracter " << i << ": " << cadena[i] << " (" << ASCII << ")";
        ASCII++;
    }

    cout << "\n\nLa variable de valor " << cadena << " es de tipo 'char' con " << sizeof(Arreglo) / MAX << " bytes" << endl;

    cout << endl;

    // Si definimos otro arreglo desde un arreglo, estaremos generando una matriz

    Arreglo cadenas[5] = {"uno", "dos", "tres", "cuatro", "cinco"}; // Equivale a una matriz de 5 filas y 10 columnas (o 5 cadenas de MAX caracteres), es decir 10 x 5 espacios
    
    for (int i = 0; i < 5; i++) {
        cout << "\nCadena " << i << ": " << cadenas[i] << endl;
        for (int j = 0; cadenas[i][j] != '\0'; j++) {
            cout << "\nCaracter " << j << ": " << cadenas[i][j]; 
        }
        cout << endl;
    }

    person P1; // 'P1' es una variable de tipo 'struct PERSONA'

    /* Asi por defecto no se puede: P1.nombre = "Matias Olivares"; */
    strcpy(P1.nombre, "Matias Olivares"); // Pero podemos uar 'strcpy' o declarar un arreglo como puntero y entonces asignar
    P1.edad = 20; // Con '.' accedemos a los atributos de la estructura

    cout << "\nHola, " << P1.nombre << " de " << P1.edad << " anios." << endl;

    cout << endl;

    return 0;
}