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

void Fecha::cargar() {
    int d, m, a;

    cout << "Día: ";
    cin >> d;
    cout << "Mes: ";
    cin >> m;
    cout << "Año: ";
    cin >> a;

   //validaciones corregir luego
    if (d < 1 || d > 31) d = 1;
    if (m < 1 || m > 12) m = 1;
    if (a < 1999) a = 1999;

    setDia(d);
    setMes(m);
    setAnio(a);
}

void Fecha::mostrar() const {
    cout << _dia << "/" << _mes << "/" << _anio;
}

