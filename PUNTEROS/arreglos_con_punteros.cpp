/******************************************************************************************
* Programa: arreglos_con_punteros.cpp
* Objetivo: Ejemplificar el uso de punteros para crear arreglos de memoria contigua.
* Fecha: 20 de febrero del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
*******************************************************************************************/


#include <iostream>
#include <cstring>
#define MAX 10

using namespace std;

void mostrar_arreglo(int arr[]); // Ambas declaraciones funcionan, al final es exactamente lo mismo con otra notacion para arreglos
void mostrar_arreglo_puntero(char *);

int main() {

    // La funcion 'malloc' debe castearse al tipo de puntero de la variable, y como parametro recibe el total de espacios a crear, asignandoles basura
    int *arreglo = (int *) malloc(MAX * sizeof(int)); // La variable 'arreglo' es un puntero que almacenara la direccion de memoria de MAX espacios de tipo 'int' 
    // malloc retorna void*, por eso lo casteas (en C++ no es necesario el cast, en C si)

    // La diferencia con declararlo como 'int arreglo[MAX]' es que las direcciones de memoria generalmente seran contiguas (mayor rapidez de ejecucion),
    // en cambio la otra forma ocupa dispersos espacios memoria disponible. Ademas, no hace falta asignar valores para que se asignes las direcciones

    mostrar_arreglo(arreglo);

    cout << endl;
    cout << "\nDireccion de memoria del arreglo: " << &arreglo << endl;

    for (int i = 0; i < MAX; i++) {
        arreglo[i] = i * i; // Para acceder a las posisiones de memoria es de igual forma con [] y los indices
        cout << "\nDireccion de memoria del elemento " << i << ": " << &arreglo[i];
    }

    cout << endl;
    mostrar_arreglo(arreglo);

    // La funcion 'calloc' funciona igual, con la diferencia de que los parametros separa el total del tipo con ',' e inicializa la memoria en 0 en numeros y '\0' en caracteres
    char *cadena = (char *) calloc(20, sizeof(char));
    // calloc retorna void*, por eso lo casteas (en C++ no es necesario el cast, en C si)

    cout << endl;
    mostrar_arreglo_puntero(cadena);

    strcpy(cadena, "hola mundo"); // Solo guarda una cantidad de caracteres menor o igual a 20 (el '\0' final tambien ocupa 1 espacio)

    cout << endl;
    mostrar_arreglo_puntero(cadena);
    cout << endl;   

    free(arreglo); // Hay que liberar la memoria asignada con 'calloc' o 'malloc'
    free(cadena);

    // En C++ moderno, lo más recomendable es usar std::string en lugar de manejar memoria manualmente

    return 0;
}

void mostrar_arreglo(int arr[]) { // Se puede definir el parametro con [] o como puntero al tipo de dato del arreglo puntero

    for (int i = 0; i < MAX; i++) {
        cout << "\nElemento " << i << ": " << arr[i];
    }
}

void mostrar_arreglo_puntero(char *arr) {

    for (int i = 0; i < MAX; i++) {
        cout << "\nCaracter " << i << ": " << arr[i];
    }
}