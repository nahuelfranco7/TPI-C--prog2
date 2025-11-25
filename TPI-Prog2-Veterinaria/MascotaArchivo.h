#pragma once
# include <cstring>
# include "Mascota.h"
/*
+ cargarMascota(const Mascota &reg): bool
+ modificarMascota(int, const Mascota &reg): bool
+ leerMascota(int, const Mascota &reg): bool
+ mostrarMascota(int, const Mascota &reg): void
+ buscarPorId(int): bool
+ getNombreArchivo(): const *char
+ setNombreArchivo(const *char): void
+ contarRegistros(): int
+ listarTodos(): void
+ eliminar(int): bool
+ modificat(int): bool

*/
class MascotaArchivo{
    private:
    const char _nombreArchivo[30] = "Mascotas.dat";
    public:
    const char* getNombreArchivo();

    int buscarPorId(int id);
    int contarRegistros();
    int generarNuevoID();

    void cargarCadena(char *palabra, int tam);
    bool cargarMascota();
    void listarTodos();
    bool eliminar(int pos);
    void mostrarMascota(int pos, const Mascota &reg);
    void listarMascotaporDueno(int dniDueno);

    bool modificar(int pos);
    bool cargarMascota(const Mascota &reg);
    bool modificarMascota(int pos, const Mascota &reg);
    bool leerMascota(int pos, Mascota &reg);//abre el archivo con rb y carga un reg en &reg

};
