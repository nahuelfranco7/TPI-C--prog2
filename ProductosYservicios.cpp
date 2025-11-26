# include<iostream>
# include<cstdlib>
# include<cstring>
# include "ProductosYservicios.h"

using namespace std;

int ProductosYservicios::getIdProducto(){return _idProducto;}
const char* ProductosYservicios::getDescripcion(){return _descripcion;}
float ProductosYservicios::getCostoProdServ(){return _costoProductoServicio;}
bool ProductosYservicios::getEstadoProducto(){return _estadoProducto;}

void ProductosYservicios::setIdProducto(int id){
_idProducto=id;
}
void ProductosYservicios::setDescripcion(const char* descripcion){
strncpy(_descripcion,descripcion,49);
}
void ProductosYservicios::setCostoProdServ(float costo){
_costoProductoServicio=costo;
}
void ProductosYservicios::setEstado(bool estado){
_estadoProducto=estado;
}
