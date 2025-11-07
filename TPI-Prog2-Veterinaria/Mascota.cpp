# include<iostream>
# include<cstdlib>
# include<cstring>
# include "Mascota.h"

using namespace std;


//getters


int Mascota::getIdMascota()const{return _idMascota;}
const char* Mascota::getNombreMascota()const{return _nombreMascota;}
Fecha Mascota::getFechaNac()const{return _fechaNac;}
int Mascota::getIdRaza()const{return _idRaza;}
char Mascota::getSexoAnimal()const{return _sexoAnimal;}
int Mascota::getIdClienteDueno()const{return _idClienteDueno;}
bool Mascota::getEstadoMascota()const{return _estadoMascota;}

void Mascota::setIdMascota(int id){
_idMascota=id;
}
void Mascota::setNombreMascota(const char* nombre){
strncpy(_nombreMascota,nombre,19);
}
void Mascota::setFechaNac(Fecha fecha){
_fechaNac=fecha;
}
void Mascota::setIdRaza(int id){
_idRaza=id;
}
void Mascota::setSexoAnimal(char sexo){
_sexoAnimal=sexo;
}
void Mascota::setIdClienteDueno(int id){
_idClienteDueno=id;
}

void Mascota::setEstadoMascota(bool estado){
_estadoMascota=estado;
}
