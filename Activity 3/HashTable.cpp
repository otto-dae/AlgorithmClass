#include <iostream>
#include <vector>
using namespace std;

// Definimos una estructura para representar pares clave-valor
struct KeyValuePair {
    string key;
    int value;
};

// Función de hash simple que convierte una clave en un índice
int hashFunction(const string& key, int tableSize) {
    int hash = 0;
    for (char ch : key) {
        hash += ch;
    }
    return hash % tableSize;
}

// Función para buscar un valor en la tabla HASH
int searchValue(const vector<KeyValuePair>& table, const string& key) {
    int tableSize = table.size();
    int index = hashFunction(key, tableSize);

    // Realizamos una búsqueda lineal en la posición calculada
    while (index < tableSize && table[index].key != key) {
        index++;
    }

    // Si encontramos la clave, devolvemos el valor; de lo contrario, devolvemos -1
    if (index < tableSize && table[index].key == key) {
        return table[index].value;
    } else {
        return -1;
    }
}

int main() {
    setlocale(LC_ALL,"");

    // Creamos una tabla HASH simple como un vector de pares clave-valor
    vector<KeyValuePair> hashTable(100); // Tamaño de la tabla HASH

    // Insertamos algunos valores en la tabla
    hashTable[hashFunction("Melcacho", 100)] = {"Melcacho", 95};
    hashTable[hashFunction("Valeria", 100)] = {"Valeria", 87};
    hashTable[hashFunction("Javier", 100)] = {"Javier", 92};

    // Buscamos un valor en la tabla
    string name = "Bob";
    int score = searchValue(hashTable, name);

    if (score != -1) {
        cout << "La calificación de " << name << " es " << score << endl;
    } else {
        cout << name << " no está en esta escuela =c" << endl;
    }

    return 0;
}
