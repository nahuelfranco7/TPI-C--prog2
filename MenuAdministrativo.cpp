#include <iostream>
#include "MenuAdministrativo.h"
#include "ManagerCliente.h"
#include "ManagerMascota.h"
#include "ManagerTurno.h"
#include "ManagerFactura.h"
using namespace std;

void MenuAdministrativo::mostrar() {
    ManagerCliente mc;
    ManagerMascota mm;
    ManagerTurno mt;
    ManagerFactura mf;

    int opc;

    while (true) {
        system("cls");
        cout << "====== MENU ADMINISTRATIVO ======\n";
        cout << "1) Gestion de Clientes\n";
        cout << "2) Gestion de Mascotas\n";
        cout << "3) Gestion de Turnos\n";
        cout << "4) Gestion de Facturas\n";
        cout << "0) Volver\n";
        cout << "----------------------------------\n";
        cout << "Opción: ";
        cin >> opc;

        switch (opc) {
        case 1: {
            int op;
            do {
                system("cls");
                cout << "=== CLIENTES ===\n";
                cout << "1) Alta cliente\n";
                cout << "2) Modificar cliente\n";
                cout << "3) Baja cliente\n";
                cout << "4) Reactivar cliente\n";
                cout << "5) Listar clientes\n";
                cout << "6) Buscar cliente por DNI\n";
                cout << "0) Volver\n";
                cout << "Opción: ";
                cin >> op;

                switch (op) {
                case 1: mc.altaCliente(); break;
                case 2: mc.modificarCliente(); break;
                case 3: mc.bajaCliente(); break;
                case 4: mc.reactivarCliente(); break;
                case 5: mc.listarClientes(); break;
                case 6:
                    {
                    int dni;
                    cout << "INGRESE DNI: " <<endl;
                    cin >> dni;
                    mc.buscarClientePorDNI(dni);
                    break;
                    }
                }
            } while (op != 0);
        } break;

        case 2: {
            int op;
            do {
                system("cls");
                cout << "=== MASCOTAS ===\n";
                cout << "1) Alta mascota\n";
                cout << "2) Modificar mascota\n";
                cout << "3) Baja mascota\n";
                cout << "4) Reactivar mascota\n";
                cout << "5) Listar mascotas\n";
                cout << "0) Volver\n";
                cout << "Opción: ";
                cin >> op;

                switch (op) {
                case 1: mm.altaMascota(); break;
                case 2: mm.modificarMascota(); break;
                case 3: mm.bajaMascota(); break;
                case 4: mm.reactivarMascota(); break;
                case 5: mm.listarMascotas(); break;
                }
            } while (op != 0);
        } break;

        case 3: {
            int op;
            do {
                system("cls");
                cout << "=== TURNOS ===\n";
                cout << "1) Alta turno\n";
                cout << "2) Modificar turno\n";
                cout << "3) Baja turno\n";
                cout << "4) Listar turnos\n";
                cout << "0) Volver\n";
                cout << "Opción: ";
                cin >> op;

                switch (op) {
                case 1: mt.altaTurno(); break;
                case 2: mt.modificarTurno(); break;
                case 3: mt.bajaTurno(); break;
                case 4: mt.listarTurnos(); break;
                }
            } while (op != 0);
        } break;

        case 4: {
            int op;
            do {
                system("cls");
                cout << "=== FACTURAS ===\n";
                cout << "1) Alta factura\n";
                cout << "2) Listar facturas\n";
                cout << "0) Volver\n";
                cout << "Opción: ";
                cin >> op;

                switch (op) {
                case 1: mf.altaFactura(); break;
                case 2: mf.listarFacturas(); break;
                }
            } while (op != 0);
        } break;

        case 0:
            return;
        }
    }
}
