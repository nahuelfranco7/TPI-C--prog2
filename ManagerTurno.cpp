# include<iostream>
# include<cstdlib>
# include<cstring>
#include "ClientesArchivo.h"
#include "ManagerTurno.h"

using namespace std;

void ManagerTurno::altaTurno() {
    TurnoArchivo archT;
    MascotaArchivo archM;
    ClientesArchivo archC;
    VeterinarioArchivo archVet;
    Turno reg;

    reg.setIdTurno( archT.contarRegistros() + 1 );

    /// --- INGRESAR DNI DEL CLIENTE DUEÑO ---
    int dni;
    cout << "Ingrese DNI del cliente dueño de la mascota (0 para salir): ";
    cin >> dni;

    if (dni == 0) return;

    while (archC.buscarporDNI(dni) == -1 || !archC.estadoCliente(dni)) {
        cout << "Cliente no encontrado o INACTIVO.\n";
        cout << "Ingrese DNI válido o 0 para salir: ";
        cin >> dni;
        if (dni == 0) return;
    }

    /// --- LISTAR MASCOTAS DEL DUENO ---
    cout << "\n--- MASCOTAS DEL CLIENTE ---\n";
    archM.listarMascotaporDueno(dni);

    /// --- INGRESAR ID DE LA MASCOTA ---
    int idMascota;
    cout << "\nIngrese ID de la mascota para el turno (0 para salir): ";
    cin >> idMascota;
    if (idMascota == 0) return;

    int posMascota = archM.buscarPorId(idMascota);
    while (posMascota == -1) {
        cout << "ID inexistente. Ingrese otro o 0 para salir: ";
        cin >> idMascota;
        if (idMascota == 0) return;
        posMascota = archM.buscarPorId(idMascota);
    }

    reg.setIdMascota(idMascota);

    /// --- MATRICULA DEL VETERINARIO ---
    int matricula;
    cout << "\nIngrese matrícula del veterinario (0 para salir): ";
    cin >> matricula;

    if (matricula == 0) return;

    int posVet = archVet.buscarPorMatricula(matricula);

    while (posVet == -1) {
        cout << "Matrícula inexistente. Ingrese otra o 0 para salir: ";
        cin >> matricula;

        if (matricula == 0) return;

        posVet = archVet.buscarPorMatricula(matricula);
    }

    reg.setMatriculaVet(matricula);

    /// --- FECHA ---
    cout << "Fecha del turno:\n";
    Fecha f;
    f.cargar();
    reg.setFechaTurno(f);

    reg.setEstadoTurno(true);

    if (archT.cargarTurno(reg))
        cout << "Turno registrado con éxito.\n";
    else
        cout << "ERROR al guardar el turno.\n";

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
