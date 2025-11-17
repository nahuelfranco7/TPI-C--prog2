#include <iostream>
#include <cstdlib>
#include "MenuRecepcionista.h"
#include "ManagerRecepcionista.h"

using namespace std;

void MenuRecepcionista::mostrar(const Usuario &usuario) {
    ManagerRecepcionista manager;
    manager.setNivelUsuario(usuario.getNivelSeguridad());

    int opcion;

    do {
        system("cls");

        cout << "=====================================\n";
        cout << "       Veterinaria Prog2       \n";
        cout << "         MENU RECEPCIONISTA\n";
        cout << "=====================================\n";
        cout << "1) Cargar y modificar turnos.\n";
        cout << "2) Listados generales\n";
        cout << "3) Consultas filtradas\n";
        cout << "4) Busquedas (DNI / Nombre mascota)\n";
        cout << "5) Facturacion (solo consultas)\n";
        cout << "0) Salir\n";
        cout << "______________________________________\n";
        cout << "Opcion: ";
        cin >> opcion;


        switch(opcion) {
            case 1: manager.menuTurnos(); break;
            case 2: manager.menuListados(); break;
            case 3: manager.menuConsultas(); break;
            case 4: manager.menuBusquedas(); break;
            case 5: manager.menuFacturacion(); break;
            case 0:
                cout << "Saliendo del menu recepcionista...\n";
                break;
            default:
                cout << "Opcion invalida\n";
                system("pause");
        }

    } while(opcion != 0);
}
