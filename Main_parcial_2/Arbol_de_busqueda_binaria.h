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
    Nodo* buscar(Nodo* nodo, int valor);
    Nodo* eliminar(Nodo* nodo, int valor); // Función recursiva para eliminar un nodo

public:
    Arbol_de_busqueda_binaria();

    // Funciones solicitadas:
    bool EsVacia();
    void Despliega();           // Despliega el árbol (inOrden)
    int obtenerAltura();        // Altura total del árbol
    int obtenerAlturaIzquierda(); // Altura del subárbol izquierdo
    int obtenerAlturaDerecha();   // Altura del subárbol derecho
    int obtenerTamaño();        // Cantidad total de nodos (cardinalidad)
    void insertar(int valor);   // Función de inserción (para pruebas)
    void buscar(int valor);     // Función para buscar un nodo
    void eliminar(int valor);   // Función para eliminar un nodo con el valor dado
};

#endif // ARBOL_BINARIO_DE_BUSQUEDA_H
