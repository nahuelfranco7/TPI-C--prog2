#pragma once
#include "Usuario.h"
#include "UsuarioArchivo.h"

class MenuRecepcionista{
public:

    //recibe el usuario que inicio sesion para pasar nivel al manager
    void mostrar(const Usuario &usuario);
};
