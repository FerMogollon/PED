/*Definición de las estructuras de datos dinámicas lineales:
1. Creación de la estructura dinámica de datos tipo lista: Utilizando la librería list, se
creará una lista que almacenará las estructuras de maquilas.
2. Creación de un arreglo dinámico: Usando la librería vector, se definirá un arreglo
dinámico que almacenará las estructuras de líneas de producción.*/

/*Funcionalidades y entregas:
1. Una función Solicitar información(struct) sin parámetros, que permita solicitar los
datos de maquila y líneas de producción. (Hacer uso de getLine)
• Commit: La declaración y definición de la función solicitar información.
1. Una función Imprimir información(void) que acepte como parámetro la estructura
de datos para imprimir la información de maquila y líneas de producción. (Se debe
tomar en cuenta si el parámetro se pasará por valor o referencia).
• Commit: La declaración y definición de la función mostrar información.
2. Una función Ordenar(void) bajo el criterio (campo) de tu selección, esta función
aceptará como parámetro la estructura dinámica de lista donde se almacena
Maquila. (Se debe tomar en cuenta si el parámetro se pasará por valor o referencia)
y el criterio (campo) de tu selección, se debe implementar la función sort de la
librería list.
• Commit: La declaración y definición de la función de ordenar.
3. Una función buscar registro de maquila (void) bajo el criterio (campo) de tu
selección, que acepte como parámetro la estructura dinámica de lista donde se
almacena Maquila. (Se debe tomar en cuenta si el parámetro se pasará por valor
o referencia), se debe implementar la librería algorithm(find), para imprimir la
información de esa maquila y sus líneas de producción.
• Commit: La declaración y definición de la función buscar.
4. Finalmente, en la función principal main, se llamarán a las funciones, y se
implementará los bucles necesarios para el funcionamiento de dicho programa.
*/

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

struct LineaProduccion {
    int numEmpleados;
    string tipoProduccion;
};

struct Maquila {
    string nombre;
    string ubicacion;
    bool certificada;
    vector<LineaProduccion> lineas;
};

void SolicitarInformacion ();

int main ()
{
    list <Maquila> maquila;
    Menu();

    return 0;
}

void SolicitarInformacion() {
    cout << "Ingrese los datos de la Maquila:\n";
    Maquila m;
    cout << "Nombre de la maquila: ";
    getline(cin, m.nombre);
    cout << "Ubicacion de la maquila: ";
    getline(cin, m.ubicacion);
    cout << "La maquila esta certificada? (1 para si, 0 para no): ";
    cin >> m.certificada;
    int numLineas;
    cout << "Ingrese el numero de lineas de produccion: ";
    cin >> numLineas;
    cin.ignore(); // Limpiar el buffer de entrada
    for (int i = 0; i < numLineas; ++i) {
        LineaProduccion lp;
        cout << "Ingrese el numero de empleados para la linea " << (i + 1) << ": ";
        cin >> lp.numEmpleados;
        cin.ignore(); // Limpiar el buffer de entrada
        cout << "Ingrese el tipo de produccion para la linea " << (i + 1) << ": ";
        getline(cin, lp.tipoProduccion);
        m.lineas.push_back(lp);
    }
}

void ImprimirInformacion (const Maquila &m) {
    cout << "Datos de la Maquila:\n";
    cout << "Nombre: " << m.nombre << endl;
    cout << "Ubicacion: " << m.ubicacion << endl;
    cout << "Certificada: " << (m.certificada ? "Si" : "No") << endl;
    cout << "Lineas de Produccion:\n";
    for (const auto &lp : m.lineas) {
        cout << "  - Numero de Empleados: " << lp.numEmpleados << ", Tipo de Produccion: " << lp.tipoProduccion << endl;
    }
}

/*Ordenar por orden alfabetico haciendo uso de la libreria list*/

void OrdenarMaquilas(list<Maquila> &maquilas) {
    maquilas.sort([](const Maquila &a, const Maquila &b) {
        return a.nombre < b.nombre; // Ordenar por nombre de forma alfabetica
    });
    cout << "Maquilas ordenadas por nombre.\n";
}


/*Buscar si una Maquila esta certificada o no mediante find_if si son mas de una imprimir todas*/
void BuscarMaquilaCertificada(list<Maquila> &maquilas) {
    if (maquilas.empty()) {
        cout << "\nNo hay maquilas registradas.\n";
        return;
    }

    bool encontrada = false;
    for (const auto &m : maquilas) {
        if (m.certificada) {
            cout << "\nMaquila certificada encontrada:\n";
            ImprimirInformacion(m);
            encontrada = true;
        }
    }
    if (!encontrada) {
        cout << "\nNo se encontraron maquilas certificadas.\n";
    }
}

//Bucar por no nombre de maquila usando find_if
void BuscarMaquilaPorNombre(const list<Maquila> &maquilas) {
    if (maquilas.empty()) {
        cout << "\nNo hay maquilas registradas.\n";
        return;
    }
    string nombreBusqueda;
    cout << "\nIngrese el nombre de la maquila a buscar: ";
    getline(cin, nombreBusqueda);

    auto encontrada = find_if(maquilas.begin(), maquilas.end(),
        [&](const Maquila &m) { return m.nombre == nombreBusqueda; });

    if (encontrada != maquilas.end()) {
        cout << "\nMaquila encontrada:\n";
        ImprimirInformacion(*encontrada);
    } else {
        cout << "\nNo se encontro una maquila con ese nombre.\n";
    }
}

/*Funcion Menu*/
void Menu() {
    list<Maquila> maquilas;
    int opcion;

    do {
        cout << "\nMenu de opciones:\n";
        cout << "1. Agregar maquila\n";
        cout << "2. Mostrar maquilas\n";
        cout << "3. Ordenar maquilas\n";
        cout << "4. Buscar maquila por nombre\n";
        cout << "5. Buscar maquilas certificadas\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1: {
                SolicitarInformacion();
            case 2:
                for (const auto &m : maquilas) {
                    ImprimirInformacion(m);
                }
                break;
            case 3:
                OrdenarMaquilas(maquilas);
                break;
            case 4:
                BuscarMaquilaPorNombre(maquilas);
                break;
            case 5:
                BuscarMaquilaCertificada(maquilas);
                break;
            case 6:
                cout << "Saliendo del programa...\n";
                break;
            default: 
                cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 6);
}
