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
    
    int num, cont; // En num se guarda el numero sacado del archivo y cont contara cuantos hay
    char nombre[15]; // Guarda el nombre del archivo
    ifstream file; // Variable tipo archivo de lectura para llamar sus metodos

    // system("cls");     
    cout << "Ingrese el nombre del archivo donde estan los datos (numeros.txt): "; // El archivo debe estar en la carpeta del ejecutable -output-
    cin >> nombre;

    file.open(nombre); // Abre el archivo para extraer datos
    if (file.fail()) { // Chequea que el archivo exista
        cout << "\nEl archivo " << nombre << " no existe";
        // system("PAUSE");
    }
    else { 
        cout << "\nLos numeros que hay en el archivo " << nombre << " son:" << endl;
        cont = 0; // En un comienzo hay cero datos

        while(!file.eof()/* + otras condiciones*/) { // Otra forma de llegar al final del archivo (solo funciona con numeros o caracteres)   
            file >> num; // Al leer el archivo es como un cin (guarda en num lo que encuentre y avanza)
            
            if (!file.eof()) { // Cada vez que se saque o cuente algo, por si hay un salto de linea al final del archivo
                cout << num << " ";
                cont++;
            }
	    }
    }
    file.close(); // Cierra el archivo
    
    cout << "\n\nEl archivo contiene " << cont << " numeros"<<endl;
    // system("PAUSE");

    return 0;
}