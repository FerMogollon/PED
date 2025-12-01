#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

void registrarUsuarios(map<string, vector<string>>&redSocial, vector<string>& usuarios){
    int n;
    cout << "Ingrese el numero de usuario que desea registrar: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        string nombre;
        cin>>nombre;
        usuarios.push_back(nombre);
        redSocial[nombre] = {};
    }
}

void registrarAmistades(map<string, vector<string>>&redSocial){
    int n;
    cout << "Ingrese el numero de usuario que existen: ";
    cin >> n;

    cout<< "Ingrese las amistades (usuario1 usuario2)\n";
    for (int i = 0; i<n; i++){
        string a, b;
        cin>>a>>b;
        redSocial[a].push_back(b);
        redSocial[b].push_back(a);
    }
}

void mostrarRed(const map<string, vector<string>>&redSocial){

    for(auto par : redSocial){
        cout<<par.first<<endl;
        for(string conexion : par.second){
            cout<<conexion<<endl;
        }
    }
}

//data.find != data.end();
void MostrarConexionDeUnUsuario(const map<string, vector<string>>&resSocial){


}

int main (){

    map<string, vector<string>> redSocial;
    vector<string> usuarios;

    registrarUsuarios(redSocial, usuarios);
    registrarAmistades(redSocial);
    return 0;
}