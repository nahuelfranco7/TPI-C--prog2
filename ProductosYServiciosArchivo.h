#pragma once
#include "ProductosYservicios.h"


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
