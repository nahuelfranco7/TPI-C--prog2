#pragma once

#include "Usuario.h"
#include "UsuarioArchivo.h"
#include "ClientesArchivo.h"
#include "MascotaArchivo.h"
#include "TurnoArchivo.h"
#include "Veterinario.h"

class ManagerVeterinario {
public:
    // ABML compatibles con MenuMaestro (nombres cortos)
    void cargar();        // alta veterinario
    void modificar();
    void eliminar();      // baja lógica
    void listar();
    void reactivar();

    // Funciones de consulta (solo lectura) — usadas por MenuVeterinario
    void verClientePorDNI();
    void listarMascotasDeCliente();
    void listarTurnoPorID();
    void listarTurnosPorFecha();
    void listarTurnosPorEstado();

    // Utilidad
    int buscarPorID(int id); // devuelve posición en Usuarios.dat si es veterinario, -1 si no

    // Listados
    void menuListadoVeterinarios();
    void listarVetporID(int idVet);
    void listarVetporMat(int MatVet);
    void listarVetporDNI(int dniVet);
    void listarVetporEstado(bool estadoVet);
    void listarVetporFechaIng(Fecha fechaIngresoVet);

};
