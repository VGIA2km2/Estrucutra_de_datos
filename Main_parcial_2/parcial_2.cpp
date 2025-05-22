#include "Recursivo.h"
#include "Arbol_de_busqueda_binaria.h"

using namespace std;

int main() {
	recursividad r;
	char buffer[100];
	cin.getline(buffer, 100);
	const char* cadena = buffer;
	int resultado = r.longitud(cadena);
	cout << resultado;
}