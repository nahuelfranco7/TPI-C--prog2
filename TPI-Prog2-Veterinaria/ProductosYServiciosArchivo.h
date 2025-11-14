#pragma once
#include "ProductosYservicios.h"

/*
+ getNombreArchivo(): const *char
+ setNombreArchivo(const *char): void

+ buscarPorId(int): bool
+ contarRegistros(): int

+ cargarProducto(const Producto &reg): bool
+ modificarProducto(int, const Producto &reg): bool
+ leerProducto(int, const Producto &reg): bool
+ precio(int): int
+ modificarPrecio(int): int
+ mostrarProdYSer(int, const Producto &reg): void

+ listarTodos(): void
+ eliminar(int): bool
+ modificar(int): bool

*/

class ProductosYServiciosArchivo{
private:
    const char _nombreArchivo[30] = "ProductosYServicios.dat";
public:
    const char* getNombrearchivo();

    int buscarporID(int id);
    int contarRegistros();
    int generarNuevoID();
    void cargarCadena(char *palabra, int tam);

    bool cargarProducto();
    bool cargarProducto(const ProductosYservicios &reg);
    bool modificarProducto(int pos, const ProductosYservicios &reg);
    bool modificarProducto(int pos);
    bool leerProducto (int pos, ProductosYservicios &reg);
    int precio (int valor);
    int modificarPrecio(int valor);
};
