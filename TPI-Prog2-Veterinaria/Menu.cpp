#include <iostream>
#include <cstdlib>
using namespace std;


// librerias
#include "Clientes.h"
#include "ClientesArchivo.h"

#include "Mascota.h"
#include "MascotaArchivo.h"





//  PROTOTIPOS

// Clientes
void menuClientes();
void agregarCliente();
void listarClientes();
void buscarDNI();

// Mascotas
void menuMascotas();
void cargarMascota();
void listarTodos();       // listar mascotas
void mostrarMascota();    // buscar/mostrar mascota

// Otros a completar
void menuVeterinarios();
void menuTurnos();
void menuFacturacion();
void menuProductos();



//              MENU PRINCIPAL

void menuPrincipal() {
    int opcion;

    do {
        system("cls");

        cout << "=====================================\n";
        cout << "       Veterinaria Prog2       \n";
        cout << "=====================================\n";
        cout << "1) Gestion de Clientes\n";
        cout << "2) Gestion de Mascotas\n";
        cout << "3) Gestion de Veterinarios\n";
        cout << "4) Gestion de Turnos\n";
        cout << "5) Facturacion\n";

        cout << "0) Salir\n";
        cout << "______________________________________\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: menuClientes(); break;
            case 2: menuMascotas(); break;
            case 3: menuVeterinarios(); break;
            case 4: menuTurnos(); break;
            case 5: menuFacturacion(); break;

            case 0:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opcion invalida\n";
                system("pause");
        }

    } while(opcion != 0);
}




//              MENU CLIENTES

void menuClientes() {
    int op;

    do {
        system("cls");

        cout << "------ GESTION DE CLIENTES ------\n";
        cout << "1) Agregar cliente\n";
        cout << "2) Listar clientes\n";
        cout << "3) Buscar cliente por DNI\n";
        cout << "0) Volver\n";
        cout << "---------------------------------\n";
        cout << "Opcion: ";
        cin >> op;

        switch(op) {
            case 1: agregarCliente(); break;
            case 2: listarClientes(); break;
            case 3: buscarDNI(); break;

            case 0: break;
            default: cout << "Opcion invalida\n"; system("pause");
        }
    } while(op != 0);
}




//              MENU MASCOTAS

void menuMascotas() {
    int op;

    do {
        system("cls");

        cout << "------ GESTION DE MASCOTAS ------\n";
        cout << "1) Cargar mascota\n";
        cout << "2) Listar todas las mascotas\n";
        cout << "3) Buscar / Mostrar mascota\n";
        cout << "0) Volver\n";
        cout << "---------------------------------\n";
        cout << "Opcion: ";
        cin >> op;

        switch(op) {
            case 1: cargarMascota(); break;
            case 2: listarTodos(); break;
            case 3: mostrarMascota(); break;

            case 0: break;
            default: cout << "Opcion invalida\n"; system("pause");
        }

    } while(op != 0);
}




//        Menus a Completar

void menuVeterinarios() {
    system("cls");
    cout << " Veterinarios";//pendiente
    system("pause");
}

void menuTurnos() {
    system("cls");
    cout << " Turnos";//pendiente
    system("pause");
}

void menuFacturacion() {
    system("cls");
    cout << " Facturacion ";//pendiente
    system("pause");
}









