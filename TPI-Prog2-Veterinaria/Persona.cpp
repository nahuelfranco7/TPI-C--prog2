# include<iostream>
# include<cstdlib>
# include<cstring>
#include "Persona.h"


using namespace std;
//getters
int Persona::getID(){return _id;}
const char* Persona::getNombre(){return _nombre;}
const char* Persona::getApellido(){return _apellido;}
const char* Persona::getDNI(){return _DNI;}
Direccion Persona::getDireccion(){return _direccion;}
const char* Persona::getTelefono(){return _telefono;}
    const char* Persona::getEmail(){return _email;}
    bool Persona::getEstado(){return _estado;}
//setters
void Persona::setNombre(const char* nombre){
strncpy(_nombre,nombre,29);
}
void Persona::setApellido(const char* apellido){
strncpy(_apellido,apellido,29);
}
void Persona::setDNI(const char* dni){
strncpy(_DNI,dni,14);
}
void Persona::setDireccion(Direccion direccion){
_direccion=direccion;
}
void Persona::setTelefono(const char* telefono){
strncpy(_telefono,telefono,19);
}
void Persona::setEmail(const char* email){
strncpy(_email,email,39);
}
void Persona::setEstado(bool estado){
_estado=estado;
}
