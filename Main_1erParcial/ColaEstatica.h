#ifndef COLAESTATICA_H
#define COLAESTATICA_H

#include <iostream>
using namespace std;

class ColaEstatica {
private:
    static const int Tamaño = 20;
    int cola[Tamaño];
    int tope; // -1 indica que la cola está vacía

public:
    ColaEstatica();  // Constructor

    // Métodos para consultar el estado
    bool llena() const;
    bool vacia() const;

    // Operaciones de la cola
    void encolar(int numero);
    void desencolar();
    void ImprimeCola() const;
    void limpia();
    void Imprimirtope() const;
};

#endif // COLAESTATICA_H
