#ifndef CLASS_ANFITRION_H
#define CLASS_ANFITRION_H

#include <iostream>
#include <string>
#include <cctype>
#include <Cabecera.h>
#include <vector>
#include <limits>

class crear_alojamiento {

private:
    int codigo;
    int identificador;
    bool tipo_casa; // true, apartamento, false; casa
    long int precio;
    string anfitrion_responsable;
    string direccion;

    vector<string> amenidades;

public:
    string nombre;
    string departamento;
    string municipio;

    // Constructor por defecto
    crear_alojamiento()
        : codigo(0), identificador(0), tipo_casa(false), precio(0),
        anfitrion_responsable(""), direccion(""), nombre(""),
        departamento(""), municipio("") {
    }

    // Método ingresar amenidades
    void ingresarAmenidades() {
        int cantidad = 0;
        // Validar entrada de cantidad
        while (true) {
            cout << "¿Cuántas amenidades desea ingresar?: ";
            if (cin >> cantidad && cantidad > 0) {
                cin.ignore(); // Limpiar el buffer
                break;
            } else {
                cout << "Por favor, ingrese un número válido mayor que 0.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        amenidades.clear(); // Limpiar amenidades previas si las hay
        for (int i = 0; i < cantidad; ++i) {
            string amenidad;
            cout << "Amenidad #" << (i + 1) << ": ";
            getline(cin, amenidad);
            if (!amenidad.empty()) {
                amenidades.push_back(amenidad);
            } else {
                cout << "La amenidad no puede estar vacía. Intente de nuevo.\n";
                --i; // Repetir este índice
            }
        }
    }

    // Método para mostrar las amenidades
    void mostrarAmenidades() const {
        if (amenidades.empty()) {
            std::cout << "\nNo se han ingresado amenidades.\n";
            return;
        }
        std::cout << "\nAmenidades ingresadas (" << amenidades.size() << "):\n";
        int idx = 1;
        for (const auto& a : amenidades) {
            std::cout << idx++ << ". " << a << std::endl;
        }
    }

    // Función auxiliar para validar la cantidad de palabras en un string
    bool validarCantidadPalabras(const string& texto, int max_palabras) const {
        int palabras = 0;
        bool en_palabra = false;
        for (char c : texto) {
            if (isspace(c)) {
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

    // Ingresar el nombre del alojamiento con validación
    void ingresarNombre() {
        string nombre_temp;
        bool valido = false;
        do {
            cout << "Ingrese el nombre de la propiedad (máximo 10 palabras): ";
            getline(cin, nombre_temp);
            valido = validarCantidadPalabras(nombre_temp, 10);
            if (!valido) {
                cout << "Demasiadas palabras o vacío. Intente de nuevo.\n";
            }
        } while (!valido);

        nombre = nombre_temp;
    }

    // Ingresar el nombre del departamento con validación
    void ingresarDepartamento() {
        string departamento_temp;
        bool valido = false;
        do {
            cout << "Ingrese el nombre del departamento (máximo 3 palabras): ";
            getline(cin, departamento_temp);
            valido = validarCantidadPalabras(departamento_temp, 3);
            if (!valido) {
                cout << "Nombre demasiado largo o vacío. Intente nuevamente.\n";
            }
        } while (!valido);

        departamento = departamento_temp;
    }

    // Ingresar el nombre del municipio con validación
    void ingresarMunicipio() {
        string municipio_temp;
        bool valido = false;
        do {
            cout << "Ingrese el nombre del municipio (máximo 3 palabras): ";
            getline(cin, municipio_temp);
            valido = validarCantidadPalabras(municipio_temp, 3);
            if (!valido) {
                cout << "Nombre demasiado largo o vacío. Intente nuevamente.\n";
            }
        } while (!valido);

        municipio = municipio_temp;
    }
    /*
    // Ingresar el código del alojamiento
    // Generar el código del alojamiento automáticamente leyendo el último código de un archivo externo
    void generarCodigoAutomatico(const string& archivo_codigos) {
        int ultimo_codigo = 0;
        ifstream archivo(archivo_codigos);
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                try {
                    int codigo_leido = stoi(linea);
                    if (codigo_leido > ultimo_codigo) {
                        ultimo_codigo = codigo_leido;
                    }
                } catch (...) {
                    // Ignorar líneas no numéricas
                }
            }
            archivo.close();
        }
        codigo = ultimo_codigo + 1;
        // Guardar el nuevo código en el archivo
        ofstream archivo_out(archivo_codigos, ios::app);
        if (archivo_out.is_open()) {
            archivo_out << codigo << endl;
            archivo_out.close();
        }
    }
    void ingresarCodigo() {
        int codigo_temp;
        cout << "Ingrese el código del alojamiento (número entero positivo): ";
        while (!(cin >> codigo_temp) || codigo_temp <= 0) {
            cout << "Código inválido. Intente nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        codigo = codigo_temp;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Ingresar el identificador del alojamiento
    void ingresarIdentificador() {
        int identificador_temp;
        cout << "Ingrese el identificador del alojamiento (número entero positivo): ";
        while (!(cin >> identificador_temp) || identificador_temp <= 0) {
            cout << "Identificador inválido. Intente nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        identificador = identificador_temp;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    */

    // Ingresar el tipo de alojamiento
    void ingresarTipoCasa() {
        int opcion;
        cout << "Seleccione el tipo de alojamiento:\n1. Apartamento\n2. Casa\nOpción: ";
        while (!(cin >> opcion) || (opcion != 1 && opcion != 2)) {
            cout << "Opción inválida. Ingrese 1 para Apartamento o 2 para Casa: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        tipo_casa = (opcion == 1);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Ingresar el precio del alojamiento
    void ingresarPrecio() {
        long int precio_temp;
        cout << "Ingrese el precio del alojamiento (valor positivo): ";
        while (!(cin >> precio_temp) || precio_temp <= 0) {
            cout << "Precio inválido. Intente nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        precio = precio_temp;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Ingresar el nombre del anfitrión responsable
    void ingresarAnfitrionResponsable() {
        string anfitrion_temp;
        bool valido = false;
        do {
            cout << "Ingrese el nombre del anfitrión responsable (máximo 5 palabras): ";
            getline(cin, anfitrion_temp);
            valido = validarCantidadPalabras(anfitrion_temp, 5);
            if (!valido) {
                cout << "Nombre demasiado largo o vacío. Intente nuevamente.\n";
            }
        } while (!valido);

        anfitrion_responsable = anfitrion_temp;
    }

    // Ingresar la dirección del alojamiento
    void ingresarDireccion() {
        string direccion_temp;
        cout << "Ingrese la dirección del alojamiento: ";
        getline(cin, direccion_temp);
        direccion = direccion_temp;
    }

    // Método para mostrar todos los datos del alojamiento
    void mostrarDatos() const {
        cout << "\n--- Datos del Alojamiento ---\n";
        cout << "Código: " << codigo << endl;
        cout << "Identificador: " << identificador << endl;
        cout << "Tipo: " << (tipo_casa ? "Apartamento" : "Casa") << endl;
        cout << "Precio: " << precio << endl;
        cout << "Anfitrión responsable: " << anfitrion_responsable << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "Municipio: " << municipio << endl;
        mostrarAmenidades();
        cout << "-----------------------------\n";
    }
};

class crear_anfitrion {
private:
    string name_2;
public:
    string name;
};

#endif // CLASS_ANFITRION_H
