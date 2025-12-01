// Tablas Hash

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

void agregar(unordered_set<string> &tablaHash, const string &nombre)
{
    auto resultado = tablaHash.insert(nombre);
    if (resultado.second)
    {
        cout << "se guardo bien " << endl;
    }
    else
    {
        cout << "el dato ya existe en la tabla " << endl;
    }
}

void eliminar(unordered_set<string> &tablaHash, const string &nombre)
{
    if (tablaHash.erase(nombre))
    {
        cout << "se elimino bien " << endl;
    }
    else
    {
        cout << "el dato no existe en la tabla " << endl;
    }
}

void buscar(unordered_set<string> &tablaHash, const string &nombre)
{
    if (tablaHash.find(nombre) != tablaHash.end())
    {
        cout << "el dato existe en la tabla " << endl;
    }
    else
    {
        cout << "el dato no existe en la tabla " << endl;
    }
}

void mostrarDatos(unordered_set<string> &tablaHash)
{
    if (tablaHash.empty())
    {
        cout << "la tabla esta vacia " << endl;
        return;
    }
    for (const string &nombre : tablaHash)
    {
        cout << nombre << " " << endl;
    }
}

void limpiarDatos(unordered_set<string> &tablaHash)
{
    tablaHash.clear();
    cout << "la tabla ha sido limpiada " << endl;
}

int main()
{

    unordered_set<string> nombres;

    agregar(nombres, "pepe");
    agregar(nombres, "luis");
    agregar(nombres, "ANA");
    agregar(nombres, "pepe");

    cout << "\nMoestrar nombres: " << endl;
    mostrarDatos(nombres);

    cout << "buscar nombre: " << endl;
    buscar(nombres, "pepe");

    cout << "eliminar nombre: " << endl;
    eliminar(nombres, "pepe");

    cout << "\nMoestrar nombres: " << endl;
    mostrarDatos(nombres);

    cout << "limpiar datos: " << endl;
    limpiarDatos(nombres);

    return 0;
}


/*
    #include <iostream>
    #include <unordered_set>
    #include <unordered_map>
    #include <string>
    using namespace std;

    void agregar(unordered_set<string> &tablaHash, const string &nombre , const int &edad)
{
    tablaHash[nombre] = edad;
}

void buscar(unordered_set<string> &tablaHash, const string &nombre)
{
    if (tablaHash.find(nombre) != tablaHash.end())
    {
        cout << "el dato existe en la tabla " << endl;
    }
    else
    {
        cout << "el dato no existe en la tabla " << endl;
    }
}

void mostrarDatos(unordered_set<string> &tablaHash)
{
    if (tablaHash.empty())
    {
        cout << "la tabla esta vacia " << endl;
        return;
    }
    for (const string &nombre : tablaHash)
    {
        cout << nombre << " " << endl;
    }
}

void limpiarDatos(unordered_set<string> &tablaHash)
{
    tablaHash.clear();
    cout << "la tabla ha sido limpiada " << endl;
}




    int main (){

        unordered_map<string, int > edades = {
            {"ana", 25},
            {"luis", 30},
            {"pepe", 23}
        };

        cout << edades ["ana"] << endl;

        return 0;
    }
        */  