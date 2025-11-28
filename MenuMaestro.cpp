#include <iostream>
using namespace std;

#include "MenuMaestro.h"
#include "ManagerCliente.h"
#include "ManagerMascota.h"
#include "ManagerTurno.h"
#include "ManagerFactura.h"
#include "ManagerVeterinario.h"
#include "ManagerUsuario.h"

void MenuMaestro::mostrar(const Usuario &user) {
    int opc;

    do {
        system("cls");
        cout << "====== MENU MAESTRO ======\n";
        cout << "1) Gestion de Usuarios\n";
        cout << "2) Gestion de Clientes\n";
        cout << "3) Gestion de Mascotas\n";
        cout << "4) Gestion de Veterinarios\n";
        cout << "5) Gestion de Turnos\n";
        cout << "6) Gestion de Facturas\n";
        cout << "7) Listados Generales\n";
        cout << "8) Reactivaciones\n";
        cout << "0) Salir\n";
        cout << "------------------------------\n";
        cout << "Opción: ";
        cin >> opc;

        switch(opc) {
            case 1: menuUsuarios(); break;
            case 2: menuClientes(); break;
            case 3: menuMascotas(); break;
            case 4: menuVeterinarios(); break;
            case 5: menuTurnos(); break;
            case 6: menuFacturas(); break;
            case 7: menuListados(); break;
            case 8: menuReactivaciones(); break;
            case 0: break;
            default: cout << "Opción inválida.\n"; system("pause");
        }
    } while(opc != 0);
}

/*USUARIOS===================================================================== */
void MenuMaestro::menuUsuarios() {
    int opc;
    do {
        system("cls");
        cout << "=== GESTION DE USUARIOS ===\n";
        cout << "1) Alta\n";
        cout << "2) Modificación\n";
        cout << "3) Baja\n";
        cout << "4) Listado\n";
        cout << "5) Reactivar\n";
        cout << "0) Volver\n";
        cout << "Opción: ";
        cin >> opc;

        switch(opc) {
            case 1: altaUsuario(); break;
            case 2: modificarUsuario(); break;
            case 3: bajaUsuario(); break;
            case 4: listarUsuarios(); break;
            case 5: reactivarUsuario(); break;
        }
    } while(opc != 0);
}

/* ------------------ A B M L R ------------------ */

void MenuMaestro::altaUsuario() {
    ManagerUsuario mgr;
    mgr.altaUsuario();
}

void MenuMaestro::modificarUsuario() {
    ManagerUsuario mgr;
    mgr.modificarUsuario();
}

void MenuMaestro::bajaUsuario() {
    ManagerUsuario mgr;
    mgr.bajaUsuario();
}

void MenuMaestro::listarUsuarios() {
    ManagerUsuario mgr;
    mgr.listarUsuarios();
}

void MenuMaestro::reactivarUsuario() {
    ManagerUsuario mgr;
    mgr.reactivarUsuario();
}

/*CLIENTES============================================================================================ */
void MenuMaestro::menuClientes() {
    int opc;
    do {
        system("cls");
        cout << "=== GESTION DE CLIENTES ===\n";
        cout << "1) Alta\n";
        cout << "2) Modificación\n";
        cout << "3) Baja\n";
        cout << "4) Listado\n";
        cout << "5) Reactivar\n";
        cout << "0) Volver\nOpción: ";
        cin >> opc;

        switch(opc) {
            case 1: altaCliente(); break;
            case 2: modificarCliente(); break;
            case 3: bajaCliente(); break;
            case 4: listarClientes(); break;
            case 5: reactivarCliente(); break;
        }
    } while(opc != 0);
}

void MenuMaestro::altaCliente() {
    ManagerCliente mgr;
    mgr.altaCliente();
}

void MenuMaestro::modificarCliente() {
    ManagerCliente mgr;
    mgr.modificarCliente();
}

void MenuMaestro::bajaCliente() {
    ManagerCliente mgr;
    mgr.bajaCliente();
}

void MenuMaestro::listarClientes() {
    ManagerCliente mgr;
    mgr.listarClientes();
}

void MenuMaestro::reactivarCliente() {
    ManagerCliente mgr;
    mgr.reactivarCliente();
}

/* MASCOTAS============================================================================================ */

void MenuMaestro::menuMascotas() {
    int opc;
    do {
        system("cls");
        cout << "=== GESTION DE MASCOTAS ===\n";
        cout << "1) Alta\n";
        cout << "2) Modificación\n";
        cout << "3) Baja\n";
        cout << "4) Listado\n";
        cout << "5) Reactivar\n";
        cout << "0) Volver\nOpción: ";
        cin >> opc;

        switch(opc) {
            case 1: altaMascota(); break;
            case 2: modificarMascota(); break;
            case 3: bajaMascota(); break;
            case 4: listarMascotas(); break;
            case 5: reactivarMascota(); break;
        }
    } while(opc != 0);
}

void MenuMaestro::altaMascota() {
    ManagerMascota mgr;
    mgr.altaMascota();
}

void MenuMaestro::modificarMascota() {
    ManagerMascota mgr;
    mgr.modificarMascota();
}

void MenuMaestro::bajaMascota() {
    ManagerMascota mgr;
    mgr.bajaMascota();
}

void MenuMaestro::listarMascotas() {
    ManagerMascota mgr;
    mgr.listarMascotas();
}

void MenuMaestro::reactivarMascota() {
    ManagerMascota mgr;
    mgr.reactivarMascota();
}

/* VETERINARIOS============================================================================================ */

void MenuMaestro::menuVeterinarios() {
    int opc;
    do {
        system("cls");
        cout << "=== GESTION DE VETERINARIOS ===\n";
        cout << "1) Alta\n";
        cout << "2) Modificación\n";
        cout << "3) Baja\n";
        cout << "4) Listado\n";
        cout << "5) Reactivar\n";
        cout << "0) Volver\nOpción: ";
        cin >> opc;

        switch(opc) {
            case 1: altaVeterinario(); break;
            case 2: modificarVeterinario(); break;
            case 3: bajaVeterinario(); break;
            case 4: listarVeterinarios(); break;
            case 5: reactivarVeterinario(); break;
        }
    } while(opc != 0);
}

void MenuMaestro::altaVeterinario() {
    ManagerVeterinario mgr;
    mgr.cargar();
}

void MenuMaestro::modificarVeterinario() {
    ManagerVeterinario mgr;
    mgr.modificar();
}

void MenuMaestro::bajaVeterinario() {
    ManagerVeterinario mgr;
    mgr.eliminar();
}

void MenuMaestro::listarVeterinarios() {
    ManagerVeterinario mgr;
    mgr.listar();
}

void MenuMaestro::reactivarVeterinario() {
    ManagerVeterinario mgr;
    mgr.reactivar();
}

/*TURNOS============================================================================================ */

void MenuMaestro::menuTurnos() {
    int opc;
    do {
        system("cls");
        cout << "=== GESTION DE TURNOS ===\n";
        cout << "1) Alta\n";
        cout << "2) Modificación\n";
        cout << "3) Baja\n";
        cout << "4) Listado\n";
        cout << "0) Volver\nOpción: ";
        cin >> opc;

        switch(opc) {
            case 1: altaTurno(); break;
            case 2: modificarTurno(); break;
            case 3: bajaTurno(); break;
            case 4: listarTurnos(); break;
           }
    } while(opc != 0);
}

void MenuMaestro::altaTurno() {
    ManagerTurno mgr;
    mgr.altaTurno();
}

void MenuMaestro::modificarTurno() {
    ManagerTurno mgr;
    mgr.modificarTurno();
}

void MenuMaestro::bajaTurno() {
    ManagerTurno mgr;
    mgr.bajaTurno();
}

void MenuMaestro::listarTurnos() {
    ManagerTurno mgr;
    mgr.listarTurnos();
}



/*FACTURAS============================================================================================ */

void MenuMaestro::menuFacturas() {
    int opc;
    do {
        system("cls");
        cout << "=== GESTION DE FACTURAS ===\n";
        cout << "1) Alta\n";
        cout << "2) Listado\n";
        cout << "0) Volver\nOpción: ";
        cin >> opc;

        switch(opc) {
            case 1: altaFactura(); break;
            case 2: listarFacturas(); break;

        }
    } while(opc != 0);
}

void MenuMaestro::altaFactura() {
    ManagerFactura mgr;
    mgr.altaFactura();
}



void MenuMaestro::listarFacturas() {
    ManagerFactura mgr;
    mgr.listarFacturas();
}

/* LISTADOS EN GENERAL Y ESPECIFICOS================================================================================== */
void MenuMaestro::menuListados() {
    system("cls");
    int opc;
    do {
        system("cls");
        cout << "=== LISTADOS GENERALES ===\n";
        cout << "1) Listado de Clientes\n";
        cout << "2) Listado de mascotas\n";
        cout << "3) Listado de veterinarios\n";
        cout << "4) Listado de facturas\n";
        cout << "5) Listado de turnos\n";
        cout << "0) Volver\n";
        cout << "Opción: \n";
        cin >> opc;


        switch(opc) {
            case 1: menuListadoClientes(); break;
            case 2: menuListadoMascotas(); break;
            case 3: menuListadoVeterinarios(); break;
            case 4: menuListadoFacturas(); break;
            case 5: menuListadoTurnos(); break;


        }

    } while(opc != 0);
    system("pause");
}

void MenuMaestro::menuListadoClientes(){
    ManagerCliente mgr;
    mgr.menuListadoClientes();
}

void MenuMaestro::menuListadoMascotas(){
    ManagerMascota mgr;
    mgr.menuListadoMascotas();
}

void MenuMaestro::menuListadoVeterinarios(){
    ManagerVeterinario mgr;
    mgr.menuListadoVeterinarios();
}

 void MenuMaestro::menuListadoFacturas(){
    ManagerFactura mgr;
// NO HICE
}

void MenuMaestro::menuListadoTurnos(){
    ManagerTurno mgr;
// NO HICE
}

/* REACTIVACIONES============================================================================================ */
void MenuMaestro::menuReactivaciones() {
    int opc;
    do {
        system("cls");
        cout << "=== REACTIVACIONES ===\n";
        cout << "1) Clientes\n";
        cout << "2) Mascotas\n";
        cout << "3) Veterinarios\n";
        cout << "4) Usuarios\n";
        cout << "5) Turnos\n";
        cout << "0) Volver\nOpción: ";
        cin >> opc;

        switch(opc) {
            case 1: reactivarCliente(); break;
            case 2: reactivarMascota(); break;
            case 3: reactivarVeterinario(); break;
            case 4: reactivarUsuario(); break;

        }
    } while(opc != 0);
}
