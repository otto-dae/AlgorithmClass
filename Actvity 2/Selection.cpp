#include <iostream>
using namespace std;

int contador=0;
int contadorV=0;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
		  contador++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
contadorV+=2;
}

int main() {

    int size;
    cout << "Igrese la cantidad de numeros que desea poner en el arreglo: " << endl;
    cin >> size;
    int arr[size] = {};
    int value;

    for (int i = 0; i <= size - 1; i++){
        cout << "Ingrese el elemento en la posicion " << i << endl;
        cin >> value;
        arr[i] = value; 
    }

	contadorV+=size;
	contadorV++;
    cout << "Arreglo desordenado: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        contador++;
    }
    cout << endl;
    selectionSort(arr, size);
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    cout<<"Total de instrucciones: "<<contador<<endl;
	cout<<"El total de variables es: "<<contadorV<<endl;

    return 0;
}
