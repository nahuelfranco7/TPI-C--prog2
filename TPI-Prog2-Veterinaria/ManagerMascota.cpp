# include<iostream>
# include<cstdlib>
# include<cstring>
#include "ManagerMascota.h"
using namespace std;

void ManagerMascota::altaMascota() {
    MascotaArchivo arch;
    Mascota reg;

    cout << "=== ALTA DE MASCOTA ===\n";
    reg.cargar();

    reg.setEstadoMascota(true);
    reg.setIdMascota( arch.contarRegistros() + 1 );

    if (arch.cargarMascota(reg))
        cout << "Mascota guardada!\n";
    else
        cout << "ERROR al guardar.\n";

    system("pause");
}

void ManagerMascota::modificarMascota() {
    MascotaArchivo arch;
    int id;
    cout << "ID de mascota a modificar: ";
    cin >> id;

    int pos = arch.buscarPorId(id);
    if (pos < 0) {
        cout << "Mascota no encontrada.\n";
        return;
    }

    Mascota reg;
    arch.leerMascota(pos, reg);

    cout << "Mascota actual:\n";
    arch.mostrarMascota(pos, reg);

    cout << "Ingrese nuevos datos:\n";
    reg.cargar();

    if (arch.modificarMascota(pos, reg))
        cout << "Modificado OK.\n";
    else
        cout << "ERROR.\n";

    system("pause");
}

void ManagerMascota::bajaMascota() {
    MascotaArchivo arch;
    int id;
    cout << "ID de mascota a dar de baja: ";
    cin >> id;

    int pos = arch.buscarPorId(id);
    if (pos < 0) {
        cout << "No existe.\n";
        return;
    }

    if (arch.eliminar(pos))
        cout << "Mascota Inactiva.\n";
    else
        cout << "ERROR.\n";

    system("pause");
}

void ManagerMascota::reactivarMascota() {
    MascotaArchivo arch;
    int id;

    cout << "ID mascota a reactivar: ";
    cin >> id;

    int pos = arch.buscarPorId(id);
    if (pos < 0) {
        cout << "No existe.\n";
        return;
    }

    Mascota reg;
    arch.leerMascota(pos, reg);
    reg.setEstadoMascota(true);

    if (arch.modificarMascota(pos, reg))
        cout << "Reactivada.\n";
    else
        cout << "ERROR.\n";

    system("pause");
}

void ManagerMascota::listarMascotas() {
    MascotaArchivo arch;
    arch.listarTodos();
    system("pause");
}
