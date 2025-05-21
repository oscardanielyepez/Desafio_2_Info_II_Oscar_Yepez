#include <iostream>
#include <string>
#include <cctype>
#include <Cabecera.h>
#include <sstream>

bool validarCantidadPalabras(const string& texto, int max_palabras) {
    istringstream stream(texto);
    string palabra;
    int contador = 0;

    while (stream >> palabra) {
        contador++;
        if (contador > max_palabras) {
            return false;
        }
    }
    return true;
}
