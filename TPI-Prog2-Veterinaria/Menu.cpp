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
        cin>>id;

        cout << "Ingrese contrasena: ";
        char contrasena[20];
        cin >> contrasena;

        int pos = archivo.buscarPorId(id);//devuelve una posicion

        if (pos >= 0 && archivo.validarContrasenaPorPos(pos, contrasena)) {

            //Acá carga el usuario completo desde archivo al objeto local
            usuario = archivo.leerRegistro(pos);

            usuarioOk = true;
        }
        else {
            cout << "ID o contrasena incorrectos. Intente nuevamente.\n";
        }

    } while (!usuarioOk);

    //A partir de acá ya está el usuario COMPLETO

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
    cargarCadena(aux,20);
    u.setNombre(aux);

    cout << "Apellido: ";
    cargarCadena(aux,20);
    u.setApellido(aux);

    cout << "DNI: ";
    cargarCadena(aux,15);
    u.setDNI(aux);

    cout << "Email: ";
    cargarCadena(aux,40);
    u.setEmail(aux);

    cout << "Clave (max 5): ";
    cargarCadena(aux,5);
    u.setClave(aux);

    cout << "Nivel de seguridad (1=Recep - 2=Vet - 3=Admin - 4=Maestro): ";
    int nivel;

    do {
    cout << "Nivel de seguridad (1=Recep - 2=Vet - 3=Admin - 4=Maestro): ";

    cin>>nivel;


    if(nivel < 1 || nivel > 4){
        cout << "Valor invalido. Debe ser 1, 2, 3 o 4." << endl;
    }

} while(nivel < 1 || nivel > 4);

    u.setNivelSeguridad(nivel);

    u.setEstado(true);

    if (arch.cargarUsuario(u))
        cout << "Usuario registrado correctamente!\n";
    else
        cout << "ERROR al guardar usuario.\n";

    system("pause");
}

void Menu::cargarCadena(char *palabra, int tam){
    int i;
    bool valido=false;

    while(!valido){
        fflush(stdin);
        i=0;

        cout<<"Ingrese (máximo "<<tam-1<<" caracteres): ";

        for(i=0;i<tam-1;i++){
            palabra[i]=cin.get();
            if(palabra[i]=='\n')break;
        }
        palabra[i]='\0';
        fflush(stdin);

        //Si el usuario paso el límite sin presionar enter
        if(i==tam-1 && palabra[i-1]!='\n'){
            cout<<"Error: no puede superar los "<<tam-1<<" caracteres.\n";

            //Limpiamos el resto de la cadena y descartamos lo que sobra en el buffer(almacenamiento)
            char basura;
            while((basura=cin.get())!='\n');

            // Borrar la cadena ingresada para que no quede basura
            palabra[0]='\0';
        }
        else {
            valido=true;
        }
    }
}

int Menu::cargarEntero(const char *mensaje, int ) {
    char buffer[100];
    bool valido = false;

    while(!valido) {
        cout << mensaje << ": ";

        cin.getline(buffer, 100);

        // Cadena vacía
        if (buffer[0] == '\0') {
            cout << "Error: debe ingresar un numero.\n";
            continue;
        }

        valido = true;

        // Validar cada caracter
        for(int j = 0; buffer[j] != '\0'; j++) {
            if(buffer[j] < '0' || buffer[j] > '9') {
                valido = false;
                break;
            }
        }

        if(!valido) {
            cout << "Error: debe ingresar solo numeros enteros.\n";
        }
    }

    return atoi(buffer);
}
