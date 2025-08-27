#include <iostream>

using namespace std;


//De abajo hacia arriba se llama abstraccion
//De arriba hacia abajo se llama herencia
struct Animal
{
    string nombre;
    double peso;
    
    void Hablar()
    {
        cout << "*Hace un sonido" << endl;
    };

    int numeroPatas;
};

struct Perro : Animal
{
    void Hablar()
    {
        cout << "Guau Guau" << endl;
    };

    int numeroPatas = 4;
};

struct Gato : Animal
{
    void Hablar()
    {
        cout << "Miau Miau" << endl;
    };

    int numeroPatas = 4;
};



int main ()
{
    Perro perro1;
    perro1.nombre = "Firulais";
    perro1.peso = 12.5;
    perro1.numeroPatas = 4;
    perro1.Hablar();

    Gato gato1;
    gato1.nombre = "Michi";
    gato1.peso = 4.2;
    perro1.numeroPatas = 4;
    gato1.Hablar();
}