#ifndef ARBOLBINARIODEBUSQUEDA_H
#define ARBOLBINARIODEBUSQUEDA_H

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) : dato(valor), izquierda(nullptr), derecha(nullptr) {}
};

class Arbol_de_busqueda_binaria {
private:
    Nodo* raiz;

    // Funciones privadas recursivas
    Nodo* insertar(Nodo* nodo, int valor);
    Nodo* eliminar(Nodo* nodo, int valor);
    Nodo* buscar(Nodo* nodo, int valor);
    Nodo* encontrarMinimo(Nodo* nodo);

    void inOrden(Nodo* nodo);
    void preOrden(Nodo* nodo);
    void postOrden(Nodo* nodo);

    int altura(Nodo* nodo);
    int nivel(Nodo* nodo, int valor, int profundidad);
    int contarHojas(Nodo* nodo);
    int contarNodos(Nodo* nodo);

    void mostrarPadres(Nodo* nodo, int valor);
    void mostrarHijos(Nodo* nodo, int valor);

public:
    Arbol_de_busqueda_binaria(); // Constructor
    ~Arbol_de_busqueda_binaria(); // Destructor
    void destruir(Nodo* nodo); // Liberar memoria

    // Métodos públicos
    void insertar(int valor);
    void eliminar(int valor);
    void buscar(int valor);

    void inOrden();
    void preOrden();
    void postOrden();

    int obtenerAltura();                  // Altura del árbol
    int obtenerAlturaIzquierda();         // Altura subárbol izquierdo
    int obtenerAlturaDerecha();           // Altura subárbol derecho
    int obtenerAlturaNodo(int valor);     // Altura de un nodo específico

    int obtenerNivel(int valor);          // Nivel de un nodo
    int obtenerTamaño();                  // Total de nodos
    int contarHojas();                    // Total de hojas

    void mostrarPadres(int valor);
    void mostrarHijos(int valor);
};

#endif // ARBOLBINARIODEBUSQUEDA_H
