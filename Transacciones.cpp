#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*Caso práctico: “Detección de transacciones sospechosas en un banco”

Imagina que trabajas en el sistema de un banco, tu tarea es analizar una lista de transacciones y:

Detectar si algún cliente hizo transacciones duplicadas (mismo monto y misma cuenta el mismo día).

Contar cuántas transacciones hizo cada cliente.

Conceptos a practicar:

unordered_set: detectar duplicados rápidamente (transacciones repetidas).

unordered_map: llevar estadísticas por cliente (conteo de transacciones).

Hash eficiente en tiempo promedio O(1). */

void agregarTransaccion(unordered_set<string> &transacciones, const string &transaccion)
{
    auto resultado = transacciones.insert(transaccion);
    if (resultado.second)
    {
        cout << "Transacción agregada: " << transaccion << endl;
    }
    else
    {
        cout << "Transacción duplicada detectada: " << transaccion << endl;
    }
}

void detectarDuplicados(const unordered_set<string> &transacciones, const string &transaccion)
{
    if (transacciones.find(transaccion) != transacciones.end())
    {
        cout << "Transacción duplicada encontrada: " << transaccion << endl;
    }
    else
    {
        cout << "Transacción única: " << transaccion << endl;
    }
}

void contarTransacciones(unordered_map<string, int> &conteoClientes, const string &cliente)
{
    conteoClientes[cliente]++;
    cout << "Cliente: " << cliente << ", Total de transacciones: " << conteoClientes[cliente] << endl;
}


int main()
{
}