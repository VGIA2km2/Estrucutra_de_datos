#include "ArbolAVL.h"

ArbolAVL::ArbolAVL() : raiz(nullptr) {}

ArbolAVL::~ArbolAVL() {
    destruir(raiz);
}

NodoAVL* ArbolAVL::insertar(NodoAVL* nodo, int valor) {
    if (!nodo)
        return new NodoAVL(valor);

    if (valor < nodo->clave)
        nodo->izquierdo = insertar(nodo->izquierdo, valor);
    else if (valor > nodo->clave)
        nodo->derecho = insertar(nodo->derecho, valor);
    else
        return nodo; // no permitir duplicados

    // Actualizar altura
    nodo->altura = 1 + std::max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));

    int balance = obtenerBalance(nodo);

    // Caso Izquierda–Izquierda
    if (balance > 1 && valor < nodo->izquierdo->clave)
        return rotarDerecha(nodo);

    // Caso Derecha–Derecha
    if (balance < -1 && valor > nodo->derecho->clave)
        return rotarIzquierda(nodo);

    return nodo;
}
