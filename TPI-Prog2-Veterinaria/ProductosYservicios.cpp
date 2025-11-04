# include<iostream>
# include<cstdlib>
# include<cstring>
# include "ProductosYservicios.h"

using namespace std;
/*private:
    int _idProducto;
    char _descripcion[50]={0};
    float _costoProductoServicio;
    bool _estadoProducto;

public:
    //getters
    int getIdProducto();
    const char* getDescripcion();
    float getCostoProdServ();
    bool getEstadoProducto();
    //setters
    void setIdProducto(int id);
    void setDescripcion(const char* descripcion);
    void setCostoProdServ(float costo);
    void setEstado(bool estado);*/
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
