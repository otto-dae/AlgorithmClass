#include <iostream>
#include <string>
using namespace std;

int binarySearch(string books[], int size, string target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (books[mid] == target) {
            return mid;
        } else if (books[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1; 
        }
    }

    return -1;
}

int main() {
    const int size = 8;
    string books[size] = {
        "A Tale of Two Cities",
        "Brave New World",
        "Crime and Punishment",
        "Don Quixote",
        "Moby Dick",
        "Pride and Prejudice",
        "The Great Gatsby",
        "To Kill a Mockingbird"
    };

    string target;
    cout << "Enter the book title to search (exact match, case sensitive):" << endl;
    getline(cin, target);

    int result = binarySearch(books, size, target);

    if (result != -1) {
        cout << "Book found: " << books[result] << endl;
    } else {
        cout << "Book not found in the list." << endl;
    }

    return 0;
}
