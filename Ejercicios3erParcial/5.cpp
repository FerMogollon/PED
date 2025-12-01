/*
Caso Practico
*/
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

struct Estudiante {
    string nombre;
    int edad;
};


int main () {

    map<int, Estudiante> infoEstudiante;

    infoEstudiante[100] = {"Pepe", 25};
    infoEstudiante[100] = {"Jose", 26};
    infoEstudiante[100] = {"Ana", 21};
    infoEstudiante[100] = {"Fulano", 19};

    //Map de cursos
    // {"Matematicas", {100, 101, 102, 103}}
    // {"Fisica" { 102, 103}}

    map<string, set<int>> cursos;

    cursos ["Matematicas"].insert(100);
    cursos ["Matematicas"].insert(101);
    cursos ["Matematicas"].insert(102);
    cursos ["Matematicas"].insert(103);

    cursos ["Fisica"].insert(102);
    cursos ["Fisica"].insert(103);
    cursos ["Fisica"].insert(103); //Set ignora el repetido

    //Mostrar los cursos

    cout << "Lista de cursos y estudiantes (ids)" << endl;
    for(auto& curso : cursos) {
        cout<< curso.first<< ": ";
        for (int id : curso.second) {
            cout << id << " ";
        }
        
        cout << endl; 

    }

    //Mostrar informacion completa de los estudiante de cada curso

    for (int id : cursos["Matematicas"]) {
        cout << id << " -> " << infoEstudiante[id].nombre << " " << infoEstudiante[id].edad;
        cout << endl;
    }
    

    return 0;
}