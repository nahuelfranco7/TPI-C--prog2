# include<iostream>
# include<cstdlib>
# include<cstring>
#include <ctime>
#include "Fecha.h"
#include "ManagerMascota.h"
#include "UsuarioArchivo.h"
using namespace std;

void ManagerMascota::altaMascota() {
      MascotaArchivo arch;
    Mascota reg;
    ClientesArchivo a;

    cout << "=== ALTA DE MASCOTA ===\n";

    int dni = -1;
    int posCliente = -1;

    // 1) Bucle para pedir DNI hasta encontrar uno válido o ingresar 0 para salir
    bool seguir = true;
    while (seguir) {

        cout << "DNI Cliente dueño (0 para volver): ";
        cin >> dni;

        if (dni == 0) {
            // El usuario quiere volver al menú anterior
            cout << "Operación cancelada.\n";
            system("pause");
            return;  // salimos directamente de altaMascota
        }

        posCliente = a.buscarporDNI(dni);

        if (posCliente == -1) {
            cout << "Cliente no encontrado. Ingrese un DNI válido o 0 para volver.\n";
            system("pause");
        }
        else {
            Clientes cli;
            a.leerClientes(posCliente, cli);

            if (!cli.getEstado()) {
                cout << "El cliente está INACTIVO. Reactívelo antes de continuar.\n";

                system("pause");
            }
            else {
                // DNI válido y cliente activo podemos seguir
                cout<<"El cliente dueno es: ";
                cli.mostrar();
                system("pause");
                seguir = false;
            }
        }
    }

    // 2) CARGA DE LA MASCOTA
    reg.cargar(dni);
    reg.setEstadoMascota(true);
    reg.setIdMascota( arch.contarRegistros() + 1 );

    if (arch.cargarMascota(reg)) {
        cout << "Mascota guardada!\n";
    }
    else {
        cout << "ERROR al guardar.\n";
    }
}

void ManagerMascota::modificarMascota() {
    MascotaArchivo arch;
    ClientesArchivo a;

    cout << "INGRESE DNI DEL CLIENTE DUENO (0 para volver): ";
    int dnicliente;
    cin >> dnicliente;

    if (dnicliente == 0) return;

    while (true) {

        int pos = a.buscarporDNI(dnicliente);
        if (pos == -1) {
            cout << "Cliente no encontrado. Ingrese uno valido o 0 para salir: ";
            cin >> dnicliente;
            if (dnicliente == 0) return;
            continue;
        }

        // Estado del cliente
        if (!a.estadoCliente(dnicliente)) {
            cout << "El cliente está INACTIVO. Reactívelo antes de continuar.\n";
            cout << "Ingrese otro DNI o 0 para salir: ";
            cin >> dnicliente;
            if (dnicliente == 0) return;
            continue;
        }

        // Listar mascotas
        cout << "\n--- MASCOTAS DEL CLIENTE ---\n";
        arch.listarMascotaporDueno(dnicliente);

        cout << "\nIngrese ID de la mascota a modificar (0 para salir): ";
        int idmascota;
        cin >> idmascota;

        if (idmascota == 0) return;

        int posMascota = arch.buscarPorId(idmascota);
        if (posMascota == -1) {
            cout << "ID de mascota inexistente.\n";
            continue;
        }

        Mascota reg;
        arch.leerMascota(posMascota, reg);

        cout << "\nMascota seleccionada:\n";
        arch.mostrarMascota(posMascota, reg);

        cout << "\nIngrese nuevos datos:\n";
        reg.cargar(dnicliente);

        if (arch.modificarMascota(posMascota, reg))
            cout << "Modificado OK.\n";
        else
            cout << "ERROR.\n";

        system("pause");
        return;
    }
}


void ManagerMascota::reactivarMascota() {
    MascotaArchivo arch;
    ClientesArchivo a;

    cout << "INGRESE DNI DEL CLIENTE DUENO (0 para volver): ";
    int dnicliente;
    cin >> dnicliente;

    if (dnicliente == 0) return;

    while (true) {

        //Validamos la existencia del cliente
        int posCliente = a.buscarporDNI(dnicliente);
        if (posCliente == -1) {
            cout << "Cliente no encontrado. Ingrese uno válido o 0 para salir: ";
            cin >> dnicliente;
            if (dnicliente == 0) return;
            continue;
        }

        //Validamos estado del cliente
        if (!a.estadoCliente(dnicliente)) {
            cout << "El cliente está INACTIVO. Reactívelo antes de continuar.\n";
            cout << "Ingrese otro DNI o 0 para salir: ";
            cin >> dnicliente;
            if (dnicliente == 0) return;
            continue;
        }

        //Listamos todas las mascotas del cliente
        cout << "\n--- MASCOTAS DEL CLIENTE ---\n";
        arch.listarMascotaporDueno(dnicliente);

        cout << "\nIngrese ID de la mascota a reactivar (0 para salir): ";
        int idMascota;
        cin >> idMascota;

        if (idMascota == 0) return;

        //Buscamos la mascota por ID
        int posMascota = arch.buscarPorId(idMascota);
        if (posMascota == -1) {
            cout << "ID de mascota inexistente.\n";
            continue;
        }

        Mascota reg;
        arch.leerMascota(posMascota, reg);

        //Verificamos que la mascota pertenece al cliente
        if (reg.getIdClienteDueno() != dnicliente) {
            cout << "La mascota NO pertenece a ese cliente.\n";
            continue;
        }

        //Verificamos que la mascota esté inactiva
        if (reg.getEstadoMascota()) {
                cout << "La mascota ya está ACTIVA.\n";
            continue;
        }

        cout << "\nMascota seleccionada:\n";
        arch.mostrarMascota(posMascota, reg);

        cout << "\n¿Confirmar reactivación? (1=SI / 0=NO): ";
        int confirmacion;
        cin >> confirmacion;

        if (confirmacion !=1) {
            cout << "Operación cancelada.\n";
            system("pause");
            return;
        }

        // Reactivar
        reg.setEstadoMascota(true);

        if (arch.modificarMascota(posMascota, reg))
            cout << "Mascota reactivada correctamente.\n";
        else
            cout << "ERROR al modificar el registro.\n";

        system("pause");
        return;
    }
}


void ManagerMascota::listarMascotas() {
    MascotaArchivo arch;
    arch.listarTodos();
    system("pause");
}

void listarMascotasporDni(int dniDueno){
    MascotaArchivo arch;
    arch.listarMascotaporDueno(dniDueno);
    system("pause");

}

void ManagerMascota::bajaMascota() {
    MascotaArchivo arch;
    ClientesArchivo a;

    cout << "INGRESE DNI DEL CLIENTE DUENO (0 para volver): ";
    int dnicliente;
    cin >> dnicliente;

    if (dnicliente == 0) return;

    while (true) {

        // Validar existencia del cliente
        int posCliente = a.buscarporDNI(dnicliente);
        if (posCliente == -1) {
            cout << "Cliente no encontrado. Ingrese uno valido o 0 para salir: ";
            cin >> dnicliente;
            if (dnicliente == 0) return;
            continue;
        }

        // Validar estado del cliente
        if (!a.estadoCliente(dnicliente)) {
            cout << "El cliente está INACTIVO. Reactívelo antes de continuar.\n";
            cout << "Ingrese otro DNI o 0 para salir: ";
            cin >> dnicliente;
            if (dnicliente == 0) return;
            continue;
        }

        // Listar mascotas del cliente
        cout << "\n--- MASCOTAS DEL CLIENTE ---\n";
        arch.listarMascotaporDueno(dnicliente);

        cout << "\nIngrese ID de la mascota a dar de baja (0 para salir): ";
        int idmascota;
        cin >> idmascota;

        if (idmascota == 0) return;

        // Buscar mascota por ID
        int posMascota = arch.buscarPorId(idmascota);
        if (posMascota == -1) {
            cout << "ID de mascota inexistente.\n";
            continue;
        }

        Mascota reg;
        arch.leerMascota(posMascota, reg);

        // Verificar si pertenece al cliente (seguridad extra)
        if (reg.getIdClienteDueno() != dnicliente) {
            cout << "La mascota NO pertenece a ese cliente.\n";
            continue;
        }

        // Verificar si ya está inactiva
        if (!reg.getEstadoMascota()) {
            cout << "La mascota ya está INACTIVA.\n";
            continue;
        }

        cout << "\nMascota seleccionada:\n";
        arch.mostrarMascota(posMascota, reg);

        cout << "\n¿Confirmar baja? (1=SI / 0=NO): ";
        int confirm;
        cin >> confirm;

        if (confirm != 1) {
            cout << "Operación cancelada.\n";
            system("pause");
            return;
        }

        // Aplicar baja lógica
        reg.setEstadoMascota(false);

        if (arch.modificarMascota(posMascota, reg))
            cout << "Mascota dada de baja correctamente.\n";
        else
            cout << "ERROR al modificar el registro.\n";

        system("pause");
        return;
    }
}
