/***********************************************************************************************
* Programa: ISPRIME.h (archivo de cabecera, funciona como una libreria)
* Objetivo: Determinar si un numero es primo o no
* Fecha: 03 de febrero del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
************************************************************************************************/

int esPrimo(int num) { // Funcion que determina si un numero es primo o no (retorna 1 si es primo, 0 si no): podriamos usar un bool

    if (num == 1) { // Si el numero es 1, entonces no es primo
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) { // Si el numero es primo, entonces no tiene divisores mayores a su mitad
        if (num % i == 0) {
            return 0; // Si tiene algun divisor distinto de 1 y si mismo, entonces no es primo
        }
    }

    return 1; // Si no tiene divisores distintos de 1 y si mismo (ya recorrio todos los posibles divisores), entonces es primo
}