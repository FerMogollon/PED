/*Matrices y funciones
    - Trabaja con una matriz estática de 5x5.
    - Implementa funciones que:
        - Llenen la matriz con números aleatorios.
        - Calculen la suma de cada fila y de cada columna.
        - Encuentren la fila con la mayor suma.
        - Trasponer la matriz.
        */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


//Se requiere una matriz 5x5
const int Filas = 5;
const int Columnas = 5;

//PROTOTIPOS 

vector<vector<int>> llenarMatriz(vector<vector<int>> m);  //Llenar una matriz

void imprimirMatriz(vector<vector<int>> m); //Imprimir una Matriz

vector<vector<int>> sumaFilas(vector<vector<int>>);//Sumar las filas de una Matriz

vector<vector<int>> sumaColumnas(vector<vector<int>> m); //Sumar las columnas de una Matriz

size_t filaMayorSuma(vector<vector<int>> m); //Econtrar la fila de mayor suma

vector<vector<int>> Trasponer (vector<vector<int>> m); // Trasponer una Matriz

int main()
{
    //Inicializamos semilla
    srand(time(0)); 

    //Definimos la Matriz Principal 5x5 y la rellenamos con ceros
    vector<vector<int>> matriz(Filas, vector<int>(Columnas, 0));

    //IMPLEMENTACION DE FUNCIONES EN EL MAIN

    matriz = llenarMatriz(matriz);
    cout << "Matriz Principal: " << endl;
    imprimirMatriz(matriz);

    cout << "---------------------------" << endl;

    vector<vector<int>> sumFilas = sumaFilas(matriz);
    cout << "Sum de cada fila de la matriz: " << endl;
    imprimirMatriz(sumFilas);

    cout << "---------------------------" << endl;

    vector<vector<int>> sumColumnas = sumaColumnas(matriz);
    cout << "Sum de cada columnas de la matriz: " << endl;
    imprimirMatriz(sumColumnas);

    cout << "---------------------------" << endl;

    cout << "Fila con la mayor suma: " <<  filaMayorSuma(sumFilas) << endl; 
    //Pasamos la matriz de sumas de filas
    //Usamos la matriz de sumas de filas porque es mas eficiente que recorrer la matriz original
    //Ya que la matriz de sumas de filas tiene solo 5 elementos, mientras que la matriz original tiene 25
    cout << "---------------------------" << endl;

    cout << "Matriz Principal Traspuesta: " << endl;
    vector<vector<int>> Traspuesta = Trasponer (matriz);
    imprimirMatriz (Traspuesta);

    return 0;
}

//FUNCION PARA LLENAR MATRIZ

//Dato de tipo vector de vectores de enteros, que recibe una matriz
vector<vector<int>> llenarMatriz(vector<vector<int>> m)

{
    //Llenamos la matriz con numeros aleatorios del 0 al 9
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m.at(i).size(); j++)
        {

            //Los indices i y j recorren la matriz, y en cada posicion se asigna un numero aleatorio
            m.at(i).at(j) = rand() % 10;
        }
    }

    //Retornamos la matriz ya llena
    return m;
}

//Funcion para imprimir la matriz
void imprimirMatriz(vector<vector<int>> m)
{
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m.at(i).size(); j++)
        {
            cout << m.at(i).at(j) << "\t";
        }

        cout << endl;
    }
}

//Funcion para sumar las filas de una matriz
vector<vector<int>> sumaFilas(vector<vector<int>> m)
{
    //Definimos una matriz de 5x1 para almacenar las sumas de cada fila
    vector<vector<int>> matriz(Filas, vector<int>(1, 0));
    for (size_t i = 0; i < m.size(); i++)
    {
        //Inicializamos un contador para sumar los elementos de cada fila
        int n = 0;

        //Sumamos los elementos de la fila i
        //at.(i) nos da la fila i, y luego recorremos esa fila con j
        for (size_t j = 0; j < m.at(i).size(); j++)
        {

            //Sumamos el elemento j de la fila i
            n += m.at(i).at(j);
        }

        //Asignamos la suma de la fila i a la matriz de sumas
        matriz.at(i).at(0) = n;
    }

    return matriz;
}

//Funcion para sumar las columnas de una matriz
vector<vector<int>> sumaColumnas(vector<vector<int>> m)
{
    //Definimos una matriz de 1x5 para almacenar las sumas de cada columna
    vector<vector<int>> matriz(1, vector<int>(Columnas, 0));
    for (size_t i = 0; i < m.size(); i++)
    {

        //Sumamos los elementos de la columna j
        //at.(i) nos da la fila i, y luego recorremos esa fila con j
        for (size_t j = 0; j < m.at(i).size(); j++)
        {

            //Sumamos el elemento j de la fila i a la suma de la columna j
            //at(0) porque solo tenemos una fila en la matriz de sumas
            matriz.at(0).at(j) += m.at(i).at(j);
        }
    }

    return matriz;
}

//Funcion para encontrar la fila con la mayor suma
//Size_t es un tipo de dato sin signo, ideal para indices y tamaños
size_t filaMayorSuma(vector<vector<int>> m)
{
    size_t fila = 0; //Variable para almacenar el indice de la fila con mayor suma
    int mayor = m.at(0).at(0); //Variable para almacenar la mayor suma, inicializada con la suma de la primera fila

    for (size_t i = 1; i < m.size(); i++) //Empezamos en 1 porque ya hemos inicializado con la fila 0
    {
        if (m.at(i).at(0) > mayor) //Si la suma de la fila i es mayor que la mayor suma actual
        {
            mayor = m.at(i).at(0); //Actualizamos la mayor suma
            fila = i;              //Actualizamos el indice de la fila con mayor suma
        }
    }

    return fila; //Retornamos el indice de la fila con mayor suma
}

//Funcion para trasponer una matriz
vector<vector<int>> Trasponer (vector<vector<int>> m) //Recibe una matriz y retorna su traspuesta
{
    vector <vector<int>> Trasp (Filas, vector<int>(Columnas, 0)); //Definimos una matriz de 5x5 para almacenar la traspuesta
    for (size_t i = 0; i < m.size(); i ++) //Recorremos la matriz original
    {
        for (size_t j = 0; j < m.at(i).size(); j ++) //Recorremos la fila i de la matriz original
        {
            Trasp.at(j).at(i) = m.at(i).at(j);  //Asignamos el elemento i,j de la matriz original al elemento j,i de la matriz traspuesta
        }
    }
    return Trasp;
}