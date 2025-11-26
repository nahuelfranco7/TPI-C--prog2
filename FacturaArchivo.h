#pragma once
#include <cstring>
#include "Factura.h"
#include "Fecha.h"

class FacturaArchivo {
private:
    char _nombreArchivo[30] = "Facturas.dat";

public:

    //getters
    const char* getNombreArchivo();

    //funciones de archivo
    bool cargarFactura(const Factura &reg);
    bool cargarFactura();

    bool leerFactura(int pos, Factura &reg);

    void mostrarFactura(int pos, const Factura &reg);

    int buscarPorId(int id);

    int contarRegistros();
    int generarNuevoID();

    void listarTodos();

    bool eliminar(int pos);
    bool modificar(int pos);

    bool modificarFactura(int pos, const Factura &reg);

    //filtros
    void mostrarPorFecha(Fecha fecha);
    void mostrarPorSemana(Fecha inicioSemana);
    void mostrarPorMes(Fecha fecha);

    //metodos
    void cargarCadena(char *palabra, int tam);
    bool fechaEsMayorIgual(Fecha a, Fecha b);
    bool fechaEsMenorIgual(Fecha a, Fecha b);
    Fecha sumarDias(Fecha f, int dias);
};
