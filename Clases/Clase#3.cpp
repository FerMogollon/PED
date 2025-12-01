#include <iostream>

using namespace std;

int suma (int* numbers, int n) 
{
    int resultado = 0; 

    for (int i = 0; i < n; i++) 
    {

        //numbers + 0 -> direccion del primer elemento
        //numbers + 1 -> direccion del segundo elemento
        //numbers + 2 -> direccion del tercer elemento
        // numbers + i -> direccion del elemento i
        // * (numbers + i) -> valor del elemento i (un puntero a int)
        // *(*numbers + i) -> valor del elemento i (un int)
        resultado += *(numbers + i);
    }

    return resultado;
}

int main()
{
    int n = 5;
    int numeros[5] = {1, 2, 3, 4, 5};

    int res  = suma (numeros, n);

    cout << "La suma es: " << res << endl;
    return 0;
}