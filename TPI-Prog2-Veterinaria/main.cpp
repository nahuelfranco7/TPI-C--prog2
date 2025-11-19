#include <iostream>
#include "Menu.h"
using namespace std;

int main(){
    Menu menu;
    int opcion = -1;

    while(opcion != 0){
        cout << "========== MENU PRINCIPAL ==========\n";
        cout << "1) Cargar usuarios iniciales\n";
        cout << "2) Ingresar al sistema\n";
        cout << "0) Salir\n";
        cout << "------------------------------------\n";

        opcion = menu.cargarEntero("Seleccion", 0);

        system("cls");

        switch(opcion){
            case 1:
                menu.cargarUsuariosIniciales();
                break;

            case 2:
                menu.mostrar();
                break;

            case 0:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }

        cout << "\n\n";
    }

    return 0;
}
