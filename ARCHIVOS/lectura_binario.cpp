/*****************************************************************************************************
* Programa: archivo_binario.cpp
* Objetivo: Lee un archivo encriptado (archivo binario) con los datos de personas para una lista.
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

struct Persona { // Como va para lista solo hacen palta los struct y no un arreglo, se enlazan con punteros luego
	char nombre[MAX];
	float peso;
	int edad;
};

int main() {

	Persona P;
	int i = 0; // Para contar el total de registros
	ifstream file;

	file.open("personas.txt", ios::binary); // Abre el archivo en modo 'ios::binary' para desencriptarlo y mostrar su contenido
	if(file.fail()){
        cerr << "\tERROR, el archivo 'personas.txt' no existe\n" << endl;
        exit(1); // En lugar de return para determinar una salida de error y no un retorno normal
	}

	while(!file.eof()){
		file.read((char *)(&P), sizeof(Persona)); // Leemos desde el archivo con 'read' en lugar de "file >> " para obtener los registros de la estructura completa por cada uno

		if(!file.eof()) { // Si no es el final del archivo, mostramos lo que acabamos de sacar del archivo dentro de los campos de la estructura
			cout << "\n================ PERSONA " << i + 1 <<" =================" << endl;
			cout << "\nNombre: ";
			cout << P.nombre;
			cout << "\nPeso: ";
			cout << P.peso;
			cout << "\nEdad: ";
			cout << P.edad;
		}

		i++;
		cout << "\n";
	}
	file.close();

	return 0;
}
