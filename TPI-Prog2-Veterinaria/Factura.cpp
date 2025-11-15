# include<iostream>
# include<cstdlib>
# include<cstring>
# include "Factura.h"

using namespace std;

int Factura::getIdFactura() const { return _idFactura; }
int Factura::getIdCliente() const { return _idCliente; }
int Factura::getIdUsuario() const { return _idUsuario; }
Fecha Factura::getFechaFactura() const { return _fechaFactura; }
float Factura::getImporteTotalFactura() const { return _importeTotalFactura; }
bool Factura::getEstadoFactura() const { return _estadoFactura; }
//setters
void Factura::setIdFactura(int id){
_idFactura=id;
}
void Factura::setIdCliente(int id){
_idCliente=id;
}
void Factura::setIdUsuario(int id){
_idUsuario=id;
}
void Factura::setFechaFactura(Fecha fecha){
_fechaFactura = fecha;
}

void Factura::setImporteTotalFactura(float importe){
_importeTotalFactura=importe;
}
void Factura::setEstadoFactura(bool estado){
_estadoFactura=estado;
}

