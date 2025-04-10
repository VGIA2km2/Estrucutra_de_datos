#include "Arbol_de_busqueda_binaria.h"
#include <algorithm> 


Arbol_de_busqueda_binaria::Arbol_de_busqueda_binaria() {
    raiz = nullptr;
}


bool Arbol_de_busqueda_binaria::EsVacia() {
    return (raiz == nullptr);
}


void Arbol_de_busqueda_binaria::inOrden(Nodo* nodo) {
    if (nodo == nullptr)
        return;
    inOrden(nodo->izquierda);
    std::cout << nodo->dato << "\t";
    inOrden(nodo->derecha);
}


void Arbol_de_busqueda_binaria::Despliega() {
    inOrden(raiz);
    std::cout << std::endl;
}


int Arbol_de_busqueda_binaria::altura(Nodo* nodo) {
    if (nodo == nullptr)
        return -1; // Por convención: altura de árbol vacío es -1
    int altIzq = altura(nodo->izquierda);
    int altDer = altura(nodo->derecha);
    return std::max(altIzq, altDer) + 1;
}


int Arbol_de_busqueda_binaria::obtenerAltura() {
    return altura(raiz);
}


int Arbol_de_busqueda_binaria::obtenerAlturaIzquierda() {
    if (raiz == nullptr)
        return -1;
    return altura(raiz->izquierda);
}


int Arbol_de_busqueda_binaria::obtenerAlturaDerecha() {
    if (raiz == nullptr)
        return -1;
    return altura(raiz->derecha);
}


int Arbol_de_busqueda_binaria::contarNodos(Nodo* nodo) {
    if (nodo == nullptr)
        return 0;
    return 1 + contarNodos(nodo->izquierda) + contarNodos(nodo->derecha);
}


int Arbol_de_busqueda_binaria::obtenerTamaño() {
    return contarNodos(raiz);
}

Nodo* Arbol_de_busqueda_binaria::buscar(Nodo* nodo, int valor) {
    if (nodo == nullptr)
        return nullptr;
    if (nodo->dato == valor)
        return nodo;
    if (valor < nodo->dato)
        return buscar(nodo->izquierda, valor);
    else
        return buscar(nodo->derecha, valor);
}


void Arbol_de_busqueda_binaria::buscar(int valor) {
    Nodo* resultado = buscar(raiz, valor);
    if (resultado)
        std::cout << "Nodo " << valor << " encontrado." << std::endl;
    else
        std::cout << "Nodo " << valor << " no encontrado." << std::endl;
}