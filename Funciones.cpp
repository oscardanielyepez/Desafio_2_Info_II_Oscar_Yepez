#include <iostream>
#include <string>
#include <cctype>
#include <Cabecera.h>
#include <fstream>

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

//Funcion que nos permitira imprimir los menu
void Imprimir_Menu(string Menu_Recibido) {
    int tam = sizeof(string Menu_Recibido) / sizeof(string Menu_Recibido[0]);
    for (int i = 0; i < tam; i++) {
        cout << Menu_Recibido[i] <<endl;
    }
}

//Nos permite pedir la opcion entre el rango de la lista.
int Pedir_Opcion(string Menu_Recibido, int opcion){
    int contador = 0;
    int tam = sizeof(Menu_Recibido) / sizeof(Menu_Recibido[0]);

    while(true){
        int contador =+ 1;

        cout << "Selecione la opcion; " << endl;
        cin >> opcion;

        if(contador >= 4){
            int opcion = Menu_Recibido[tam -1]; // Debemos entregar la opcion de salir.
            break;
        }else if (int opcion <= tam && int opcion >= tam){
            return opcion;
        }else{
            ; // No hace nada.
        }
    }
}

void Ejecutar_Accion(int opcion, int Num_H_A){

    switch (Num_H_A) {
        case 1:
            cout << "Menu de huespedes: " << endl;

            /*
            {"1: Bucar reservaciones ",
             "2: Reservar alojamientos ",
             "3: Anular reservacion ",
             "4: Volver "};
            */

            switch (opcion) {
                case 1:
                    Bucar_reservacion(); //Enteoria aqui meteremos el filtro
                    break;
                case 2:
                    Reservar_Alojamiento();
                    break;
                case 3:
                    Anular_Reservacion();
                    break;
                default:
                    cout << "La puteria debe haber un error; " << endl;
            }
            break;
        case 2:
            cout << "Menu de anfitriones: " << endl;
            switch (opcion) {
            case 1:
                Bucar_reservacion(); //Enteoria aqui meteremos el filtro, se supone que esta estara definida
                    break;
            case 2:
                Reservar_Alojamiento();
                    break;
            case 3:
                Anular_Reservacion();
                    break;
            default:
                cout << "La puteria debe haber un error; " << endl;
            }
            break;
        default:
            cout << "La puteria debe haber un error; " << endl;
    }
}

// Función auxiliar para validar usuario y contraseña
bool login(string usuario_login, string archivo_txt) {
    ifstream archivo(archivo_txt);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << archivo_txt << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos = linea.find(':');
        if (pos == string::npos) continue;

        string usuario = linea.substr(0, pos);
        string contrasena_archivo = linea.substr(pos + 1);

        if (usuario == usuario_login) {
            string contrasena_ingresada;
            cout << "Ingresa la contraseña: ";
            cin >> contrasena_ingresada;
            return contrasena_ingresada == contrasena_archivo;
        }
    }

    return false;
}

// Función principal que determina si el login es válido
bool Login_Valido(string tipo) {
    /*
    Esta función valida si el inicio es válido según el tipo de usuario:
    - tipo == "admin" → lee archivo Users_Admin.txt
    - tipo == "anfitrion" → lee archivo Users_Anfitrion.txt
    */

    string usuario;
    cout << "Ingresa tu nombre de usuario: ";
    cin >> usuario;

    if (tipo == "admin") {
        return login(usuario, "Users_Admin.txt");
    } else if (tipo == "anfitrion") {
        return login(usuario, "Users_Anfitrion.txt");
    } else {
        cerr << "Tipo de usuario no reconocido." << endl;
        return false;
    }
}
