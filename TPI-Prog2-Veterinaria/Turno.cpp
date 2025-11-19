# include<iostream>
# include<cstdlib>
# include<cstring>
# include "Turno.h"

using namespace std;

int Turno::getIdTurno()const{return _idTurno;}
int Turno::getIdMascota()const{return _idMascota;}
int Turno::getIdVet()const{return _idVet;}
Fecha Turno::getFechaTurno()const{return _fechaTurno;}
bool Turno::getEstadoTurno()const{return _estadoTurno;}

//setters
void Turno::setIdTurno(int id){
_idTurno=id;
}
void Turno::setIdMascota(int id){
_idMascota=id;
}
void Turno::setIdVet(int id){
_idVet=id;
}
void Turno::setFechaTurno(Fecha fecha){
_fechaTurno=fecha;
}
void Turno::setEstadoTurno(bool estado){
_estadoTurno=estado;
}


void Turno::cargar() {

    cout << "Ingrese ID de Mascota: ";
    cin >> _idMascota;

    cout << "Ingrese ID del Veterinario: ";
    cin >> _idVet;

    cout << "Ingrese fecha del turno: \n";
    _fechaTurno.cargar();

    _estadoTurno = true;
}



void Turno::mostrar(){

    cout << "ID Turno: " << _idTurno << endl;
    cout << "ID Mascota: " << _idMascota << endl;
    cout << "ID Veterinario: " << _idVet << endl;

    cout << "Fecha: ";
    _fechaTurno.mostrar();

    cout << "Estado: " << (_estadoTurno ? "ACTIVO" : "INACTIVO") << endl;
}
