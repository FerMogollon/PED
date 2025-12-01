#include <iostream>

using namespace std;

struct Movimiento {
    int id;
    char tipo; // 'D' para deposito, 'R' para retiro
    double monto;
    double saldoPosterior;
    Movimiento* siguiente;
    Movimiento* anterior;
};

void mostrarMovimientos(Movimiento* cabeza);
void agregarMovimiento(Movimiento*& cabeza, int id, char tipo, double monto);
void eliminarMovimiento(Movimiento*& cabeza, int id);
void recalcularSaldo(Movimiento* cabeza);

int main ()
{
    Movimiento* cabeza = nullptr;
    int opcion, id;
    char tipo;
    double monto;

    do {
        cout << "\n1. Agregar movimiento\n2. Mostrar movimientos\n3. Eliminar movimiento\n4. Salir\nOpcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1:
                cout << "ID: "; cin >> id;
                cout << "Tipo (D/R): "; cin >> tipo;
                cout << "Monto: "; cin >> monto;
                agregarMovimiento(cabeza, id, tipo, monto);
                break;
            case 2:
                mostrarMovimientos(cabeza);
                break;
            case 3:
                cout << "ID a eliminar: "; cin >> id;
                eliminarMovimiento(cabeza, id);
                break;
        }
    } while(opcion != 4);

    // Esto se usa para liberar la memoria al final
    Movimiento* actual = cabeza;
    while (actual != nullptr) {
        Movimiento* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    return 0;
}

void mostrarMovimientos(Movimiento* cabeza) {
    Movimiento* actual = cabeza;
    cout << "Movimientos de la cuenta:" << endl;
    cout << "ID\tTipo\tMonto\tSaldo Posterior" << endl;
    while (actual != nullptr) {
        cout << actual->id << "\t" << actual->tipo << "\t" << actual->monto << "\t" << actual->saldoPosterior << endl;
        actual = actual->siguiente;
    }
}

void agregarMovimiento(Movimiento*& cabeza, int id, char tipo, double monto) {
    Movimiento* nuevo = new Movimiento();
    nuevo->id = id;
    nuevo->tipo = tipo;
    nuevo->monto = monto;
    nuevo->siguiente = nullptr;
    nuevo->anterior = nullptr;

    if (cabeza == nullptr) {
        nuevo->saldoPosterior = (tipo == 'D') ? monto : -monto;
        cabeza = nuevo;
    } else {
        Movimiento* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        nuevo->anterior = actual;
        actual->siguiente = nuevo;
        nuevo->saldoPosterior = actual->saldoPosterior + ((tipo == 'D') ? monto : -monto);
    }
}

void eliminarMovimiento(Movimiento*& cabeza, int id) {
    Movimiento* actual = cabeza;
    while (actual != nullptr && actual->id != id) {
        actual = actual->siguiente;
    }
    if (actual == nullptr) {
        cout << "Movimiento con ID " << id << " no encontrado." << endl;
        return;
    }
    if (actual->anterior != nullptr) {
        actual->anterior->siguiente = actual->siguiente;
    } else {
        cabeza = actual->siguiente;
    }
    if (actual->siguiente != nullptr) {
        actual->siguiente->anterior = actual->anterior;
    }
    delete actual;
    recalcularSaldo(cabeza);
}

void recalcularSaldo(Movimiento* cabeza) {
    Movimiento* actual = cabeza;
    double saldo = 0.0;
    while (actual != nullptr) {
        saldo += (actual->tipo == 'D') ? actual->monto : -actual->monto;
        actual->saldoPosterior = saldo;
        actual = actual->siguiente;
    }
}
