#pragma once
# include <cstring>
# include <iostream>

class ManagerRecepcionista{

public:
    ManagerRecepcionista() { _nivelUsuario = 1; } // por defecto recepcionista si se usa sin pasar nivel
    void setNivelUsuario(int nivel) { _nivelUsuario = nivel; }
    int getNivelUsuario() const { return _nivelUsuario; }

    // Submenus
    void menuTurnos();
    void menuListados();
    void menuConsultas();
    void menuBusquedas();
    void menuFacturacion();

private:
    int _nivelUsuario;

    // Acciones que realizan los menus
    void cargarTurno();
    void modificarTurno();

    void listarClientes();
    void listarMascotas();
    void listarVeterinarios();
    void listarFacturas();
    void listarTurnos();

    void consultaPorID();
    void consultaPorDNI();
    void consultaPorFecha();
    void consultaPorEstado();

    bool buscarClientePorDNI();
    void buscarMascotaPorNombre();

    void facturacionVerDetalle();

    // Informes
    void informeCantidadTurnosMes();
    void informeRecaudacionMes();
    void informeRecaudacionPorVeterinario();
    void informeRecaudacionPorDia();
};
