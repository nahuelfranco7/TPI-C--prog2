# include<iostream>
# include<cstdlib>
# include<cstring>
#include "Veterinario.h"

using namespace std;
/*
    int getMatriculaVet();
    Fecha getFechaIngreso();
    void setMatriculaVet(int matricula);
    void setFechaIngresoVet(Fecha fechaIngreso);
*/
int Veterinario::getMatriculaVet(){
return _matriculaVet;
}
Fecha Veterinario::getFechaIngreso(){
return _fechaIngresoVet;
}

void Veterinario::setMatriculaVet(int matricula){
_matriculaVet=matricula;
}
void Veterinario::setFechaIngresoVet(Fecha fechaIngreso){
_fechaIngresoVet=fechaIngreso;
}
