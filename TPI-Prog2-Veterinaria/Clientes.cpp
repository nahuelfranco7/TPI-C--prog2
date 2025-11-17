#include <iostream>
#include <cstring>
#include "Clientes.h"
using namespace std;

// =======================
// FUNCIÓN LOCAL
// =======================
void Clientes::cargarCadena(char *palabra, int tam) {
    int i = 0;
    fflush(stdin);
    for (i = 0; i < tam; i++) {
        palabra[i] = cin.get();
        if (palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

// =======================
// GETTERS / SETTERS
// =======================
int Clientes::getIdCliente() {
    return _idCliente;
}

void Clientes::setIdCliente(int id) {
    _idCliente = id;

    // sincroniza el ID también con Persona::_id
    _id = id;
}

// =======================
//       CARGAR
// =======================
void Clientes::cargar() {
    cout << "Nombre: ";
    cargarCadena(_nombre, 30);

    cout << "Apellido: ";
    cargarCadena(_apellido, 30);

    cout << "DNI: ";
    cargarCadena(_DNI, 15);

    cout << "\n--- DIRECCION ---\n";
    _direccion.cargarDireccion();

    cout << "Telefono: ";
    cargarCadena(_telefono, 20);

    cout << "Email: ";
    cargarCadena(_email, 40);

    _estado = true;
}

// =======================
//       MOSTRAR
// =======================
void Clientes::mostrar() {
    cout << "ID Cliente: " << _idCliente << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "DNI: " << _DNI << endl;

    cout << "--- DIRECCION ---\n";
    _direccion.mostrarDireccion();

    cout << "Telefono: " << _telefono << endl;
    cout << "Email: " << _email << endl;
    cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << endl;
    cout << "---------------------------------\n";
}
