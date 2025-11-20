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

    int nuevoIdUsuario = archU.contarRegistros() + 1;
    u.setIdUsuario(nuevoIdUsuario);

    cout << "=== ALTA DE VETERINARIO ===\n";

    char aux[40];
    int dni;

    cout << "Nombre: ";
    cargarCadena(aux, 30);
    u.setNombre(aux);

    cout << "Apellido: ";
    cargarCadena(aux, 30);
    u.setApellido(aux);

    cout << "DNI: ";
    cin >> dni;
    u.setDNI(dni);

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
    cout << "Matricula profesional: ";
    int mat;
    cin >> mat;
    v.setMatriculaVet(mat);

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
    int id;
    cout << "ID de veterinario a modificar: ";
    cin >> id;

    int pos = arch.buscarPorId(id);
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
        cout << "El ID ingresado no corresponde a un veterinario.\n";
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

    cout << "Ingrese nuevo DNI (ENTER para mantener): ";
    int dni;
    if (dni > 0) u.setDNI(dni);

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
    int id;
    cout << "ID de veterinario a dar de baja: ";
    cin >> id;

    int pos = arch.buscarPorId(id);
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

    if (arch.eliminar(id))
        cout << "Veterinario dado de baja (inactivo).\n";
    else
        cout << "ERROR al dar de baja.\n";

    system("pause");
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
    int id;
    cout << "ID de veterinario a reactivar: ";
    cin >> id;

    int pos = arch.buscarPorId(id);
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
