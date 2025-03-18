#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    string names [] = {
        "Otto",
        "Armando",
        "Zicklose",
        "Juan Pablo"
    };

    sort(begin(names), end(names));

    for(int i = 0; i < sizeof(names)/sizeof(names[0]); i++)
  {
    cout << names[i] << endl;
  }

  return 0;
}