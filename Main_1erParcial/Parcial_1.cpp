#include <iostream>
#include "ColaEstatica.h"
#include "ColaCircular.h"
#include "ListaSimplementeEnlazadaNormal.h"
#include "ListaDoblementeEnlazada.h"

using namespace std;

//Funcion para el submenu de la Lista doblemente Enlazada circular
void menuListaDoblementeEnlazada(ListaDoblementeEnlazada& lde) {
    int opcion, elemento;
    do {
        cout << "\n----- Menu Lista doblemente Enlazada circular -----\n";
        cout << "1. Agregar (Ingresa un elemento)\n";
        cout << "2. Eliminar (Elimina un elemento)\n";
        cout << "3. Imprimir Lista\n";
        cout << "4. Limpiar Lista\n";
        cout << "5. Volver al Menu Principal\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese el elemento a agregar: ";
            cin >> elemento;
            lde.agregar(elemento);
            break;
        case 2:
            cout << "Escriba el numero que quiera eliminar: ";
            cin >> elemento;
            lde.eliminar(elemento);
            break;
        case 3:
            lde.imprimir();
            break;
        case 4:
            lde.limpiar();
            break;
        case 5:
            cout << "Volviendo al Menu Principal...\n";
            break;
        default:
            cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 5);
}

//Funcion para el submenu de la Lista Simplemente Enlazada
void menuListaSimplementeEnlazada(ListaSimplementeEnlazada& lse) {
    int opcion, elemento;
    do {
        cout << "\n----- Menu Lista Simplemente Enlazada -----\n";
        cout << "1. Agregar (Ingresa un elemento)\n";
        cout << "2. Eliminar (Elimina un elemento)\n";
        cout << "3. Imprimir Lista\n";
        cout << "4. Limpiar Lista\n";
        cout << "5. Volver al Menu Principal\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese el elemento a agregar: ";
            cin >> elemento;
            lse.agregar(elemento);
            break;
        case 2:
            cout << "Escriba el numero que quiera eliminar: ";
            cin >> elemento;
            lse.eliminar(elemento);
            break;
        case 3:
            lse.imprimir();
            break;
        case 4:
            lse.limpiar();
            break;
        case 5:
            cout << "Volviendo al Menu Principal...\n";
            break;
        default:
            cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 5);
}

// Función para el submenu de la Cola Estatica
void menuColaEstatica(ColaEstatica& cola) {
    int opcion, elemento;
    do {
        cout << "\n----- Menu Cola Estatica -----\n";
        cout << "1. Encolar (Ingresa un elemento)\n";
        cout << "2. Desencolar (Elimina un elemento)\n";
        cout << "3. Imprimir Cola\n";
        cout << "4. Limpiar Cola\n";
        cout << "5. Mostrar tope\n";
        cout << "6. Volver al Menu Principal\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese el elemento a agregar: ";
            cin >> elemento;
            cola.encolar(elemento);
            break;
        case 2:
            cola.desencolar();
            break;
        case 3:
            cola.ImprimeCola();
            break;
        case 4:
            cola.limpia();
            break;
        case 5:
            cola.Imprimirtope();
            break;
        case 6:
            cout << "Volviendo al Menu Principal...\n";
            break;
        default:
            cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 6);
}

// Función para el submenu de la Cola Circular
void menuColaCircular(ColaCircular& cola) {
    int opcion, elemento;
    do {
        cout << "\n----- Menu Cola Circular -----\n";
        cout << "1. Encolar (Ingresa un elemento)\n";
        cout << "2. Desencolar (Elimina un elemento)\n";
        cout << "3. Imprimir Cola\n";
        cout << "4. Limpiar Cola\n";
        cout << "5. Mostrar indices\n";
        cout << "6. Volver al Menu Principal\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese el elemento a agregar: ";
            cin >> elemento;
            cola.encolar(elemento);
            break;
        case 2:
            cola.desencolar();
            break;
        case 3:
            cola.ImprimeCola();
            break;
        case 4:
            cola.limpia();
            break;
        case 5:
            cola.ImprimirIndices();
            break;
        case 6:
            cout << "Volviendo al Menu Principal...\n";
            break;
        default:
            cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 6);
}

int main() {
    ColaEstatica colaEstatica;
    ColaCircular colaCircular;
    ListaSimplementeEnlazada listasimplementeenlazada;
    ListaDoblementeEnlazada listaDoblementeEnlazada;
    int opcion;

    do {
        cout << "\n===== Menu Principal =====\n";
        cout << "1. Cola Estatica\n";
        cout << "2. Cola Circular\n";
        cout << "3. Lista Simplemente Enlazada\n";
        cout << "4. Lista Doblemente Enlazada\n";
        cout << "5. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            menuColaEstatica(colaEstatica);
            break;
        case 2:
            menuColaCircular(colaCircular);
            break;
        case 3:
            menuListaSimplementeEnlazada(listasimplementeenlazada);
            break;
        case 4:
            menuListaDoblementeEnlazada(listaDoblementeEnlazada);
            break;
        case 5:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
