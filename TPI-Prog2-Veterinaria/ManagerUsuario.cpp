# include<iostream>
# include<cstdlib>
# include<cstring>
#include "ManagerUsuario.h"
using namespace std;

void ManagerUsuario::altaUsuario() {
    UsuarioArchivo arch;
    Usuario reg;

    cout << "=== ALTA DE USUARIO ===\n";


    int nuevoID = arch.contarRegistros() + 1;
    reg.setIdUsuario(nuevoID);

    cout << "ID asignado automáticamente: " << nuevoID << endl;

    cout << "Ingrese nombre: ";
    char nombre[30];
    arch.cargarCadena(nombre, 29);
    reg.setNombre(nombre);

    cout << "Ingrese apellido: ";
    char apellido[30];
    arch.cargarCadena(apellido, 29);
    reg.setApellido(apellido);

    cout << "Ingrese clave: ";
    char clave[20];
    arch.cargarCadena(clave, 19);
    reg.setClave(clave);

    int nivel;
    do {
        cout << "Nivel de seguridad (1-4): ";
        cin >> nivel;
        if (nivel < 1 || nivel > 4) cout << "Valor inválido.\n";
    } while (nivel < 1 || nivel > 4);
    reg.setNivelSeguridad(nivel);

    reg.setEstado(true);

    if (arch.cargarUsuario(reg))
        cout << "Usuario guardado correctamente.\n";
    else
        cout << "ERROR al guardar usuario.\n";

    system("pause");
}

void ManagerUsuario::modificarUsuario() {
    UsuarioArchivo arch;
    int id;

    cout << "ID de usuario a modificar: ";
    cin >> id;

    if (arch.modificar(id))
        cout << "Modificación exitosa.\n";
    else
        cout << "No se pudo modificar.\n";

    system("pause");
}

void ManagerUsuario::bajaUsuario() {
    UsuarioArchivo arch;
    int dni;
    cout << "DNI de usuario a dar de baja: ";
    cin >> dni;

    if (arch.eliminar(dni))
        cout << "Usuario inactivado.\n";
    else
        cout << "ERROR al dar de baja.\n";

    system("pause");
}

void ManagerUsuario::reactivarUsuario() {
    UsuarioArchivo arch;
    int dni;
    cout << "DNI de usuario a reactivar: ";
    cin >> dni;

    int pos = arch.buscarporDNI(dni);
    if (pos < 0) {
        cout << "Usuario no encontrado.\n";
        system("pause");
        return;
    }

    Usuario reg;
    arch.leerUsuario(pos, reg);
    reg.setEstado(true);

    if (arch.modificarUsuario(pos, reg))
        cout << "Usuario reactivado.\n";
    else
        cout << "ERROR.\n";

    system("pause");
}

void ManagerUsuario::listarUsuarios() {
    UsuarioArchivo arch;
    cout << "=== LISTADO DE USUARIOS ===\n";
    arch.listarTodos();
    system("pause");
}

void ManagerUsuario::buscarUsuarioPorId() {
    UsuarioArchivo arch;
    int id;
    cout << "Ingrese ID del usuario: ";
    cin >> id;

    int pos = arch.buscarPorId(id);
    if (pos < 0) {
        cout << "No encontrado.\n";
    } else {
        arch.mostrarUsuario(pos);
    }

    system("pause");
}
