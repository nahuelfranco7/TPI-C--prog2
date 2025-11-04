#pragma once
#include <cstring>
#pragma once
#include <cstring> // para strncpy

class Direccion {
private:
    char _pais[40];
    char _provincia[30];
    char _ciudad[50];
    char _calle[50];
    int _altura;
    int _codPostal;

public:

    Direccion();

    //getters
    const char* getPais();
    const char* getProvincia();
    const char* getCiudad();
    const char* getCalle();
    int getAltura();
    int getCodPostal();

    //setters
    void setPais(const char* pais);
    void setProvincia(const char* provincia);
    void setCiudad(const char* ciudad);
    void setCalle(const char* calle);
    void setAltura(int altura);
    void setCodPostal(int codPostal);

};
