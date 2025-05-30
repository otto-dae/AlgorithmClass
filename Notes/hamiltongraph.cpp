#include <iostream>
#include <cstdlib>
#include <iomanip> // Para setw

using namespace std;

// Códigos ANSI para colores en consola
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define YELLOW  "\033[1;33m"
#define RESET   "\033[0m"

const int MAX_VERTICES = 10;

// Estructura para un nodo en la lista de adyacencia
struct Nodo {
    int destination;
    Nodo* next;
};

// Estructura para un vértice del grafo
struct Vertex{
    int idVertex;
    Nodo *adjacent;//puntero al inicio de la lista enlazada de nodos Nodo, que representan los vértices adyacentes a ese vértice en particular.
    Vertex *next;
};

// Puntero al inicio de la lista de vértices
Vertex *headListVertex = nullptr;
int numVertex = 0;

// Prototipos de funciones
void menu();
void insertarVertice();
void insertarArista();
void eliminarVertice();
void eliminarArista();
void buscarVertice();
//void mostrar1ConexionesVertice();
void mostrarGrafo();
bool existeCicloHamiltoniano();
bool hamiltonianoUtil(int path[], int pos);
bool esSeguro(int v, int path[], int pos);
void imprimirCicloHamiltoniano(int path[]);
Vertex * obtenerVertices(int);
bool existeArista(int, int);
//void mostrarMatrizAdyacencia();


int main() {
    system("clear");
    menu();
    return 0;
}

// Menú de opciones para el usuario
void menu() {
    int opcion;
    bool loop = true;

    do {
        cout << CYAN << "\n\t\tGRAFO - CICLO HAMILTONIANO\n" << RESET;
        cout << "\n1. Insertar Vertice";
        cout << "\n2. Insertar Arista";
        cout << "\n3. Eliminar Vertice";
        cout << "\n4. Eliminar Arista";
        cout << "\n5. Buscar Vertice";
        cout << "\n6. Mostrar Conexiones de un Vertice";
        cout << "\n7. Mostrar Grafo";
        cout << "\n8. Verificar Ciclo Hamiltoniano";
        cout << "\n9. MostrarMatrizAdyacencia";
        cout << "\n10. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                insertarVertice();
                break;
            case 2:
                insertarArista();
                break;
            case 3:
                eliminarVertice();
                break;
            case 4:
                eliminarArista();
                break;
            case 5:
                buscarVertice();
                break;
            /*case 6:
                mostrarConexionesVertice();
                break;
            case 7:
                mostrarGrafo();
                break;*/
            case 8:
                if (existeCicloHamiltoniano()) {
                    cout << YELLOW << "\n¡Existe un Ciclo Hamiltoniano!\n" << RESET;
                } else {
                    cout << RED << "\nNo existe un Ciclo Hamiltoniano.\n" << RESET;
                }
                break;
           /* case 9:
                    mostrarMatrizAdyacencia();
                break;*/
            case 10:
                loop = false;
                break;
            default:
                cout << RED << "Opción inválida.\n" << RESET;
        }
    } while(loop);
}

// Inserta un nuevo vértice si no se ha alcanzado el máximo
void insertarVertice() {
    if (numVertex >= MAX_VERTICES) {
        cout << RED << "Máximo de vértices alcanzado.\n" << RESET;
        return;
    }

    Vertex *new_vertex = new Vertex();
    new_vertex->idVertex = numVertex;
    new_vertex->adjacent = nullptr;
    new_vertex->next = headListVertex;
    headListVertex = new_vertex;
    cout << GREEN << "Vértice " << new_vertex->idVertex << " agregado.\n" << RESET;
    numVertex++;
}

// Inserta una arista entre dos vértices
void insertarArista() {
    int origin, destination;
    cout << "Ingrese vértice origen: "; cin >> origin;
    cout << "Ingrese vértice destino: "; cin >> destination;

    Vertex *vOrigin = obtenerVertices(origin);
    Vertex *vDestination = obtenerVertices(destination);

    if (!vOrigin || !vDestination) {
        cout << RED << "Uno o ambos vértices no existen.\n" << RESET;
        return;
    }

    if (existeArista(origin, destination)) {
        cout << YELLOW << "La arista ya existe.\n" << RESET;
        return;
    }

    // Agregar en lista de adyacencia (no dirigido)
   // Crear nuevo nodo para el vértice origen apuntando al destino
   Nodo* new_vertex1 = new Nodo();                  // Se reserva memoria para el nuevo nodo
   new_vertex1->destination = destination;                // Se asigna el valor del destination
   new_vertex1->next = vOrigin->adjacent;  // El next nodo será la lista actual de adjacent
   vOrigin->adjacent = new_vertex1;             // Se inserta al principio de la lista

   

     
    // Crear nuevo nodo para el vértice destino apuntando al origen (porque el grafo es no dirigido)
    Nodo* new_vertex2 = new Nodo;                  // Se repite el mismo proceso para el otro vértice
    new_vertex2->destination = origin;
    new_vertex2->next = vDestination->adjacent;
    vDestination->adjacent = new_vertex2;

    cout << GREEN << "Arista agregada entre " << origin << " y " << destination << ".\n" << RESET;
}

// Elimina un vértice y todas sus conexiones
void eliminarVertice() {
    int idVertex;
    cout << "Ingrese vértice a eliminar: ";
    cin >> idVertex;

    // Eliminar conexiones en otros vértices
    //Recorremos todos los vertices del grafo 
    Vertex* aux_deleteC = headListVertex; //aux_deleteC recorrera la lista de vertices
    while (aux_deleteC) {

//Se recorre la lista de adyacencia de cada vértice, y si uno de los nodos apunta al vértice que vas a eliminar (idVertex), 
//entonces se elimina ese nodo y se actualiza el next del nodo anterior usando *current = (*current)->next;.
//Este elimina nodos en listas enlazadas sin necesidad de usar un puntero al nodo anterior explícitamente. 
//técnica común en implementaciones eficientes y seguras de listas enlazadas    
Nodo ** current = &(aux_deleteC->adjacent);//current es un puntero a puntero que inicialmente apunta al puntero adyacente del vértice actual.
        while (*current) {
            if ((*current)->destination == idVertex) {
                Nodo* deleted = *current; //Guardamos elpuntero *current en deleted.
                *current = (*current)->next; //Reemplazamos el puntero anterior (*current) al siguiente nodo ((*current)->next), eliminando así el nodo actual de la lista.
                delete deleted;
                } else {
                current = &((*current)->next);// le decimos a current que ahora apunte al puntero que apunta al siguiente nodo.//Así, seguimos recorriendo la lista, siempre manteniendo acceso al puntero que hay que modificar si encontramos un nodo que se deba eliminar.
            }
        }
aux_deleteC = aux_deleteC ->next;// aux_deleteC es un puntero tipo Vertex*, que está recorriendo la lista de vértices del grafo.
}


    // Eliminar vértice de la lista
    Vertex **current = &headListVertex;
    while (*current) {
        if ((*current)->idVertex == idVertex) {
            Vertex *deleted = *current;
            *current = (*current)->next;

            // Liberar su lista de adyacencia
            Nodo *aux = deleted->adjacent;
            while (aux) {
                Nodo *aux_delete = aux;
                aux = aux->next;
                delete aux_delete;
            }

            delete deleted;
            numVertex--;
            cout << GREEN << "Vértice " << idVertex << " eliminado.\n" << RESET;
            return;
        }
        current = &((*current)->next);
    }

    cout << RED << "Vértice no encontrado.\n" << RESET;
}

// Elimina una arista entre dos vértices
void eliminarArista() {
    int origin, destination;
    cout << "Ingrese vértice origin: "; cin >> origin;
    cout << "Ingrese vértice destination: "; cin >> destination;

    Vertex * vOrigin = obtenerVertices(origin);
    Vertex * vDestination = obtenerVertices(destination);

    if (!vOrigin || !vDestination) {
        cout << RED << "Uno o ambos vértices no existen.\n" << RESET;
        return;
    }

    // Eliminar arista de origen a destino

    //Si la arista va de origen a destino, recorres la lista enlazada con el Nodo** 
    //para poder modificar el puntero de enlace (ya sea desde el vértice o desde un nodo intermedio).
    Nodo **ptr = &(vOrigin->adjacent);
    while (*ptr) {
        if ((*ptr)->destination == destination) {
            Nodo *deleted = *ptr;
            *ptr = (*ptr)->next;
            delete deleted;
            break;
        }
        ptr = &((*ptr)->next);
    }

    // Eliminar arista de destino a origen
    ptr = &(vDestination->adjacent);
    while (*ptr) {
        if ((*ptr)->destination == origin) {
            Nodo * deleted = *ptr;
            *ptr = (*ptr)->next;
            delete deleted;
            break;
        }
        ptr = &((*ptr)->next);
    }

    cout << GREEN << "Arista entre " << origin << " y " << destination << " eliminada.\n" << RESET;
}

// Busca un vértice por ID 
void buscarVertice() {
    int idVertex;
    cout << "Ingrese vértice a buscar: ";
    cin >> idVertex;
    if (obtenerVertices(idVertex)) {
        cout << GREEN << "El vértice " << idVertex << " existe.\n" << RESET;
    } else {
        cout << RED << "Vértice no encontrado.\n" << RESET;
    }
}

// Obtener un vértice por ID
Vertex* obtenerVertices(int id) {
    Vertex* temp = headListVertex;
    while (temp) {
        if (temp->idVertex == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}


// Muestra la lista de adyacencia del grafo
void mostrarGrafo() {
    Vertex * v = headListVertex;
    while (v) {
        cout << BLUE << v->idVertex << ": " << RESET;
        Nodo* n = v->adjacent;
        while (n) {
            cout << n->destination << " ";
            n = n->next;
        }
        cout << "\n";
        v = v->next;
    }
}


// Verifica si existe una arista entre dos vértices
bool existeArista(int origin, int destination) {
    Vertex *v = obtenerVertices(origin);
    Nodo *n = v->adjacent;
    while (n) {
        if (n->destination == destination) return true;
        n = n->next;
    }
    return false;
}

// CICLO HAMILTONIANO
bool existeCicloHamiltoniano() {
    int path[MAX_VERTICES];
    

    for (int i = 0; i < MAX_VERTICES; i++) path[i] = -1;

    path[0] = 0;
     
     if (hamiltonianoUtil(path, 1)) {
        imprimirCicloHamiltoniano(path);
        return true;
    }
    return false;
}

bool hamiltonianoUtil(int path[], int pos) {
    if (pos == numVertex) {
        return existeArista(path[pos - 1], path[0]);
    }

    for (int v = 1; v < numVertex; v++) {
         
            if (esSeguro(v, path, pos)) {
            path[pos] = v;
             
             if (hamiltonianoUtil(path, pos + 1)) return true;
            path[pos] = -1;
        }
    }
    return false;
}

 
bool esSeguro(int v, int path[], int pos) {
    if (!existeArista(path[pos - 1], v)) return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

void imprimirCicloHamiltoniano(int path[]) {
    cout << GREEN << "Ciclo Hamiltoniano: ";
    for (int i = 0; i < numVertex; i++) {
        cout << path[i] << " -> ";
    }
    cout << path[0] << "\n" << RESET;
}