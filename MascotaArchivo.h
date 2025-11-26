#pragma once
# include <cstring>
# include "Mascota.h"

class MascotaArchivo{
    private:
    const char _nombreArchivo[30] = "Mascotas.dat";
    public:
    const char* getNombreArchivo();

    int buscarPorId(int id);
    int contarRegistros();
    int generarNuevoID();

    void cargarCadena(char *palabra, int tam);
    bool cargarMascota(int dni);
    void listarTodos();
    bool eliminar(int pos);
    void mostrarMascota(int pos, const Mascota &reg);
    void listarMascotaporDueno(int dniDueno);

    bool modificar(int pos);
    bool guardarMascota(const Mascota &reg);
    bool modificarMascota(int pos, const Mascota &reg);
    bool leerMascota(int pos, Mascota &reg);//abre el archivo con rb y carga un reg en &reg
    int calcularEdad(int dia, int mes, int anio);
};
