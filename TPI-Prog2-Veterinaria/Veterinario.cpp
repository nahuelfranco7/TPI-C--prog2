# include<iostream>
# include<cstdlib>
# include<cstring>
#include "Veterinario.h"

using namespace std;

int Veterinario::getMatriculaVet() const{
return _matriculaVet;
}
Fecha Veterinario::getFechaIngreso()const{
return _fechaIngresoVet;
}

void Veterinario::setMatriculaVet(int matricula){
_matriculaVet=matricula;
}
void Veterinario::setFechaIngresoVet(Fecha fechaIngreso){
_fechaIngresoVet=fechaIngreso;
}
