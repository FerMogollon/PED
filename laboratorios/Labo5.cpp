#include <iostream>
#include <queue>
using namespace std;

struct persona{
string nombre;
int asiento;
string categoria;
};
int cont = 0;
queue<persona> cola;

void mostrarCola();
void agregarPersona(queue<persona>& cola, int& cont);
void IniciarViaje(queue<persona>& pasajeros);

int main(){
    
    int op;
    do{
        cout << "Menu de opciones" << endl;
        cout << "1. Agregar persona a la cola" << endl;
        cout << "2. Mostrar cola" << endl;
        cout << "3. Iniciar viaje" << endl;
        cout << "4. Salir" << endl;
        cin >> op;

        switch(op){
            case 1:
                agregarPersona(cola, cont);
                break;
            case 2:
                mostrarCola();
                break;
            case 3:
                IniciarViaje(cola);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
        }
    } while (op != 4);


    return 0;
}


void IniciarViaje(queue<persona>& pasajeros) {
int cantidad = 0;

	if (pasajeros.empty()) {
		cout << "No hay pasajeros para iniciar el viaje." <<endl;
		return;
	}

	do{
		persona p = pasajeros.front();
		pasajeros.pop();
		cout << "Iniciando viaje para el pasajero: :" << endl;
		cout << "Nombre: " << p.nombre << ", asiento: " << p.asiento << ", categoria: " << p.categoria << endl;
    } while (!pasajeros.empty() && ++cantidad < 2);
}

void mostrarCola() {
    if (cola.empty()) {
        cout << "No hay personas en la cola en este momento." << endl;
        return;
    }
    queue<persona> copiaCola = cola;
    cout << "Personas en la cola:" << endl;
    while (!copiaCola.empty()) {
        persona p = copiaCola.front();
        cout << "Nombre: " << p.nombre << ", Numero de Asiento: " << p.asiento << ", Categoria: " << p.categoria << endl;
        copiaCola.pop();
    }
}

void agregarPersona(queue<persona>& cola, int& cont){
    int op;
    cout << "Cuantas personas desea agregar a la cola?" << endl;
    cin >> op;
    for (int i = 0; i < op ; i++){
    persona p;
    cout << "Ingrese nombre: " << endl;
    cin >> p.nombre;
    cout << "Ingrese su categoria" << endl;
    cin >> p.categoria;
    p.asiento = cont + 1;
    cola.push(p);
    cont++;
    }
}