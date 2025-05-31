    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;

    bool matchPattern(const string& text, const string& pattern) {
        int n = text.size();
        int m = pattern.size();

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && text[i + j] == pattern[j]) {
                j++;
            }
            if (j == m) return true;
        }
        return false;
    }

    int main() {
        vector<string> products = {
            "Laptop Lenovo ThinkPad",
            "Smartphone Samsung Galaxy",
            "Smartwatch Apple Watch",
            "Laptop HP Pavilion",
            "Tablet Samsung Galaxy Tab",
            "Mouse Logitech",
            "Laptop Dell Inspiron"
        };

        string pattern;
        cout << "Enter search pattern: ";
        getline(cin, pattern);

        bool found = false;
        cout << "\nMatching products:\n";
        for (const string& product : products) {
            if (matchPattern(product, pattern)) {
                cout << "- " << product << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No products match the search pattern." << endl;
        }

        return 0;
    }
