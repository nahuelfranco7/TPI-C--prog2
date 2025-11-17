# include<iostream>
# include<cstdlib>
#include "ManagerCliente.h"
using namespace std;

void ManagerCliente::altaCliente() {
    ClientesArchivo arch;
    Clientes reg;

    cout << "=== ALTA DE CLIENTE ===\n";
    reg.cargar();

    reg.setEstado(true);
    reg.setIdCliente( arch.contarRegistros() + 1 );

    if (arch.cargarClientes(reg)) {
        cout << "Cliente guardado correctamente.\n";
    } else {
        cout << "ERROR al guardar cliente.\n";
    }
    system("pause");
}

void ManagerCliente::modificarCliente() {
    ClientesArchivo arch;
    int id;
    cout << "ID de cliente a modificar: ";
    cin >> id;

    int pos = arch.buscarporId(id);
    if (pos < 0) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    Clientes reg;
    arch.leerClientes(pos, reg);

    cout << "Cliente actual:\n";
    arch.mostrarClientes(pos, reg);

    cout << "Ingrese nuevos datos:\n";
    reg.cargar();

    if (arch.modificarClientes(pos, reg))
        cout << "Modificado correctamente.\n";
    else
        cout << "ERROR al modificar.\n";

    system("pause");
}

void ManagerCliente::bajaCliente() {
    ClientesArchivo arch;
    int id;
    cout << "ID de cliente a dar de baja: ";
    cin >> id;

    int pos = arch.buscarporId(id);
    if (pos < 0) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    if (arch.eliminar(pos))
        cout << "Cliente dado de baja (estado = false).\n";
    else
        cout << "ERROR al dar de baja.\n";

    system("pause");
}

void ManagerCliente::reactivarCliente() {
    ClientesArchivo arch;
    int id;
    cout << "ID de cliente a reactivar: ";
    cin >> id;

    int pos = arch.buscarporId(id);
    if (pos < 0) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    Clientes reg;
    arch.leerClientes(pos, reg);
    reg.setEstado(true);

    if (arch.modificarClientes(pos, reg))
        cout << "Cliente reactivado.\n";
    else
        cout << "ERROR al reactivar.\n";

    system("pause");
}

void ManagerCliente::listarClientes() {
    ClientesArchivo arch;
    arch.listarTodos();
    system("pause");
}

void ManagerCliente::buscarClientePorDNI() {
    char dni[25];
    cout << "Ingrese DNI del cliente: ";
    cin >> dni;

    ClientesArchivo arch;
    Clientes c;
    bool found = false;
    int total = arch.contarRegistros();

    for (int i=0; i<total; i++) {
        if (!arch.leerClientes(i, c)) continue;
        if (strcmp(c.getDNI(), dni)==0) {
            arch.mostrarClientes(i, c);
            found = true;
        }
    }

    if (!found) cout << "No encontrado.\n";

    system("pause");
}
