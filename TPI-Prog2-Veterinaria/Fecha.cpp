# include<iostream>
# include<cstdlib>
# include<cstring>
# include "Fecha.h"

using namespace std;

int Fecha::getDia(){return _dia;}
int Fecha::getMes(){return _mes;}
int Fecha::getAnio(){return _anio;}
void Fecha::setDia(int dia){
_dia=dia;
}
void Fecha::setMes(int mes){
_mes=mes;
}
void Fecha::setAnio(int anio){
_anio=anio;
}

