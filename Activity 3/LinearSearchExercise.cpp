#include <iostream>
#include <string>
using namespace std;

// Structure to store name and phone number
struct Friend {
    string name;
    string phone;
};

// Linear search function
int linearSearch(Friend friends[], int size, string target) {
    for (int i = 0; i < size; i++) {
        if (friends[i].phone == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    const int size = 6;
    Friend friends[size] = {
        {"Carlos", "52 55 1234 5678"},
        {"Valeria", "52 33 9876 5432"},
        {"Luis", "52 81 2468 1357"},
        {"Sofia", "52 55 7654 3210"},
        {"Ana", "52 33 1122 3344"},
        {"Diego", "52 81 9988 7766"}
    };

    string number;
    cout << "Enter the number to search (format: 52 xx xxxx xxxx):" << endl;

    getline(cin, number); // No cin.ignore() needed here if there was no cin >> before

    int result = linearSearch(friends, size, number);

    if (result != -1) {
        cout << "Your friend is: " << friends[result].name
             << ", phone number: " << friends[result].phone << endl;
    } else {
        cout << "Your friend is not in your contact list." << endl;
    }

    return 0;
}
