#include <iostream>

using namespace std;


int main(){

    int n=2, counter =1;
    bool prime = true;

    while(counter < 101){
        for(int i = 2; i <= (n/2); i++){
            if(n%i == 0){
                prime = false;
                break;
            }
        }
        if(prime == true){
            cout << n << endl;
            counter++;
        }
        else{
            prime = true;
        }
        n++;
    }

   

    
    return 0;
}