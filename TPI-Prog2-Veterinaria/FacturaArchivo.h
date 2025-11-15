#pragma once
#include <cstring>
#include "Factura.h"

class FacturaArchivo {

private:
    const char _nombreArchivo[30] = "Facturas.dat";

public:
    const char* getNombreArchivo();

    int buscarPorId(int id);
    int contarRegistros();
    int generarNuevoID();

    bool cargarFactura();
    bool cargarFactura(const Factura &reg);

    bool leerFactura(int pos,Factura &reg);
    void mostrarFactura(int pos,const Factura &reg);

    void listarTodos();

    bool modificar(int pos);
    bool modificarFactura(int pos,const Factura &reg);

    bool eliminar(int pos);
};
