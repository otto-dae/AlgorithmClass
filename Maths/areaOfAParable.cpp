#include <iostream>

using namespace std;

int main() {
    const int SIZE = 90; 
    const double lenghtRect = 0.175;
    double medidas[SIZE] = {
        0.8, 2.7, 3.9, 4.8, 6.4, 8.2, 9.9, 11.3,
        12.6, 13.6, 14, 15.3, 16.5, 17.5, 19.5, 21, 22.4,
        23.8, 25.4, 26.1, 26.4, 28.1, 29.3, 30.7, 
        35.4, 36.1, 36.9, 38.1, 39.1, 40.0, 41.4, 
        42.7, 43.8, 44.9, 45.6, 47.3, 48.4, 49.0, 
        49.7, 50.4, 51.1, 51.9, 52.5, 53.0, 53.6, 
        54.5, 55.0, 55.8, 56.3, 57.0, 57.8, 58.6, 
        59.2, 60.2, 60.7, 61.3, 62.5, 63.0, 63.5, 
        64.7, 65.3, 65.9, 66.4, 66.9, 67.2, 67.6,
        68.0, 68.5, 68.9, 69.0, 69.1, 69.4, 69.6,
        69.7, 69.9, 70.1, 70.2, 70.3, 70.4, 70.6, 
        70.7, 70.8, 70.85, 70.9, 71.0, 71.1, 71.15, 
        71.17, 71.19, 71.21

        
    };
    
    double areaUnderTheParable = 0;
    // Imprimir los valores del arreglo
    for (int i = 0; i < SIZE; i++) {
        
        areaUnderTheParable += medidas[i] * lenghtRect;
       }

       cout << areaUnderTheParable;
}