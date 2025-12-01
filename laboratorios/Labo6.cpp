#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

struct Habitacion {
    int numero;
    string tipo;
    double precioPorNoche;
    int capacidad;
    bool disponible;
};

list<Habitacion> habitacion;

void ordenarPorprecio(list<Habitacion>& habitaciones);
void mostrarHabitaciones(const list<Habitacion> lista);
void BuscarHabitacion(list<Habitacion>& habitacion, int numeroBuscado);
Habitacion agregarHabitacion();

int main() {

    int opcion;
    do {
        cout << "Menu de opciones:\n";
        cout << "1. Agregar habitacion\n";
        cout << "2. Mostrar habitaciones\n";
        cout << "3. Ordenar habitaciones por precio\n";
        cout << "4. Buscar habitacion por numero\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Habitacion nuevaHabitacion = agregarHabitacion();
                habitacion.push_back(nuevaHabitacion);
                break;
            }
            case 2:
                mostrarHabitaciones(habitacion);
                break;
            case 3:
                ordenarPorprecio(habitacion);
                cout << "Habitaciones ordenadas por precio.\n";
                break;
            case 4: {
                int numeroBuscado;
                cout << "Ingrese el numero de habitacion a buscar: ";
                cin >> numeroBuscado;
                BuscarHabitacion(habitacion, numeroBuscado);
                break;
            }
            case 5:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 5);
    
    return 0;
}

void BuscarHabitacion(list<Habitacion>& Habitaciones, int numeroBuscado) {

    auto comparar = [](const Habitacion& a, const Habitacion& b) {
        return a.numero < b.numero;
    };

    Habitaciones.sort(comparar);

    Habitacion buscar{};
    buscar.numero = numeroBuscado;

    auto iterador = lower_bound(Habitaciones.begin(), Habitaciones.end(), buscar, comparar);

    if (iterador != Habitaciones.end() && iterador->numero == numeroBuscado) {
        cout << "Habiteradoración encontrada:\n";
        cout << "Número: " << iterador->numero << endl;
        cout << "Tipo: " << iterador->tipo << endl;
        cout << "precioPorNoche: $" << iterador->precioPorNoche << endl;
        cout << "Capacidad: " << iterador->capacidad << endl;
        cout << "disponible: " << (iterador->disponible ? "Reservada" : "Disponible") << endl;
    } else {
        cout << "No se encontró la habitacion de número " << numeroBuscado << ".\n";
    }
}

Habitacion agregarHabitacion() {
    Habitacion h;
    cout << "Ingrese el numero de habitacion: " << endl;
    cin >> h.numero;
    cout << "Ingrese el tipo de habitacion: " << endl;
    getline(cin >> ws, h.tipo);
    cout << "Ingrese el precio" << endl;
    cin >> h.precioPorNoche;
    cout << "Ingrese la capacidad" << endl;
    cin >> h.capacidad;
    cout << "La habitacion esta disponible? (1 para si, 0 para no): " << endl;
    cin >> h.disponible;
    return h;
}

void mostrarHabitaciones(const list<Habitacion> lista){
    cout << "Lista de Habitaciones:" << endl;
    for (const auto& h : lista) {
        cout << "Tipo de habitacion: " << h.tipo << endl;
        cout << "precioPorNoche: " << h.precioPorNoche << endl;
        cout << "Capacidad: " << h.capacidad << endl;
        if (h.disponible) {
            cout << "disponible: Reservada" <<endl; }
        else {
            cout << "disponible: Disponible" <<endl; }
        cout << "------------------------" << endl;
    }
}

void ordenarPorprecio(list<Habitacion>& habitaciones) {
    habitaciones.sort([](const Habitacion& a, const Habitacion& b) {
        return a.precioPorNoche< b.precioPorNoche;
    });
}