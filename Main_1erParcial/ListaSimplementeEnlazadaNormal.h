#ifndef LISTASIMPLEMENTENELAZADA_H
#define LISTASIMPLEMENTENELAZADA_H

#include <iostream>
using namespace std;

class ListaSimplementeEnlazada {
private:
	struct Nodo
	{
		int dato;
		Nodo* Sig;
	}*inicio;

public:
	ListaSimplementeEnlazada(); //Constructor

	//Metodos de apoyo
	bool vacia() const;
	void inicializa(int numero);

	//funciones de la lista
	void agregar(int numero);
	void eliminar(int numero);
	void imprimir() const;
	void limpiar();

};


#endif // LISTASIMPLEMENTENELAZADA_H
