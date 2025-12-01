#include <iostream>
// Matriz dinamica

using namespace std;

int main()
{
    // n = numero de filas
    // m = numero de columnas

    int n, m;

    cout << "Ingrese el numero de filas: ";
    cin >> n;
    cout << "Ingrese el numero de columnaas: ";
    cin >> m;
    
    int **matriz = new int *[n];

    for (int i = 0; i < n; i++)
    {
        matriz[i] = new int[m];
    }

    int value = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(*(matriz + i) + j) = value++;
        }
    }

    cout << "Matriz: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << *(*(matriz + i) + j) << "\t";
        }
        cout << endl;
    }

    // Liberar memoria
    for (int i = 0; i < n; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz; // Liberar la memoria de las filas

    return 0;
}