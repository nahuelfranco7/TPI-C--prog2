#pragma once
# include <cstring>
# include "Mascota.h"
# include "DetalleFactura.h"

class DetalleFacturaArchivo{
private:
    const char _nombreArchivo[30]="DetalleFacturaArchivo.dat";
public:


    const char* getNombreArchivo();

    int buscarPorId(int id);//devuelve una posición
    int contarRegistros();
    int generarNuevoID();

    bool cargarDetalle();
    bool cargarDetalle(const DetalleFacturaArchivo &reg);
    bool modificarDetalleArchivo(int pos,const DetalleFacturaArchivo &reg);
    bool leerDetalle(int pos, const DetalleFacturaArchivo &reg);
    bool eliminar(int pos);
    bool modificar(int pos);

    void mostrarDetalle(int, const DetalleFacturaArchivo &reg);
    void listarTodos();

};
