#include <iostream>
#include <cstdlib>
#include <cstring>
#include "TurnoArchivo.h"
#include "Fecha.h"
#include "Mascota.h"

using namespace std;


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

    int matricula;
    Fecha fechaTurno;

    idTurno=generarNuevoId();
    reg.setIdTurno(idTurno);

    cout<<"Ingrese id Mascota:"<<endl;
    cin>> idMascota;
    reg.setIdMascota(idMascota);

    cout<<"Ingrese Matricula de Veterinario: "<<endl;
    cin>> matricula;
    reg.setMatriculaVet(matricula);

    cout<<"Ingrese la fecha del turno: "<<endl;
    fechaTurno.cargar();
    reg.setFechaTurno(fechaTurno);

        if (cargarTurno(reg)) {
        cout << "DETALLE GUARDADO EXITOSAMENTE." << endl;
        return true;
    } else {
        cout << "ERROR AL GUARDAR EL DETALLE." << endl;
        return false;
    }

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
        if (reg.getEstadoTurno() == true) {
            cout << "-----------------------------" << endl;
            cout << "REGISTRO N°: " << i + 1 << endl;
            cout << "ID TURNO: " << reg.getIdTurno() << endl;
            cout << "ID MASCOTA: " << reg.getIdMascota() << endl;
            cout << "ID VETERINARIO: " << reg.getMactriculaVet() << endl;
            Fecha fe = reg.getFechaTurno();
            cout << "FECHA DEL TURNO: " << fe.getDia() << "/" << fe.getMes() << "/"  << fe.getAnio() << endl;
        } //aca tambien, faltan datos que tenemos que vincular
        i++;
    }

    fclose(p);
}

bool TurnoArchivo::eliminar(int pos){
     FILE *p=fopen(_nombreArchivo,"rb+");
    if(p==nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO DE TURNOS."<<endl;
        return false;
    }

    Turno reg;

    //Posicionamos en el registro indicado
    fseek(p,pos*sizeof(Turno),SEEK_SET);

    //Leemos el registro existente
    if(fread(&reg, sizeof(Turno),1,p)!=1) {
        fclose(p);
        cout<<"NO SE PUDO LEER EL REGISTRO EN LA POSICION INDICADA."<<endl;
        return false;
    }

    //Modifica el estado a inactivo
    reg.setEstadoTurno(false);

    //Volver a posicionarse en la misma posición para sobrescribir
    fseek(p,pos*sizeof(Turno),SEEK_SET);

    //Escribir el registro modificado
    bool ok=fwrite(&reg, sizeof(Turno),1,p);

    fclose(p);
    return ok;
}

void TurnoArchivo::mostrarTurno(int pos,const Turno &reg){
    cout<<"---------------------------------"<<endl;
    cout<<"POSICION EN EL ARCHIVO: "<<pos;
    cout<<"ID TURNO: "<<reg.getIdTurno();
    cout<<"VETERINARIO: "<<reg.getMactriculaVet();
    cout<<"ID MASCOTA: "<<reg.getIdMascota();
    Fecha fe = reg.getFechaTurno();
    cout<<"FECHA DEL TURNO: " << fe.getDia() << "/" << fe.getMes() << "/" << fe.getAnio() << endl;
}
void TurnoArchivo::mostrarTurno(const Turno &reg) {
    cout << "---------------------------------\n";
    cout << "ID TURNO: " << reg.getIdTurno() << endl;
    cout << "ID MASCOTA: " << reg.getIdMascota() << endl;
    cout << "ID VETERINARIO: " << reg.getMactriculaVet() << endl;

    Fecha fe = reg.getFechaTurno();
    cout << "FECHA DEL TURNO: ";
    cout << fe.getDia() << "/" << fe.getMes() << "/" << fe.getAnio() << endl;

    cout << "ESTADO: " << (reg.getEstadoTurno() ? "ACTIVO" : "INACTIVO") << endl;
}


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

bool TurnoArchivo::leerTurno(int pos, Turno &reg){
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return false;

    fseek(p, pos * sizeof(Turno), SEEK_SET);
    bool ok = fread(&reg, sizeof(Turno), 1, p);
    fclose(p);

    return ok;

}
