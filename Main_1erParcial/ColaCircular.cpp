#include "ColaCircular.h"

ColaCircular::ColaCircular() {
    inicio = 0;
    final = 0;
}

bool ColaCircular::llena() const {
    return ((final + 1) % Tamaño == inicio);
}

bool ColaCircular::vacia() const {
    return (inicio == final);
}

void ColaCircular::encolar(int numero) {
    if (llena()) {
        cout << "La cola esta llena" << endl;
    }
    else {
        cola[final] = numero;
        final = (final + 1) % Tamaño;
    }
}

void ColaCircular::desencolar() {
    if (vacia()) {
        cout << "La cola esta vacia" << endl;
    }
    else {
        inicio = (inicio + 1) % Tamaño;
    }
}

void ColaCircular::ImprimeCola() const {
    if (vacia()) {
        cout << "La cola esta vacia" << endl;
    }
    else {
        cout << "Cola: ";
        int i = inicio;
        while (i != final) {
            cout << cola[i] << " ";
            i = (i + 1) % Tamaño;
        }
        cout << endl;
    }
}

void ColaCircular::limpia() {
    if (vacia()) {
        cout << "La cola esta vacia" << endl;
    }
    else {
        inicio = 0;
        final = 0;
        cout << "La cola ahora esta limpia" << endl;
    }
}

void ColaCircular::ImprimirIndices() const {
    cout << "El inicio es: " << inicio << "  El final es: " << final << endl;
}
