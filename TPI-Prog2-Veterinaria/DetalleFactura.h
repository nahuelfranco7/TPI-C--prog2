#pragma once
#include <cstring>
class DetalleFactura{
private:
    int _idDetalle;
    int _idProducto;
    int _idFactura;
    int _cantidad;
    float _precioUnitario;
    bool _estado;
public:
    //getters
    int getIdDetalle();
    int getIdProducto();
    int getIdFactura();
    int getCantidad();
    float getPrecioUnitario();
    bool getEstado();
    //setters
    void setIdDetalle(int id);
    void setIdProducto(int id);
    void setIdFactura(int id);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precio);
    void setEstado(bool estado);


};
