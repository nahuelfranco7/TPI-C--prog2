#pragma once
# include <cstring>

class ProductosYservicios{
private:
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
    void setEstado(bool estado);
};
