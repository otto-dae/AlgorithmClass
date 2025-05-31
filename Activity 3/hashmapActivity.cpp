#include <iostream>
#include <string>
using namespace std;

const int MAX_CONTACTOS = 5;

int buscarContacto(string nombres[], int tamano, string nombreBuscado) {
    for (int i = 0; i < tamano; i++) {
        if (nombres[i] == nombreBuscado) {
            return i; 
        }
    }
    return -1;
}

int main() {
    string nombres[MAX_CONTACTOS] = {"Alice", "Bob", "Charlie", "Diana", "Eva"};
    string telefonos[MAX_CONTACTOS] = {
        "+52 55 1234 5678",
        "+52 33 9876 5432",
        "+52 81 2468 1357",
        "+52 55 7654 3210",
        "+52 33 1122 3344"
    };

    string nombreBuscado;
    cout << "Introduce el nombre del contacto a buscar: ";
    getline(cin, nombreBuscado);

    int posicion = buscarContacto(nombres, MAX_CONTACTOS, nombreBuscado);

    if (posicion != -1) {
        cout << "Contacto encontrado:" << endl;
        cout << "Nombre: " << nombres[posicion] << endl;
        cout << "Número: " << telefonos[posicion] << endl;
    } else {
        cout << "El contacto '" << nombreBuscado << "' no está en la lista." << endl;
    }

    return 0;
}
