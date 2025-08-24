/*****************************************************************************************************
* Programa: lectura_archivo.cpp
* Objetivo: Lee los datos de un archivo que contiene numeros, ademas indica cuantos hay en el archivo.
* Fecha: 12 de febrero del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
******************************************************************************************************/

#include<iostream>
#include<fstream> // Libreria para el manejo de archivos
#include<stdlib.h> // o <cstdlib> para llamadas del sistema

using namespace std;

int main() {

    int n, num; // En num se guarda el numero sacado del archivo
    char nombre[15]; // Guarda el nombre del archivo
    ofstream file; // Variable tipo archivo de escritura para llamar sus metodos

    // system("cls");     
    cout << "Ingrese el nombre del archivo donde poner datos (.txt): "; // El archivo debe estar en la carpeta del ejecutable -output-
    cin >> nombre;

    file.open(nombre); // Abre el archivo para registrar datos
    if (file.fail()) { // Chequea que el archivo exista
        cout << "\nEl archivo " << nombre << " no existe";
        system("PAUSE");
    }
    else { 
        cout << "\nIngrese la cantidad de numeros enteros a ingresar: ";
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            cout<<"\nIngrese un dato: ";
            cin >> num; // Se guarda el valor en una variable y despues se escribe en el archivo

            file << num << "\n"; // Al escribir en el archivo es igual que un cout (terminara con un salto de linea extra)
        }
        // system("PAUSE");
    }
    file.close(); // Cierra el archivo

    cout << "\nArchivo creado con exito!" << endl;
    system("PAUSE");

    return 0;
}