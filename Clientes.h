#pragma once
#include <cstring>
#include "Persona.h"

class Clientes : public Persona {
private:
    int _idCliente;



public:
    int getIdCliente();
    void setIdCliente(int id);

    void cargar(int dni);
    void mostrar();

    void cargarCadena(char* palabra, int tam);
};
