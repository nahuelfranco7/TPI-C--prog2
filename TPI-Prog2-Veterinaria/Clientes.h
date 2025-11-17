#pragma once
#include <cstring>
#include "Persona.h"

class Clientes : public Persona {
private:
    int _idCliente;

    //Función local para cargar cadenas
    void cargarCadena(char* palabra, int tam);

public:
    int getIdCliente();
    void setIdCliente(int id);

    void cargar();
    void mostrar();
};
