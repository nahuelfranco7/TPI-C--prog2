#pragma once
#include "Usuario.h"

class Menu{
public:
    void mostrar();
    void cargarUsuariosIniciales();
    void cargarCadena(char *palabra, int tam);
    int cargarEntero(const char *mensaje, int tamMax);
};
