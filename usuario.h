#pragma once
# include <cstring>
#include "Persona.h"

class Usuario : public Persona{
private:
    int _idUsuario = 0;
    char _clave[6] = {0};// 5 caracteres + '\0'
    int _nivelSeguridad = 0;
    bool _estado;

public:
    Usuario();
    Usuario(int id, const char* clave , int nivel, bool estado);

    //Getters
    int getIdUsuario() const;
    const char* getClave() const;
    int getNivelSeguridad() const;
    bool getEstado() const;
    //Setters
    void setIdUsuario(int id);
    void setClave(const char* clave);
    void setNivelSeguridad(int nivel);
    void setEstado(bool estado);

};
