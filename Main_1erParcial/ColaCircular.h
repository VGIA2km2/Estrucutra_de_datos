#ifndef COLACIRCULAR_H
#define COLACIRCULAR_H

#include <iostream>
using namespace std;

class ColaCircular {
private:
    static const int Tamaño = 20;
    int cola[Tamaño];
    int inicio;
    int final;

public:
    ColaCircular();  // Constructor

    // Métodos para consultar el estado
    bool llena() const;
    bool vacia() const;

    // Operaciones de la cola
    void encolar(int numero);
    void desencolar();
    void ImprimeCola() const;
    void limpia();
    void ImprimirIndices() const;
};

#endif // COLACIRCULAR_H
