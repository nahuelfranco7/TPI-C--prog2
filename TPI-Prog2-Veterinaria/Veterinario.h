#pragma once
#include <cstring>
#include "Persona.h"
#include "Fecha.h"
class Veterinario:Persona{
private:
    int _matriculaVet;
    Fecha _fechaIngresoVet;
public:
    int getMatriculaVet();
    Fecha getFechaIngreso();
    void setMatriculaVet(int matricula);
    void setFechaIngresoVet(Fecha fechaIngreso);
};
