#include "ListaSimplementeEnlazadaCircular.h"

ListaSimplementeEnlazadaCircular::ListaSimplementeEnlazadaCircular() {
    inicio = nullptr;
}

bool ListaSimplementeEnlazadaCircular::vacia() const {
    return inicio == nullptr;
}

void ListaSimplementeEnlazadaCircular::inicializa(int numero) {
    inicio = new Nodo;
    inicio->dato = numero;
    inicio->Sig = inicio; 
}

void ListaSimplementeEnlazadaCircular::agregar(int numero) {
    if (vacia()) {
        inicializa(numero);
    }
    else {
        Nodo* NuevoNodo = new Nodo;
        NuevoNodo->dato = numero;

        Nodo* aux = inicio;
        Nodo* prev = nullptr;

        do {
            prev = aux;
            aux = aux->Sig;
        } while (aux != inicio && aux->dato < numero);

        if (prev == aux) { 
            Nodo* ultimo = inicio;
            while (ultimo->Sig != inicio) {
                ultimo = ultimo->Sig;
            }
            NuevoNodo->Sig = inicio;
            inicio = NuevoNodo;
            ultimo->Sig = inicio;
        }
        else {
            prev->Sig = NuevoNodo;
            NuevoNodo->Sig = aux;
        }
    }
}

void ListaSimplementeEnlazadaCircular::eliminar(int numero) {
    if (vacia()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Nodo* aux = inicio;
    Nodo* prev = nullptr;

    do {
        if (aux->dato == numero) {
            if (aux == inicio) {
                if (inicio->Sig == inicio) {
                    delete inicio;
                    inicio = nullptr;
                }
                else {
                    Nodo* ultimo = inicio;
                    while (ultimo->Sig != inicio) {
                        ultimo = ultimo->Sig;
                    }
                    inicio = inicio->Sig;
                    ultimo->Sig = inicio;
                    delete aux;
                }
            }
            else {
                prev->Sig = aux->Sig;
                delete aux;
            }
            return;
        }
        prev = aux;
        aux = aux->Sig;
    } while (aux != inicio);

    cout << "El numero: " << numero << " no esta en la lista" << endl;
}

void ListaSimplementeEnlazadaCircular::imprimir() const {
    if (vacia()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Nodo* aux = inicio;
    do {
        cout << aux->dato << " ";
        aux = aux->Sig;
    } while (aux != inicio);
    cout << endl;
}

void ListaSimplementeEnlazadaCircular::limpiar() {
    if (vacia()) {
        cout << "La lista se encuentra vacia" << endl;
        return;
    }

    Nodo* aux = inicio;
    Nodo* siguiente;

    do {
        siguiente = aux->Sig;
        delete aux;
        aux = siguiente;
    } while (aux != inicio);

    inicio = nullptr;
}
