/**************************************************************************************
* Programa: arreglos_unidimensionales.cpp
* Objetivo: Explicar el funcionamiento de los arreglos y cadenas de caracteres.
* Fecha: 20 de febrero del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
***************************************************************************************/

#include <iostream>
#include <cstring> // Se puede usar con areglos de caracteres o cadenas
#define MAX 10

using namespace std;

void mostrar_arreglo(int arr[]);
void cambiar_valores(int arr[]); // Esnecesario especificar que es un arreglo con [] en vez de solo poner el tipo, aunque no es necesario el maximo

int main() {

    int arreglo[MAX]; // La variable 'arreglo' almacena valores de tipo 'int' en 'MAX' espacios de memoria una vez asignado los valores (es un puntero)

    cout << "\nCantidad de bytes por elemento: " << sizeof(int) << endl;

    cout << "\nDireccion de memoria: " << &arreglo << endl; // La variable completa se guarda en la direccion de memoria del primer elemento

    for (int i = 0; i < MAX; i++) { // Las posiciones de un arreglo de 'n' elementos van desde 0 hasta n - 1
        arreglo[i] = i + 1; // Necesario para asignar las demas direcciones de memoria desde el primer elemento
        cout << "\nDireccion de memoria elemento " << i << ": " << &arreglo[i];
    }

    cout << "\n\n**********************************************************" << endl;

    mostrar_arreglo(arreglo); // Se envia la direccion de memoria de arreglo, puesto que la variable es un puntero hacia las demas direcciones

    cout << endl;
    cambiar_valores(arreglo); // No es necesario retornar un nuevo arreglo o los valores nuevos, se cambian en la funcion desde la direccion de memoria
    
    cout << endl;
    mostrar_arreglo(arreglo); // Verificamos el cambio global

    cout << "\n\n**********************************************************" << endl;

    // Para cadenas de caracteres se usa un arreglo de tipo 'char' donde el final de la cadena deberia contener el caracter nulo '\0'

    char cadena[20] = {"hola mundo"}; // Se le asigna un 'string' directamente, guarda todo entre "" hasta ocupar el espacio maximo asignado

    for (int i = 0; i < 20; i++) { // Despues de que acabe el string, se muestran los caracteres nulos hasta 20
        cout << "\nCaracter " << i << ": " << cadena[i];
    }

    // Para cadenas hechas con arreglos se puede usar cin.getline(arreglo, MAX, 'delimitador') para guardar frases hasta cieto delimitador como \n
    // La variable tipo 'string' no guarda espacios, y se puede obtener simplemente con cin

    cout << "\n\n**********************************************************" << endl;

    char cadena2[20] = {'a', 'd', 'i', 'o', 's', ' ', 'm', 'u', 'n', 'd', 'o', '\n', '1'}; // Otra forma de asignarle los caracteres uno por uno
    // Se pueden guardar caracteres especiales como \n, \b, etc. y numeros como caracteres de 1 digito

    for (int i = 0; cadena2[i] != '\0'; i++) { // Con la condicion evitamos mostrar los caracteres nulos no utilizados
        cout << "\nCaracter " << i << ": " << cadena2[i];
    }
    
    cout << endl;

    return 0;
}

void mostrar_arreglo(int arr[]) { // Se puede o no indicar el maximo del arreglo

    for (int i = 0; i < MAX; i++) {
        cout << "\nElemento " << i << ": " << arr[i];
    }
}

void cambiar_valores(int arr[MAX]) { // Como los arreglos se envian por referencia al ser punteros, lo que se cambie en una funcion local afecta globalemnte

    for (int i = 0; i < MAX; i++) {
        arr[i] = i * 2; // Necesario para asignar las demas direcciones de memoria desde el primer elemento
        cout << "\nNuevo elemento " << i << ": " << arr[i];
    }
} 