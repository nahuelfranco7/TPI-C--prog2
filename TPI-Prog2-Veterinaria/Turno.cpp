# include<iostream>
# include<cstdlib>
# include<cstring>
# include "Turno.h"

using namespace std;

int Turno::getIdTurno(){return _idTurno;}
int Turno::getIdMascota(){return _idMascota;}
int Turno::getIdVet(){return _idVet;}
Fecha Turno::getFechaTurno(){return _fechaTurno;}
bool Turno::getEstadoTurno(){return _estadoTurno;}

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
