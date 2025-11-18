#include <iostream>
#include "Menu.h"
using namespace std;

int main(){
    Menu menu;

    int opcion;
    cout << "1) Cargar usuarios iniciales\n";
    cout << "2) Ingresar al sistema\n";
    cin >> opcion;

    system("cls");

    if(opcion == 1){
        menu.cargarUsuariosIniciales();
        return 0;  // termina luego de cargar
    }

    if(opcion == 2){
        menu.mostrar();   // login normal
    }

    return 0;
}

