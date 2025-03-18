#include <iostream>
#include <math.h>

int contar(int);

using namespace std;

int main() {

    cout << "Insert a number" << endl;
    int x;
    cin >> x;
    
    double sqrtHand = pow(x, 0.5);

    cout << "The sqrt of " << x << "is: " << sqrtHand;

}

