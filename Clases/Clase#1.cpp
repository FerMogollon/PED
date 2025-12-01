#include <iostream>

using namespace std;


int main ()
{
    // Variable que guarda un 10
    int number = 10;

    //Variable que guarda la direccion de memoria de la variable que guarda un 10
    int* numberPtr = &number;

    cout << "Valor de number: " << number << endl;
    cout << "Direccion de number: " << &number << endl;
    cout << "Variable que guarda la direccion de memoria donde esta number " << numberPtr << endl;
    cout << "A lo que apunta numberPtr: " << *numberPtr << endl;

    *numberPtr = 11;
    cout << "Nuevo numero: " << number << endl;
}
