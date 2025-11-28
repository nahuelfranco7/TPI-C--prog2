# include<iostream>
# include<cstdlib>
#include "ManagerCliente.h"
using namespace std;

void ManagerCliente::altaCliente() {
    ClientesArchivo arch;
    Clientes reg;

    cout << "=== ALTA DE CLIENTE ===\n";


    cout << "INGRESE DNI: " << endl;
    int dni;
    cin >> dni;

    bool valido = true;
    valido = buscarClientePorDNI(dni);

   if(valido){
    reg.cargar(dni);
    reg.setEstado(true);
    reg.setIdCliente( arch.contarRegistros() + 1 );

   } else cout<< "EL CLIENTE YA EXISTE.. " <<endl;


    if (arch.cargarClientes(reg)) {
        cout << "Cliente guardado correctamente.\n";
    } else {
        cout << "ERROR al guardar cliente.\n";
    }
    system("pause");
}

void ManagerCliente::modificarCliente() {
    ClientesArchivo arch;
    int dni;
    cout << "DNI de Cliente a modificar: ";
    cin >> dni;

    int pos = arch.buscarporDNI(dni);
    if (pos < 0) {
        cout << "Cliente no encontrado.\n";
        system ("pause");
        return;
    }

    Clientes reg;
    arch.leerClientes(pos, reg);

    cout << "Cliente actual:\n";
    arch.mostrarClientes(pos, reg);

    cout << "Ingrese nuevos datos:\n";
    reg.cargar(dni);

    if (arch.modificarClientes(pos, reg))
        cout << "Modificado correctamente.\n";
    else
        cout << "ERROR al modificar.\n";

    system("pause");
}

void ManagerCliente::bajaCliente() {
    ClientesArchivo arch;
   /* int id;
    cout << "ID de cliente a dar de baja: ";
    cin >> id;*/

    int dni;
    cout << "DNI de cliente a dar de baja: " <<endl;
    cin >> dni;

    int pos = arch.buscarporDNI(dni);
    cout << "Posicion cliente: " <<pos <<endl;
    if (pos < 0) {
        cout << "Cliente no encontrado.\n";
        system ("pause");
        return;
    }

    if (arch.eliminar(pos))
        cout << "Cliente dado de baja (estado = false).\n";
    else
        cout << "ERROR al dar de baja.\n";

    system("pause");
}

void ManagerCliente::reactivarCliente() {
    ClientesArchivo arch;
    int DNI;
    cout << "DNI del cliente a reactivar: ";
    cin >> DNI;

    int pos = arch.buscarporDNI(DNI);
    if (pos < 0) {
        cout << "Cliente no encontrado.\n";
        system ("pause");
        return;
    }

    Clientes reg;
    arch.leerClientes(pos, reg);
    reg.setEstado(true);

    if (arch.modificarClientes(pos, reg))
        cout << "Cliente reactivado.\n";
    else
        cout << "ERROR al reactivar.\n";

    system("pause");
}
/*-----------LISTADOS DE CLIENTES-------------------------------------------------------------------*/

void ManagerCliente::menuListadoClientes(){
    ClientesArchivo arch;
    int opc;
    do {
        system("cls");
        cout << "----LISTADOS DE CLIENTES----" <<endl;
        cout << "1. Listar clientes por ID" << endl;
        cout << "2. Listar clientes por DNI" << endl;
        cout << "3. Listar clientes por Apellido" <<endl;
        cout << "4. Listar clientes por Estado" <<endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: " << endl;
        cin >> opc;

        switch (opc){
            case 1:
                int idcliente;
                cout << "Ingrese ID de Cliente: " << endl;
                cin >> idcliente;
                arch.listarClientesporID(idcliente);
                break;
            case 2:
                int dnicliente;
                cout << "Ingrese DNI de cliente: " << endl;
                cin >> dnicliente;
                arch.listarClientesporDNI(dnicliente);
                break;
            case 3:
                char apellido [30];
                cout << "Ingrese apellido del cliente: " <<endl;
                cargarCadena(apellido,29);
                arch.listarClientesporApellido(apellido);
                break;
            case 4:
                bool estado;
                int aux;
                cout << "Ingrese estado" << endl;
                cout << "1. Estado Inactivo " << endl;
                cout << "2. Estado Activo " << endl;
                cin >> aux;
                if (aux == 1 || aux == 2){
                estado = aux - 1;
                arch.listarClientesporEstado(estado);
                }else{
                cout << "Estado incorrecto. Intente nuevamente" << endl;
                }
                break;
        }
    }
    while (opc != 0);
    system ("pause");
}

void ManagerCliente::listarClientes() {
    ClientesArchivo arch;
    arch.listarTodos();
    system("pause");
}

bool ManagerCliente::buscarClientePorDNI(int dni) {
    ClientesArchivo arch;
    Clientes c;
    bool encontro = false;
    int total = arch.contarRegistros();

    for (int i=0; i<total; i++) {
        if (!arch.leerClientes(i, c)) continue;
        if (c.getDNI()==dni) {
            arch.mostrarClientes(i, c);
            encontro = false;
            return encontro;
        }
    } return true;

    system("pause");
}

void ManagerCliente::cargarCadena(char *palabra, int tam){
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

            // Borramos la cadena ingresada para que no quede basura
            palabra[0]='\0';
        }
        else {
            valido=true;
        }
    }
}

int cargarEntero(const char *mensaje, int tamMax) {
    char buffer[100];
    bool valido = false;

    while(!valido) {
        cout << mensaje << " (max " << tamMax-1 << " caracteres): ";

        //LECTURA
        int i = 0;
        for(i = 0; i < tamMax - 1; i++) {
            buffer[i] = cin.get();
            if (buffer[i] == '\n') break;
        }
        buffer[i] = '\0';

        // Si el usuario supera el límite sin presionar ENTER
        if(i == tamMax - 1 && buffer[i-1] != '\n') {
            cout << "Error: excedio el maximo permitido.\n";

            // limpiar el resto del buffer
            char basura;
            while((basura = cin.get()) != '\n');

            continue;   // volver a pedir
        }

        // ----- VALIDACIÓN (ASCII) -----

        // Cadena vacía
        if(buffer[0] == '\0') {
            cout << "Error: debe ingresar un numero.\n";
            continue;
        }

        valido = true;

        // Validamps caracter por caracter
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

    // Convertimos a entero de nuevo
    return atoi(buffer);
}

