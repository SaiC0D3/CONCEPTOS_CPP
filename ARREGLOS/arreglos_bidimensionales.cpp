/******************************************************************************************
* Programa: arreglos_bidimensionales.cpp
* Objetivo: Explicar el funcionamiento de las matrices y arreglos de cadenas de caracteres.
* Fecha: 20 de febrero del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
*******************************************************************************************/

#include <iostream>
#include <cstring> // Se puede usar con areglos de caracteres o cadenas

using namespace std;

#define FILAS 5
#define COLUMNAS 5

void mostrar_matriz(int mat[][COLUMNAS]); // Es necesario especificar al menos la cantidad de columnas (es la cantidad de espacios del segundo puntero)

int main() {

    int matriz[FILAS][COLUMNAS]; // Los arreglos bidimensionales son doble punteros, uno apunta a 'FILAS' espacios de memoria y cada espacio apunta a 'COLUMNAS' espacios
    // En total tenemos FILAS x COLUMNAS espacios de memoria distintos una vez asignados los valores
    /*
        [ ] -> [ ][ ][ ][ ]... COLUMNAS
        [ ] ...
        [ ] ...
        [ ] ...
        ...
        FILAS
    */

    for (int i = 0; i < FILAS; i++) { // Por cada elemento de los 'FILAS' espacios se asignan los 'COLUMNAS' espacios
        for (int j = 0; j < COLUMNAS; j++) { // Cuando la primera fila tiene todas sus columnas asignadas, pasa a la siguiente fila
            matriz[i][j] = j + i;
            cout << "\nDireccion de memoria del elemento (" << i << "," << j << "): " << &matriz[i][j];
        }
    }

    cout << endl;
    mostrar_matriz(matriz);

    // Otra forma de asignar valores numero a numero, dentro de los {} van las 5 filas, cada una con sus 5 columnas dentro de otros {}
    int matriz2[FILAS][COLUMNAS] = { {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}};

    mostrar_matriz(matriz2);

    // Para guardar arreglos donde cada elemento sea una cadena de caracteres usamos:

    // El arreglo 'glosario' puede guardar 5 cadenas de caracteres, cada una con a lo mas 20 caracteres (la inicializacion es diferente con numeros)
    char glosario[5][20] = { "primera", "segunda", "tercera", "cuarta", "quinta" }; // Pueden asignarse frases completas de largo 20
    int largo;

    for (int i = 0; i < 5; i++) { 
        largo = strlen(glosario[i]); // Las cadenas se pueden obtener simpelmente con 'i', si se quiere separar por caracter hace falta el 'j'
        cout << "\nPalabra " << i << ": " << glosario[i] << " (" << largo << " caracteres)" << endl;
        for (int j = 0; glosario[i][j] != '\0'; j++) { 
            cout << "\nCaracter " << j << ": " << glosario[i][j];
        }
        cout << endl;
    }

    return 0;
}

void mostrar_matriz(int mat[FILAS][COLUMNAS]) { // Tambien son recibidos por referencia por lo que los cambios son globales

    cout << endl;
    for (int i = 0; i < FILAS; i++) { 
        for (int j = 0; j < COLUMNAS; j++) { 
            cout << "Elemento (" << i << "," << j << "): " << mat[i][j] << " ";
        }
        cout << endl;
    }
}