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

void ManagerTurno::menuListadoTurnos() {

    TurnoArchivo arch;
    int opc;

    do {
        system("cls");
        cout << "----LISTADOS DE TURNOS----" << endl;
        cout << "1. Listar turnos por ID" << endl;
        cout << "2. Listar turnos por ID Mascota" << endl;
        cout << "3. Listar turnos por ID Veterinario" << endl;
        cout << "4. Listar turnos por Fecha" << endl;
        cout << "5. Listar turnos por Estado" << endl;
        cout << "6. Listar turnos por DNI Cliente" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch (opc) {

        case 1: {
            int id;
            cout << "Ingrese ID turno: ";
            cin >> id;
            arch.listarTurnosPorID(id);
            system("pause");
            break;
        }

        case 2: {
            int idMascota;
            cout << "Ingrese ID mascota: ";
            cin >> idMascota;
            arch.listarTurnosPorIDMascota(idMascota);
            system("pause");
            break;
        }

        case 3: {
            int idVet;
            cout << "Ingrese Matricula veterinario: ";
            cin >> idVet;
            arch.listarTurnosPorMatVeterinario(idVet);
            system("pause");
            break;
        }

        case 4: {
            Fecha fecha;
            int d, m, a;
            cout << "Ingrese fecha (DD MM AAAA): ";
            cin >> d >> m >> a;
            fecha.setDia(d);
            fecha.setMes(m);
            fecha.setAnio(a);

            arch.listarTurnosPorFecha(fecha);
            system("pause");
            break;
        }

        case 5: {
            int aux;
            bool estado;

            cout << "Estado:\n";
            cout << "1. Inactivo\n";
            cout << "2. Activo\n";
            cout << "Opción: ";
            cin >> aux;

            if (aux==1 || aux==2) {
                estado = aux - 1;
                arch.listarTurnosPorEstado(estado);
            } else {
                cout << "Estado incorrecto.\n";
            }
            system("pause");
            break;
        }

        case 6: {
            int dni;
            cout << "Ingrese DNI del cliente: ";
            cin >> dni;

            listarTurnosPorDNICliente(dni);
            system("pause");
            break;
        }

        }

    } while (opc != 0);
}

void ManagerTurno::listarTurnosPorDNICliente(int dni) {
    TurnoArchivo arch;
    arch.listarTurnosPorDNICliente(dni);
    system("pause");
}


