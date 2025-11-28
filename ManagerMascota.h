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
    int calcularEdad(int dia, int mes, int anio);
    // LISTADOS
    void menuListadoMascotas();
    void listarMascotasporID(int idMascota);
    void listarMascotasporIDraza(int idRaza);
    void listarMascotasporFechaNac(Fecha fechaMascota);
    void listarMascotasporSexo(char sexo);
    void listarMascotasporEstado(bool estado);
};
