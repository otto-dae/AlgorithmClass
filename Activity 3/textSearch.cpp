#include <iostream>
#include <string>
using namespace std;

int searchPattern(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            return i; // Devuelve la posición donde se encontró el patrón
        }
    }

    return -1; // Devuelve -1 si el patrón no se encuentra
}

int main() {
    string text = "Este es un ejemplo de búsqueda de patrón en un texto.";
    string pattern;

    cout << "Introduce una palabra a buscar: " << endl;
    cin >> pattern;

    int result = searchPattern(text, pattern);

    if (result != -1) {
        cout << "Patron encontrado en la posicion " << result << endl;
    } else {
        cout << "Patron no encontrado en el texto" << endl;
    }

    return 0;
}