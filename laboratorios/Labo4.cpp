#include <iostream>

using namespace std;

struct nodo
{
    int id;
    char tipo;
    double monto;
    double saldoPosterior;
    nodo *anterior;
    nodo *siguiente;
};
// * es una variable que almacena la direccion de memoria de otra variable
// & se usa para obtener la direccion de memoria de una variable y modificar su valor directamente

void mostrarMovimientos(nodo *cabeza); // usamos *cabeza para indicar que es un puntero a nodo, para trabajar con la lista sin modificarla
void agregarMovimiento(nodo *&cabeza, int id, char tipo, double monto); // usamos *&cabeza para modificar el puntero original
void recalcularSaldo(nodo *cabeza); // usamos *cabeza para indicar que es un puntero a nodo
void eliminarMovimiento(nodo *&cabeza, int ident); // usamos *&cabeza para modificar el puntero original

int main()
{
    nodo *cabeza = nullptr;
    int opcion, id;
    char tipo;
    double monto;

    do
    {
        cout << "\n1. Agregar movimiento\n2. Mostrar movimientos\n3. Eliminar movimiento\n4. Salir\nOpcion: ";
        cin >> opcion;
        if (!cin)
        {
            cout << "Entrada invalida. Por favor ingrese un numero entero.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        switch (opcion)
        {
        case 1:
            cout << "ID: ";
            cin >> id;
            cout << "Tipo (D/R): ";
            cin >> tipo;
            if (tipo != 'D' && tipo != 'R')
            {
                cout << "Tipo invalido. Use 'D' para deposito y 'R' para retiro.\n";
                break;
            }
            cout << "Monto: ";
            cin >> monto;
            agregarMovimiento(cabeza, id, tipo, monto);
            break;
        case 2:
            mostrarMovimientos(cabeza);
            break;
        case 3:
            cout << "ID a eliminar: ";
            cin >> id;
            if (!cin)
            {
                cout << "Entrada invalida. Por favor ingrese un numero entero.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }
            eliminarMovimiento(cabeza, id);
            break;
        default:
            if (opcion != 4)
                cout << "Opcion invalida.\n";
            break;
        }
    } while (opcion != 4);

    // Esto se usa para liberar la memoria al final
    nodo *actual = cabeza;
    while (actual != nullptr)
    {
        nodo *temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    return 0;
}

void mostrarMovimientos(nodo *cabeza)
{
    nodo *actual = cabeza; // usamos un puntero auxiliar para recorrer la lista sin modificar el puntero original

    if (actual == nullptr) // lista vacia
    {
        cout << "No hay movimientos para mostrar.\n";
        return;
    }
    cout << "Movimientos de la cuenta:" << endl;
    cout << "ID\tTipo\tMonto\tSaldo Posterior" << endl;
    while (actual != nullptr)
    {
        cout << actual->id << "\t" << actual->tipo << "\t" << actual->monto << "\t" << actual->saldoPosterior << endl;
        actual = actual->siguiente;
    }
}

void agregarMovimiento(nodo *&cabeza, int id, char tipo, double monto) // usamos *&cabeza para modificar el puntero original
{
    nodo *nuevo = new nodo(); // crear nuevo nodo, asignar memoria dinámicamente, * para que persista fuera de la función
    nuevo->id = id; // -> se usa para acceder a los miembros de una estructura a través de un puntero
    nuevo->tipo = tipo;
    nuevo->monto = monto;
    nuevo->siguiente = nullptr;
    nuevo->anterior = nullptr; // nuevo nodo no tiene anterior aún

    if (cabeza == nullptr) // lista vacia
    {
        if (tipo == 'D')
        {
            nuevo->saldoPosterior = monto;
        }
        else
        {
            nuevo->saldoPosterior = -monto;
        }
        cabeza = nuevo;
    }
    else
    {
        nodo *actual = cabeza;
        while (actual->siguiente != nullptr)
        {
            actual = actual->siguiente;
        }
        nuevo->anterior = actual;
        actual->siguiente = nuevo;
        if (tipo == 'D')
        {
            nuevo->saldoPosterior = actual->saldoPosterior + monto;
        }
        else
        {
            nuevo->saldoPosterior = actual->saldoPosterior - monto;
        }
    }
}


void recalcularSaldo(nodo * cabeza)
{
    nodo *actual = cabeza;
    double saldo = 0.0;
    while (actual != nullptr)
    {
        if (actual->tipo == 'D')
        {
            saldo += actual->monto;
        }
        else
        {
            saldo -= actual->monto;
        }
        actual->saldoPosterior = saldo;
        actual = actual->siguiente;
    }
}

void eliminarMovimiento(nodo * &cabeza, int ident)
{
    nodo *actual = cabeza;

    while (actual != nullptr && actual->id != ident)
    {
        actual = actual->siguiente;
    }

    if (actual == nullptr)
    {
        cout << "Valor no encontrado \n";
        return;
    }

    if (actual->anterior != nullptr)
    {
        actual->anterior->siguiente = actual->siguiente;
    }
    else
    {
        cabeza = actual->siguiente;
    }

    if (actual->siguiente != nullptr)
    {
        actual->siguiente->anterior = actual->anterior;
    }

    delete actual;
    recalcularSaldo(cabeza);
}