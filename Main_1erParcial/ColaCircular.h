#ifndef COLACIRCULAR_H
#define COLACIRCULAR_H

#include <iostream>
using namespace std;

class ColaCircular {
private:
    static const int Tama�o = 20;
    int cola[Tama�o];
    int inicio;
    int final;

public:
    ColaCircular();  // Constructor

    // M�todos para consultar el estado
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
