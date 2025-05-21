#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

int main() {

    bool start = true;
	int contador = 0;
    int opcion;

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
            cout << "Iniciar sesion como Huesped" << endl;
            // Lógica para iniciar sesión como huésped
            break;
        case 2:
            cout << "Iniciar sesion como Anfitrion" << endl;
            // Lógica para iniciar sesión como anfitrión
            break;
        case 3:
            cout << "Saliendo del programa..." << endl;
            return 0;
    }

}
