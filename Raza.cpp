# include<iostream>
# include<cstdlib>
# include<cstring>
# include "Raza.h"

using namespace std;

Raza::Raza(){
_idRaza = 0;
_descripcionRaza[0]='\0';
_descripcionAnimal[0]='\0';
_estadoRaza=true;
}
//gettersS
int Raza::getIdRaza(){
return _idRaza;
}

const char* Raza::getDescripcionRaza(){
return _descripcionRaza;
}

const char* Raza::getDescirpcionAnimal(){
return _descripcionAnimal;
}

bool Raza::getEstadoRaza(){
return _estadoRaza;
}

void Raza::setIdRaza(int id){
_idRaza=id;
}

void Raza::setDescripcionRaza(const char* descripcion){
strncpy(_descripcionRaza, descripcion,19);
}

void Raza::setDescripcionAnimal(const char* descripcion){
strncpy(_descripcionAnimal,descripcion,19);
}

void Raza::setEstadoRaza(bool estado){
_estadoRaza=estado;
}

