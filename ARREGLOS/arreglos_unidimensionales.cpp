/**************************************************************************************
* Programa: arreglos_unidimensionales.cpp
* Objetivo: Explicar el funcionamiento de los arreglos y cadenas de caracteres.
* Fecha: 20 de febrero del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
***************************************************************************************/

#include <iostream>
#include <cstring> // Se puede usar con arreglos de caracteres o cadenas
#define MAX 10

using namespace std;

void mostrar_arreglo(int arr[]);
void cambiar_valores(int arr[]); // Es necesario especificar que es un arreglo con [] en vez de solo poner el tipo, aunque no es necesario el maximo

int main() {

    int arreglo[MAX]; // La variable 'arreglo' almacena valores de tipo 'int' en 'MAX' espacios de memoria una vez asignado los valores (es un puntero)

    cout << "\nCantidad de bytes por elemento: " << sizeof(int) << endl;

    cout << "\nDireccion de memoria: " << &arreglo << endl; // La variable completa se guarda en la direccion de memoria del primer elemento (indice = 0)

    for (int i = 0; i < MAX; i++) { // Las posiciones de un arreglo de 'n' elementos van desde 0 hasta n - 1
        arreglo[i] = i + 1; // Necesario para asignar las demas direcciones de memoria desde el primer elemento
        cout << "\nDireccion de memoria elemento " << i << ": " << &arreglo[i];
    }

    cout << "\n\n**********************************************************" << endl;

    mostrar_arreglo(arreglo); // Se envia la direccion de memoria de 'arreglo', puesto que la variable es un puntero hacia las demas direcciones

    cout << endl;
    cambiar_valores(arreglo); // No es necesario retornar un nuevo arreglo o los valores nuevos, se cambian en la funcion desde la direccion de memoria
    
    cout << endl;
    mostrar_arreglo(arreglo); // Verificamos el cambio global de 'arreglo'

    cout << "\n\n**********************************************************" << endl;

    // Para cadenas de caracteres se usa un arreglo de tipo 'char' donde el final de la cadena deberia contener el caracter nulo '\0'

    char cadena[20] = {"hola mundo"}; // Se le asigna un 'string' directamente, guarda todo entre "" hasta ocupar el espacio maximo asignado

    for (int i = 0; i < 20; i++) { // Despues de que acabe el string de largo menor a 20, se muestran los caracteres nulos hasta 20
        cout << "\nCaracter " << i << ": " << cadena[i];
    }

    cout << "\n\n**********************************************************" << endl;


    // Para cadenas hechas con arreglos se puede usar cin.getline(arreglo, MAX, 'delimitador') para guardar frases hasta cieto delimitador como \n
    // La variable tipo 'string' no guarda espacios, y se puede obtener simplemente con cin (sin usar arreglos)

    char cadena2[MAX];

    cout << "\nIngrese su nombre: ";
    cin.getline(cadena2, MAX, '\n'); // En este caso, cuando inserte un salto de linea o 'Enter', se termina el string ingresado
    
    char saludo[2*MAX] = "Hola ";
    strcat(saludo, cadena2); // Podemos concatenar el string 'Hola ' con el nombre ingresado (se guarda en saludo)
    cout << "=> " << saludo << "!";

    cout << "\n\n**********************************************************" << endl;

    char cadena3[20] = {'a', 'd', 'i', 'o', 's', ' ', 'm', 'u', 'n', 'd', 'o', '\n', '1'}; // Otra forma de asignarle los caracteres uno por uno
    // Se pueden guardar caracteres especiales como \n, \b, etc. y numeros como caracteres de 1 digito

    for (int i = 0; cadena3[i] != '\0'; i++) { // Con la condicion evitamos mostrar los caracteres nulos no utilizados
        cout << "\nCaracter " << i << ": " << cadena3[i];
    }

    cout << "\n\n**********************************************************" << endl;

    // Esta misma condicion anterior se puede usar para recorrer los elementos del arreglo con un while, ya que el string finaliza con algun \0
    int i = 0;
    char cadena4[MAX] = {}; // Para inicializar la cadena como nula en cada elemento

    cout << "\nIngrese una palabra de a lo mas " << MAX << " letras (terminar con '.'): ";

    char temp;
    while (i < MAX) { // Guarda caracter a caracter hasta encontrar un punto insertado '.' o alcanzar el máximo
        cin >> temp;
        if (temp == '.') { // Asegura que deje de leer caracteres al encontrar un punto
            break;
        }
        cadena4[i] = temp;
        i++;
    }
    cadena4[i] = '\0'; // Asegura el fin de la cadena

    i = 0;
    cout << "\n\nCadena de caracteres: '";
    while (cadena4[i] != '\0') { // Muestra todos los elementos hasta encontrar el caracter nulo final (el '\n' ingresado es el penultimo)
        cout << cadena4[i];
        i++;
    }
    cout << "'";
    
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