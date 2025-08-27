/*Crea un programa que permita gestionar una agenda de contactos.

1) Se debe almacenar en un array simple (con maximo de 100 contactos)
la siguiente informacion por cada contacto
    - nombre
    - telefono
    - email

2) EL usuario debe poder elegir entre las siguiente opciones por medio
de un menu.
    - Mostrar agenda completa
    - Agregar contacto nuevo
    - Buscar un contacto (Mostrar la posicion en la agenda)
    - Editar un contacto
    - Eliminar un contacto

3) Crear un programa limpio y reutilizable.*/

#include <iostream>

using namespace std;

struct Contacto
{
    string nombre;
    string telefono;
    string email;
};

const int MAX_CONTACTOS = 100;
Contacto agenda[MAX_CONTACTOS];
int totalContactos = 0;

// DECLARACION DE FUNCIONES
void mostrarAgenda(Contacto agenda[], int numContactos);
int agregarContacto(Contacto agenda[], int numContactos);
int buscarContacto(Contacto agenda[], int numContactos, string nombreBuscado);
void editarContacto(Contacto agenda[], int numContactos);
int eliminarContacto(Contacto agenda[], int numContactos);
void mostrarEncontrado(Contacto agenda[], int numContactos);
void mostrarMenu();
void ejecutarAgenda();

int main()
{
    ejecutarAgenda();
    return 0;
}

//DEFINICION DE FUNCIONES

void mostrarAgenda(Contacto agenda[], int numContactos)
{
    cout << "Agenda de Contactos:" << endl;
    if (numContactos == 0)
    {
        cout << "La agenda esta vacia " << endl;
    }

    for (int i = 0; i < numContactos; i++)
    {
        cout << "Contacto " << i + 1 << ":" << endl;
        cout << "Nombre: " << agenda[i].nombre << endl;
        cout << "Telefono: " << agenda[i].telefono << endl;
        cout << "Email: " << agenda[i].email << endl;
        cout << "------------------------" << endl;
    }
}

int agregarContacto(Contacto agenda[], int numContactos)
{
    if (numContactos >= MAX_CONTACTOS)
    {
        cout << "La agenda esta llena. No se pueden agregar mas contactos." << endl;
        return numContactos;
    }

    Contacto nuevoContacto;
    cout << "Ingrese el nombre del contacto: ";
    getline(cin >> ws, nuevoContacto.nombre);
    cout << "Ingrese el telefono del contacto: ";
    getline(cin, nuevoContacto.telefono);
    cout << "Ingrese el email del contacto: ";
    getline(cin, nuevoContacto.email);

    agenda[numContactos] = nuevoContacto;
    cout << "Contacto agregado exitosamente." << endl;
    return numContactos + 1;
}

int buscarContacto(Contacto agenda[], int numContactos, string nombreBuscado)
{
    for (int i = 0; i < numContactos; i++)
    {
        if (agenda[i].nombre == nombreBuscado)
        {
            cout << "Contacto encontrado en la posicion: " << i + 1 << endl;
            cout << "Nombre: " << agenda[i].nombre << endl;
            cout << "Telefono: " << agenda[i].telefono << endl;
            cout << "Email: " << agenda[i].email << endl;
            return i; // Retorna la posicion del contacto encontrado
        }
    }
    return -1; // Retorna -1 si no se encuentra el contacto
}

void editarContacto(Contacto agenda[], int numContactos)
{
    string nombreBuscado;
    cout << "Ingrese el nombre del contacto a editar: ";
    getline(cin >> ws, nombreBuscado);

    int posicion = buscarContacto(agenda, numContactos, nombreBuscado);
    if (posicion == -1)
    {
        cout << "Contacto no encontrado." << endl;
        return;
    }

    cout << "Ingrese el nuevo Nombre (deje en blanco para no cambiar): ";
    string nuevoNombre;
    getline(cin, nuevoNombre);
    if (!nuevoNombre.empty())
    {
        agenda[posicion].nombre = nuevoNombre;
    }

    cout << "Ingrese el nuevo Telefono (deje en blanco para no cambiar): ";
    string nuevoTelefono;
    getline(cin, nuevoTelefono);
    if (!nuevoTelefono.empty())
    {
        agenda[posicion].telefono = nuevoTelefono;
    }

    cout << "Ingrese el nuevo Email (deje en blanco para no cambiar): ";
    string nuevoEmail;
    getline(cin, nuevoEmail);
    if (!nuevoEmail.empty())
    {
        agenda[posicion].email = nuevoEmail;
    }
}

int eliminarContacto(Contacto agenda[], int numContactos)
{
    string nombreBuscado;
    cout << "Ingrese el nombre del contacto a eliminar: ";
    getline(cin >> ws, nombreBuscado);

    int posicion = buscarContacto(agenda, numContactos, nombreBuscado);
    if (posicion == -1)
    {
        cout << "Contacto no encontrado." << endl;
        return numContactos;
    }

    for (int i = posicion; i < numContactos - 1; i++)
    {
        agenda[i] = agenda[i + 1];
    }
    cout << "Contacto eliminado exitosamente." << endl;
    return numContactos - 1;
}

void mostrarEncontrado(Contacto agenda[], int numContactos)
{
    string nombreBuscado;
    cout << "Ingrese el nombre del contacto a buscar: ";
    getline(cin >> ws, nombreBuscado);

    int posicion = buscarContacto(agenda, numContactos, nombreBuscado);
    if (posicion == -1)
    {
        cout << "Contacto no encontrado." << endl;
        return;
    }

    cout << "Contacto encontrado en la posicion: " << posicion + 1 << endl;
    cout << "Nombre: " << agenda[posicion].nombre << endl;
    cout << "Telefono: " << agenda[posicion].telefono << endl;
    cout << "Email: " << agenda[posicion].email << endl;
}

void mostrarMenu()
{
    cout << "Menu de Opciones:" << endl;
    cout << "1. Mostrar agenda completa" << endl;
    cout << "2. Agregar contacto nuevo" << endl;
    cout << "3. Buscar un contacto" << endl;
    cout << "4. Editar un contacto" << endl;
    cout << "5. Eliminar un contacto" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opcion (1-6): ";
}

void ejecutarAgenda()
{
    int opcion;
    do
    {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer después de leer la opción

        switch (opcion)
        {
        case 1:
            mostrarAgenda(agenda, totalContactos);
            break;
        case 2:
            totalContactos = agregarContacto(agenda, totalContactos);
            break;
        case 3:
            mostrarEncontrado(agenda, totalContactos);
            break;
        case 4:
            editarContacto(agenda, totalContactos);
            break;
        case 5:
            totalContactos = eliminarContacto(agenda, totalContactos);
            break;
        case 6:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion invalida. Por favor intente de nuevo." << endl;
        }
    } while (opcion != 6);
}