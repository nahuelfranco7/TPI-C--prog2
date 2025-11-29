#pragma once
#include "TurnoArchivo.h"
#include "Turno.h"
#include "MascotaArchivo.h"
#include "VeterinarioArchivo.h"

class ManagerTurno {
public:
    void altaTurno();
    void modificarTurno();
    void bajaTurno();
    void listarTurnos();
    void menuListadoTurnos();
    void listarTurnosPorDNICliente(int dni);
};
