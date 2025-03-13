#include <iostream>

using namespace std;

int arra[0]={};
void sort(int[], int);

int main(){

    int size;
    cout << "Insert size of array: ";
    cin >> size;
    cout << "Insert values of the array: ";
    arra[size] = {};

    for(int i = 0; i<size; i++){
        cout << "Number: " << i+1 << endl;
        cin >> arra[i];
    }

    return 0;
}

void sort(int arra[], int size){
    int temp;

    for(int j=size; j>0; j++){
        
    }
}