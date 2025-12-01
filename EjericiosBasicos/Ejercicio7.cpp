/*7. Arreglo estático
    - Declara un arreglo estático de enteros de tamaño 10.
    - Llénalo con valores aleatorios entre 1 y 100.
    - Implementa funciones para:
        - Encontrar el máximo.
        - Encontrar el mínimo.
        - Calcular el promedio.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int maxValor(int x[]);
int minValor(int x[]);
float Promedio(int x[]);

int main()
{
    int Arr[10];
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int n = rand() % 101;
        Arr[i] = n;
    }

    cout << "Array Principal: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << Arr[i] << "\t";
    }
    cout << endl;

    cout << "-----------------------------------" << endl;

    int k = maxValor(Arr);
    cout << "El mayor valor esta en la posiciom " << k << endl;

    cout << "-----------------------------------" << endl;

    int j = minValor(Arr);
    cout << "El menor valor esta en la posiciom " << j << endl;

    cout << "-----------------------------------" << endl;

    float p = Promedio(Arr);
    cout << "El promedio es " << p << endl;

    return 0;
}

int maxValor(int x[])
{
    int Max = 0;

    for (int i = 0; i < 10; i++)
    {
        if (x[i] > x[Max])
        {
            Max = i;
        }
    }

    return Max;
}

int minValor(int x[])
{
    int Min = 0;

    for (int i = 0; i < 10; i++)
    {
        if (x[i] < x[Min])
        {
            Min = i;
        }
    }

    return Min;
}

float Promedio(int x[])
{
    float N = 0;
    float Promedio;

    for (int i = 0; i < 10; i++)
    {
        N += x[i];
    }

    Promedio = N / 10;

    return Promedio;
}
