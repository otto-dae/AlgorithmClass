#include <iostream>

using namespace std;

int arra[0]={};
void SortBubble(int[], int);

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

    SortBubble(arra, size);

    cout << "Sorted array ";
    for(int i = 0; i<size; i++){
        cout  << arra[i] << ", " ;
    }
    return 0;
}

void SortBubble(int arra[], int size){
    int temp;

    for(int i=0; i < size -1; ++i){
        for(int j = 0; j < size - i -1; ++j){

            if(arra[j] > arra[j+1]){

                temp = arra[j];
                arra[j] = arra[j+1];
                arra[j+1] = temp;
            }
        }
    }
}