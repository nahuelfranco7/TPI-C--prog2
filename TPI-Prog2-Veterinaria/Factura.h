#pragma once
# include <cstring>
# include "Fecha.h"

class Factura{

private:
    int _idFactura;
    int _idCliente;
    int _idUsuario;
    Fecha _fechaFactura;
    float _importeTotalFactura;
    bool _estadoFactura;
public:
    //getters
    int getIdFactura();
    int getIdCliente();
    int getIdUsuario();
    Fecha getFechaFactura();
    float getImporteTotalFactura();
    bool getEstadoFactura();
    //setters
    void setIdFactura(int id);
    void setIdCliente(int id);
    void setIdUsuario(int id);
    void setFechaFactura(Fecha fecha);
    void setImporteTotalFactura(float importe);
    void setEstadoFactura(bool estado);
};
