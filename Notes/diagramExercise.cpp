#include <iostream>

using namespace std;

    int hours;
    float salary, hourlyRate;
    string name, flag;

int main(){

    system("clear");

    do
    {
        cout << "Insert your name, hours and hourly rate:" << endl;
        getline(cin, name);
        cin >> hours;
        cin >> hourlyRate;

        if(hours <= 40){
            salary = hours * hourlyRate;
        }else{
            salary = (hours-40) * 1.5 * hourlyRate + 40 * hourlyRate;
        }

        cout << "The salary of " << name << " is: " << salary << endl;

        cout << "You wish to continue?" << "[y]yes  [n]no" << endl;
        cin >> flag;

        cin.clear();
        cin.ignore(100, '\n');

    } while (flag == "y");
    

    return 0;
}