/*Simula el sistema de espera en una montania tusa donde las personas entran en orden y se les    
asigna un asiento automaticamente 
Cada personas tiene: 
-Nombre
-Numero se asiento (asignado automaticamente y secuencialmente) 
-Categorua (Adulto, ninio, etc)

Requerimientos
1. UNa Queue y un struct Persona 
2. IMplementa: 
	a. agregarPersonas(): Agrega una persona a la cola con su numero de asiento
	b. mostrarCola(): Muestra todas las personas en espera.
	c. inciarViaje(): elimina de la cola a un grupo sde personas (por ejemplo, 5) ymuestra
		los datos de las personas que suben al viaje. 
3. Muestra mensajes clastos cuando no haya personas en la cola.

NOTA: EL menu es opcional, servira para probar de forma interactiva como cambian los resultados*/

#include <iostream>
#include <queue>

using namespace std;
struct Persona {
    string nombre;
    int numeroAsiento;
    string categoria;
};
queue<Persona> cola;
int siguienteNumeroAsiento = 1;
void agregarPersonas() {
    Persona nuevaPersona;
    cout << "Ingrese el nombre de la persona: ";
    cin >> nuevaPersona.nombre;
    cout << "Ingrese la categoria (Adulto/Ninio): ";
    cin >> nuevaPersona.categoria;
    nuevaPersona.numeroAsiento = siguienteNumeroAsiento++;
    cola.push(nuevaPersona);
    cout << "Persona agregada con exito. Numero de asiento: " << nuevaPersona.numeroAsiento << endl;
}

void mostrarCola() {
    if (cola.empty()) {
        cout << "No hay personas en la cola." << endl;
        return;
    }
    queue<Persona> copiaCola = cola;
    cout << "Personas en la cola:" << endl;
    while (!copiaCola.empty()) {
        Persona p = copiaCola.front();
        cout << "Nombre: " << p.nombre << ", Numero de Asiento: " << p.numeroAsiento << ", Categoria: " << p.categoria << endl;
        copiaCola.pop();
    }
}

void iniciarViaje(int numeroPersonas) {
    if (cola.empty()) {
        cout << "No hay personas en la cola para iniciar el viaje." << endl;
        return;
    }
    cout << "Iniciando viaje con las siguientes personas:" << endl;
    for (int i = 0; i < numeroPersonas; ++i) {
        if (cola.empty()) {
            cout << "No hay mas personas en la cola." << endl;
            break;
        }
        Persona p = cola.front();
        cout << "Nombre: " << p.nombre << ", Numero de Asiento: " << p.numeroAsiento << ", Categoria: " << p.categoria << endl;
        cola.pop();
    }
}

int main() {
    int opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Agregar Persona\n";
        cout << "2. Mostrar Cola\n";
        cout << "3. Iniciar Viaje\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                agregarPersonas();
                break;
            case 2:
                mostrarCola();
                break;
            case 3: {
                int numeroPersonas;
                cout << "Ingrese el numero de personas para iniciar el viaje: ";
                cin >> numeroPersonas;
                iniciarViaje(numeroPersonas);
                break;
            }
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);
    return 0;
}