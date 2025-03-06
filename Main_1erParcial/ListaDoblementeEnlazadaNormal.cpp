#include "ListaDoblementeEnlazadaNormal.h"

ListaDoblementeEnlazadaNormal::ListaDoblementeEnlazadaNormal() {
    cabeza = nullptr;
}


bool ListaDoblementeEnlazadaNormal::vacia() const {
    return cabeza == nullptr;
}


void ListaDoblementeEnlazadaNormal::inicializa(int numero) {
    cabeza = new Nodo;
    cabeza->dato = numero;
    cabeza->Sig = nullptr;
    cabeza->ant = nullptr;
}


void ListaDoblementeEnlazadaNormal::agregar(int numero) {
    if (vacia()) {
        inicializa(numero);
    }
    else {
        Nodo* NuevoNodo = new Nodo;
        NuevoNodo->dato = numero;
        NuevoNodo->Sig = nullptr;
        NuevoNodo->ant = nullptr;

        Nodo* aux = cabeza;
        Nodo* prev = nullptr;


        while (aux != nullptr && aux->dato < numero) {
            prev = aux;
            aux = aux->Sig;
        }

        if (prev == nullptr) {
            NuevoNodo->Sig = cabeza;
            cabeza->ant = NuevoNodo;
            cabeza = NuevoNodo;
        }
        else {
            prev->Sig = NuevoNodo;
            NuevoNodo->ant = prev;
            NuevoNodo->Sig = aux;
            aux->ant = NuevoNodo;
        }
    }
}


void ListaDoblementeEnlazadaNormal::eliminar(int numero) {
    if (vacia()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Nodo* aux = cabeza;
    Nodo* prev = nullptr;

    while (aux != nullptr && aux->dato != numero) {
        prev = aux;
        aux = aux->Sig;
    }

    if (aux == nullptr) {
        cout << "El numero " << numero << " no esta en la lista" << endl;
        return;
    }
    else if (prev == nullptr) {
        cabeza = cabeza->Sig;
        if (cabeza->Sig != nullptr) {
            cabeza->ant = nullptr;
        }
    }
    else {
        prev->Sig = aux->Sig;
        aux->Sig->ant = prev;
    }

    delete aux;
}

void ListaDoblementeEnlazadaNormal::imprimir() const {
    if (vacia()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Nodo* aux = cabeza;
    while (aux != nullptr) {
        cout << aux->dato << " ";
        aux = aux->Sig;
    }
    cout << endl;
}

void ListaDoblementeEnlazadaNormal::limpiar() {
    Nodo* aux = cabeza;
    while (aux != nullptr) {
        Nodo* siguiente = aux->Sig;
        delete aux;
        aux = siguiente;
    }
    cabeza = nullptr;
}