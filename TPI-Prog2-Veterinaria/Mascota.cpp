# include<iostream>
# include<cstdlib>
# include<cstring>
# include "Mascota.h"

using namespace std;

/*
//getters
    int getIdMascota();
    const char* getNombreMascota();
    Fecha getFechaNac();
    int getIdRaza();
    const char* getSexoAnimal();
    int getIdClienteDueño();
    bool getEstadoMascota();
    //setters
    void setIdMascota(int id);
    void setNombreMascota(const char* nombre);
    void setFechaNac(Fecha fecha);
    void setIdRaza(int id);
    void setSexoAnimal(const char* sexo);
    void setIdCliente(int id);
    void setEstadoMascota(int id);
*/

int Mascota::getIdMascota(){return _idMascota;}
const char* Mascota::getNombreMascota(){return _nombreMascota;}
Fecha Mascota::getFechaNac(){return _fechaNac;}
int Mascota::getIdRaza(){return _idRaza;}
char Mascota::getSexoAnimal(){return _sexoAnimal;}
int Mascota::getIdClienteDueno(){return _idClienteDueno;}
bool Mascota::getEstadoMascota(){return _estadoMascota;}

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
