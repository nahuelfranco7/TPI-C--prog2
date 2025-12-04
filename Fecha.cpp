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
    if (d < 1 || d > 31) d = -1;
    if (m < 1 || m > 12) m = -1;
    if (a < 1999 || a >= 2026) a = -1;

    setDia(d);
    setMes(m);
    setAnio(a);
}

void Fecha::cargarPreCarga(int dia,int mes,int anio) {
    int d, m, a;

    d = dia;
    m = mes;
    a = anio;

   //validaciones corregir luego
    if (d < 1 || d > 31) d = -1;
    if (m < 1 || m > 12) m = -1;
    if (a < 1999 || a >= 2026) a = -1;

    setDia(d);
    setMes(m);
    setAnio(a);
}

void Fecha::mostrar() const {
    cout << _dia << "/" << _mes << "/" << _anio;
}


bool Fecha::esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

bool Fecha::fechaValida(int dia, int mes, int anio) {

    if (anio < 1900 || anio > 2026) return false;
    if (mes < 1 || mes > 12) return false;
    if (dia < 1 || dia > 31) return false;

    int diasEnMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (mes == 2 && esBisiesto(anio)) {
        if (dia >= 1 && dia <= 29) return true;
        else {return false;}
    }

    return dia <= diasEnMes[mes - 1];
}
