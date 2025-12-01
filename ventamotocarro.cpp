#include <iostream>

using namespace std;

class Vehiculo
{

    // Atributos: Caracteriscas
private:
    string marca;
    string modelo;
    int anio;

    // Metodos: Funciones o acciones
public:
    Vehiculo(string _marca, string _modelo, int _anio)
    {
        marca = _marca;
        modelo = _modelo;
        anio = _anio;
    }

    // getters

    string getMarca() const
    {
        return marca;
    }

    string getModelo() const
    {
        return modelo;
    }

    int getAnio() const
    {
        return anio;
    }

    virtual void mostrarInfo()
    {
        cout << "Marca: " << marca << "\n";
        cout << "Modelo: " << modelo << "\n";
        cout << "Anio: " << anio << "\n";
    }
    virtual ~Vehiculo() {};
};

// Herencia

class Auto : public Vehiculo
{
private:
    int numPuertas;

public:
    Auto(string _marca, string _modelo, int _anio, int _numPuertas)
        : Vehiculo(_marca, _modelo, _anio), numPuertas(_numPuertas){}

    int getNumPuertas() const {
        return numPuertas;
    }
};

int main()
{
Vehiculo* lista[2];

lista[0] = new Auto("Toyota", "Corolla", 2025, 4);
lista[0] ->mostrarInfo();

lista[1] = new Auto("Honda", "Civic", 2027, 4);
lista[1] ->mostrarInfo();

    return 0;
}