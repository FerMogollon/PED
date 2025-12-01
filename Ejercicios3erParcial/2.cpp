/*

set - Eliminar duplicados y ordenar numeros dada de una lista de enteros, 
eliminar duplicados y mostrarlos ordenados.

*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main () {
    vector<int> numeros = {5 , 2, 3, 5, 8};

    set <int> numeros_ordenados(numeros.begin(), numeros. end());

    for (int x : numeros_ordenados) {
        cout << x << " ";
    }

    return 0;
}