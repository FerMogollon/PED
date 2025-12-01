/*4. Cadenas con funciones y arrays
Trabaja con char[] (no con string).
    - Implementa funciones que:
        - Verifiquen si una cadena es un palíndromo.
        - Conviertan todas las letras a mayúsculas.
        - Cuenten cuántas vocales y consonantes tiene.*/

#include <iostream>
#include <cstring>

using namespace std;

// Prototipos de funciones
bool Palindromo(char x[]);
void Mayuscula(char x[], char y[]);
int contarVocales(char x[]);
int contarConsonantes(char x[]);

int main()
{
    // Declaración de dos arreglos de caracteres para almacenar las palabras ingresadas
    char Palabra1[100] = {};
    char Palabra2[100] = {};

    // Solicita al usuario la primera palabra
    cout << "Ingrese la 1ra palabra: ";
    cin >> Palabra1; // Lee la palabra (hasta un espacio)
    cout << endl;

    // Solicita al usuario la segunda palabra
    cout << "Ingrese la 2da palabra: ";
    cin >> Palabra2; // Lee la palabra (hasta un espacio)
    cout << endl;

    // Verifica si la primera palabra es un palíndromo
    if (!Palindromo(Palabra1))
    {
        cout << "La palabra " << Palabra1 << ", No es un Palindromo" << endl;
    }
    else
    {
        cout << "La palabra " << Palabra1 << ", Es un Palindromo" << endl;
    }

    cout << "---------------------------" << endl;

    // Verifica si la segunda palabra es un palíndromo
    if (!Palindromo(Palabra2))
    {
        cout << "La palabra " << Palabra2 << ", No es un Palindromo" << endl;
    }
    else
    {
        cout << "La palabra " << Palabra2 << ", Es un Palindromo" << endl;
    }

    cout << "---------------------------" << endl;

    // Muestra ambas palabras en mayúsculas
    Mayuscula(Palabra1, Palabra2);

    cout << "---------------------------" << endl;

    // Cuenta y muestra la cantidad de vocales y consonantes de ambas palabras
    cout << "La palabra " << Palabra1 << " tiene " << contarVocales(Palabra1) << " vocales" << endl;
    cout << "La palabra " << Palabra1 << " tiene " << contarConsonantes(Palabra1) << " consonantes" << endl;
    cout << "La palabra " << Palabra2 << " tiene " << contarVocales(Palabra2) << " vocales" << endl;
    cout << "La palabra " << Palabra2 << " tiene " << contarConsonantes(Palabra2) << " consonantes" << endl;

    return 0;
}

// Función que verifica si una palabra es palíndromo
bool Palindromo(char x[100])
{
    char original[100];   // Arreglo para almacenar la palabra original en minúsculas
    char invertida[100];  // Arreglo para almacenar la palabra invertida

    strcpy(original, x);      // Copia la palabra original a 'original'
    strlwr(original);         // Convierte 'original' a minúsculas para comparar sin distinguir mayúsculas/minúsculas
    int n = strlen(original); // Calcula la longitud de la palabra

    // Invierte la palabra: recorre desde el final al principio y guarda en 'invertida'
    for (int i = 0; i < n; i++)
    {
        invertida[i] = original[n - 1 - i];
    }
    invertida[n] = '\0'; // Agrega el carácter nulo al final para terminar la cadena

    // Compara la palabra original (en minúsculas) con la invertida
    if (strcmp(original, invertida) == 0)
    {
        return true; // Es palíndromo
    }
    else
    {
        return false; // No es palíndromo
    }
}

// Función que muestra ambas palabras en mayúsculas
void Mayuscula(char x[100], char y[100])
{
    char Mayus1[100] = {}; // Arreglo auxiliar para la primera palabra en mayúsculas
    char Mayus2[100] = {}; // Arreglo auxiliar para la segunda palabra en mayúsculas
    strcpy(Mayus1, x);     // Copia la primera palabra
    strcpy(Mayus2, y);     // Copia la segunda palabra
    strupr(Mayus1);        // Convierte la primera palabra a mayúsculas
    strupr(Mayus2);        // Convierte la segunda palabra a mayúsculas

    cout << "Palabra 1 en Mayuscula: " << Mayus1 << endl;
    cout << "Palabra 2 en Mayuscula: " << Mayus2 << endl;
}

// Función que cuenta la cantidad de vocales en una palabra
int contarVocales(char x[])
{
    int n = strlen(x); // Longitud de la palabra
    int Vocales = 0;   // Contador de vocales

    // Recorre cada carácter de la palabra
    for (int i = 0; i < n; i++)
    {
        char c = tolower(x[i]); // Convierte el carácter a minúscula para comparar sin distinguir mayúsculas/minúsculas
        // Si el carácter es una vocal, incrementa el contador
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            Vocales++;
        }
    }
    return Vocales; // Devuelve la cantidad de vocales encontradas
}

// Función que cuenta la cantidad de consonantes en una palabra
int contarConsonantes(char x[])
{
    int n = strlen(x); // Longitud de la palabra
    int Consonantes = 0; // Contador de consonantes

    // Recorre cada carácter de la palabra
    for (int i = 0; i < n; i++)
    {
        char c = tolower(x[i]); // Convierte el carácter a minúscula
        // Si el carácter es una letra y no es vocal, es consonante
        if ((c >= 'a' && c <= 'z') && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
        {
            Consonantes++;
        }
    }
    return Consonantes; // Devuelve la cantidad de consonantes encontradas
}