#include <iostream>
#include <cstdlib>
#include <cstring>
#include "TurnoArchivo.h"
#include "Fecha.h"
///#include "Mascota.h"

using namespace std;

/*

    int buscarPorId(int id);
    int contarRegistros();
    int generarNuevoId();

    void cargarCadena(char *palabra, int tam);
    bool cargarTurno();
    void listarTodos(); falta este
    void eliminar(int pos);
    void mostrarTurno(int pos, const Turno &reg);

    bool modificar(int pos);
    bool cargarTurno(const Turno &reg);
    bool modificarTurno(int pos, const Turno &reg);
    bool leerTurno(int pos, const Turno &reg);
*/

const char* TurnoArchivo::getNombreArchivo(){
    return _nombreArchivo;
}

int TurnoArchivo::buscarPorId(int id){
    Turno reg;
    int pos = 0;
    FILE* p=fopen(_nombreArchivo,"rb");
    if (p==nullptr) return false;
    while (fread(&reg,sizeof(Turno),1,p)){
        if (reg.getIdTurno()==id){
            fclose(p);
            return pos;
        }
        pos++;
    }
    return -1;
}

int TurnoArchivo::contarRegistros(){
    FILE* p=fopen(_nombreArchivo,"rb");
    if (p==nullptr) return -1;
    fseek(p,0,SEEK_END);
    int tamanio=ftell(p);
    fclose(p);
    int cantidadRegistros=tamanio/sizeof(Turno);
    return cantidadRegistros;
}

int TurnoArchivo::generarNuevoId() {
    return contarRegistros() + 1;
}
//cargar cadena------------------------------------------
void TurnoArchivo::cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0; i < tam; i++){
        palabra[i] = cin.get();
        if (palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}
/*----------------------------------------------------*/
bool TurnoArchivo::cargarTurno(const Turno &reg) {
    FILE *p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Turno), 1, p);
    fclose(p);
    return ok;
}

bool TurnoArchivo::cargarTurno(){
    Turno reg;
    int idTurno;
    int idMascota;
    int idVet;
    Fecha fechaTurno;

    idTurno=generarNuevoId();
    reg.setIdTurno(idTurno);

    cout<<"Ingrese id Mascota:"<<endl;
    cin>> idMascota;
    reg.setIdMascota(idMascota);

    cout<<"Ingrese id Veterinario: "<<endl;
    cin>> idVet;
    reg.setIdVet(idVet);

    cout<<"Ingrese la fecha del turno: "<<endl;
    fechaTurno.cargar();
    reg.setFechaTurno(fechaTurno);
}
void TurnoArchivo::listarTodos(){
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) {
        cout << "ERROR AL ABRIR EL ARCHIVO DE TURNOS." << endl;
        return;
    }

    Turno reg;
    int i = 0;

    cout << "=== LISTADO DE TURNOS ===" << endl;


    while (fread(&reg, sizeof(Turno), 1, p) == 1) {
        if (reg.getEstado() == true) {
            cout << "-----------------------------" << endl;
            cout << "REGISTRO N°: " << i + 1 << endl;
            cout << "ID TURNO: " << reg.getIdTurno() << endl;
            cout << "ID MASCOTA: " << reg.getIdMascota() << endl;
            cout << "ID VETERINARIO: " << reg.getIdVet() << endl;
            cout << "FECHA DEL TURNO: " << reg.getFechaTurno() << endl;
        } //aca tambien, faltan datos que tenemos que vincular
        i++;
    }

    fclose(p);
}

void TurnoArchivo::eliminar(int pos){
    Turno reg;

    // 1) Leer el registro
    if (!leerTurno(pos, reg)) {
        cout << "NO SE PUDO LEER EL REGISTRO." << endl;
        return false;
    }

    // 2) Cambiar su estado
    reg.setEstadoTurno(false);

    // 3) Sobrescribir el registro con el estado actualizado
    if (!modificarTurno(pos, reg)) {
        cout << "NO SE PUDO ESCRIBIR EL REGISTRO." << endl;
        return false;
    }

    cout << "TURNO ELIMINADO (ESTADO = FALSE)." << endl;
    return true;
}

void TurnoArchivo::mostrarTurno(int pos, const Turno &reg){
    cout<<"---------------------------------"<<endl;
    cout<<"POSICION EN EL ARCHIVO: "<<pos;
    cout<<"ID TURNO: "<<reg.getIdTurno();
    cout<<"VETERINARIO: "<<reg.getIdVet();
    cout<<"ID MASCOTA: "<<reg.getIdMascota();
    cout<<"FECHA DEL TURNO: "<<reg.getFechaTurno();
} /// Traer nombre de la mascota, nombre del cliente y telefono?

bool TurnoArchivo::modificar(int pos){
    Turno reg;
    FILE *p = fopen(_nombreArchivo,"rb+");
    if (p==nullptr) return false;

    fseek(p,pos*sizeof(Turno),SEEK_SET);
    fread(&reg,sizeof(Turno),1,p);

    cout << "Registro actual:\n";
    mostrarTurno(pos, reg);

    cout << "\nIngrese los nuevos datos:\n";
    cargarTurno();

    //va de nuevo posición del registro para sobrescribirlo
    fseek(p, pos * sizeof(Turno), SEEK_SET);

    bool ok = fwrite(&reg, sizeof(Turno), 1, p);//creo una var booleana para devolver si es que carga true o false

    fclose(p);
    return ok;

}

bool TurnoArchivo::modificarTurno(int pos, const Turno &reg) {
    FILE *p = fopen(_nombreArchivo, "rb+"); //lectura y escritura
    if (p == nullptr) return false;

    fseek(p, pos * sizeof(Turno), SEEK_SET); //Nos movemos a la posición exacta

    bool escribio = fwrite(&reg, sizeof(Turno), 1, p); //Sobrescribe el registro

    fclose(p);
    return escribio;
}
