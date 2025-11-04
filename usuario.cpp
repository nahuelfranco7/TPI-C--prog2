#include <iostream>
#include "Usuario.h"

using namespace std;

Usuario::Usuario(){
_idUsuario=0;
_clave[0]='\0';
_nivelSeguridad=0;
_estado=true;
}

Usuario::Usuario(int id, const char* clave, int nivel,bool estado){
    _idUsuario= id;
    strncpy(_clave,clave,5);
    _nivelSeguridad=nivel;
    _estado=estado;

}
//getters
int Usuario::getIdUsuario(){
return _idUsuario;
}

const char* Usuario::getClave(){
return _clave;
}

int Usuario::getNivelSeguridad(){
return _nivelSeguridad;
}

bool Usuario::getEstado(){
return _nivelSeguridad;
}
//setters
void Usuario::setIdUsuario(int id){
_idUsuario=id;
}

void Usuario::setClave(const char* clave){
strncpy(_clave,clave,5);
}

void Usuario::setNivelSeguridad(int nivel){
    _nivelSeguridad=nivel;
}

void Usuario::setEstado(bool estado){
_estado=estado;
}
