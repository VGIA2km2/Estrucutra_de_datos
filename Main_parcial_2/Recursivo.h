#ifndef RECURSIVO_H
#define RECURSIVO_H

#include <iostream>
#include <string.h>
using namespace std;

class recursividad {
private:
	
public:
	recursividad(); //Constructor

	int exponente(int numero, int exponente);
	int PotenciaParImpar(int numero, int exponente);
	int longitud(const char* cadena);
	bool esPalindromo(string palabra, int inicio, int fin);

};


#endif // RECURSIVO_H
