#pragma once
# include<cstring>
class Raza{

private:
    int _idRaza;
    char _descripcionRaza[20];
    char _descripcionAnimal[20];
    bool _estadoRaza;
public:
    Raza();
    int getIdRaza();
    const char* getDescripcionRaza();
    const char* getDescirpcionAnimal();
    bool getEstadoRaza();
private:
    void setIdRaza(int id);
    void setDescripcionRaza(const char* descripcion);
    void setDescripcionAnimal(const char* descripcion);
    void setEstadoRaza(bool estado);

};
