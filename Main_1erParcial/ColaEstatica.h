#ifndef COLAESTATICA_H
#define COLAESTATICA_H

#include <iostream>
using namespace std;

class ColaEstatica {
private:
    static const int Tama�o = 20;
    int cola[Tama�o];
    int tope; // -1 indica que la cola est� vac�a

public:
    ColaEstatica();  // Constructor

    // M�todos para consultar el estado
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
