#include "Recursivo.h"

recursividad::recursividad() {

}

int recursividad::exponente(int numero,int exp) {
    if (exp == 0) {
        return 1;
    }
    else if (exp == 1) {
        return numero;
    }
    else {
        return numero * exponente(numero, exp - 1);
    }
}


int recursividad::PotenciaParImpar(int numero, int exp) {
    if (exp == 0) {
        return 1;
    }
    else if (exp == 1) {
        return numero;
    }
    else if (exp % 2 == 0) {
        int x = PotenciaParImpar(numero, exp / 2);
        return x * x;
    }
    else {
        int x = PotenciaParImpar(numero, exp / 2);
        return numero * x * x;
    }
}