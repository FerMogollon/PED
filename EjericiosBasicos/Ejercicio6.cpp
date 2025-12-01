/*6. Funciones con structs
Modifica el ejercicio anterior:
    -Implementa una función leerEstudiante() que devuelva un Estudiante.
    -Implementa una función mejorPromedio() que reciba un arreglo de estudiantes y retorne el índice del mejor.
*/

#include <iostream>
#include <vector>

using namespace std;

const int N = 3;

struct Estudiantes
{
    string Nombre;
    int Edad;
    float promedio;
};

Estudiantes leerEstudiante(Estudiantes x[], int Tamanio);
int mejorPromedio(Estudiantes x[], int Tamanio);

int main()
{
    Estudiantes alumnos[N];

    for (int i = 0; i < N; i++)
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

    int k = mejorPromedio(alumnos, N);

    cout << "El alumno con mejor Promedio es: " << alumnos[k].Nombre << " , con " << alumnos[k].promedio << " de promedio" << endl;

    leerEstudiante();

    cout << "Saliendo..." << endl;
    return 0;
}

int mejorPromedio(Estudiantes x[], int Tamanio)
{
    int Mayor = 0;
    for (int i = 0; i < Tamanio; i++)
    {
        if (x[i].promedio > x[Mayor].promedio)
        {
            Mayor = i;
        }
    }

    return Mayor;
}

Estudiantes leerEstudiante()
{
    Estudiantes e;

    cout << "Nombre: ";
    getline(cin >> ws, e.Nombre);
    cout << endl;
    cout << "Edad: ";
    cin >> e.Edad;
    cout << endl;
    cout << "Promedio: ";
    cin >> e.promedio;
    cout << endl;

    return e;
}