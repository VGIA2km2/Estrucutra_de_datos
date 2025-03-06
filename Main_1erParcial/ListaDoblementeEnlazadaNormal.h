#ifndef LISTADOBLEMENTEENLAZADANORMAL_H
#define LISTADOBLEMENTEENLAZADANORMAL_H

#include <iostream>
using namespace std;

class ListaDoblementeEnlazadaNormal {
private:
	struct Nodo
	{
		int dato;
		Nodo* Sig;
		Nodo* ant;
	}*cabeza;

public:
	ListaDoblementeEnlazadaNormal(); //Constructor

	//Metodos de apoyo
	bool vacia() const;
	void inicializa(int numero);

	//funciones de la lista
	void agregar(int numero);
	void eliminar(int numero);
	void imprimir() const;
	void limpiar();

};


#endif // LISTADOBLEMENTEENLAZADANORMAL_H
