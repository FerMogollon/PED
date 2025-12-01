#include <iostream>

using namespace std;

// New
// Delete

int main()
{
    int n;

    do {
    cout << "Cuantos numeros quieres ingresar? " << endl;
    cin >> n;

    if (n == 0)
        break;

    // Array dinamico
    int *array = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Ingresa el numero #" << i + 1 << " : " << endl;
        cin >> array[i];
    }

    cout << "Los numeros que ingresaste son: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << endl;
    }

    delete[] array;
    } while (true);

    return 0;
}