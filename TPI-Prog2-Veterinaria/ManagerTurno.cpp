# include<iostream>
# include<cstdlib>
# include<cstring>
#include "ManagerTurno.h"
using namespace std;

void ManagerTurno::altaTurno() {
    TurnoArchivo arch;
    Turno reg;

    reg.setIdTurno( arch.contarRegistros() + 1 );

    cout << "ID Mascota: ";
    int idM; cin >> idM;
    reg.setIdMascota(idM);

    cout << "ID Veterinario: ";
    int idV; cin >> idV;
    reg.setIdVet(idV);

    cout << "Fecha del turno:\n";
    Fecha f; f.cargar();
    reg.setFechaTurno(f);

    reg.setEstadoTurno(true);

    if (arch.cargarTurno(reg))
        cout << "Turno registrado.\n";
    else
        cout << "ERROR.\n";

    system("pause");
}

void ManagerTurno::modificarTurno() {
    TurnoArchivo arch;
    int id;
    cout << "ID Turno a modificar: ";
    cin >> id;

    int pos = arch.buscarPorId(id);
    if (pos < 0) { cout << "No existe.\n"; return; }

    Turno reg;
    arch.leerTurno(pos, reg);

    cout << "Turno actual:\n";
    arch.mostrarTurno(pos, reg);

    cout << "Ingrese nuevos datos:\n";
    reg.cargar();

    if (arch.modificarTurno(pos, reg))
        cout << "Turno modificado.\n";
    else
        cout << "ERROR.\n";

    system("pause");
}

void ManagerTurno::bajaTurno() {
    TurnoArchivo arch;
    int id;
    cout << "ID turno a anular: ";
    cin >> id;

    int pos = arch.buscarPorId(id);
    if (pos < 0) { cout << "No existe.\n"; return; }

    if (arch.eliminar(pos))
        cout << "Turno inactivado.\n";
    else
        cout << "ERROR.\n";

    system("pause");
}

void ManagerTurno::listarTurnos() {
    TurnoArchivo arch;
    arch.listarTodos();
    system("pause");
}
