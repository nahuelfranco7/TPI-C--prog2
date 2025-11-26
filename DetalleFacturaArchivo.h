#pragma once
# include <cstring>
# include "Mascota.h"
# include "DetalleFactura.h"

class DetalleFacturaArchivo{
private:
    const char _nombreArchivo[30]="DetalleFacturaArchivo.dat";
public:


    const char* getNombreArchivo();


    int buscarPorIdDetalle(int id);
    bool buscarPorIdFactura(int idFactura);
    int contarRegistros();
    int generarNuevoID();

    bool cargarDetalle();
    bool cargarDetalle(const DetalleFactura &reg);
    bool modificarDetalleArchivo(int pos,const DetalleFactura &reg);
    bool leerDetalle(int pos, DetalleFactura &reg);
    bool eliminar(int pos);
    bool modificar(int pos);

    void mostrarPorIdDetalle(int idDetalle);
    void mostrarPorIdFactura(int idFactura);
    void listarTodos();

};
