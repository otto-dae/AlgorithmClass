#include <iostream>
#include <cmath> 

using namespace std;

double logBase(double, double);
bool isBase(double, double, double);
bool isExponent(double, double, double);


int main() {
    double a= 2, b=32, c= 21;
    
    bool baseResponse = isBase(a, b, c);

    cout << boolalpha;
    cout << "Es verdad? El cambio de Base: " << baseResponse << endl;
    cout << "Es verdad? lo de la exponiencia o no se como se llame: " << isExponent(a, b, c);

    return 0;
}

double logBase(double base, double num){

    return log(num) / log(base);    
}

bool isBase(double a, double b, double c){

    double logBaseA = logBase(b, a);
    double LogBaseCA = logBase(c, a);
    double LogBaseCB = logBase(c, b);
    if(LogBaseCA / LogBaseCB == logBaseA){
        return true;
    }

    return false;
}

bool isExponent(double a, double b, double c){

    double powALog = pow(a, (logBase(a, b)));
    double LogBaseAPow = logBase(a, pow(a,b));
    if(LogBaseAPow == b && powALog == b){
        return true;
    }

    return false;
}