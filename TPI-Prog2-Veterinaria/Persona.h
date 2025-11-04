#pragma once
#include <string>
#include "Direccion.h"
class Persona{

protected://esto será asignado por la clase hija
    int _id;
    char _nombre[30];
    char _apellido[30];
    int _DNI;
    Direccion _direccion;
    int _telefono;
    char _email[40];
    bool _estado;
public:
   // Getters
    int getID();
    const char* getNombre();
    const char* getApellido();
    int getDNI();
    Direccion getDireccion();
    int getTelefono();
    const char* getEmail();
    bool getEstado();

    // Setters
    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setDNI(int dni);
    void setDireccion(Direccion direccion);
    void setTelefono(int telefono);
    void setEmail(const char* email);
    void setEstado(bool estado);

};
