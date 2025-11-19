#include <iostream>
#include <cstring>
#include "MenuVeterinario.h"

#include "ClientesArchivo.h"
#include "MascotaArchivo.h"
#include "TurnoArchivo.h"

using namespace std;

void MenuVeterinario::mostrar(const Usuario& usuario) {

    ManagerVeterinario manager;

    int opc;

    do {
        system("cls");

        cout << "=====================================\n";
        cout << "        MENU VETERINARIO\n";
        cout << "=====================================\n";
        cout << "Usuario: " << usuario.getNombre() << " " << usuario.getApellido() << "\n";
        cout << "-------------------------------------\n";

    cout << "1) Ver cliente por DNI\n";
    cout << "2) Listar mascotas de un cliente\n";
    cout << "3) Consultar turno por ID\n";
    cout << "4) Consultar turnos por fecha\n";
    cout << "5) Consultar turnos por estado\n";
    cout << "-------------------------------------\n";
    cout << "0) Volver al menu anterior\n\n";

        cout << "Opcion: ";
        cin >> opc;



        system("cls");

        switch (opc) {
            case 1:
                manager.verClientePorDNI();
                break;

            case 2:
                manager.listarMascotasDeCliente();
                break;

            case 3:
                manager.listarTurnoPorID();
                break;

            case 4:
                manager.listarTurnosPorFecha();
                break;

            case 5:
                manager.listarTurnosPorEstado();
                break;

            case 0:
                cout << "Saliendo del Menu Veterinario...\n";
                system("pause");
                break;

            default:
                cout << "Opcion invalida.\n";
                system("pause");
                break;
        }

    } while (opc != 0);
}

void MenuVeterinario::mostrarOpciones() {
    cout << "1) Ver cliente por DNI\n";
    cout << "2) Listar mascotas de un cliente\n";
    cout << "3) Consultar turno por ID\n";
    cout << "4) Consultar turnos por fecha\n";
    cout << "5) Consultar turnos por estado\n";
    cout << "-------------------------------------\n";
    cout << "0) Volver al menu anterior\n\n";
}
