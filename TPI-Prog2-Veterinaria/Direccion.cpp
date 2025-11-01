# include<iostream>
# include<cstdlib>
# include<cstring>
#include "Direccion.h"
using namespace std;

Direccion::Direccion() {
    _pais[0] = '\0';
    _provincia[0] = '\0';
    _ciudad[0] = '\0';
    _calle[0] = '\0';
    _altura = 0;
    _codPostal = 0;
}

// Getters
const char* Direccion::getPais() { return _pais; }
const char* Direccion::getProvincia() { return _provincia; }
const char* Direccion::getCiudad() { return _ciudad; }
const char* Direccion::getCalle() { return _calle; }
int Direccion::getAltura() { return _altura; }
int Direccion::getCodPostal() { return _codPostal; }

// Setters con strncpy para limitar caracteres
void Direccion::setPais(const char* pais) {
    strncpy(_pais, pais, 39);
}

void Direccion::setProvincia(const char* provincia) {
    strncpy(_provincia, provincia, 29);
}

void Direccion::setCiudad(const char* ciudad) {
    strncpy(_ciudad, ciudad, 49);
}

void Direccion::setCalle(const char* calle) {
    strncpy(_calle, calle, 49);
}

void Direccion::setAltura(int altura) {
    _altura = altura;
}

void Direccion::setCodPostal(int codPostal) {
    _codPostal = codPostal;
}
