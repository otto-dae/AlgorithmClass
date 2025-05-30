#include <iostream>

using namespace std;

int counter=0;
int counterV=0;

void ordenamientoInsercion(int arr[],int size){
for(int i=1;i<size;i++){
    int inserted=arr[i];
    int j=i-1;

    //mover los elementos mayores que insertada en una posición hacia arriba
    while(j>=0 && arr[j]>inserted){
        counter++;
   arr[j+1]=arr[j];
        j--;

    }
    arr[j+1]=inserted;
    /*for (int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout << endl;*/
}
counterV+=2;
}

int main()
{
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
    cout<<"El arreglo original es: "<<endl;
    for (int i=0; i<size; i++){
        cout<<arreglo[i]<<" ";
    }

    cout<<endl;

    ordenamientoInsercion(arreglo,size);

    cout<<"El arreglo ordenado es: "<<endl;
    for (int i=0; i<size; i++){
        cout<<arreglo[i]<<" ";
    }

    cout<<endl<<"El total de instrucciones es: "<<counter<<endl;
	cout<<endl<<"El total de variables es: "<<counterV<<endl;

    return 0;
}
