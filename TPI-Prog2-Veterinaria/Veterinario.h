#pragma once
#include <cstring>
#include "Persona.h"
#include "Fecha.h"
class Veterinario: public Persona{
private:
    int _matriculaVet;
    Fecha _fechaIngresoVet;
public:
    int getMatriculaVet() const;
    Fecha getFechaIngreso() const;
    void setMatriculaVet(int matricula);
    void setFechaIngresoVet(Fecha fechaIngreso);
};
