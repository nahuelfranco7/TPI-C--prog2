# include<iostream>
# include<cstdlib>
# include<cstring>
# include "Factura.h"

using namespace std;

int Factura::getIdFactura() const { return _idFactura; }
int Factura::getIdCliente() const { return _idCliente; }
int Factura::getIdUsuario() const { return _idUsuario; }
Fecha Factura::getFechaFactura() const { return _fechaFactura; }
float Factura::getImporteTotalFactura() const { return _importeTotalFactura; }
bool Factura::getEstadoFactura() const { return _estadoFactura; }
//setters
void Factura::setIdFactura(int id){
_idFactura=id;
}
void Factura::setIdCliente(int id){
_idCliente=id;
}
void Factura::setIdUsuario(int id){
_idUsuario=id;
}
void Factura::setFechaFactura(Fecha fecha){
_fechaFactura = fecha;
}

void Factura::setImporteTotalFactura(float importe){
_importeTotalFactura=importe;
}
void Factura::setEstadoFactura(bool estado){
_estadoFactura=estado;
}

void cargarCadena(char *palabra, int tam) {
    int i = 0;
    fflush(stdin);
    for (i = 0; i < tam; i++){
        palabra[i] = cin.get();
        if (palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

void Factura::cargar() {
    cout << "ID Cliente: ";
    cin >> _idCliente;

    cout << "ID Usuario (vendedor): ";
    cin >> _idUsuario;

    cout << "Fecha de la factura:\n";
    _fechaFactura.cargar();

    cout << "Importe total: ";
    cin >> _importeTotalFactura;

    _estadoFactura = true;
}

void Factura::mostrar() {
    cout << "ID Factura: " << _idFactura << endl;
    cout << "ID Cliente: " << _idCliente << endl;
    cout << "ID Usuario: " << _idUsuario << endl;
    cout << "Fecha: ";
    _fechaFactura.mostrar();
    cout << "Importe total: " << _importeTotalFactura << endl;
    cout << "Estado: " << (_estadoFactura ? "Activo" : "Anulada") << endl;
    cout << "---------------------------\n";
}

