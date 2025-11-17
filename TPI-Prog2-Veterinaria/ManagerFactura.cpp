# include<iostream>
# include<cstdlib>
# include<cstring>
#include "ManagerFactura.h"
using namespace std;

void ManagerFactura::altaFactura() {
    FacturaArchivo arch;
    Factura reg;

    reg.setIdFactura( arch.contarRegistros() + 1 );
    reg.cargar();

    if (arch.cargarFactura(reg))
        cout << "Factura guardada.\n";
    else
        cout << "ERROR al guardar.\n";

    system("pause");
}

void ManagerFactura::listarFacturas() {
    FacturaArchivo arch;
    arch.listarTodos();
    system("pause");
}
