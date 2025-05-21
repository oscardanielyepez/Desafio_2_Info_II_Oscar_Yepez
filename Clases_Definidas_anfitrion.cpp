#include <iostream>
#include <string>
#include <cctype>
#include <Cabecera.h>
#include <vector>

using namespace std;

class crear_alojamiento {

private:
    int codigo;
    int identificador;
    bool tipo_casa; // true, apartamento, false; casa
    long int precio;
    string afitrion_responsable;
    string direccion;

    vector<string> amenidades;

public:
    string nombre;
    string departamento;
    string municipio;

    // Método ingresar amenidades
    void ingresarAmenidades() {
        int cantidad;

        while (true) {
            try {
                cout << "¿Cuántas amenidades desea ingresar?: ";
                cin >> cantidad;
                cin.ignore(); // Limpiar el buffer, ignora el \n
            } catch (const exception& e) {
                cout << "\n";
            }
        }

        for (int i = 0; i < cantidad; ++i) {
            string amenidad;
            cout << "Amenidad #" << (i + 1) << ": ";
            getline(cin, amenidad);
            amenidades.push_back(amenidad);
        }
    }

    // Método para mostrar las amenidades
    void mostrarAmenidades() const {
        std::cout << "\nAmenidades ingresadas:\n";
        for (const auto& a : amenidades) {
            std::cout << "- " << a << std::endl;
        }
    }

    // Creamos una funcion para asignar datos principales.
    //Nombre del alojamiento, con su respectiva validacion.
    void ingresarNombre() {
        string nombre_temp;
        do {
            cout << "Ingrese el nombre de la propiedad (máximo 10 palabras): ";
            getline(cin, nombre_temp);

            if (!validarCantidadPalabras(nombre_temp, 10)) {
                cout << "Demasiadas palabras. Intente de nuevo.\n";
            }

        } while (!validarCantidadPalabras(nombre_temp, 10));

        nombre = nombre_temp;
    }

    //Nombre del departamento con su respeca validacion.
    void ingresarDepartamento() {
        std::string departamento_temp;
        do {
            std::cout << "Ingrese el nombre del departamento (máximo 3 palabras): ";
            std::getline(std::cin, departamento_temp);

            if (!validarCantidadPalabras(departamento_temp, 3)) {
                std::cout << "Nombre demasiado largo. Intente nuevamente.\n";
            }

        } while (!validarCantidadPalabras(departamento_temp, 3));

        departamento = departamento_temp;
    }
};


class crear_anfitrion {
private:

public:
    string name;
};
