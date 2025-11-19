#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "ManagerRecepcionista.h"

#include "ClientesArchivo.h"
#include "MascotaArchivo.h"
#include "VeterinarioArchivo.h"
#include "TurnoArchivo.h"
#include "FacturaArchivo.h"
#include "DetalleFacturaArchivo.h"


// Menus de turnos

void ManagerRecepcionista::menuTurnos() {
    int opc;

    do {
        system("cls");
        cout << "=== TURNOS ===\n";
        cout << "1) Cargar turno\n";
        cout << "2) Modificar turno\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> opc;


        switch (opc) {
            case 1:
                cargarTurno();
                break;

            case 2:
                modificarTurno();
                break;

            case 0:
                break;

            default:
                cout << "Opcion invalida.\n";
                system("pause");
                break;
        }

    } while (opc != 0);
}

/*------------------------------------------------*/
void ManagerRecepcionista::modificarTurno() {
    TurnoArchivo archT;
    Turno turno;
    int id;

    system("cls");
    cout << "=== MODIFICAR TURNO ===\n\n";


    cout << "Ingrese ID de turno a modificar: ";
    cin >> id;


    int pos = archT.buscarPorId(id);
    if (pos < 0) {
        cout << "No existe un turno con ese ID.\n";
        system("pause");
        return;
    }

    // 2) Leemos el turno
    if (!archT.leerTurno(pos, turno)) {
        cout << "Error al leer el turno.\n";
        system("pause");
        return;
    }

    // 3) Mostramos datos actuales
    cout << "\n--- Datos actuales ---\n";
    archT.mostrarTurno(pos, turno);

    // 4) Modificamos datos
    int opcion;
    bool salir = false;

    do {
        cout << "\n--- MENU DE MODIFICACION ---\n";
        cout << "1) Cambiar ID Mascota\n";
        cout << "2) Cambiar ID Veterinario\n";
        cout << "3) Cambiar Fecha\n";
        cout << "4) Cambiar Estado (1 activo / 0 inactivo)\n";
        cout << "0) Guardar y salir\n";
        cout << "Opcion: ";
        cin >> opcion;



        switch(opcion) {
            case 1: {
                int idM;
                cout << "Nuevo ID de mascota: ";
                cin >> idM;
                    turno.setIdMascota(idM);
            } break;
            case 2: {
                int idV;
                cout << "Nuevo ID de veterinario: ";
                cin >> idV;
                    turno.setIdVet(idV);
            } break;
            case 3: {
                Fecha f;
                cout << "Nueva fecha:\n";
                f.cargar();
                turno.setFechaTurno(f);
            } break;

            case 4: {
                int e;
                cout << "Estado (1 activo / 0 inactivo): ";
                cin >> e;

                    turno.setEstadoTurno(e == 1);

            } break;

            case 0:
                salir = true;
                break;

            default:
                cout << "Opcion invalida.\n";
                break;
        }

    } while (!salir);

    // 5) Guardar cambios
    if (archT.modificarTurno(pos, turno)) {
        cout << "\nTurno modificado correctamente.\n";
    } else {
        cout << "\nERROR: No se pudo guardar la modificacion.\n";
    }

    system("pause");
}

/*-------------------------------------------------*/
void ManagerRecepcionista::cargarTurno() {

    TurnoArchivo archT;
    MascotaArchivo archM;
    VeterinarioArchivo archV;
    Turno turno;

    system("cls");
    cout << "=== CARGAR NUEVO TURNO ===\n\n";


    //1) Generar ID (autoincremental)

    int nuevoID = archT.contarRegistros() + 1;
    turno.setIdTurno(nuevoID);



    // 2) Ingresar ID Mascota

    int idMascota;
    bool valido = false;

    do {
        cout << "ID Mascota: ";
        cin >> idMascota;

         if (idMascota <= 0) {
            cout << "Error: El ID debe ser positivo.\n";
        }
        else {
            int pos = archM.buscarPorId(idMascota);
            if (pos < 0) {
                cout << "No existe una mascota con ese ID.\n";
            } else {
                valido = true;
            }
        }

    } while (!valido);

    turno.setIdMascota(idMascota);



    // 3) Ingresar ID Veterinario

    int idVet;
    valido = false;

    do {
        cout << "ID Veterinario: ";
        cin >> idVet;
 if (idVet <= 0) {
            cout << "Error: El ID debe ser positivo.\n";
        }
        else {
            int pos = archV.buscarPorId(idVet);
            if (pos < 0) {
                cout << "No existe un veterinario con ese ID.\n";
            } else {
                valido = true;
            }
        }

    } while (!valido);

    turno.setIdVet(idVet);



    // 4) Cargar fecha
    // ------------------------------
    cout << "\nIngrese fecha del turno:\n";
    Fecha f;
    f.cargar();
    turno.setFechaTurno(f);


  // 5) Estado

    turno.setEstadoTurno(true);

    // 6) Guardar en archivo

    if (archT.cargarTurno(turno)) {
        cout << "\nTurno cargado correctamente.\n";
    }
    else {
        cout << "\nERROR: No se pudo guardar el turno.\n";
    }

    system("pause");
}

/*-------------------------------------------------*/
void ManagerRecepcionista::menuFacturacion() {
    // Recepcionista puede ver facturas, no emitir
    if (!(_nivelUsuario == 1 || _nivelUsuario == 3 || _nivelUsuario == 4)) {
        cout << "Acceso denegado a Facturacion.\n";
        system("pause");
        return;
    }

    int opc;
    do {
        system("cls");
        cout << "=== FACTURACION (Consultas) ===\n";
        cout << "1) Ver detalle de factura\n";
        cout << "2) Listar facturas\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> opc;

        switch(opc) {
            case 1: facturacionVerDetalle(); break;
            case 2: listarFacturas(); break;
            case 0: break;
            default: cout << "Opcion invalida\n"; system("pause"); break;
        }
    } while(opc != 0);
}

// Listados

void ManagerRecepcionista::menuListados() {
    int opcion;

    do {
        system("cls");
        cout << "=====================================\n";
        cout << "         LISTADOS GENERALES\n";
        cout << "=====================================\n";
        cout << "1) Listar clientes\n";
        cout << "2) Listar mascotas\n";
        cout << "3) Listar veterinarios\n";
        cout << "4) Listar facturas\n";
        cout << "5) Listar turnos\n";
        cout << "0) Volver al menu anterior\n";
        cout << "-------------------------------------\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: listarClientes();     break;
            case 2: listarMascotas();     break;
            case 3: listarVeterinarios(); break;
            case 4: listarFacturas();     break;
            case 5: listarTurnos();       break;
            case 0: break;
            default:
                cout << "Opcion invalida\n";
                system("pause");
        }

    } while (opcion != 0);
}


/*----------------------------*/
void ManagerRecepcionista::listarClientes() {
    ClientesArchivo arch;
    cout << "=== LISTADO DE CLIENTES ===\n";
    arch.listarTodos();
    system("pause");
}

void ManagerRecepcionista::listarMascotas() {
    MascotaArchivo arch;
    cout << "=== LISTADO DE MASCOTAS ===\n";
    arch.listarTodos();
    system("pause");
}

void ManagerRecepcionista::listarVeterinarios() {
    VeterinarioArchivo arch;
    cout << "=== LISTADO DE VETERINARIOS ===\n";
    arch.listarTodos();
    system("pause");
}

void ManagerRecepcionista::listarFacturas() {
    FacturaArchivo arch;
    cout << "=== LISTADO DE FACTURAS ===\n";
    arch.listarTodos();
    system("pause");
}

void ManagerRecepcionista::listarTurnos() {
    TurnoArchivo arch;
    cout << "=== LISTADO DE TURNOS ===\n";
    arch.listarTodos();
    system("pause");
}

// Consultas
// ---------------------------
void ManagerRecepcionista::menuConsultas() {
    int opcion;

    do {
        system("cls");
        cout << "=====================================\n";
        cout << "           CONSULTAS FILTRADAS\n";
        cout << "=====================================\n";
        cout << "1) Consulta por ID\n";
        cout << "2) Consulta por DNI\n";
        cout << "3) Consulta por Fecha de Turno\n";
        cout << "4) Consulta por Estado de Turno\n";
        cout << "0) Volver al menu anterior\n";
        cout << "-------------------------------------\n";
        cout << "Opcion: ";
        cin >> opcion;

            switch(opcion) {
            case 1: consultaPorID();     break;
            case 2: consultaPorDNI();    break;
            case 3: consultaPorFecha();  break;
            case 4: consultaPorEstado(); break;
            case 0: break;
            default:
                cout << "Opcion invalida.\n";
                system("pause");
        }

    } while (opcion != 0);
}

void ManagerRecepcionista::consultaPorID() {
    int tipo;
    cout << "Consultar por ID en: 1) Cliente 2) Mascota 3) Veterinario 4) Turno\n";
    cout << "Opcion: ";
    cin >> tipo;

    if (tipo == 1) {
        int id; cout << "ID Cliente: "; cin >> id;

        ClientesArchivo arch; Clientes reg;
        int pos = arch.buscarporId(id);
        if (pos < 0) { cout << "Cliente no encontrado.\n"; return; }
        arch.mostrarClientes(pos, reg);
    } else if (tipo == 2) {
        int id; cout << "ID Mascota: "; cin >> id;

        MascotaArchivo arch; Mascota reg;
        int pos = arch.buscarPorId(id);
        if (pos < 0) { cout << "Mascota no encontrada.\n"; return; }
        arch.mostrarMascota(pos, reg);
    } else if (tipo == 3) {
        int id; cout << "ID Veterinario: "; cin >> id;

        VeterinarioArchivo arch; Veterinario reg;
        int pos = arch.buscarPorId(id);
        if (pos < 0) { cout << "Veterinario no encontrado.\n"; return; }
        arch.mostrarVeterinario(pos, reg);
    } else if (tipo == 4) {
        int id; cout << "ID Turno: "; cin >> id;

        TurnoArchivo arch; Turno reg;
        int pos = arch.buscarPorId(id);
        if (pos < 0) { cout << "Turno no encontrado.\n"; return; }
        arch.mostrarTurno(pos, reg);
    } else {
        cout << "Opcion invalida\n";
    }
    system("pause");
}

void ManagerRecepcionista::consultaPorDNI() {
    cout << "Buscar por DNI (Clientes / Veterinarios)\n";
    int dni;
    cout << "DNI: ";
    cin >> dni;


    ClientesArchivo archC; Clientes c;
    int totalC = archC.contarRegistros();
    bool encontrado = false;
    for (int i=0;i<totalC;i++){
        if (!archC.leerClientes(i,c)) continue;
        if (c.getDNI() == 0) {
            archC.mostrarClientes(i, c);
            encontrado = true;
        }
    }

    VeterinarioArchivo archV; Veterinario v;
    int totalV = archV.contarRegistros();
    for (int i=0;i<totalV;i++){
        if (!archV.leerVet(i,v)) continue;

        if (v.getDNI() == 0) {
            archV.mostrarVeterinario(i, v);
            encontrado = true;
        }
    }

    if (!encontrado) cout << "No se encontraron registros con ese DNI.\n";
    system("pause");
}

void ManagerRecepcionista::consultaPorFecha() {
    cout << "Buscar turnos por fecha\n";
    Fecha fecha;
    fecha.cargar();

    TurnoArchivo archT; Turno t;
    int total = archT.contarRegistros();
    bool encontro = false;
    for (int i=0;i<total;i++){
        if (!archT.leerTurno(i,t)) continue;
        Fecha f = t.getFechaTurno();
        if (f.getDia() == fecha.getDia() && f.getMes() == fecha.getMes() && f.getAnio() == fecha.getAnio()) {
            cout << "ID Turno: " << t.getIdTurno() << " | Mascota: " << t.getIdMascota() << " | Vet: " << t.getIdVet() << " | Estado: " << (t.getEstadoTurno() ? "ACTIVO" : "INACTIVO") << "\n";
            encontro = true;
        }
    }
    if (!encontro) cout << "No se encontraron turnos en esa fecha.\n";
    system("pause");
}

void ManagerRecepcionista::consultaPorEstado() {
    cout << "Consulta por estado de turnos\n";
    cout << "Ingrese 1 para ACTIVO o 0 para INACTIVO: ";
    int s;
    cin >> s;

    bool estado = (s == 1);

    TurnoArchivo archT; Turno t;
    int total = archT.contarRegistros();
    bool encontro = false;
    for (int i=0;i<total;i++){
        if (!archT.leerTurno(i,t)) continue;
        if (t.getEstadoTurno() == estado) {
            cout << "ID Turno: " << t.getIdTurno() << " | Mascota: " << t.getIdMascota() << " | Vet: " << t.getIdVet() << " | Fecha: ";
            t.getFechaTurno().mostrar(); cout << " | Estado: " << (t.getEstadoTurno() ? "ACTIVO" : "INACTIVO") << "\n";
            encontro = true;
        }
    }
    if (!encontro) cout << "No se encontraron turnos con ese estado.\n";
    system("pause");
}


// Busquedas rapidas
// ---------------------------
void ManagerRecepcionista::menuBusquedas() {
    int opcion;

    do {
        system("cls");
        cout << "=====================================\n";
        cout << "           BUSQUEDAS GENERALES\n";
        cout << "=====================================\n";
        cout << "1) Buscar cliente por DNI\n";
        cout << "2) Buscar mascota por nombre\n";
        cout << "0) Volver al menu anterior\n";
        cout << "-------------------------------------\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                buscarClientePorDNI();
                break;

            case 2:
                buscarMascotaPorNombre();
                break;

            case 0:
                break;

            default:
                cout << "Opcion invalida.\n";
                system("pause");
        }

    } while (opcion != 0);
}

bool ManagerRecepcionista::buscarClientePorDNI() {

    int dni;
    cout << "Ingrese DNI del cliente: ";
    cin >> dni;

    ClientesArchivo archC; Clientes c;
    int total = archC.contarRegistros();
    int pos = -1;
    for (int i=0;i<total;i++){
        if (!archC.leerClientes(i,c)) continue;
        if (c.getDNI()== 0) { pos = i; break; }
    }

    if (pos < 0) {
        cout << "Cliente no encontrado.\n";
        system("pause");
        return false;
    }

    archC.mostrarClientes(pos, c);

    // listar mascotas del cliente
    MascotaArchivo archM; Mascota m;
    int totalM = archM.contarRegistros();
    bool a = false;
    for (int i=0;i<totalM;i++){
        if (!archM.leerMascota(i,m)) continue;
        if (m.getIdClienteDueno() == c.getIdCliente()) {
            cout << "ID Mascota: " << m.getIdMascota() << " - Nombre: " << m.getNombreMascota() << " - Estado: " << (m.getEstadoMascota() ? "ACTIVO" : "INACTIVO") << "\n";
            a = true;
        }
    }
    if (!a) cout << "El cliente no tiene mascotas registradas.\n";
    system("pause");
}

void ManagerRecepcionista::buscarMascotaPorNombre() {
    char nombre[30];
    cout << "Ingrese nombre de la mascota: ";
    cin >> nombre;

    MascotaArchivo archM; Mascota m;
    int total = archM.contarRegistros();
    bool encontro = false;
    for (int i=0;i<total;i++){
        if (!archM.leerMascota(i,m)) continue;
        if (strcmp(m.getNombreMascota(), nombre) == 0) {
            cout << "ID Mascota: " << m.getIdMascota() << " - Nombre: " << m.getNombreMascota() << " - ID Dueno: " << m.getIdClienteDueno() << " - Estado: " << (m.getEstadoMascota() ? "ACTIVO" : "INACTIVO") << "\n";
            encontro = true;
        }
    }
    if (!encontro) cout << "No se encontraron mascotas con ese nombre.\n";
    system("pause");
}

// Facturacion (detalle)
// ---------------------------
void ManagerRecepcionista::facturacionVerDetalle() {
    FacturaArchivo archF;
    DetalleFacturaArchivo archD;
    int id;
    cout << "Ingrese ID de factura: ";
    cin >> id;

    int pos = archF.buscarPorId(id);
    if (pos < 0) { cout << "Factura no encontrada.\n"; system("pause"); return; }


    Factura f;
    if (!archF.leerFactura(pos, f)) { cout << "Error leyendo factura.\n"; system("pause"); return; }
    cout << "Factura ID: " << f.getIdFactura() << " | Fecha: "; f.getFechaFactura().mostrar(); cout << " | Importe: " << f.getImporteTotalFactura() << " | Estado: " << (f.getEstadoFactura() ? "ACTIVO":"ANULADA") << "\n";
    cout << "Detalle:\n";
    archD.mostrarPorIdFactura(f.getIdFactura());
    system("pause");
}

// Informes
// ---------------------------
void ManagerRecepcionista::informeCantidadTurnosMes() {
    cout << "Informe: Cantidad de turnos en el mes elegido\n";
    int mes, anio;
    cout << "Mes (1-12): ";
    cin >> mes;
    cout << "Anio (YYYY): ";
    cin >> anio;

    TurnoArchivo archT; Turno t;
    int total = archT.contarRegistros();
    int contador = 0;
    for (int i=0;i<total;i++) {
        if (!archT.leerTurno(i,t)) continue;
        Fecha f = t.getFechaTurno();
        if (f.getMes() == mes && f.getAnio() == anio) contador++;
    }

    cout << "Total de turnos en " << mes << "/" << anio << ": " << contador << "\n";
    system("pause");
}

void ManagerRecepcionista::informeRecaudacionMes() {
    cout << "Informe: Recaudacion del mes\n";
    int mes, anio;
    cout << "Mes (1-12): "; cin >> mes;
    cout << "Anio (YYYY): "; cin >> anio;

    FacturaArchivo archF; Factura f;
    int total = archF.contarRegistros();
    double suma = 0.0;
    for (int i=0;i<total;i++) {
        if (!archF.leerFactura(i,f)) continue;
        Fecha fe = f.getFechaFactura();
        if (fe.getMes() == mes && fe.getAnio() == anio && f.getEstadoFactura()) {
            suma += f.getImporteTotalFactura();
        }
    }

    cout << "Recaudacion total en " << mes << "/" << anio << ": " << suma << "\n";
    system("pause");
}

void ManagerRecepcionista::informeRecaudacionPorVeterinario() {
    cout << "Informe: Recaudacion por veterinario (mes elegido)\n";
    int mes, anio;
    cout << "Mes (1-12): "; cin >> mes;
    cout << "Anio (YYYY): "; cin >> anio;

    FacturaArchivo archF;
    Factura f;
    int total = archF.contarRegistros();
    // 1) obtenemos la lista de veterinarios activos
    VeterinarioArchivo archV; Veterinario v;
    int totalV = archV.contarRegistros();

    for (int j=0;j<totalV;j++) {
        if (!archV.leerVet(j,v)) continue;
        int idVet = v.getID();
        float suma = 0.0;
        for (int i=0;i<total;i++) {
            if (!archF.leerFactura(i,f)) continue;
            Fecha fe = f.getFechaFactura();
            if (fe.getMes() == mes && fe.getAnio() == anio && f.getEstadoFactura() && f.getIdUsuario() == idVet) {

                suma += f.getImporteTotalFactura();
            }
        }
        cout << "Veterinario ID: " << idVet << " - Nombre: "; cout << v.getApellido() << ", " << v.getNombre() << " - Recaudacion: " << suma << "\n";
    }
    system("pause");
}

void ManagerRecepcionista::informeRecaudacionPorDia() {
    cout << "Informe: Recaudacion por dia (en mes elegido)\n";
    int mes, anio;
    cout << "Mes (1-12): "; cin >> mes;
    cout << "Anio (YYYY): "; cin >> anio;

    FacturaArchivo archF;
    Factura f;
    int total = archF.contarRegistros();

    // recorremos y vamos sumando por dia (mostramos cada dia encontrado)
    for (int dia = 1; dia <= 31; dia++) {
    float sumaDia = 0.0;
    bool existe = false;

    for (int i = 0; i < total; i++) {
        if (archF.leerFactura(i, f)) {//si lee
            Fecha fe = f.getFechaFactura();

            if (fe.getMes() == mes &&
                fe.getAnio() == anio &&
                fe.getDia() == dia &&
                f.getEstadoFactura()) {

                sumaDia += f.getImporteTotalFactura();
                existe = true;
            }
        }
        //Si no lee no entraen if
    }

    if (existe) {
        cout << "Dia " << dia << ": " << sumaDia << "\n";
    }
}
    system("pause");
}
