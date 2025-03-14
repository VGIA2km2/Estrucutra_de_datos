#include "LDE.h"

LDE::LDE() {
    inicio = nullptr;
}

bool LDE::vacia() const {
    return inicio == nullptr;
}

void LDE::insertarPorPosicion(int numero, int posicion) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = numero;
    nuevoNodo->Sig = nullptr;
    nuevoNodo->ant = nullptr;

    if (posicion < 0) {
        cout << "Posición inválida." << endl;
        delete nuevoNodo;
        return;
    }

    if (posicion == 0) { 
        if (vacia()) {
            inicio = nuevoNodo;
        }
        else {
            nuevoNodo->Sig = inicio;
            inicio->ant = nuevoNodo;
            inicio = nuevoNodo;
        }
        return;
    }

    Nodo* aux = inicio;
    int indice = 0;

    
    while (aux != nullptr && indice < posicion - 1) {
        aux = aux->Sig;
        indice++;
    }

    if (aux == nullptr) {
        cout << "Posición fuera de rango." << endl;
        delete nuevoNodo;
        return;
    }

    
    nuevoNodo->Sig = aux->Sig;
    nuevoNodo->ant = aux;

    if (aux->Sig != nullptr) {
        aux->Sig->ant = nuevoNodo;
    }

    aux->Sig = nuevoNodo;
}

void LDE::eliminar(int numero) {
    if (vacia()) {
        cout << "La lista está vacía" << endl;
        return;
    }

    Nodo* aux = inicio;

    while (aux != nullptr && aux->dato != numero) {
        aux = aux->Sig;
    }

    if (aux == nullptr) {
        cout << "El número " << numero << " no está en la lista" << endl;
        return;
    }

    if (aux->ant != nullptr) {
        aux->ant->Sig = aux->Sig;
    }
    else {
        inicio = aux->Sig; 
    }

    if (aux->Sig != nullptr) {
        aux->Sig->ant = aux->ant;
    }

    delete aux;
}

void LDE::imprimir() const {
    if (vacia()) {
        cout << "La lista está vacía" << endl;
        return;
    }

    Nodo* aux = inicio;
    while (aux != nullptr) {
        cout << aux->dato << " ";
        aux = aux->Sig;
    }
    cout << endl;
}

void LDE::limpiar() {
    Nodo* aux = inicio;
    while (aux != nullptr) {
        Nodo* siguiente = aux->Sig;
        delete aux;
        aux = siguiente;
    }
    inicio = nullptr;
}
