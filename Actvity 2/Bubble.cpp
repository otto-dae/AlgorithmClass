#include <iostream>

using namespace std;

int counter = 0;
int counterV=0;

void ordenamientoBurbuja(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
		counter++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }

        }
    }
counterV++;
}

int main() {
    
    int size;
    cout << "Igrese la cantidad de numeros que desea poner en el arreglo: " << endl;
    cin >> size;
    int arreglo[size] = {};
    int value;
    for (int i = 0; i <= size - 1; i++){
        cout << "Ingrese el elemento en la posicion " << i << endl;
        cin >> value;
        arreglo[i] = value; 
    }

    counterV+=size;
	counterV++;
    cout << "El arreglo original es: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    ordenamientoBurbuja(arreglo, size);

    cout << "El arreglo ordenado es: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arreglo[i] << " ";
    }

    cout << endl << "El total de instrucciones es: " << counter << endl;
	cout<<endl<<"El total de variables es: "<<counterV<<endl;
    return 0;

}
