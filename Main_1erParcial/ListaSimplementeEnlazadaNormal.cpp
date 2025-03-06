#include "ListaSimplementeEnlazadaNormal.h"

ListaSimplementeEnlazada::ListaSimplementeEnlazada() {
    inicio = nullptr;
}


bool ListaSimplementeEnlazada::vacia() const {
    return inicio == nullptr;
}


void ListaSimplementeEnlazada::inicializa(int numero) {
    inicio = new Nodo;
    inicio->dato = numero;
    inicio->Sig = nullptr;  
}


void ListaSimplementeEnlazada::agregar(int numero) {
    if (vacia()) {
        inicializa(numero);
    }
    else {
        Nodo* NuevoNodo = new Nodo;
        NuevoNodo->dato = numero;
        NuevoNodo->Sig = nullptr;

        Nodo* aux = inicio;
        Nodo* prev = nullptr;


        while (aux != nullptr && aux->dato < numero) {
            prev = aux;
            aux = aux->Sig;
        }

        if (prev == nullptr) {  
            NuevoNodo->Sig = inicio;
            inicio = NuevoNodo;
        }
        else {  
            prev->Sig = NuevoNodo;
            NuevoNodo->Sig = aux;
        }
    }
}


void ListaSimplementeEnlazada::eliminar(int numero) {
    if (vacia()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Nodo* aux = inicio;
    Nodo* prev = nullptr;

    while (aux != nullptr && aux->dato != numero) {
        prev = aux;
        aux = aux->Sig;
    }

    if (aux == nullptr) { 
        cout << "El numero " << numero << " no esta en la lista" << endl;
        return;
    }

    if (prev == nullptr) { 
        inicio = inicio->Sig;
    }
    else { 
        prev->Sig = aux->Sig;
    }

    delete aux;
}

void ListaSimplementeEnlazada::imprimir() const {
    if (vacia()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Nodo* aux = inicio;
    while (aux != nullptr) {
        cout << aux->dato << " ";
        aux = aux->Sig;
    }
    cout << endl;
}

void ListaSimplementeEnlazada::limpiar() {
    Nodo* aux = inicio;
    while (aux != nullptr) {
        Nodo* siguiente = aux->Sig;
        delete aux;
        aux = siguiente;
    }
    inicio = nullptr;
}