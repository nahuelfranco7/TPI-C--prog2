#pragma once
# include <cstring>
# include "Usuario.h"

class UsuarioArchivo{
private:
    const char _nombreArchivo[30] = "Usuarios.dat";
public:
    const char* getNombreArchivo() const { return _nombreArchivo; }
    //getters
    const char* getNombreArchivo();

    //métodos
    bool cargarUsuario(const Usuario &reg);
    bool modificarUsuario(int pos,const Usuario &reg);
    bool leerUsuario(int pos, Usuario &reg);//va sin const xq cuando copia del archivo al obj, va a modificar el obj para luego leerlo
    Usuario leerRegistro(int pos);
    void mostrarUsuario(int pos);
    int buscarPorId(int id);
    int contarRegistros();
    void listarTodos();
    bool eliminar(int id);
    bool modificar(int id);
    void cargarCadena(char *palabra, int tam);
    bool validarContrasenaPorPos(int pos, const char* contrasena);

};
