#include "ListaDoblementeEnlazada.h"

ListaDoblementeEnlazada::ListaDoblementeEnlazada() {
	cabeza = nullptr;
	cola = nullptr;
}

bool ListaDoblementeEnlazada::vacia() const {
	return (cabeza == nullptr && cola == nullptr);
}

void ListaDoblementeEnlazada::inicializa() {
	cabeza = new Nodo;
	cola = cabeza;
}


void ListaDoblementeEnlazada::agregar(int numero) {
	if (vacia()) {
		inicializa();
		cabeza->dato = numero;
		cabeza->Sig = cabeza;
		cabeza->ant = cabeza;
	}
	else {
		Nodo* NuevoNodo = new Nodo;
		NuevoNodo->dato = numero;
		NuevoNodo->Sig = nullptr;
		Nodo* aux = cabeza;


		if (NuevoNodo->dato < cabeza->dato) {
			cabeza->ant = NuevoNodo;
			cola->Sig = NuevoNodo;
			NuevoNodo->Sig = cabeza;
			NuevoNodo->ant = cola;
			cabeza = NuevoNodo;
		}
		else {
			while (aux->Sig != cabeza && NuevoNodo->dato > aux->Sig->dato) {
				aux = aux->Sig;
			}
			if (aux->Sig == cabeza) {
				aux->Sig = NuevoNodo;
				NuevoNodo->ant = aux;
				NuevoNodo->Sig = cabeza;
				cola = NuevoNodo;
			}
			else {
				NuevoNodo->Sig = aux->Sig;
				NuevoNodo->ant = aux;
				aux->Sig->ant = NuevoNodo;
				aux->Sig = NuevoNodo;
			}
		}

	}
}

void ListaDoblementeEnlazada::eliminar(int numero) {
	if (vacia()) {
		cout << "La lista esta vacia" << endl;
		return;
	}
	else {

		if (numero == cabeza->dato) {
			if (cabeza == cola) {
				cabeza = nullptr;
				cola = nullptr;
			}
			else {
				Nodo* aux = cabeza;
				cola->Sig = cabeza->Sig;
				cabeza->Sig->ant = cola;
				cabeza = cabeza->Sig;
				delete aux;
			}

		}
		else {
			Nodo* aux = cabeza;

			while (aux->Sig != cabeza) {
				if (numero == aux->Sig->dato) {
					if (aux->Sig == cola) {
						Nodo* aux1 = aux->Sig;
						aux->Sig = aux1->Sig;
						aux1->Sig->ant = aux;
						cola = aux;
						delete aux1;
						return;
					}
					Nodo* aux1 = aux->Sig;
					aux->Sig = aux1->Sig;
					aux1->Sig->ant = aux;
					delete aux1;
					return;
				}
				aux = aux->Sig;
			}
			cout << "El numero: " << numero << " no esta en la lista" << endl;
		}

	}
}

void ListaDoblementeEnlazada::imprimir() const {
	if (vacia()) {
		cout << "La lista esta vacia" << endl;
	}
	else {
		Nodo* aux = cabeza;
		do {
			cout << aux->dato << " ";
			aux = aux->Sig;
		} while (aux != cabeza);
		cout << endl;
	}
}

void ListaDoblementeEnlazada::limpiar() {
	if (vacia()) {
		cout << "La lista se encuentra vacia" << endl;
	}
	else {
		Nodo* aux = cabeza;
		cola->Sig = nullptr;
		while (aux != nullptr) {
			Nodo* aux1 = aux;
			aux = aux->Sig;
			delete aux1;
		}
		cabeza = nullptr;
		cola = nullptr;
	}
}