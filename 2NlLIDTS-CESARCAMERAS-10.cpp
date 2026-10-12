
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

// Recorre la lista desde la cabeza hacia la cola
// Muestra tambien la direccion de memoria de cada nodo y sus enlaces
void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;

    while (actual != nullptr) {
        cout << "Dato: " << actual->dato
            << " | Direccion: " << actual
            << " | Anterior: " << actual->anterior
            << " | Siguiente: " << actual->siguiente << endl;

        actual = actual->siguiente;
    }

    cout << endl;
}

// Recorre la lista desde la cola hasta la cabeza
// cuando el apuntador anterior
void imprimirListaInversa(Nodo* cola) {
    Nodo* actual = cola;

    while (actual != nullptr) {
        cout << "Dato: " << actual->dato
            << " | Direccion: " << actual
            << " | Anterior: " << actual->anterior
            << " | Siguiente: " << actual->siguiente << endl;

        actual = actual->anterior;
    }

    cout << endl;
}

void borrarLista(Nodo*& cabeza, Nodo*& cola) {
    int contador = 0;

    while (cabeza != nullptr) {
        Nodo* siguiente = cabeza->siguiente;
        contador++;

        // Se imprime antes de borrar: despues el nodo ya no existe
        cout << "Elemento borrado " << contador
            << " | Dato: " << cabeza->dato
            << " | Direccion: " << cabeza << endl;

        delete cabeza;
        cabeza = siguiente;
    }

    cout << "Total de elementos borrados: "
        << contador << endl;

    cola = nullptr;
}

// Agrega un nodo al final; mantener la cola evita recorrer toda la lista
void agregarNodo(Nodo*& cabeza, Nodo*& cola, int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    if (cabeza == nullptr) {
        // Lista vacia: el mismo nodo es cabeza y cola
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    }
    else {
        cola->siguiente = nuevoNodo;  // El ultimo nodo apunta al nuevo
        nuevoNodo->anterior = cola;   // El nuevo apunta hacia el anterior
        cola = nuevoNodo;             // El nuevo pasa a ser la cola
    }
}

int main() {
    cout << "Actividad 6 - Lista Doblemente Enlazada"
        << endl;

    Nodo* cabeza = nullptr;  // Apuntador al primer nodo
    Nodo* cola = nullptr;    // Apuntador al ultimo nodo
    int tamanio;

    cout << "Ingresa la cantidad de elementos de la lista enlazada: ";
    cin >> tamanio;

    if (tamanio <= 0) {
        cout << "Cantidad de elementos no valida" << endl;
        return 1;
    }

    for (int i = 0; i < tamanio; i++) {
        int valor;

        cout << "Ingresa el dato " << i + 1 << ": ";
        cin >> valor;

        // Invocamos la funcion para agregar el nodo
        agregarNodo(cabeza, cola, valor);
    }

    cout << "\nImprimiendo lista (de inicio a fin):"
        << endl;
    imprimirLista(cabeza);

    cout << "\nImprimiendo lista (de fin a inicio):"
        << endl;
    imprimirListaInversa(cola);

    cout << "\nLiberando lista de memoria" << endl;
    borrarLista(cabeza, cola);

    return 0;
}