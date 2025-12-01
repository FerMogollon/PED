#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm> // Para sort
#include <iomanip>   // Para setprecision (imprimir decimales bonitos)

using namespace std;

// --- COMMIT 1: Creación del struct ---
struct Libro {
    string titulo;
    string autor;
    int vecesPrestado;
    int copiasDisponibles;
    float indicePopularidad;
};

// --- COMMIT 2: Definición de estructuras dinámicas ---
// Alias para no escribir tanto:
// Mapa Interno: Título -> Struct Libro
using MapaLibros = map<string, Libro>;
// Mapa Externo: Nombre Biblioteca -> Mapa de Libros
using MapaBibliotecas = map<string, MapaLibros>;

// --- PROTOTIPOS DE FUNCIONES ---
void solicitarInformacionLibro(Libro& libro);
void calcularIndiceDePopularidad(Libro& libro);
void buscarLibrosPorPalabraClave(const MapaBibliotecas& bibliotecas);
void obtenerTop5Populares(const MapaBibliotecas& bibliotecas);
void copiarLibro(MapaBibliotecas& bibliotecas);
void imprimirLibro(const Libro& l);

// --- FUNCIONES ---

// 1. SOLICITAR INFORMACIÓN (COMMIT 3)
void solicitarInformacionLibro(Libro& libro) {
    cin.ignore(); // Limpiar buffer antes de leer strings
    cout << "Ingrese el Titulo: ";
    getline(cin, libro.titulo);
    
    cout << "Ingrese el Autor: ";
    getline(cin, libro.autor);
    
    cout << "Veces Prestado: ";
    cin >> libro.vecesPrestado;
    
    cout << "Copias Disponibles: ";
    cin >> libro.copiasDisponibles;
    
    // El índice se calcula después, aquí lo dejamos en 0 o llamamos a la función
    libro.indicePopularidad = 0.0f; 
}

// 2. CALCULAR POPULARIDAD (COMMIT 4)
void calcularIndiceDePopularidad(Libro& libro) {
    // Fórmula: popularidad = vecesPrestado / (copiasDisponibles + 1)
    // Importante: (float) para que no haga división entera y pierda decimales
    libro.indicePopularidad = (float)libro.vecesPrestado / (libro.copiasDisponibles + 1);
}

// 3. BUSCAR POR PALABRA CLAVE (COMMIT 5)
void buscarLibrosPorPalabraClave(const MapaBibliotecas& bibliotecas) {
    string busqueda;
    cout << "Ingrese titulo o autor a buscar: ";
    cin.ignore();
    getline(cin, busqueda);
    
    bool encontrado = false;
    
    // Iterar sobre Bibliotecas
    for (const auto& [nombreBiblio, libros] : bibliotecas) {
        // Iterar sobre Libros de esa biblioteca
        for (const auto& [titulo, libroStruct] : libros) {
            
            // string::npos significa "no encontrado". Si es diferente, es que SÍ está.
            // Buscamos coincidencia en Título O en Autor
            if (libroStruct.titulo.find(busqueda) != string::npos || 
                libroStruct.autor.find(busqueda) != string::npos) {
                
                cout << "\nEncontrado en [" << nombreBiblio << "]:\n";
                imprimirLibro(libroStruct);
                encontrado = true;
            }
        }
    }
    
    if (!encontrado) cout << "No se encontraron libros con esa palabra clave.\n";
}

// 4. TOP 5 POPULARES (COMMIT 6)
void obtenerTop5Populares(const MapaBibliotecas& bibliotecas) {
    string nombreBiblio;
    cout << "Ingrese el nombre de la biblioteca para ver el TOP 5: ";
    cin.ignore();
    getline(cin, nombreBiblio);

    // Verificar si la biblioteca existe usando .count() o .find()
    // Nota: find devuelve un iterador al elemento si existe, o .end() si no.
    auto itBiblio = bibliotecas.find(nombreBiblio);

    if (itBiblio == bibliotecas.end()) {
        cout << "Esa biblioteca no existe.\n";
        return;
    }

    // Extraemos el mapa de libros de esa biblioteca
    const MapaLibros& librosDeEsaBiblio = itBiblio->second;
    
    // Paso 1: Copiar a Vector para poder ordenar
    vector<Libro> ranking;
    for (const auto& [titulo, libroStruct] : librosDeEsaBiblio) {
        ranking.push_back(libroStruct);
    }

    // Paso 2: Ordenar con Lambda (Mayor a Menor popularidad)
    sort(ranking.begin(), ranking.end(), [](const Libro& a, const Libro& b) {
        return a.indicePopularidad > b.indicePopularidad;
    });

    // Paso 3: Mostrar Top 5 (o menos si no hay 5)
    cout << "\n--- TOP 5 LIBROS MAS POPULARES EN " << nombreBiblio << " ---\n";
    for (size_t i = 0; i < min(ranking.size(), size_t(5)); i++) {
        cout << "#" << i+1 << " ";
        imprimirLibro(ranking[i]);
    }
}

// 5. COPIAR LIBRO (COMMIT 7)
void copiarLibro(MapaBibliotecas& bibliotecas) {
    string biblioOrigen, biblioDestino, tituloLibro;
    cin.ignore();
    
    cout << "Biblioteca ORIGEN: ";
    getline(cin, biblioOrigen);
    
    // Verificamos origen
    if (bibliotecas.find(biblioOrigen) == bibliotecas.end()) {
        cout << "Error: La biblioteca origen no existe.\n";
        return;
    }

    cout << "Titulo del libro a copiar (Exacto): ";
    getline(cin, tituloLibro);

    // Verificamos que el libro exista en el origen
    // bibliotecas[biblioOrigen] nos da el mapa de libros
    if (bibliotecas[biblioOrigen].count(tituloLibro) == 0) {
        cout << "Error: El libro no esta en la biblioteca de origen.\n";
        return;
    }

    cout << "Biblioteca DESTINO: ";
    getline(cin, biblioDestino);
    
    // COPIA:
    // 1. Obtenemos el libro del origen
    Libro libroCopiado = bibliotecas[biblioOrigen][tituloLibro];
    
    // 2. Lo insertamos en el destino
    // Si la biblioteca destino no existe, el map la crea automáticamente aquí
    bibliotecas[biblioDestino][tituloLibro] = libroCopiado;
    
    cout << "Libro copiado exitosamente a " << biblioDestino << ".\n";
}

// Helper para imprimir bonito
void imprimirLibro(const Libro& l) {
    cout << "* " << l.titulo << " (" << l.autor << ") - Popularidad: " 
         << fixed << setprecision(2) << l.indicePopularidad << endl;
}

// --- MENÚ (COMMIT 8 - EXTRA) ---
int main() {
    // Estructura Principal: Mapa de Mapas
    MapaBibliotecas misBibliotecas;
    int opcion = 0;

    do {
        cout << "\n--- GESTION DE BIBLIOTECAS ---\n";
        cout << "1. Agregar Libro a una Biblioteca\n";
        cout << "2. Buscar Libro (Global)\n";
        cout << "3. Ver Top 5 Popularidad (Por Biblioteca)\n";
        cout << "4. Copiar Libro entre Bibliotecas\n";
        cout << "5. Ver todos los libros (Debug)\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                string nombreBiblio;
                cout << "Nombre de la Biblioteca: ";
                cin.ignore();
                getline(cin, nombreBiblio);
                
                Libro nuevoLibro;
                // Llamada Función 1
                solicitarInformacionLibro(nuevoLibro);
                // Llamada Función 2
                calcularIndiceDePopularidad(nuevoLibro);
                
                // Guardar en el mapa anidado
                // [NombreBiblio] accede al primer mapa
                // [TituloLibro] accede al segundo mapa
                misBibliotecas[nombreBiblio][nuevoLibro.titulo] = nuevoLibro;
                
                cout << "Libro agregado correctamente.\n";
                break;
            }
            case 2:
                buscarLibrosPorPalabraClave(misBibliotecas);
                break;
            case 3:
                obtenerTop5Populares(misBibliotecas);
                break;
            case 4:
                copiarLibro(misBibliotecas);
                break;
            case 5:
                // Imprimir todo para verificar
                for(const auto& [nomBib, mapLibros] : misBibliotecas) {
                    cout << "\nBiblioteca: " << nomBib << endl;
                    for(const auto& [tit, lib] : mapLibros) {
                        imprimirLibro(lib);
                    }
                }
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 6);

    return 0;
}