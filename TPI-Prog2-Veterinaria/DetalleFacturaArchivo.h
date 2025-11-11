#pragma once
# include <cstring>
# include "DetalleFactura.h"

class DetallleFacturaArchivo{
private:
    const char _nombreArchivo[30]="DetalleFacturaArchivo.dat";
public:
    /*
+ cargarDetalle(const Detalle &reg): bool
+ modificarDetalleArchivo(int, const DetalleFactura &reg)
+ leerDetalle(int, const Detalle &reg): bool
+ mostrarDetalle(int, const Detalle &reg): void
+ buscarPorId(int): bool
+ getNombreArchivo(): const *char
+ setNombreArchivo(const *char): void
+ contarRegistros(): int
+ listarTodos(): void
+ eliminar(int): bool
+ modificat(int): bool
    */
    const char* getNombreArchivo();

    int buscarPorId(int id);
    int contarRegistros();
    int generarNuevoID();

    bool cargarDetalle();
    bool cargarDetalle(const DetalleFactura &reg);
    bool modificarDetalleArchivo(int pos,const DetalleFactura &reg);
    bool leerDetalle(int pos, const DetalleFactura &reg);
    bool eliminar(int pos);
    bool modificar(int pos);

    void mostrarDetalle(int, const DetalleFactura &reg);
    void listarTodos();

};
