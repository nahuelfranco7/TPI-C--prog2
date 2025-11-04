#pragma once
# include <cstring>
# include "Fecha.h"

class Turno{
private:
    int _idTurno;
    int _idMascota;
    int _idVet;
    Fecha _fechaTurno;
    bool _estadoTurno;
public:
    //getters
    int getIdTurno();
    int getIdMascota();
    int getIdVet();
    Fecha getFechaTurno();
    bool getEstadoTurno();
    //setters
    void setIdTurno(int id);
    void setIdMascota(int id);
    void setIdVet(int id);
    void setFechaTurno(Fecha fecha);
    void setEstadoTurno(bool estado);

};
