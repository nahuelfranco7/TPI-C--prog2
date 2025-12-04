#include "Factura.h"
#include "FacturaArchivo.h"
#include "ProductosYServiciosArchivo.h"
#include "DetalleFacturaArchivo.h"

class ManagerFactura {
public:
    void altaFactura();
    void listarFacturas();
    void menuListadoFacturas();
    void cargarFacturaMGR();

        //INFORMES
    void recaudacionPorVet();
    void recaudacionPorDia();
    void recaudacionPorMes();

    // void modificarFactura();
    // void anularFactura();
    // void listarPorID();
    // void listarPorCliente();
    // void listarPorFecha();
};



