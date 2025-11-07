#pragma once
# include <cstring>
# include "Fecha.h"

class Mascota{

private:
    int _idMascota;
    char _nombreMascota[20];
    Fecha _fechaNac;
    int _idRaza;
    char _sexoAnimal;
    int _idClienteDueno;
    bool _estadoMascota;
public:
    //getters(todos llevan const al final para que puedan ser llamados luego desde los métodos que utilizan registros constantes)
    int getIdMascota() const;
    const char* getNombreMascota() const;
    Fecha getFechaNac() const;
    int getIdRaza() const;
    char getSexoAnimal()const ;
    int getIdClienteDueno()const;
    bool getEstadoMascota()const;
    //setters
    void setIdMascota(int id);
    void setNombreMascota(const char* nombre);
    void setFechaNac(Fecha fecha);
    void setIdRaza(int id);
    void setSexoAnimal(char sexo);
    void setIdClienteDueno(int id);
    void setEstadoMascota(bool estado);
};

