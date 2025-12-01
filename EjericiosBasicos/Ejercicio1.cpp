#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

/*Crea un programa que:
 - Genere un arreglo de 20 números aleatorios entre 1 y 100.
    - Implemente funciones para:
        - Contar cuántos son pares e impares.
        - Encontrar el segundo mayor y el segundo menor.
        - Invertir el arreglo (sin usar otro arreglo auxiliar).
*/

//PROTOTIPOS
int Pares(vector<int> n); //Contar numeros pares

void Mayor(vector<int> n); //Encontrar el segundo mayor y el segundo menor

void invertirArreglo(vector<int> n); //Invertir el arreglo

int main()
{
    vector<int> random; //Definimos un vector para almacenar los numeros aleatorios
    srand(time(0)); //Inicializamos la semilla


    //Llenamos el vector con 20 numeros aleatorios entre 1 y 100
    cout << "Vector original: " << endl;
    for (int i = 0; i < 20; i++)
    {
        int n = rand() % 101;
        random.push_back(n);
    }

    //Imprimimos el vector original
    for (int i = 0; i < 20; i++)
    {
        cout << random.at(i) << " ";
    }
    cout << endl;
    int n = random.size(); //Tamaño del vector
    
    cout << "Vector invertido: " << endl;
    invertirArreglo (random); //Invertimos el vector
    
    cout << endl;

    cout << "Cantidad de numero pares: " << Pares (random) << endl; //Contamos los numeros pares
    cout << "Cantidad de numeros impares: " << n - Pares(random) << endl; //Contamos los numeros impares

    Mayor (random); //Encontramos el segundo mayor y el segundo menor


    return 0;
}

//Funcion para contar numeros pares
int Pares(vector<int> vec) 
{
    int x = 0; //Contador de numeros pares
    for (int i = 0; i < 20; i++) //Recorremos el vector
    {
        if (vec.at(i) % 2 == 0) //Si el numero es par
        {
            x++; //Incrementamos el contador
        }
    }

    return x;
}

//Funcion para encontrar el segundo mayor y el segundo menor
void Mayor(vector<int> vec)
{
    int segundoMayor = 0; //Variable para almacenar el segundo mayor
    int segundoMenor = 0; //Variable para almacenar el segundo menor

    sort(vec.begin(), vec.end(), greater<int>()); //Ordenamos el vector de mayor a menor

    cout << "Vector ordenado de Mayor a Menor" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << vec.at(i) << " "; //Imprimimos el vector ordenado
    }

    cout << endl;
    
    segundoMayor = vec.at(1); //El segundo mayor es el segundo elemento del vector ordenado
    segundoMenor = vec.at(18); //El segundo menor es el penultimo elemento del vector ordenado

    cout << "El segundo numero mayor del vector es: " << segundoMayor << endl;
    cout << "El segundo numero menor del vector es: " << segundoMenor << endl;
}

//Funcion para invertir el arreglo sin usar otro arreglo auxiliar
void invertirArreglo(vector<int> vec)
{
    int n = vec.size(); //Tamaño del vector
    for (int i = 0; i < n /2; i++) //Recorremos la mitad del vector, intercambiando los elementos.
    {
        int temp = 0; //Variable temporal para almacenar el valor del elemento i
        temp = vec.at(i); //Asignamos el valor del elemento i a temp
        vec.at(i) = vec.at(n - 1 -i); //Intercambiamos el elemento i con el elemento n-1-i, que es el elemento simetrico
        vec.at(n - 1 - i) = temp; //Asignamos el valor de temp al elemento n-1-i, que es el elemento simetrico
    }

    for (int i = 0; i < 20; i++)
    {
        cout << vec.at(i) << " "; //Imprimimos el vector invertido
    }
}
