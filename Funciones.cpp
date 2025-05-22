#include <iostream>
#include <string>
#include <cctype>
#include <Cabecera.h>
#include <sstream>

// Función auxiliar para validar la cantidad de palabras en un string
bool validarCantidadPalabras(const std::string& texto, int max_palabras) {
    int palabras = 0;
    bool en_palabra = false;
    for (char c : texto) {
        if (isspace(static_cast<unsigned char>(c))) {
            if (en_palabra) {
                palabras++;
                en_palabra = false;
            }
        } else {
            en_palabra = true;
        }
    }
    if (en_palabra) palabras++;
    return palabras > 0 && palabras <= max_palabras;
}

void imprimir_Menu () {
    cout << "Aqui debemos imprimir el menu" <<endl;
}
