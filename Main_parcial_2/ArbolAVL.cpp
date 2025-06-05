#include "ArbolAVL.h"

ArbolAVL::ArbolAVL() : raiz(nullptr) {}

ArbolAVL::~ArbolAVL() {
    destruirRec(raiz);
}

void ArbolAVL::insertar(int valor) {
    raiz = insertarRec(raiz, valor);
}

NodoAVL* ArbolAVL::insertarRec(NodoAVL* nodo, int valor) {
    if (nodo == nullptr) {
        return new NodoAVL(valor);
    }
    if (valor < nodo->clave) {
        nodo->izquierdo = insertarRec(nodo->izquierdo, valor);
    }
    else if (valor > nodo->clave) {
        nodo->derecho = insertarRec(nodo->derecho, valor);
    }
    else {
        return nodo;
    }

    nodo->altura = 1 + std::max(obtenerAltura(nodo->izquierdo),
        obtenerAltura(nodo->derecho));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && valor < nodo->izquierdo->clave) {
        return rotarDerecha(nodo);
    }

    if (balance < -1 && valor > nodo->derecho->clave) {
        return rotarIzquierda(nodo);
    }

    if (balance > 1 && valor > nodo->izquierdo->clave) {
        nodo->izquierdo = rotarIzquierda(nodo->izquierdo);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && valor < nodo->derecho->clave) {
        nodo->derecho = rotarDerecha(nodo->derecho);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

NodoAVL* ArbolAVL::rotarDerecha(NodoAVL* y) {
    NodoAVL* x = y->izquierdo;
    NodoAVL* T2 = x->derecho;

    x->derecho = y;
    y->izquierdo = T2;

    y->altura = std::max(obtenerAltura(y->izquierdo),
        obtenerAltura(y->derecho)) + 1;
    x->altura = std::max(obtenerAltura(x->izquierdo),
        obtenerAltura(x->derecho)) + 1;

    return x;
}

NodoAVL* ArbolAVL::rotarIzquierda(NodoAVL* x) {
    NodoAVL* y = x->derecho;
    NodoAVL* T2 = y->izquierdo;

    y->izquierdo = x;
    x->derecho = T2;

    x->altura = std::max(obtenerAltura(x->izquierdo),
        obtenerAltura(x->derecho)) + 1;
    y->altura = std::max(obtenerAltura(y->izquierdo),
        obtenerAltura(y->derecho)) + 1;

    return y;
}

int ArbolAVL::obtenerAltura(NodoAVL* nodo) const {
    if (nodo == nullptr)
        return 0;
    return nodo->altura;
}

int ArbolAVL::obtenerBalance(NodoAVL* nodo) const {
    if (nodo == nullptr)
        return 0;
    return obtenerAltura(nodo->izquierdo) - obtenerAltura(nodo->derecho);
}

void ArbolAVL::recorrerInOrder() const {
    inOrderRec(raiz);
    std::cout << std::endl;
}

void ArbolAVL::inOrderRec(NodoAVL* nodo) const {
    if (nodo == nullptr)
        return;
    inOrderRec(nodo->izquierdo);
    std::cout << nodo->clave << " ";
    inOrderRec(nodo->derecho);
}

void ArbolAVL::destruirArbol() {
    destruirRec(raiz);
    raiz = nullptr;
}

void ArbolAVL::destruirRec(NodoAVL* nodo) {
    if (nodo == nullptr)
        return;
    destruirRec(nodo->izquierdo);
    destruirRec(nodo->derecho);
    delete nodo;
}