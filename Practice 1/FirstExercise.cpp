#include <iostream>

int contar(int);

using namespace std;

int main() {

    int num;
    cout << "Ingrese un número entero positivo: ";
    cin >> num;

    int cantidad = contar (num);

    cout << "El número " << num << " tiene " <<cantidad << " numeros "<<endl;
    cout << "El número " << num << " tiene " <<cantidad << " numeros "<<endl;

    return 0;
}

int contar (int num) {
    int contador = 0;
    while (num > 0) {
    num /= 10;
    contador++;
    }
    return contador;
}