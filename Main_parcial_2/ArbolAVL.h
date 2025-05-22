#ifndef ARBOL_AVL_H
#define ARBOL_AVL_H

#include <iostream>

// Nodo de un árbol AVL
class NodoAVL {
public:
    int clave;
    NodoAVL* izquierdo;
    NodoAVL* derecho;
    int altura;

    explicit NodoAVL(int valor)
        : clave(valor), izquierdo(nullptr), derecho(nullptr), altura(1) {
    }
};

// Clase árbol AVL
class ArbolAVL {
public:
    NodoAVL* raiz;

    ArbolAVL();
    ~ArbolAVL();

    NodoAVL* insertar(NodoAVL* nodo, int valor);
    NodoAVL* rotarDerecha(NodoAVL* y);
    NodoAVL* rotarIzquierda(NodoAVL* x);
    int obtenerAltura(NodoAVL* nodo) const;
    int obtenerBalance(NodoAVL* nodo) const;
    void recorrerInOrder(NodoAVL* nodo) const;
    void destruir(NodoAVL* nodo);
};

#endif // ARBOL_AVL_H