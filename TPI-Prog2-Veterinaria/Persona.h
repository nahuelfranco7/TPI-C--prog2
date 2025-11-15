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
    int getID()const;
    const char* getNombre() const;
    const char* getApellido() const;
    const char* getDNI() const;
    Direccion getDireccion() const;
    const char* getTelefono() const;
    const char* getEmail() const;
    bool getEstado() const;

    // Setters
    void setId(int id);
    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setDNI(const char* dni);
    void setDireccion(Direccion direccion);
    void setTelefono(const char* telefono);
    void setEmail(const char* email);
    void setEstado(bool estado);

};
