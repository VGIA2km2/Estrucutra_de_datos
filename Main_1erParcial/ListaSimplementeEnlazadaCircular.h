#ifndef LISTASIMPLEMENTENELAZADACIRCULAR_H
#define LISTASIMPLEMENTENELAZADACIRCULAR_H

#include <iostream>
using namespace std;

class ListaSimplementeEnlazadaCircular {
private:
	struct Nodo
	{
		int dato;
		Nodo* Sig;
	}*inicio;

public:
	ListaSimplementeEnlazadaCircular(); //Constructor

	//Metodos de apoyo
	bool vacia() const;
	void inicializa(int numero);

	//funciones de la lista
	void agregar(int numero);
	void eliminar(int numero);
	void imprimir() const;
	void limpiar();

};


#endif // LISTASIMPLEMENTENELAZADACIRCULAR_H