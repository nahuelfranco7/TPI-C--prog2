# include<iostream>
# include<cstdlib>
# include<cstring>
# include "DetalleFacturaArchivo.h"

using namespace std;

/*
    const char* getNombreArchivo();

    bool cargarDetalle(const DetalleFactura &reg);
    bool modificarDetalleArchivo(int pos,const DetalleFactura &reg);
    bool leerDetalle(int pos, const DetalleFactura &reg);
    bool buscarPorId(int id);
    bool eliminar(int pos);
    bool modificar(int pos);

    void mostrarDetalle(int, const DetalleFactura &reg);
    void listarTodos();
    int contarRegistros();


*/

const char* DetallleFacturaArchivo::getNombreArchivo(){
return _nombreArchivo;
}

