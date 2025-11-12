#pragma once
#include <string>
#include "Direccion.h"
class Persona{

protected://esto será asignado por la clase hija
    int _id;
    char _nombre[30];
    char _apellido[30];
    char _DNI[15];
    Direccion _direccion;
    char _telefono[20];
    char _email[40];
    bool _estado;
public:
   // Getters
    int getID();
    const char* getNombre();
    const char* getApellido();
    const char* getDNI();
    Direccion getDireccion();
    const char* getTelefono();
    const char* getEmail();
    bool getEstado();

    // Setters
    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setDNI(const char* dni);
    void setDireccion(Direccion direccion);
    void setTelefono(const char* telefono);
    void setEmail(const char* email);
    void setEstado(bool estado);

};
