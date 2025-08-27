#include <iostream>

using namespace std;

int main()
{

    int n = 0;

    cout << "Cuantas tablas de multiplicar quieres? ";
    cin >> n;

    int matrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }

    cout << "Tabla de multiplicar de " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
