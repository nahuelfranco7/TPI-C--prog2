#pragma once
# include <cstring>
# include "Usuario.h"

class UsuarioArchivo{
private:
    char _nombreArchivo[30];
    void cargarCadena(char *palabra, int tam);
public:
    //constructor
    UsuarioArchivo(const char *nombreArchivo = "Usuarios.dat") {
        strncpy(_nombreArchivo, nombreArchivo, 29);
        _nombreArchivo[29] = '\0';
    }
    //getters
    const char* getNombreArchivo();
    //setters
    void setNombreArchivo(const char* nomberArchivo);
    //métodos
    bool cargarUsuario(const Usuario &reg);
    bool modificarUsuario(int pos,const Usuario &reg);
    bool leerUsuario(int pos, Usuario &reg);//va sin const xq cuando copia del archivo al obj, va a modificar el obj para luego leerlo
    void mostrarUsuario(int pos);
    int buscarPorId(int id);
    int contarRegistros();
    void listarTodos();
    bool eliminar(int id);
    bool modificar(int id);

};
