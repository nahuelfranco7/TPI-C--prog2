#include <iostream>
#include <cstring>

#include "ManagerVeterinario.h"
#include "VeterinarioArchivo.h"
#include "Clientes.h"
#include "Mascota.h"
#include "Turno.h"
#include "Fecha.h"

using namespace std;


static void cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0; i < tam - 1; i++){
        int c = cin.get();
        if (c == EOF || c == '\n') break;
        palabra[i] = (char)c;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

/*    ABML / Métodos principales
   =========================== */

void ManagerVeterinario::cargar() {

    /// =============================
    ///  PRIMERA PARTE: Cargar USUARIO
    /// =============================
    UsuarioArchivo archU;
    Usuario u;

    cout << "=== ALTA DE VETERINARIO ===\n";

    bool valido = true;
    int DNI;
    while(valido){
    cout << "DNI del Veterinario: ";
    cin >> DNI;

    if(archU.buscarporDNI(DNI)==-1){
    u.setDNI(DNI);
    valido = false;}
    else{ cout << "EL DNI YA EXISTE. INGRESE UN DNI VALIDO." << endl;
        return;}
}
    int nuevoIdUsuario = archU.contarRegistros() + 1;
    u.setIdUsuario(nuevoIdUsuario);

    char aux[40];

    cout << "Nombre: ";
    cargarCadena(aux, 30);
    u.setNombre(aux);

    cout << "Apellido: ";
    cargarCadena(aux, 30);
    u.setApellido(aux);

    cout << "Email: ";
    cargarCadena(aux, 40);
    u.setEmail(aux);

    cout << "Telefono: ";
    cargarCadena(aux, 20);
    u.setTelefono(aux);

    cout << "Clave (max 5 caracteres): ";
    cargarCadena(aux, 6);
    u.setClave(aux);

    u.setNivelSeguridad(2); // veterinario
    u.setEstado(true);

    bool okUsuario = archU.cargarUsuario(u);
    if (!okUsuario) {
        cout << "ERROR al guardar Usuario.\n";
        system("pause");
        return;
    }


    /// ============================================
    ///  SEGUNDA PARTE: Cargar REGISTRO VETERINARIO
    /// ============================================
    VeterinarioArchivo archV;
    Veterinario v;

    bool valido1 = true;
    int mat;
    while(valido1){
    cout << "Matricula del Veterinario: ";
    cin >> mat;

    if(archV.buscarMatriculaVet(mat) == -1){
    v.setMatriculaVet(mat);
    valido1 = false;} else {cout << "LA MATRICULA YA EXISTE. INGRESE UNA MATRICULA VALIDA." << endl;
    return;}
}

    int nuevoIdVet = archV.contarRegistros() + 1;
    v.setId(nuevoIdVet);

    /// Copiar datos personales desde Usuario
    v.setNombre(u.getNombre());
    v.setApellido(u.getApellido());
    v.setDNI(u.getDNI());
    v.setDireccion(u.getDireccion());
    v.setTelefono(u.getTelefono());
    v.setEmail(u.getEmail());
    v.setEstado(u.getEstado());

    /// Datos específicos del veterinario
    Fecha f;
    cout << "Fecha de ingreso:\n";
    f.cargar();
    v.setFechaIngresoVet(f);


    if (archV.cargarVet(v))
        cout << "Veterinario guardado en Veterinarios.dat\n";
    else
        cout << "ERROR al guardar veterinario\n";

    cout << "Alta de veterinario completada correctamente.\n";
    system("pause");
        }
void ManagerVeterinario::modificar() {
    UsuarioArchivo arch;
    int dni;
    cout << "Ingrese Dni del veterinario a modificar: "<<endl;
    cin >> dni;

    int pos = arch.buscarporDNI(dni);
    if (pos < 0) {
        cout << "Veterinario no encontrado.\n";
        system("pause");
        return;
    }

    Usuario u;
    if (!arch.leerUsuario(pos, u)) {
        cout << "Error leyendo el registro.\n";
        system("pause");
        return;
    }

    if (u.getNivelSeguridad() != 2) {
        cout << "El Dni ingresado no corresponde a un veterinario.\n";
        system("pause");
        return;
    }

    cout << "Veterinario actual:\n";
    arch.mostrarUsuario(pos);

    // solicitamos nuevos datos
    char buf[100];
    cout << "Ingrese nuevo nombre (ENTER para mantener): ";

    cargarCadena(buf, 30);
    if (strlen(buf) > 0) u.setNombre(buf);

    cout << "Ingrese nuevo apellido (ENTER para mantener): ";
    cargarCadena(buf, 30);
    if (strlen(buf) > 0) u.setApellido(buf);

    cout << "Ingrese nuevo email (ENTER para mantener): ";
    cargarCadena(buf, 40);
    if (strlen(buf) > 0) u.setEmail(buf);

    cout << "Ingrese nuevo telefono (ENTER para mantener): ";
    cargarCadena(buf, 20);
    if (strlen(buf) > 0) u.setTelefono(buf);

    cout << "Ingrese nueva clave (ENTER para mantener): ";
    char claveBuf[6];
    cargarCadena(claveBuf, 6);
    if (strlen(claveBuf) > 0) u.setClave(claveBuf);

    if (arch.modificarUsuario(pos, u))
        cout << "Veterinario modificado correctamente.\n";
    else
        cout << "ERROR al modificar.\n";

    system("pause");
}

void ManagerVeterinario::eliminar() {
    UsuarioArchivo arch;
    int dni;
    cout << "Dni de veterinario a dar de baja: ";
    cin >> dni;

    int pos = arch.buscarporDNI(dni);
    if (pos < 0) {
        cout << "Veterinario no encontrado.\n";
        system("pause");
        return;
    }

    Usuario u;
    arch.leerUsuario(pos, u);
    if (u.getNivelSeguridad() != 2) {
        cout << "El ID ingresado no corresponde a un veterinario.\n";
        system("pause");
        return;
    }

    if (arch.eliminar(dni))
        cout << "Veterinario dado de baja (inactivo).\n";
    else
        cout << "ERROR al dar de baja.\n";

    system("pause");
}
//-----------LISTADOS VETERINARIOS-----------------------------------------------------------------

void ManagerVeterinario::menuListadoVeterinarios(){
    VeterinarioArchivo arch;
    int opc;
    do {
        system("cls");
        cout << "----LISTADOS DE VETERINARIOS----" << endl;
        cout << "1. Listar veterinarios por ID" << endl;
        cout << "2. Listar veterinarios por matricula" << endl;
        cout << "3. Listar veterinarios por DNI" << endl;
        cout << "4. Listar veterinarios por estado" << endl;
        cout << "5. Listar veterinarios por fecha de ingreso" <<endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: " << endl;
        cin >>opc;

        switch (opc){
            case 1:
                int idVet;
                cout << "Ingrese ID veterinario: " << endl;
                cin >> idVet;
                arch.listarVetporID(idVet);
                break;
            case 2:
                int matVet;
                cout << "Ingrese matricula del veterinario: " << endl;
                cin >> matVet;
                arch.listarVetporMat(matVet);
                break;
            case 3:
                int dniVet;
                cout << "Ingrese Dni veterinario: " << endl;
                cin >> dniVet;
                arch.listarVetporDNI(dniVet);
                break;
            case 4:
                bool estadoVet;
                int aux;
                cout << "Ingrese estado veterinario: " << endl;
                cout << "1. Estado Inactivo" << endl;
                cout << "2. Estado Activo" << endl;
                cin >> aux;
                if(aux == 1 || aux == 2){
                estadoVet = aux - 1;
                arch.listarVetporEstado(estadoVet);
                }
                break;
            case 5:
                Fecha fechaIngVet;
                int dia, mes, anio;
                cout << "Ingrese fecha de ingreso veterinario: " << endl;
                cout << "Ingrese dia: " << endl;
                cin >> dia;
                fechaIngVet.setDia(dia);
                cout << "Ingrese mes: " << endl;
                cin >> mes;
                fechaIngVet.setMes(mes);
                cout << "Ingrese anio: " << endl;
                cin >> anio;
                fechaIngVet.setAnio(anio);
                arch.listarVetporFechaIng(fechaIngVet);
                break;
        }
    } while (opc != 0);
}
void listarVetporID(int idVet){
    VeterinarioArchivo arch;
    arch.listarVetporID(idVet);
}
void listarVetporMat(int MatVet){
    VeterinarioArchivo arch;
    arch.listarVetporMat(MatVet);
}
void listarVetporDNI(int dniVet){
    VeterinarioArchivo arch;
    arch.listarVetporDNI(dniVet);
}
void listarVetporEstado(bool estadoVet){
    VeterinarioArchivo arch;
    arch.listarVetporEstado(estadoVet);
}
void listarVetporFechaIng(Fecha fechaIngresoVet){
    VeterinarioArchivo arch;
    arch.listarVetporFechaIng(fechaIngresoVet);
}


void ManagerVeterinario::listar() {
    UsuarioArchivo arch;
    int total = arch.contarRegistros();
    Usuario u;
    cout << "=== LISTADO DE VETERINARIOS ===\n";
    for (int i = 0; i < total; i++) {
        if (arch.leerUsuario(i, u)) {  //si pudo leer el ab

        if (u.getNivelSeguridad() == 2) {
            cout << "---------------------------\n";
            cout << "ID: " << u.getIdUsuario() << "\n";
            cout << "Nombre: " << u.getNombre() << " " << u.getApellido() << "\n";
            cout << "DNI: " << u.getDNI() << "\n";
            cout << "Email: " << u.getEmail() << "\n";
            cout << "Estado: " << (u.getEstado() ? "Activo" : "Inactivo") << "\n";
        }

    }
    }
    system("pause");
}

void ManagerVeterinario::reactivar() {
    UsuarioArchivo arch;
    int dni;
    cout << "Dni de veterinario a reactivar: ";
    cin >> dni;

    int pos = arch.buscarporDNI(dni);
    if (pos < 0) {
        cout << "Veterinario no encontrado.\n";
        system("pause");
        return;
    }

    Usuario u;
    if (!arch.leerUsuario(pos, u)) { cout << "Error leyendo.\n"; system("pause"); return; }
    if (u.getNivelSeguridad() != 2) {
        cout << "El ID ingresado no corresponde a un veterinario.\n";
        system("pause");
        return;
    }

    u.setEstado(true);
    if (arch.modificarUsuario(pos, u))
        cout << "Veterinario reactivado.\n";
    else
        cout << "ERROR al reactivar.\n";

    system("pause");
}

/* FUNCIONES DE CONSULTA
   =========================================================== */

void ManagerVeterinario::verClientePorDNI() {
    int dni;
    cout << "Ingrese DNI: ";
    cin >> dni;

    ClientesArchivo archC;
    Clientes c;
    int total = archC.contarRegistros();
    for (int i = 0; i < total; i++) {
        if (!archC.leerClientes(i, c)) continue;
        if (c.getDNI() == 0) {
            archC.mostrarClientes(i, c);
            system("pause");
            return;
        }
    }

    cout << "Cliente no encontrado.\n";
    system("pause");
}

void ManagerVeterinario::listarMascotasDeCliente() {
    int dni;
    cout << "Ingrese DNI del cliente: ";
    cin >> dni;

    ClientesArchivo archC;
    Clientes c;
    int totalC = archC.contarRegistros();
    int idCliente = -1;
    for (int i = 0; i < totalC; i++) {
        if (!archC.leerClientes(i, c)) continue;
        if (c.getDNI() == 0) { idCliente = c.getIdCliente(); break; }
    }

    if (idCliente < 0) {
        cout << "Cliente no encontrado.\n";
        system("pause");
        return;
    }

    MascotaArchivo archM;
    Mascota m;
    int totalM = archM.contarRegistros();
    bool encontro = false;
    cout << "Mascotas del cliente:\n";
    for (int i = 0; i < totalM; i++) {
        if (!archM.leerMascota(i, m)) continue;
        if (m.getIdClienteDueno() == idCliente) {
            cout << "ID: " << m.getIdMascota() << " - " << m.getNombreMascota()
                 << " (" << (m.getEstadoMascota() ? "ACTIVO" : "INACTIVO") << ")\n";
            encontro = true;
        }
    }
    if (!encontro) cout << "No tiene mascotas registradas.\n";
    system("pause");
}

void ManagerVeterinario::listarTurnoPorID() {
    int id;
    cout << "ID Turno: ";
    cin >> id;

    TurnoArchivo archT;
    Turno t;
    int total = archT.contarRegistros();
    for (int i = 0; i < total; i++) {
        if (!archT.leerTurno(i, t)) continue;
        if (t.getIdTurno() == id) {
            archT.mostrarTurno(t);
            system("pause");
            return;
        }
    }
    cout << "Turno no encontrado.\n";
    system("pause");
}

void ManagerVeterinario::listarTurnosPorFecha() {
    Fecha f;
    cout << "Ingrese fecha del turno:\n";
    f.cargar();

    TurnoArchivo archT;
    Turno t;
    int total = archT.contarRegistros();
    bool encontro = false;
    for (int i = 0; i < total; i++) {
        if (!archT.leerTurno(i, t)) continue;
        Fecha ft = t.getFechaTurno();
        if (ft.getDia() == f.getDia() && ft.getMes() == f.getMes() && ft.getAnio() == f.getAnio()) {
            archT.mostrarTurno(t);
            encontro = true;
        }
    }
    if (!encontro) cout << "No hay turnos en esa fecha.\n";
    system("pause");
}

void ManagerVeterinario::listarTurnosPorEstado() {
    int est;
    cout << "Estado (0=Pendiente,1=Atendido,2=Cancelado): ";
    cin >> est;

    TurnoArchivo archT;
    Turno t;
    int total = archT.contarRegistros();
    bool found = false;
    for (int i = 0; i < total; i++) {
        if (!archT.leerTurno(i, t)) continue;
        if (t.getEstadoTurno() == est) {
            archT.mostrarTurno(t);
            found = true;
        }
    }
    if (!found) cout << "No hay turnos con ese estado.\n";
    system("pause");
}

/* Buscar veterinario por ID (devuelve posicion en archivo usuarios o -1) */
int ManagerVeterinario::buscarPorID(int id) {
    UsuarioArchivo arch;
    int total = arch.contarRegistros();
    Usuario usuario;

    for (int i = 0; i < total; i++) {
        if (!arch.leerUsuario(i, usuario)) continue;
        if (usuario.getIdUsuario() == id && usuario.getNivelSeguridad() == 2) return i;
    }
    return -1;
}
