/***********************************************************************************
* Programa: punteros_multiples.cpp
* Objetivo: Explicar el uso de punteros dobles y multiples (puntero a otro puntero).
* Fecha: 21 de febrero del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
************************************************************************************/

#include <iostream>

using namespace std;

int main() {

    int **puntero = new int*; // En este caso, 'puntero' almacena la direccion de memoria de otro puntero, el cual almacenara otra direccion (se puede hacer con cuantos '*' queramos)
    // Con 'new' reservamos memoria para otro puntero de tipo 'int'
    // Se pueden definir tantos '*' como se quiera, resguardando reservar memoria correctamente y eleiminandola finalmente

    int num = 100;

    *puntero = &num; // Otraforma es con '*puntero = new int(100);'

    cout << "\nDireccion de memoria del puntero doble: " << &puntero << endl;
    cout << "\nValor (direccion) dentro del puntero doble: " << puntero << endl;

    cout << "\nDireccion de memoria del puntero simple: " << &(*puntero) << endl;
    cout << "\nValor (direccion) dentro del puntero simple: " << &(**puntero) << endl;
    cout << "\nValor dentro del puntero simple: " << **puntero << endl;

    cout << "\nDireccion de memoria del numero " << num << ": " << &num << endl;

    delete *puntero; // Liberamos la memoria del entero
    delete puntero; // Liberamos la memoria del puntero

    return 0;
}
