#include <iostream>
using namespace std;
int contador=0;
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;  // Devuelve el índice si se encuentra el elemento
        }
        if (arr[mid] < target) {
            left = mid + 1;
            contador++;
        } else {
            right = mid - 1;            
            contador++;

        }
    }
    return 'a';  // Devuelve a si el elemento no se encuentra
}

int main() {
    int n=10;
    int arr[n] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 20;
    int result = binarySearch(arr, 0, n - 1, target);

    if (result != 'a') {
        cout << "Elemento encontrado en el índice " << result << endl;
    } else {
        cout << "Elemento no encontrado" << endl;
    }
    cout<<"La cantidad de instrucciones fue "<<contador;
    return 0;
}
