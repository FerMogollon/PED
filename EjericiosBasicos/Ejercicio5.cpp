/*5. Structs básicos
Crea un struct Estudiante que almacene: nombre, edad y promedio.
    - Pide al usuario los datos de 3 estudiantes.
    - Imprime cuál tiene el mejor promedio.*/

#include <iostream>

using namespace std;

struct Estudiantes
{
    string Nombre;
    int Edad;
    float promedio;
};

int main()
{
    Estudiantes alumnos[3];

    int n = sizeof(alumnos) / sizeof(alumnos[0]);

    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese los datos del alumno " << i + 1 << ": " << endl;
        cout << "Nombre: ";
        getline(cin >> ws, alumnos[i].Nombre);
        cout << endl;
        cout << "Edad: ";
        cin >> alumnos[i].Edad;
        cout << endl;
        cout << "Promedio: ";
        cin >> alumnos[i].promedio;
        cout << endl;
    }

    int Mayor = 0;
    for (int i = 0; i < n; i++)
    {
        if(alumnos[i].promedio > alumnos[Mayor].promedio)
        {
            Mayor = i;
        }
    }

    cout << "El alumno con mejor Promedio es: " << alumnos[Mayor].Nombre << " , con " << alumnos[Mayor].promedio << " de promedio" << endl;

    return 0;
}