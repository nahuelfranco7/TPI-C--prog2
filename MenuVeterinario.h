#pragma once
# include <cstring>
# include <iostream>
#include "Usuario.h"
#include "ManagerVeterinario.h"

class MenuVeterinario {
public:
    void mostrar(const Usuario& usuario);

private:
    void mostrarOpciones();
};




