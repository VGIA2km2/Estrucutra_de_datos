#include "Recursivo.h"
#include "Arbol_de_busqueda_binaria.h"

using namespace std;

int main() {
	recursividad r;
    string cadena;
    cout << "Ingresa una palabra: ";
    cin >> cadena;

    if (r.esPalindromo(cadena, 0, cadena.length() - 1)) {
        cout << "Es un palindromo." << endl;
    }
    else {
        cout << "No es un palindromo." << endl;
    }

    return 0;
}