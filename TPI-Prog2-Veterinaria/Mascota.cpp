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
int Mascota::getDniClienteDueno() const {return _dniClienteDueno;}
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
void Mascota::setDniClienteDueno(int dni){
_dniClienteDueno=dni;
}

void Mascota::setEstadoMascota(bool estado){
_estadoMascota=estado;
}

// --- cargarCadena ---
void Mascota::cargarCadena(char *palabra, int tam) {
    int i = 0;
    fflush(stdin);
    for (i = 0; i < tam; i++) {
        palabra[i] = cin.get();
        if (palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

void Mascota::cargar() {
    cout << "Nombre mascota: ";
    cargarCadena(_nombreMascota, 20);

    cout << "Fecha nacimiento: \n";
    _fechaNac.cargar();

    cout << "ID raza: ";
    cin >> _idRaza;

    cout << "Sexo (M/H): ";
    cin >> _sexoAnimal;

//reemplazo vincular id cliente con vincular con DNI
/*
    cout << "ID cliente dueño: ";
    cin >> _idClienteDueno;*/

    cout << "DNI Cliente dueño: ";
    cin >> _dniClienteDueno; // VALIDAR QUE EXISTE

    _estadoMascota = true;
}

void Mascota::mostrar() {
    cout << "ID Mascota: " << _idMascota << endl;
    cout << "Nombre: " << _nombreMascota << endl;
    cout << "Fecha de nacimiento: ";
    _fechaNac.mostrar();
    cout << "ID raza: " << _idRaza << endl;
    cout << "Sexo: " << _sexoAnimal << endl;
    cout << "DNI cliente dueño: " << _dniClienteDueno << endl;
    cout << "Estado: " << (_estadoMascota ? "Activo" : "Inactivo") << endl;
}
