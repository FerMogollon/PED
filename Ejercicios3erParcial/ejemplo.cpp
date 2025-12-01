#include <iostream>
#include <set>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
    int id;
    string nombre;
    int nivel;
    string clase;
    int poder;

    //Operador < para ordenar en el set por id
    bool operator<(const Player& otro) const {
        return id < otro.id;
    }
};


int main () {
    
    vector<Player> datosIniciales = {
    {104, "Carlos", 50, "Guerrero", 2000},
    {105, "Pedro", 28, "Asesino", 600},
    {106, "Manuel", 5, "Tanque", 10},
    {107, "Angie", 37, "Curandera", 300},
    {108, "Sofia", 49, "Maga", 2500}
    };

    set<Player> jugadoresSet;
    for (const auto& jugador : datosIniciales) {
        jugadoresSet.insert(jugador);
    }

    map<string, set<int>> claseMap;
    for (const auto& jugador : jugadoresSet) {
        claseMap[jugador.clase].insert(jugador.id);
    }
    cout << "Jugadores clasificados por clase:\n";
    for (const auto& [clase, ids] : claseMap) {
        cout << "Clase: " << clase << " -> IDs: ";
        for (const auto& id : ids) {
            cout << id << " ";
        }
        cout << "\n";
    }

    unordered_map<int, Player> jugadorMap;
    for (const auto& jugador : jugadoresSet) {
        jugadorMap[jugador.id] = jugador;
    }
    cout << "Acceso rapido a datos del jugador con ID 107:\n";
    const auto& jugador107 = jugadorMap[107];   
    cout << "Nombre: " << jugador107.nombre << ", Nivel: " << jugador107.nivel
         << ", Clase: " << jugador107.clase << ", Poder: " << jugador107.poder << "\n";

    vector<int> niveles;
    for (const auto& jugador : jugadoresSet) {
        niveles.push_back(jugador.nivel);
    }
    cout << "Niveles de los jugadores:\n";
    for (const auto& nivel : niveles) {
        cout << nivel << " ";
    }

    sort(niveles.begin(), niveles.end());
    cout << "\nNiveles ordenados:\n";
    for (const auto& nivel : niveles) {
        cout << nivel << " ";
    }

    int nivelBuscado = 37;
    bool nivelExiste = binary_search(niveles.begin(), niveles.end(), nivelBuscado);
    cout << "Nivel " << nivelBuscado << (nivelExiste ? " existe.\n" : " no existe.\n");     

    int poderMinimo = 1000;
    vector<Player> jugadoresFiltrados;
    copy_if(jugadoresSet.begin(), jugadoresSet.end(), back_inserter(jugadoresFiltrados),
            [poderMinimo](const Player& p) { return p.poder > poderMinimo; });
    cout << "Jugadores con poder mayor a " << poderMinimo << ":\n";
    for (const auto& jugador : jugadoresFiltrados) {
        cout << "ID: " << jugador.id << ", Nombre: " << jugador.nombre << ", Poder: " << jugador.poder << "\n";
    }

    vector<Player> jugadoresVector(jugadoresSet.begin(), jugadoresSet.end());

    sort(jugadoresVector.begin(), jugadoresVector.end(),
         [](const Player& a, const Player& b) { return a.poder > b.poder; });

        //Investigar a fondo bien por que esto funciona (no se como pero funciona)
    cout << "Top 3 jugadores mas fuertes:\n";
    for (size_t i = 0; i < min(jugadoresVector.size(), size_t(3)); ++i) {
        const auto& jugador = jugadoresVector[i];
        cout << "ID: " << jugador.id << ", Nombre: " << jugador.nombre << ", Poder: " << jugador.poder << "\n";
    }
    return 0;
}