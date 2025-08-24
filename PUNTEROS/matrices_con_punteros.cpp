/***************************************************************************************************
* Programa: matrices_con_punteros.cpp
* Objetivo: Ejemplificar el uso de punteros para crear arreglos bidimensionales de memoria contigua.
* Fecha: 21 de febrero del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
****************************************************************************************************/

#include <iostream>
#define FILAS 5
#define COLUMNAS 5 

using namespace std;

void mostrar_matriz(int **);

int main() {

    // Usamos 'calloc' para inicializar los elementos en 0
    int **matriz = (int **) calloc(FILAS, sizeof(int)); // La variable 'matriz' es un doble puntero, primero asignamos espacio a las filas... 
    for (int i = 0; i < FILAS; i++) { 
        matriz[i] = (int *) calloc(COLUMNAS, sizeof(int)); // ... Y por cada espacio de fila creado, asignamos memoria a las columnas
    }

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if(i == j) {
                matriz[i][j] = 1;
            } // No hace falta el 'else {matriz[i][j] = 0;} al haberlos inicializadas ya en 0
        }
    }
    
    /* Para las filas se hace un casteo a doble puntero, mientras que las columnas solo de punteros simples:

        matriz (doble puntero ** a 5 filas)
        |
        |
        |─> matriz[0] (puntero simple * a 5 columnas) ──> matriz[0][0] ... matriz[0][COLUMNAS-1]
        |      .
        |      .
        |      .
        └─> matriz[FILAS-1] (puntero simple * a 5 columnas) ──> matriz[FILAS-1][0] ... matriz[FILAS-1][COLUMNAS-1]

    */

    cout << endl;
    mostrar_matriz(matriz);
    cout << endl;   

    for (int j = 0; j < COLUMNAS; j++) {
        free(matriz[j]); // Eliminamos primero la memoria de columnas de cada fila
    }
    free(matriz); // Luego eliminamos las filas por completo (orden inverso a cuando se reservo la memoria dinamica)

    return 0;
}

void mostrar_matriz(int **matriz) {

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout  << matriz[i][j] << " ";
        }
        cout << endl;
    }
}