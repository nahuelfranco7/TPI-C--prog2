#pragma once
#include <cstring>
#include "Turno.h"

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
    void mostrarTurno(int pos,const Turno &reg);
    void mostrarTurno(const Turno &reg);

    bool modificar(int pos);
    bool cargarTurno(const Turno &reg);
    bool modificarTurno(int pos, const Turno &reg);
    bool leerTurno(int pos, Turno &reg);

    //funciones nuevas para listados
    void listarTurnosPorID(int id);
    void listarTurnosPorIDMascota(int idMascota);
    void listarTurnosPorMatVeterinario(int idVet);
    void listarTurnosPorFecha(Fecha fecha);
    void listarTurnosPorEstado(bool estado);
    void listarTurnosPorIDCliente(int idCliente);
    int contarMascotasCliente(int dniCliente);
    void listarTurnosPorDNICliente(int dniCliente);





};
