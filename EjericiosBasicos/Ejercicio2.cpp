/*Suma de vectores
    - Crea dos arreglos de tamaño n.
    - Implementa funciones para:
        - Llenar ambos arreglos con números enteros.
        - Calcular la suma elemento a elemento en un tercer arreglo.
        - Calcular el producto escalar de los dos vectores.*/

#include <iostream>
#include <vector>
using namespace std;

//PROTOTIPOS
vector<int> llenarArreglo(); //Llenar un arreglo

void vectorSuma(vector<int> n, vector<int> m); //Sumar dos arreglos

int Escalar(vector<int> n, vector<int> m); //Calcular el producto escalar de dos arreglos

int main()
{
    vector<int> n; //Definimos un vector para almacenar los numeros aleatorios
    vector<int> m; //Definimos un vector para almacenar los numeros aleatorios

    n = llenarArreglo(); //Llenamos el primer arreglo
    m = llenarArreglo(); //Llenamos el segundo arreglo

    cout << "Arreglo 1: ";
    for (int i = 0; i < 5; i++)
    {
        cout << n.at(i) << " "; //Imprimimos el primer arreglo
    }

    cout << endl;

    cout << "Arreglo 2: ";
    for (int i = 0; i < 5; i++)
    {
        cout << m.at(i) << " "; //Imprimimos el segundo arreglo
    }

    cout << endl;

    cout << "-----------------------" << endl;
    vectorSuma(n, m); //Sumamos ambos arreglos
    cout << "-----------------------" << endl;
    cout << "El escalar de ambos vectores es: " << Escalar(n, m) << endl; //Calculamos el producto escalar de ambos arreglos
    return 0;
}

//Funcion para llenar un arreglo
vector<int> llenarArreglo()
{
    vector<int> n;
    cout << "Llene el arreglo de tamanio 5" << endl;

    for (int i = 0; i < 5; i++)
    {
        int x = 0;
        cin >> x;
        n.push_back(x); //Agregamos el numero al final del vector
    }

    return n; //Retornamos el vector lleno
    cout << endl;
}

//Funcion para sumar dos arreglos
void vectorSuma(vector<int> n, vector<int> m)
{
    vector<int> w; //Definimos un vector para almacenar la suma de ambos arreglos

    for (int i = 0; i < 5; i++)
    {
        int x = 0; //Variable para almacenar la suma de ambos arreglos
        x = n.at(i) + m.at(i); //Sumamos los elementos de ambos arreglos

        w.push_back(x); //Agregamos la suma al final del vector
    }

    for (int i = 0; i < 5; i++)
    {
        cout << w.at(i) << " "; //Imprimimos el vector suma
    }

    cout << endl;
}

//Funcion para calcular el producto escalar de dos arreglos
int Escalar(vector<int> n, vector<int> m)
{
    int x = 0;

    for (int i = 0; i < 5; i++)
    {
        x += n.at(i) * m.at(i); //Calculamos el producto escalar de ambos arreglos
    }

    return x; //Retornamos el producto escalar
}
