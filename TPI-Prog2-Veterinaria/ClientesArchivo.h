#pragma once
#include "Clientes.h"
#include "Direccion.h"
#include <cstring>

/*
+ cargarNuevoCliente(const Clientes &reg): bool
+ modificarCliente(int, const Clientes &reg ): bool
+ leerCliente(int, Clientes &reg): bool
+ mostrarCliente(int, Clientes &reg): void
+ buscarPorId(int): bool
+ getNombreArchivo(): const *char
+ setNombreArchivo(const *char): void
+ contarRegistros(): int
+ listarTodos(): void
+ eliminar(int): bool
+ modificat(int): bool

*/

class ClientesArchivo{
    private:
    const char _nombreArchivo[30] = "Clientes.dat";
    public:
    const char* getNombreArchivo();

    int buscarporId(int id);//ok
    int contarRegistros();//ok
    int generarNuevoID();//ok

    void cargarCadena(char *palabra, int tam);//ok nuevo método
    bool cargarClientes();//ok
    void listarTodos();//ok
    bool eliminar(int pos);//ok
    void mostrarClientes(int pos, const Clientes &reg);//ok

    bool modificar(int pos);//ok
    bool cargarClientes(const Clientes &reg);
    bool modificarClientes(int pos, const Clientes &reg);//ok
    bool leerClientes(int pos, Clientes &reg);//ok

};
