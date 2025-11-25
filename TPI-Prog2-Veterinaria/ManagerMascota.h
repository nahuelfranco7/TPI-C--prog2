#pragma once
#include "MascotaArchivo.h"
#include "ClientesArchivo.h"
#include "Mascota.h"
#include "Clientes.h"

class ManagerMascota {
public:
    void altaMascota();
    void modificarMascota();
    void bajaMascota();
    void reactivarMascota();
    void listarMascotas();
    void listarMascotasporDni(int dniDueno);
};
