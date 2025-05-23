#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <Cabecera.h>
#include <class_Anfitrion.h>
#include <class_Huesped.h>

using namespace std;

int main() {

    bool start = true;
    bool start_2 = false;
    bool lg_valido = false;
    int opcion = 0;
    int Num_H = 1;
    int Num_A = 2;

    string Menu_Principal[3] = {"1: Huesped", "2: Anfitrion", "3: Salir"};

    string Menu_Anfitrion[10] = {"1: Crear alojamiento: ",
                                "2: Borrar alojamiento: ",
                                "3: Consultar reservaciones: ",
                                "4: Actualizar historico",
                                "5: Finalizar seccion"};

    string Menu_Login_Anfitrion[3] = {"1: Inicar sesion: ",
                                      "2: Crear usuario",
                                      "3: Volver"};

    string Menu_Huesped [4] {"1: Bucar reservaciones ",
                           "2: Reservar alojamientos ",
                           "3: Anular reservacion ",
                           "4: Volver "};

    while (start){
        //Imprimir menu inicial:
        Imprimir_Menu(string Menu_Principal);
        opcion = Pedir_Opcion(string Menu_Principal, int opcion);

        if (int opcion == 3) {
            bool start = false;
        }

        if (int opcion >=1 && int opcion <= 3){
            start_2 = true;
        }

        while (start_2) {
            //Imprimimos menu de huesped
            if (int opcion == 1){
                Imprimir_Menu(Menu_Huesped);
                int opcion = Pedir_Opcion (string Menu_Huesped, int opcion);

                if (int opcion = 4){
                    bool start_2 == false;
                    break;
                } else {
                    Ejecutar_Accion(int opcion, Num_H);
                }

            //Menu de anfitrion
            } else if(int opcion == 2){

                //Segundo menu, crear o iniciar seccion.
                while (lg_valido == false) {
                    Imprimir_Menu(string Menu_Login_Anfitrion);
                    int opcion = Perdir_Opcion(string Menu_Login_Anfitrion, int opcion)

                        if (opcion == 3) {
                            break; // Enteoria deberiamos romper el ciclo que repite el menu 2, de anfitrion
                    }

                    switch (opcion) {
                    case 1:
                        cout << "Estamos iniciando seccion:" << endl;
                        bool lg_valido = Login_Valido(string login); // Esta funcion en teoria nos deberia permitir inciar seccion, validando en el archivo de User_Afitrion
                        break;
                    case 2:
                        cout << "Estamos creando un usuario anfitrion" << endl;
                        bool lg_valido = Login_Valido(string admin);

                        //Tienen que iniciar como admin, para poder crear.
                        if (lg_valido){
                            Crear_Usuario() //Enteoria aqui deberiamos llamar la funcion que nos crear a los usuarios
                            break;
                        }
                        break;
                    default:
                        cout << "Opción no válida." << endl;
                    };
                }

                //Despues de iniciar seccion.
                if (Login_Valido) {
                    Imprimir_Menu(string Menu_Huesped);
                    int opcion = Pedir_Opcion (string Menu_Huesped, int opcion);

                    if (int opcion == 2){
                        bool start_2 = false;
                        break;
                    } else {
                        Ejecutar_Accion(int opcion, Num_A)
                    }
                }else {
                    ; // No estamos haciendo, nada pq no deberiamos llegar aqui.
                }
            }

            } else if(int opcion == 3){
                //En teoria no deberia llegar aca.
                break;
            }else {
                //No deberia llegar aca.
                break;
            }
        }
}
