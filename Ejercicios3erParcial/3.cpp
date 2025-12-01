
/*
unordered set - Encontrar el primer numero duplicado.
Dado un arreglo, encuentra el promer numero que se repite. 

*/
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main () {
    vector <int> numeros = {5, 3, 5, 1, 8, 3, 2};
    unordered_set<int> recorridos;

    for (int n : numeros){

        if (recorridos.count(n) != 0){
            cout << "Primer duplicado: " << n << endl;
        }

        recorridos.insert(n);
    }
}