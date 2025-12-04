#pragma once
#include "ProductosYservicios.h"


class ProductosYServiciosArchivo{
private:
    const char _nombreArchivo[30] = "ProductosYServicios.dat";
public:
    const char* getNombrearchivo();

    int buscarPorID(int id);
    int contarRegistros();
    int generarNuevoID();
    void cargarCadena(char *palabra, int tam);

    bool cargarProducto();
    bool cargarProducto(const ProductosYservicios &reg);
    bool modificarProducto(int pos, const ProductosYservicios &reg);
    bool modificarProducto(int pos);
    bool leerProducto (int pos, ProductosYservicios &reg);

    float precioProducto(int id);
    int modificarPrecio(int valor);

    void listarProductos();

    void menuProductosyServicios();
};
