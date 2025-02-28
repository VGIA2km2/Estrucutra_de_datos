#include "ColaEstatica.h"

ColaEstatica::ColaEstatica() {
    tope = -1;
}

bool ColaEstatica::llena() const {
    return (tope == Tamaño - 1);
}

bool ColaEstatica::vacia() const {
    return (tope == -1);
}

void ColaEstatica::encolar(int numero) {
    if (llena()) {
        cout << "La cola esta llena" << endl;
    }
    else {
        tope++;
        cola[tope] = numero;
    }
}

void ColaEstatica::desencolar() {
    if (vacia()) {
        cout << "La cola esta vacia" << endl;
    }
    else {
        // Desplazar elementos a la izquierda
        for (int i = 0; i < tope; i++) {
            cola[i] = cola[i + 1];
        }
        tope--;
    }
}

void ColaEstatica::ImprimeCola() const {
    if (vacia()) {
        cout << "La cola esta vacia" << endl;
    }
    else {
        cout << "Cola: ";
        for (int i = 0; i <= tope; i++) {
            cout << cola[i] << " ";
        }
        cout << endl;
    }
}

void ColaEstatica::limpia() {
    if (vacia()) {
        cout << "La cola esta vacia" << endl;
    }
    else {
        tope = -1;
        cout << "La cola ahora esta limpia" << endl;
    }
}

void ColaEstatica::Imprimirtope() const {
    cout << "El tope es: " << tope << endl;
}
