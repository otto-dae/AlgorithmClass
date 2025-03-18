#include <iostream>

using namespace std;

int fibonacciSequence(int);

int main(){

    int n;
    cout << "Enter the amount of digits to found in the fibonacci sequence: " << endl;
    cin >> n;
    
    for(int i = 0; i <= n; n--){
        cout << fibonacciSequence(n-1);

    }
    return 0;
}   

int fibonacciSequence(int n){

    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    return fibonacciSequence(n-1) + fibonacciSequence(n-2);
}