#include <iostream>

using namespace std;

int fibonacciSequence(int);

int main(){\

    int num = 100, aux, suma; 

    cout << "The Armstrong numbers of 3 digits are: " << endl;

    while(num < 1000){
        aux = num;
        suma = 0;
        while(aux > 0){
            suma += ((aux%10) * (aux%10) * (aux%10));
            aux/=10;
        }

        if(num == suma){
            cout << num << endl;
        }
        num++;
    }
    return 0;
}