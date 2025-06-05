#ifndef ARBOL_AVL_H
#define ARBOL_AVL_H

#include <algorithm>  // para std::max
#include <iostream>   // para std::cout


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

class ArbolAVL {
public:
    NodoAVL* raiz;


    ArbolAVL();
    ~ArbolAVL();


    void insertar(int valor);
    void recorrerInOrder() const;
    void destruirArbol();

private:
    NodoAVL* insertarRec(NodoAVL* nodo, int valor);
    NodoAVL* rotarDerecha(NodoAVL* y);
    NodoAVL* rotarIzquierda(NodoAVL* x);
    int obtenerAltura(NodoAVL* nodo) const;
    int obtenerBalance(NodoAVL* nodo) const;
    void inOrderRec(NodoAVL* nodo) const;
    void destruirRec(NodoAVL* nodo);
};

#endif // ARBOL_AVL_H
