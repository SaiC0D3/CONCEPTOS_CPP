/****************************************************************************
* Programa: arreglos_de_estructuras.cpp
* Objetivo: Ejemplificar el uso de arreglos cuyos elementos son estructuras.
* Fecha: 21 de febrero del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
*****************************************************************************/

#include <iostream>
#include <cstring>
#define MAX 30

using namespace std;

struct PAIS {
    char *nombre; // Atributo arreglo de puntero
    char capital[MAX]; // Atributo arreglo comun
    float habitantes;
};

void mostrar_paices(PAIS p[], int n) ;

int main() {

    PAIS Paices[5]; // Definimos la variable de tipo 'struct PAIS' como un arreglo de 5 elementos struct (tambien se puede definir como puntero)
    // PAIS *Paices = (PAIS *) malloc(5, sizeof(PAIS)); // Se castea a un puntero de tipo 'struct PAIS' y el tamaño reservado es de un struct PAIS con sus atributos
    int total;

    cout << "\nIngrese el total de paices a registrar: "; cin >> total;
    cin.ignore();

    for (int i = 0; i < total; i++) { // Con i accedemos a cada posicion del arreglo y con '.' accedemos a los atributos de cada elemento struct
        Paices[i].nombre = (char *) malloc(MAX * sizeof(char)); // Asignamos memoria para el nombre en cada elemento del arreglo
        cout << "\nIngrese nombre del pais " << i + 1 << ": ";
        cin.getline(Paices[i].nombre, MAX, '\n');
        cout << "\nIngrese nombre de la capital del pais " << i + 1 << ": ";
        cin.getline(Paices[i].capital, MAX, '\n');
        cout << "\nIngrese la cantidad de habitantes del pais (en millones): ";
        cin >> Paices[i].habitantes;
        cin.ignore(); // Siempre antesde usar un getline luego de haber usado cin
        cout << endl;
    }

    mostrar_paices(Paices, total);
    cout << endl;

    return 0;
}

void mostrar_paices(PAIS p[], int n) {

    for (int i = 0; i < n; i++) {
        cout << "\n======== Pais " << i + 1 << " =======================================================";
        cout << "\nLa capital de " << p[i].nombre << " es " << p[i].capital << ", con un total de " << p[i].habitantes << " habitantes." << endl;
    }
}