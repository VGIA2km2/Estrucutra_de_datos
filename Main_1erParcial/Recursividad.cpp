#include "Recursivo.h"

recursividad::recursividad() {

}

int recursividad::exponente(int numero,int exponente) {
    if (exponente == 0) {
        return 1;
    }
    else if (exponente == 1) {
        return numero;
    }
    else {
        return numero * recursividad::exponente(numero, exponente - 1);
    }
}
