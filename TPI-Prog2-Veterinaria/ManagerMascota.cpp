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

    bool valido = true;
    while (valido){
        int dni;
        cout << "DNI Cliente dueño: ";
        cin >> dni;
    if (a.buscarporDNI(dni) == -1 || a.estadoCliente() == false){
        cout << "Cliente no encontrado, dar de alta cliente antes o ingresar uno valido.\n";
        valido = false;
        system ("pause");
    } else {



    reg.cargar(dni);
    reg.setEstadoMascota(true);
    reg.setIdMascota( arch.contarRegistros() + 1 );

    if (arch.cargarMascota(reg)){
        cout << "Mascota guardada!\n";
        valido = false;
        system ("pause");}
    else{
        cout << "ERROR al guardar.\n";
        valido = false;
        system("pause");}

    }
  }
}

void ManagerMascota::modificarMascota() {
    MascotaArchivo arch;
    ClientesArchivo a;
    int dnicliente;
    cout << "INGRESE DNI DE CLIENTE DUENO: \n";
    cin >> dnicliente;

    bool valido = true;
    while (valido){
    if (a.buscarporDNI(dnicliente)==-1 || a.estadoCliente() == false){
        cout << "Cliente no encontrado.\n";
        valido = false;
    } else {

    Mascota reg;
    arch.listarMascotaporDueno(dnicliente);
    int idmascota;
    cout << "INGRESE ID DE LA MASCOTA A MODIFICAR: \n";
    cin >> idmascota;
    int pos;
    pos = arch.buscarPorId(idmascota);
    arch.leerMascota(pos, reg);

    cout << "Mascota seleccionada:\n";
    arch.mostrarMascota(pos, reg);

    cout << "Ingrese nuevos datos:\n";
    reg.cargar(dnicliente);

    if (arch.modificarMascota(pos, reg))
        cout << "Modificado OK.\n";
    else
        cout << "ERROR.\n";
    }
    system("pause");
    return;
}
}
/*void ManagerMascota::bajaMascota() {
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
}*/

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

void listarMascotasporDni(int dniDueno){
    MascotaArchivo arch;
    arch.listarMascotaporDueno(dniDueno);
    system("pause");

}
