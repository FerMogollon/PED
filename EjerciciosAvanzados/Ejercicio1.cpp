/*
1. Sistema de gestión de inventario
Crea un programa que maneje productos con un struct Producto que tenga:
id, nombre, precio, cantidad.
El programa debe:
    - Usar un arreglo dinámico de productos.
    - Permitir:
        - Agregar productos.
        - Buscar por id.
        - Actualizar la cantidad.
        - Calcular el valor total del inventario.
*/

#include <iostream>
#include <vector>

using namespace std;

struct Producto
{
    string Nombre;
    float Precio;
    int id;
    int Cantidad;
};

void mostrarProductos(vector<Producto> m);
vector<Producto> agregarProducto(vector<Producto> m);
int buscarID(vector<Producto> m, int idBuscado);
vector<Producto> actualizarCantidad(vector<Producto> n, int idBuscado);
float valorTotal(vector<Producto> m);
vector<Producto> Menu(vector<Producto> m);

int main()
{
    vector<Producto> Inventario;
    Inventario = Menu(Inventario);
    return 0;
}

void mostrarProductos(vector<Producto> m)
{
    cout << "PRODUCTOS: " << endl;
    for (size_t i = 0; i < m.size(); i++)
    {
        cout << "Producto: " << m.at(i).Nombre << endl;
        cout << "Precio: " << m.at(i).Precio << endl;
        cout << "ID: " << m.at(i).id << endl;
        cout << "Cantidad: " << m.at(i).Cantidad << endl;
        cout << "----------------------------------------" << endl;
    }
}

vector<Producto> agregarProducto(vector<Producto> m)
{
    Producto nuevo;
    cout << "Ingrese los datos del nuevo producto: " << endl;
    cout << "Producto: ";
    getline(cin >> ws, nuevo.Nombre);
    cout << endl;
    cout << "Precio: ";
    cin >> nuevo.Precio;
    cout << endl;
    cout << "Id: ";
    cin >> nuevo.id;
    cout << endl;
    cout << "Cantidad: ";
    cin >> nuevo.Cantidad;
    cout << endl;
    m.push_back(nuevo);
    return m;
}

int buscarID(vector<Producto> m, int idBuscado)
{
    int Encontrado = -1; //-1 para no encontrado
    for (size_t i = 0; i < m.size(); i++)
    {
        if (m.at(i).id == idBuscado)
        {
            Encontrado = i;
        }
    }
    return Encontrado;
}

vector<Producto> actualizarCantidad(vector<Producto> m, int idBuscado)
{
    int Encontrado = -1;
    for (size_t i = 0; i < m.size(); i++)
    {
        if (m.at(i).id == idBuscado)
        {
            Encontrado = i;
        }
    }

    if (Encontrado == -1)
    {
        cout << "Producto no encontrado";
    }
    else
    {
        cout << "Ingrese la nuevo cantidad del producto: ' " << m.at(Encontrado).Nombre << " '" << endl;
        cin >> m.at(Encontrado).Cantidad;
    }
    return m;
}

float valorTotal(vector<Producto> m)
{
    float sumTotal = 0;
    for (size_t i = 0; i < m.size(); i++)
    {
        sumTotal += m.at(i).Precio * m.at(i).Cantidad;
    }
    return sumTotal;
}

vector<Producto> Menu(vector<Producto> m)
{
    int Opcion = 0;
    int idBuscado = 0;
    int Found = 0;
    int idBuscar = 0;
    float Value = 0;
    cout << "Bienvenido al Sistema de Gestion de Inventario" << endl;
    do
    {
        cout << "Ingrese una de las opciones: " << endl;
        cout << "1. Mostrar Inventario" << endl;
        cout << "2. Agregar Producto" << endl;
        cout << "3. Buscar Producto" << endl;
        cout << "4. Actualizar Cantidad de un Producto" << endl;
        cout << "5. Valor Total del Inventario" << endl;
        cout << "6. Salir" << endl;
        cin >> Opcion;
        if (cin.fail())
        {
            cout << "ERROR. Ingrese unicamente numeros" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (Opcion)
        {
        case 1:
            mostrarProductos(m);
            break;

        case 2:
            m = agregarProducto(m);
            break;

        case 3:
            cout << "Ingrese el ID del producto que desea buscar: " << endl;
            cin >> idBuscado;
            if (cin.fail())
            {
                cout << "ERROR. Ingrese unicamente numeros" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            Found = buscarID(m, idBuscado);

            if (Found == -1)
            {
                cout << "Producto No Encontrado" << endl;
            }
            else
            {
                cout << "Producto Encontrado: " << endl;
                cout << "Producto: " << m.at(Found).Nombre << endl;
                cout << "Precio: " << m.at(Found).Precio << endl;
                cout << "ID: " << m.at(Found).id << endl;
                cout << "Cantidad: " << m.at(Found).Cantidad << endl;
            }
            break;
        case 4:
            cout << "Ingrese el ID del producto que desea buscar: " << endl;
            cin >> idBuscar;
            if (cin.fail())
            {
                cout << "ERROR. Ingrese unicamente numeros" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            m = actualizarCantidad(m, idBuscar);
            break;
        case 5:
            Value = valorTotal(m);
            cout << "El valor total del inventario es de: " << Value << " $" << endl;
            break;
        case 6:
            cout << "Hasta otra!" << endl;
            break;

        default:
            cout << "Ingrese numeros dentro del rango de opciones" << endl;
            continue;
        }
    } while (Opcion != 6);
    return m;
}
