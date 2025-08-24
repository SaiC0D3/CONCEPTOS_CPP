/**************************************************************************************
* Programa: lista_enlazada.cpp
* Objetivo: Crear una lista enlazada mediante estructuras con punteros.
* Fecha: 19 de febrero del 2025
* Autor: Matías Olivares Morales
* Compilador: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
* 
***************************************************************************************/

#include <iostream>

using namespace std;

struct Lista {
    int dato;
    Lista *sgte;
};

Lista* ingresar_ordenado(int, Lista *); // El * despues del tipo es igual que ponerlo antes del nombre (es semantico: para entender que la devolución es puntero)
void mostrar_lista(Lista *);
void liberar_lista(Lista *);

int main() {

    Lista *head = NULL;

    int n, dato;

    cout << "\nCuantos numeros quiere ingresar a la lista? -> "; cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nIngrese un entero a la lista: "; cin >> dato;
        head = ingresar_ordenado(dato, head);
    }

    mostrar_lista(head);
    cout << endl;

    // Liberacion de memoria
    liberar_lista(head);

    return 0;
}

Lista* ingresar_ordenado(int x, Lista *head) {

    Lista *nodo = new Lista;
    Lista *nodo2;

    if (nodo == NULL) {
        cout << "\nNo hay espacio en la memoria para crear la lista completa." << endl;
        return head;
    } 

    nodo->dato = x;
    nodo->sgte = head;

    if (head == NULL || nodo->dato <= head->dato) {
        head = nodo;
    } else {
        nodo2 = head->sgte;
        while (nodo2 != NULL && nodo->dato > nodo2->dato) {
            nodo->sgte = nodo2;
            nodo2 = nodo2->sgte;
        }
        nodo->sgte->sgte = nodo;
        nodo->sgte = nodo2;
    }

    return head;
}

void mostrar_lista(Lista *head) {

    Lista *nodo = head; // Al solo mostrar, no es recomendable asignar nueva memoria

    if (!nodo) {
        cout << "\nLa lista esta vacia.\n" << endl;
    } else {
        cout << endl;
        while (nodo != NULL) {
            cout << nodo->dato << " -> ";
            nodo = nodo->sgte;
        }
        cout << "NULL" << endl;
    }
}

void liberar_lista(Lista *head) {
    while (head != NULL) {
        Lista *temp = head;
        head = head->sgte;
        delete temp;
    }
}
