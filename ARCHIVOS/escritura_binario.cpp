/*****************************************************************************************************
* Programa: escritura_binario.cpp
* Objetivo: Crea un archivo encriptado (archivo binario) con los datos de personas para una lista.
* Fecha: 16 de febrero del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
******************************************************************************************************/

#include<iostream>
#include<fstream> // Libreria para el manejo de archivos
#include<stdlib.h> // o <cstdlib> para llamadas del sistema

using namespace std;

#define MAX 30

struct Persona { // Como va para lista solo hacen falta los struct y no un arreglo, se enlazan con punteros luego
	char nombre[MAX];
	float peso;
	int edad;
};

int main() {

	Persona P; // Variable tipo 'Persona' con tres campos
	ofstream file; // Archivo de salida (escritura en el archivo)
    char nombre[15]; // Guarda el nombre del archivo
    int total;

    // system("cls");     
    cout << "Ingrese el nombre del archivo donde registrar personas (personas.txt): "; // El archivo debe estar en la carpeta del ejecutable -output-
    cin >> nombre;

    do {
        cout << "\nIngrese la cantidad de personas a ingresar (natural): ";
        cin >> total;

        if (total < 0) {
            cout << "\nEl valor que ingreso en valido, intente otra vez." << endl;
        }
	} while (total < 0);

    cin.ignore(); // Para quitar del buffer de entrada (consola) el '\n' al ingresar n

	file.open(nombre, ios::binary); // Abre el archivo para ingresar datos en modo 'ios::binary' (entrada encriptada) - hay otros como ios:app para concatenar 
    for (int i = 0; i < total; i++) {
        cout << "\nIngrese el nombre: ";
        cin.getline(P.nombre, MAX); // Los datos se guardan en memoria primero con "cin >> " ... (se puede delimitar el ingreso ante un slato de linea)
        
        cout << "Ingrese el peso: ";
        cin >> P.peso;

        cout << "Ingrese la edad: ";
        cin >> P.edad;
        cin.ignore(); // Para resetear el buffer de entrada antes de otro cin.getline

        file.write((char *)(&P), sizeof(Persona)); // ... Para luego copiarlos a la estructura 'Persona' como puntero a char (texto en el archivo) con 'write' en vez de "file << "
    }
	file.close();

	return 0;
}