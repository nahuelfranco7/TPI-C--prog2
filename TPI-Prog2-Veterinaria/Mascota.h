#pragma once
# include <cstring>
# include "Fecha.h"

class Mascota{
/*
+ idMascota: int
+ nombreMascota: char[20]
+ fechaNac: Fecha
+ idRaza: int
+ sexoAnimal: char
+ idClienteDueño: int
+ estadoMascota: bool
*/
private:
    int _idMascota;
    char _nombreMascota[20];
    Fecha _fechaNac;
    int _idRaza;
    char _sexoAnimal;
    int _idClienteDueno;
    bool _estadoMascota;
public:
    //getters
    int getIdMascota();
    const char* getNombreMascota();
    Fecha getFechaNac();
    int getIdRaza();
    char getSexoAnimal();
    int getIdClienteDueno();
    bool getEstadoMascota();
    //setters
    void setIdMascota(int id);
    void setNombreMascota(const char* nombre);
    void setFechaNac(Fecha fecha);
    void setIdRaza(int id);
    void setSexoAnimal(char sexo);
    void setIdClienteDueno(int id);
    void setEstadoMascota(bool estado);
};
