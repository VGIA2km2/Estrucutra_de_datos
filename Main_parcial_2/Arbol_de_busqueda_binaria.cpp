#include "Arbol_de_busqueda_binaria.h"

int Arbol_de_busqueda_binaria::altura(Nodo* nodo) {
    if (nodo == nullptr) {
        return -1; //altura de nodo nulo es -1
    }

    int izquierda = altura(nodo->izquierda);
    int derecha = altura(nodo->derecha);
    return max(izquierda, derecha) + 1;
}

int Arbol_de_busqueda_binaria::obtenerAltura() {
    return altura(raiz);
}

int Arbol_de_busqueda_binaria::obtenerAlturaIzquierda() {
    if (raiz == nullptr) {
        return -1;
    }
    return altura(raiz->izquierda);
}

int Arbol_de_busqueda_binaria::obtenerAlturaDerecha() {
    if (raiz == nullptr) {
        return -1;
    }
    return altura(raiz->derecha);
}
