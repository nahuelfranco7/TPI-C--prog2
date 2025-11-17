#pragma once
#include "UsuarioArchivo.h"
#include "Usuario.h"

class ManagerUsuario {
public:
    void altaUsuario();
    void modificarUsuario();
    void bajaUsuario();
    void reactivarUsuario();
    void listarUsuarios();
    void buscarUsuarioPorId();
};
