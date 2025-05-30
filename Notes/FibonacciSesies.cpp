#include <iostream>
#include <cstdlib>

using namespace std;

void HanoiTower(int, char, char, char);

int main(){
    int n;
    cout << "Insert the number of disk in the tower: " << endl;
    cin >> n;

    HanoiTower(n, 'A', 'B', 'C');
    return 0;
}

void HanoiTower(int n, char originTower, char auxTower,  char destinedTower){
    if(n==1){
        cout << "Move disk: " << n << " of " << originTower << " to " << destinedTower << endl;
    }else{
        HanoiTower(n-1, originTower, destinedTower, auxTower);
        cout << "Move disk "<< n << " from " << originTower << " to " << destinedTower << endl;
        HanoiTower(n-1,auxTower, originTower,  destinedTower);
    }
}