#pragma once
#include "Usuario.h"

class MenuMaestro {
public:
    void mostrar(const Usuario &user);

private:
    // SUBMENÚS PRINCIPALES
    void menuUsuarios();
    void menuClientes();
    void menuMascotas();
    void menuVeterinarios();
    void menuTurnos();
    void menuFacturas();
    void menuProductosyServicios();
    void menuListados();
    void menuInformes();
    void menuReactivaciones();

    // --- Gestión de Usuarios ---
    void altaUsuario();
    void modificarUsuario();
    void bajaUsuario();
    void listarUsuarios();
    void reactivarUsuario();

    // --- Clientes ---
    void altaCliente();
    void modificarCliente();
    void bajaCliente();
    void listarClientes();
    void reactivarCliente();

    // --- Mascotas ---
    void altaMascota();
    void modificarMascota();
    void bajaMascota();
    void listarMascotas();
    void reactivarMascota();

    // --- Veterinarios ---
    void altaVeterinario();
    void modificarVeterinario();
    void bajaVeterinario();
    void listarVeterinarios();
    void reactivarVeterinario();

    // --- Turnos ---
    void altaTurno();
    void modificarTurno();
    void bajaTurno();
    void listarTurnos();
    void reactivarTurno();

    // --- Facturas ---
    void altaFactura();
    void listarFacturas();

    // --- Listados ---
    void menuListadoClientes();
    void menuListadoMascotas();
    void menuListadoVeterinarios();
    void menuListadoFacturas();
    void menuListadoTurnos();

    // --- Informes ---
    void recaudacionPorDia();
    void recaudacionPorVet();
    void recaudacionPorMes();
    void cantidadTurnosMes();

};
