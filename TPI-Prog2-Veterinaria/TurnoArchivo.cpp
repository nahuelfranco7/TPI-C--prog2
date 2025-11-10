#include <iostream>
#include <cstdlib>
#include <cstring>
#include "TurnoArchivo.h"
using namespace std;

/*

    int buscarPorId(int id);
    int contarRegistros();
    int generarNuevoId();

    void cargarCadena(char *palabra, int tam);
    bool cargarTurno();
    void listarTodos();
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
    if (p==nullptr) return 1; //Acá no iria return false?
    while (fread(&reg,sizeof(Turno),1,p)){
        if (reg.getIdTurno()==id){ //Acá id no esta declarado o soy yo? jaja
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

int TurnoArchivo::generarNuevoID() {
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
bool TurnoArchivo::cargarTurno(const Mascota &reg) {
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

    reg.setIdTurno(generarNuevoID);

    cout<<"

    /*  int _idTurno;
    int _idMascota;
    int _idVet;
    Fecha _fechaTurno;
    bool _estadoTurno;*/
}
