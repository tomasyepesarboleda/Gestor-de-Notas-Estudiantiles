#include <iostream>
#include <string>
using namespace std;

// -----------------------------
// ESTRUCTURA DEL NODO
// -----------------------------
struct Nodo {
    int codigo;               // Código del estudiante
    string nombre;            // Nombre del estudiante
    string asignatura;        // Asignatura inscrita
    float nota;               // Nota final
    Nodo* siguiente;          // Puntero al siguiente nodo
};

// Puntero al inicio de la lista
Nodo* cabeza = nullptr;

// -----------------------------
// FUNCIONES
// -----------------------------

// Registrar estudiante (insertar nodo al final)
void insertar() {
    Nodo* nuevo = new Nodo();
    cout << "\n--- REGISTRO DE ESTUDIANTE ---\n";
    cout << "Codigo: "; cin >> nuevo->codigo;
    cin.ignore();
    cout << "Nombre: "; getline(cin, nuevo->nombre);
    cout << "Asignatura: "; getline(cin, nuevo->asignatura);
    cout << "Nota final: "; cin >> nuevo->nota;
    nuevo->siguiente = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        Nodo* aux = cabeza;
        while (aux->siguiente != nullptr)
            aux = aux->siguiente;
        aux->siguiente = nuevo;
    }

    cout << "Estudiante registrado correctamente.\n";
}

// Mostrar todos los estudiantes
void mostrar() {
    if (cabeza == nullptr) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    Nodo* aux = cabeza;
    cout << "\n--- LISTA DE ESTUDIANTES ---\n";
    while (aux != nullptr) {
        cout << "Codigo: " << aux->codigo << endl;
        cout << "Nombre: " << aux->nombre << endl;
        cout << "Asignatura: " << aux->asignatura << endl;
        cout << "Nota: " << aux->nota << endl;
        cout << "-----------------------------\n";
        aux = aux->siguiente;
    }
}

// Buscar estudiante por código
void buscar() {
    int codigoBuscado;
    cout << "\nIngrese el codigo del estudiante a buscar: ";
    cin >> codigoBuscado;

    Nodo* aux = cabeza;
    while (aux != nullptr) {
        if (aux->codigo == codigoBuscado) {
            cout << "\n--- ESTUDIANTE ENCONTRADO ---\n";
            cout << "Nombre: " << aux->nombre << endl;
            cout << "Asignatura: " << aux->asignatura << endl;
            cout << "Nota: " << aux->nota << endl;
            return;
        }
        aux = aux->siguiente;
    }

    cout << "No se encontro el estudiante.\n";
}

// Calcular promedio general
void calcularPromedio() {
    if (cabeza == nullptr) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    float suma = 0;
    int contador = 0;
    Nodo* aux = cabeza;
    while (aux != nullptr) {
        suma += aux->nota;
        contador++;
        aux = aux->siguiente;
    }

    cout << "\nPromedio general del grupo: " << (suma / contador) << endl;
}

// Mostrar aprobados y reprobados
void mostrarAprobadosReprobados() {
    if (cabeza == nullptr) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    cout << "\n--- APROBADOS ---\n";
    Nodo* aux = cabeza;
    while (aux != nullptr) {
        if (aux->nota >= 3.0)
            cout << aux->nombre << " (" << aux->nota << ")\n";
        aux = aux->siguiente;
    }

    cout << "\n--- REPROBADOS ---\n";
    aux = cabeza;
    while (aux != nullptr) {
        if (aux->nota < 3.0)
            cout << aux->nombre << " (" << aux->nota << ")\n";
        aux = aux->siguiente;
    }
}

// -----------------------------
// MENÚ PRINCIPAL
// -----------------------------
int main() {
    int opcion;
    do {
        cout << "\n========= MENU PRINCIPAL =========\n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Buscar estudiante\n";
        cout << "4. Calcular promedio general\n";
        cout << "5. Ver aprobados y reprobados\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: insertar(); break;
            case 2: mostrar(); break;
            case 3: buscar(); break;
            case 4: calcularPromedio(); break;
            case 5: mostrarAprobadosReprobados(); break;
            case 6: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 6);

    return 0;
}
