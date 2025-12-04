# include<iostream>
# include<cstdlib>
# include<cstring>
# include "DetalleFactura.h"

using namespace std;


//getters

int DetalleFactura::getIdDetalle(){return _idDetalle;}
int DetalleFactura::getIdProducto(){return _idProducto;}
int DetalleFactura::getIdFactura(){return _idFactura;}
int DetalleFactura::getCantidad(){return _cantidad;}
float DetalleFactura::getPrecioUnitario(){return _precioUnitario;}
bool DetalleFactura::getEstado(){return _estado;}

//setters

void DetalleFactura::setIdDetalle(int id){
_idDetalle=id;
}
void DetalleFactura::setIdProducto(int id){
_idProducto=id;
}
void DetalleFactura::setIdFactura(int id){
_idFactura=id;
}
void DetalleFactura::setCantidad(int cantidad){
_cantidad=cantidad;
}
void DetalleFactura::setPrecioUnitario(float precio){
_precioUnitario=precio;
}
void DetalleFactura::setEstado(bool estado){
_estado=estado;
}
