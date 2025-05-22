#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <Cabecera.h>
#include <class_Anfitrion.h>
#include <class_Huesped.h>

using namespace std;

int main() {

    string Menu_Principal[3] = {"1: Huesped", "2: Anfitrion", "Salir"};
    string Menu_Anfitrion[10] = {"1: Crear alojamiento: ",
                                "2: Borrar alojamiento: ",
                                "3: Consultar reservaciones: ",
                                "4: Actualizar historico", };

    bool start = true;
    int contador = 0;
    int opcion = 0;


    //Para pedir opcion del menu inicial.
    while (start) {
            // Se maneja bajo excepcion.
            try {
                cout << "Iniciar como Huespued o Anfitrion" << endl;
                cout << "1. Huesped" << endl;
                cout << "2. Anfitrion" << endl;
                cout << "3. Salir" << endl;
                cin >> opcion;
            }
            catch (const exception& e) {
                cout << "\n";
            }

            contador += 1;

            //Se entiende que con el try, no lo deja pasar, pero por su las moscas.
            if (opcion >= 1 && opcion <= 3)
            {
                start = false;
            }
            else if (contador >= 4)
            {
                start = false;
            }
            else
            {
                cout << "No has ingresado una opcion correcta:\n\n" << "Intentos realizados: " << contador << endl;
            }
    }

    switch (opcion) {
        case 1:
            cout << "Has iniciado como Huesped" << endl;

            imprimir_Menu_Hueped();
            cin >> opcion;
            break;
        case 2:
            cout << "Iniciar sesion como Anfitrion" << endl;
            cin >> opcion;
            break;
        case 3:
            cout << "Saliendo del programa..." << endl;
            cin >> opcion;
            return 0;
    }

}
