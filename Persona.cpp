# include<iostream>
# include<cstdlib>
# include<cstring>
#include "Persona.h"


using namespace std;
//getters
int Persona::getID() const {return _id;}
const char* Persona::getNombre() const {return _nombre;}
const char* Persona::getApellido() const {return _apellido;}
int Persona::getDNI()const {return _DNI;}
Direccion Persona::getDireccion()const{return _direccion;}
const char* Persona::getTelefono()const{return _telefono;}
    const char* Persona::getEmail()const{return _email;}
    bool Persona::getEstado()const {return _estado;}
//setters
void Persona::setId(int id) {
    _id = id;
}
void Persona::setNombre(const char* nombre){
strncpy(_nombre,nombre,29);
}
void Persona::setApellido(const char* apellido){
strncpy(_apellido,apellido,29);
}
void Persona::setDNI(int dni){
_DNI = dni;
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
