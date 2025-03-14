#ifndef LDE_H
#define LDE_H

#include <iostream>
using namespace std;

class LDE {
private:
    struct Nodo {
        int dato;
        Nodo* Sig;
        Nodo* ant;
    } *inicio, *cola;

public:
    LDE(); // Constructor

    // Métodos de apoyo
    bool vacia() const;
    void limpiar();

    // Funciones de la lista
    void insertarPorPosicion(int numero, int posicion);
    void eliminar(int numero);
    void imprimir() const;
};

#endif // LDE_H

