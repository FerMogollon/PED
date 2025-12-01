/*
Sistema para gestionar informacion de cines

Cada cine tiene:

- Nombre del cine (string)
- Direccion Web (string)
- Un arreglo de 5 estructuras anidadas que representan las salas del cine

Cada Sala tiene:
- Numero de sala (int)
- Nombre de la pelicula en la cartelera (string)
- Numero de butacas disponibles (int)

Menu

1. Solicitar datos
2. Imprimir informacion
3. Calcular total de butacas
4. Buscar Pelicula
5. Salir del Programa
*/

#include <iostream>

using namespace std;

const int N = 5; // Numero total de salas

struct SalaCine
{
    int numSala;
    string Pelicula;
    int dispButacas;
};

struct Cine
{
    string Nombre;
    string URL;
    SalaCine salas[N];
};

Cine ingresarDatos(Cine m);
void mostrarInformacion(Cine m);
int totalButacas(Cine m);
int buscarPelicula(Cine m);
Cine Menu(Cine m);

int main()
{
    Cine miCine;

    miCine = Menu(miCine);
    return 0;
}

Cine ingresarDatos(Cine m)
{
    cout << "Ingrese los datos del cine: " << endl;
    cout << "Nombre del Cine:";
    getline(cin >> ws, m.Nombre);
    cout << "URL del Cine: ";
    getline(cin, m.URL);
    for (size_t i = 0; i < N; i++)
    {
        cout << "Sala #" << i + 1 << endl;
        cout << "Numero de sala: ";
        cin >> m.salas[i].numSala;
        cout << "Nombre de Sala: ";
        getline(cin >> ws, m.salas[i].Pelicula);
        cout << "Butacas Disponibles: ";
        cin >> m.salas[i].dispButacas;
        cout << "---------------------------" << endl;
    }

    return m;
}

void mostrarInformacion(Cine m)
{
    cout << "INFORMACION GENERAL DEL CINE" << endl;
    cout << "Nombre del cine: " << m.Nombre << endl;
    cout << "URL: " << m.URL << endl;
    for (size_t i = 0; i < N; i++)
    {
        cout << "Sala #" << m.salas[i].numSala << endl;
        cout << "Pelicula: " << m.salas[i].Pelicula << endl;
        cout << "Butacas: " << m.salas[i].dispButacas << endl;
        cout << "---------------------------" << endl;
    }
}

int totalButacas(Cine m)
{
    int x = 0;
    for (size_t i = 0; i < N; i++)
    {
        x += m.salas[i].dispButacas;
    }

    return x;
}

int buscarPelicula(Cine m)
{
    int Encontrado = -1; //-1 para no encontrado
    string Buscar;
    cout << "Ingrese el nombre de la pelicula: " << endl;
    getline(cin >> ws, Buscar);

    for (size_t i = 0; i < N; i++)
    {
        if (Buscar == m.salas[i].Pelicula)
        {
            Encontrado = i;
        }
    }

    return Encontrado;
}

Cine Menu(Cine m)
{
    int opcion = 0;
    int tButacas = 0;
    int indexPeli = 0;

    cout << "Bienvenido al Sistema de Gestion del Cine" << endl;

    do
    {
        cout << "----MENU----" << endl;
        cout << "1. Actualizar Datos" << endl;
        cout << "2. Imprimir Informacion" << endl;
        cout << "3. Calcular total de Butacas" << endl;
        cout << "4. Buscar Pelicula" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese un opcion: ";
        cin >> opcion;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "ERROR. INGRESE UNICAMENTE NUMEROS" << endl;
            continue;
        }

        switch (opcion)
        {
        case 1:
            m = ingresarDatos(m);
            break;
        case 2:
            mostrarInformacion(m);
            break;
        case 3:
            tButacas = totalButacas(m);
            cout << "Total de butacas del Cine: " << tButacas << endl;
            break;
        case 4:
            indexPeli = buscarPelicula(m);
            if (indexPeli == -1)
            {
                cout << "Pelicula no disponible" << endl;
            }
            else
            {
                cout << "Pelicula Disponible" << endl;
                cout << "Sala #" << m.salas[indexPeli].numSala << endl;
                cout << "Pelicula: " << m.salas[indexPeli].Pelicula << endl;
            }
            break;
        case 5:
            cout << "Hasta otra :)" << endl;
            break;
        default:
            cout << "Ingrese unicamente una de las opciones" << endl;
            continue;
        }

        cout << "---------------------------" << endl;

    } while (opcion != 5);

    return m;
}