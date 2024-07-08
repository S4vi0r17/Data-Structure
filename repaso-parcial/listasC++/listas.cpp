#include <iostream>

class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int dato) {
        this->dato = dato;
        this->siguiente = nullptr;
    }
};

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    void insertarAlInicio(int dato) {
        Nodo* nuevoNodo = new Nodo(dato);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    void insertarAlFinal(int dato) {
        Nodo* nuevoNodo = new Nodo(dato);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            return;
        }
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }

    void eliminar(int dato) {
        if (cabeza == nullptr) {
            return;
        }
        if (cabeza->dato == dato) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return;
        }
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->dato != dato) {
            actual = actual->siguiente;
        }
        if (actual->siguiente == nullptr) {
            return;
        }
        Nodo* temp = actual->siguiente;
        actual->siguiente = actual->siguiente->siguiente;
        delete temp;
    }

    void mostrar() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        std::cout << "null" << std::endl;
    }
};

int main() {
    ListaEnlazada lista;
    lista.insertarAlInicio(3);
    lista.insertarAlInicio(2);
    lista.insertarAlInicio(1);

    lista.mostrar(); // Salida: 1 -> 2 -> 3 -> null

    lista.insertarAlFinal(4);
    lista.mostrar(); // Salida: 1 -> 2 -> 3 -> 4 -> null

    lista.eliminar(3);
    lista.mostrar(); // Salida: 1 -> 2 -> 4 -> null

    return 0;
}
