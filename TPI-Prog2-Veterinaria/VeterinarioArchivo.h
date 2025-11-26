#pragma once
#include <cstring>
#include "Veterinario.h"

class VeterinarioArchivo {
private:
    char _nombreArchivo[30]="Veterinarios.dat";

public:
    const char* getNombreArchivo() const { return _nombreArchivo; }
    void setNombreArchivo(const char* nombre) { strcpy(_nombreArchivo, nombre); }

    int contarRegistros();
    int buscarPorId(int id);
    int generarNuevoID();

    void cargarCadena(char *palabra, int tam);

    bool cargarVet();
    bool cargarVet(const Veterinario &reg);
    int buscarporDNI(int DNI);
    int buscarMatriculaVet(int matVet);


    bool leerVet(int pos, Veterinario &reg);
    void mostrarVeterinario(int pos, const Veterinario &reg);
    int buscarPorMatricula(int matricula);

    void listarTodos();

    bool modificar(int pos);
    bool modificarVet(int pos, const Veterinario &reg);

    bool eliminar(int pos);
};
