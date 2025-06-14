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

int recursividad::longitud(const char* cadena){
    if (*cadena == '\0') {
        return 0;
    }
    else {
        return 1 + longitud(cadena + 1);
    }
}


bool recursividad::esPalindromo(string palabra, int inicio, int fin) {
    if (inicio >= fin) {
        return true; 
    }

    if (palabra[inicio] != palabra[fin]) {
        return false; 
    }

    return esPalindromo(palabra, inicio + 1, fin - 1); // revisa el centro
}