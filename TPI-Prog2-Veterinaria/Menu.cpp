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


void Menu::cargarUsuariosIniciales() {
    UsuarioArchivo arch;
    Usuario u;

    cout << "=== CARGA RAPIDA DE USUARIOS ===\n";

    int nuevoId = arch.contarRegistros() + 1;
    u.setIdUsuario(nuevoId);

    char aux[50];

    cout << "Nombre: ";
    cin.ignore();
    cin.getline(aux, 50);
    u.setNombre(aux);

    cout << "Apellido: ";
    cin.getline(aux, 50);
    u.setApellido(aux);

    cout << "DNI: ";
    cin.getline(aux, 15);
    u.setDNI(aux);

    cout << "Email: ";
    cin.getline(aux, 50);
    u.setEmail(aux);

    cout << "Clave (max 5): ";
    cin.getline(aux, 6);
    u.setClave(aux);

    cout << "Nivel de seguridad (1=Recep - 2=Vet - 3=Admin - 4=Maestro): ";
    int nivel;
    cin >> nivel;
    u.setNivelSeguridad(nivel);

    u.setEstado(true);

    if (arch.cargarUsuario(u))
        cout << "Usuario registrado correctamente!\n";
    else
        cout << "ERROR al guardar usuario.\n";

    system("pause");
}
