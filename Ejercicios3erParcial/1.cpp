#include <iostream>
#include <map>
#include <sstream>

using namespace std;


int main (){
    string text = "hola como estan hola";
    map<string, int> frecuencia;

    string palabra;
    stringstream ss(text); // "Hola | como | estan| hola"

    while (ss >> palabra){
        frecuencia [palabra] ++;
    }

    for (auto& par : frecuencia) {
        cout << par.first<< " " << "se repite: " << par.second<<endl;
    }
}
