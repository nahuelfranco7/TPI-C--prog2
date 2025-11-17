#include <iostream>
#include <cstdlib>
using namespace std;

#include "Menu.h"
#include "MenuRecepcionista.h"
#include "MenuVeterinario.h"
#include "MenuAdministrativo.h"
#include "MenuMaestro.h"

void Menu::mostrar() {
    UsuarioArchivo archivo;
    Usuario usuario;   //usuario se carga cuando el login es correcto
    bool usuarioOk = false;

    do {
        cout << "Ingrese ID: ";
        int id;
        cin >> id;

        cout << "Ingrese contrasena: ";
        char contrasena[20];
        cin >> contrasena;

        int pos = archivo.buscarPorId(id);

        if (pos >= 0 && archivo.validarContrasenaPorPos(pos, contrasena)) {

            //Acá carga el usuario completo desde archivo al objeto local
            usuario = archivo.leerRegistro(pos);

            usuarioOk = true;
        }
        else {
            cout << "ID o contrasena incorrectos. Intente nuevamente.\n";
        }

    } while (!usuarioOk);

    // A partir de acá ya está el usuario COMPLETO

    cout<<"=====================================\n";
    cout<<"       SISTEMA DE VETERINARIA        \n";
    cout<<"=====================================\n";
    cout<<"Bienvenido/a " << usuario.getNombre() << " " << usuario.getApellido() << "\n";
    cout<<"Nivel de acceso: " << usuario.getNivelSeguridad() << "\n";
    cout<<"-------------------------------------\n";
    cout<<"Ingresando a su menu correspondiente...\n\n";

    system("pause");
    system("cls");

    int nivel = usuario.getNivelSeguridad();

    switch (nivel) {
        case 1: {
        MenuRecepcionista menu;
        menu.mostrar(usuario);
        } break;

        case 2: {
            MenuVeterinario menu;
            menu.mostrar(usuario);
        } break;

        case 3: {
            MenuAdministrativo menu;
            menu.mostrar();
        } break;

        case 4: {
            MenuMaestro menu;
            menu.mostrar(usuario);
        } break;

        default:
            cout << "ERROR: Nivel de usuario no valido.\n";
            system("pause");
            break;
    }
}
