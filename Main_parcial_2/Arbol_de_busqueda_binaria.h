#ifndef ARBOL_BINARIO_DE_BUSQUEDA_H
#define ARBOL_BINARIO_DE_BUSQUEDA_H

#include <iostream>
using namespace std;

// Estructura del nodo
struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) : dato(valor), izquierda(nullptr), derecha(nullptr) {}
};

class Arbol_de_busqueda_binaria {
private:
    Nodo* raiz;

    // Funciones recursivas privadas
    void inOrden(Nodo* nodo);
    int altura(Nodo* nodo);
    int contarNodos(Nodo* nodo);

public:
    Arbol_de_busqueda_binaria();

    // Funciones solicitadas:
    bool EsVacia();
    void Despliega();           // Recorre inOrden y muestra el �rbol
    int obtenerAltura();        // Altura total del �rbol
    int obtenerAlturaIzquierda(); // Altura del sub�rbol izquierdo
    int obtenerAlturaDerecha();   // Altura del sub�rbol derecho
    int obtenerTama�o();        // Total de nodos (cardinalidad)

    // (Opcional) Funci�n de inserci�n para pruebas:
    void insertar(int valor);
};

#endif // ARBOL_BINARIO_DE_BUSQUEDA_H
