#pragma once
#include "ClientesArchivo.h"
#include "MascotaArchivo.h"
#include "Clientes.h"
#include "Mascota.h"

class ManagerCliente {
public:
    void altaCliente();
    void modificarCliente();
    void bajaCliente();
    void reactivarCliente();
    void listarClientes();
    void buscarClientePorDNI();
};
