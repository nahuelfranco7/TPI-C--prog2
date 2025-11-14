#pragma once
#include <cstring>
#include "Turno.h"

/*
+ cargarTurno(const Turno &reg): bool
+ modificarTurno(int, const Turno &reg): bool
+ leerTurno(int, const Turno &reg): bool
+ mostrarTurno(int, const Turno &reg): void
+ buscarPorId(int): bool
+ getNombreArchivo(): const *char
+ setNombreArchivo(const *char): void
+ contarRegistros(): int
+ listarTodos(): void
+ eliminar(int): bool
+ modificat(int): bool

*/

class TurnoArchivo{

private:
    const char _nombreArchivo[30] = "Turno.dat";
    public:
    const char* getNombreArchivo();

    int buscarPorId(int id);
    int contarRegistros();
    int generarNuevoId();

    void cargarCadena(char *palabra, int tam);
    bool cargarTurno();
    void listarTodos();
    bool eliminar(int pos);
    void mostrarTurno(int pos, Turno &reg);

    bool modificar(int pos);
    bool cargarTurno(const Turno &reg);
    bool modificarTurno(int pos, const Turno &reg);
    bool leerTurno(int pos, const Turno &reg);



};
