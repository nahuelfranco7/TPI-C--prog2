#pragma once
#include <cstring>
#include "Persona.h"
#include "Fecha.h"
class Veterinario: public Persona{
private:
    int _matriculaVet;
    Fecha _fechaIngresoVet;
    int _idUsuarioAsociado;//para relacionarlo con la lista de usuarios
public:
    int getMatriculaVet() const;
    Fecha getFechaIngreso() const;
    void setMatriculaVet(int matricula);
    void setFechaIngresoVet(Fecha fechaIngreso);

    int getIdUsuarioAsociado() const;
    void setIdUsuarioAsociado(int id);
};
