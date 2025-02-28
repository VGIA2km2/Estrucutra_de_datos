#ifndef LISTADOBLEMENTEENLAZADA_H
#define LISTADOBLEMENTEENLAZADA_H

#include <iostream>
using namespace std;

class ListaDoblementeEnlazada {
private:
	struct Nodo
	{
		int dato;
		Nodo* Sig;
		Nodo* ant;
	}*cabeza,*cola;

public:
	ListaDoblementeEnlazada(); //Constructor

	//Metodos de apoyo
	bool vacia() const;
	void inicializa();

	//funciones de la lista
	void agregar(int numero);
	void eliminar(int numero);
	void imprimir() const;
	void limpiar();

};


#endif // LISTADOBLEMENTEENLAZADA_H