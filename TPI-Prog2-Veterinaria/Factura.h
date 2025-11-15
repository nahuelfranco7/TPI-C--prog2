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
    int getIdFactura() const;
    int getIdCliente() const;
    int getIdUsuario() const;
    Fecha getFechaFactura() const;
    float getImporteTotalFactura() const;
    bool getEstadoFactura() const;
    //setters
    void setIdFactura(int id);
    void setIdCliente(int id);
    void setIdUsuario(int id);
    void setFechaFactura(Fecha fecha);
    void setImporteTotalFactura(float importe);
    void setEstadoFactura(bool estado);
};
