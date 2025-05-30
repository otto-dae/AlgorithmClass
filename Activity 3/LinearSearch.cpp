
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Devuelve el índice si se encuentra el elemento
        }
    }
    return 'a'; // Devuelve -1 si el elemento no se encuentra
 }

int main() {
    int tamano=6;
    int objetivo=-1;
    int arr[tamano] = {2, -1, 6, 8, 10, 12};
    int result = linearSearch(arr, tamano, objetivo);
    if (result != 'a') {
        cout << "Elemente found in index " << result << endl;
    }
    else {
        cout << "Elemento no encontrado" << endl;
    }
    return 0;
}
