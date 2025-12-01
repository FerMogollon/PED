#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    queue<string> cola;
    int opcion;

    do
    {
        cout << "Menu de opciones" << endl;
        cout << "1. Agregar jugador" << endl;
        cout << "2. Mostrar orden de turnos" << endl;
        cout << "3. Avanzar (rotar)" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        if (!cin)
        {
            cin.clear();            // Limpiar el estado de error
            cin.ignore(1000, '\n'); // Ignorar la entrada incorrecta
            cout << "Error: Entrada invalida. Por favor ingrese un numero." << endl;
            return 1;
        }
        switch (opcion)
        {
        case 1:
        {
            string jugador;
            cout << "Ingrese el nombre del jugador: ";
            cin >> jugador;
            cola.push(jugador);
            break;
        }
        case 2:
        {
            if (cola.empty())
            {
                cout << "No hay jugadores en la cola." << endl;
            }
            else
            {
                cout << "Orden de turnos: ";
                queue<string> temp = cola; // Crear una copia temporal para mostrar sin modificar la original
                while (!temp.empty())
                {
                    cout << temp.front() << " ";
                    temp.pop();
                    if (!temp.empty())
                        cout << "-> ";
                }
                cout << endl;
            }
            break;
        }
        case 3:
        {
            if (cola.empty())
            {
                cout << "No hay jugadores en la cola." << endl;
            }
            else
            {
                string jugadorActual = cola.front();
                cola.pop();
                cola.push(jugadorActual);
                cout << "Turno avanzado. Ahora es el turno de: " << cola.front() << endl;
            }
            break;
        }
        case 4:
            cout << "Saliendo del programa." << endl;
            break;
        }
    } while (opcion != 4);
    return 0;
}