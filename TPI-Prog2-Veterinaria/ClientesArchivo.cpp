#include <iostream>
#include <cstring>
#include "ClientesArchivo.h"

using namespace std;

/*
    int buscarporId(int id);
    int contarRegistros();
    int generarNuevoID();

    void cargarCadena(char *palabra, int tam);
    bool cargarClientes(); HASTA ACA LLEGUE XD
    void listarTodos();
    void eliminar(int pos);
    void mostrarClientes(int pos, const Clientes &reg);

    bool modificar(int pos);
    bool cargarClientes(const Clientes &reg);
    bool modificarClientes(int pos, const Clientes &reg);
    bool leerClientes(int pos, Clientes &reg);//abre el archivo con rb y carga un reg en &reg

*/

const char* ClientesArchivo::getNombreArchivo(){
return _nombreArchivo;
}

int ClientesArchivo::buscarporId(int id){
    Clientes reg;
    int pos = 0;
    FILE *p = fopen (_nombreArchivo,"rb");
    if (p==nullptr) return false;
    while (fread(&reg, sizeof(Clientes),1,p)){
        if (reg.getIdCliente==id){
            fclose(p)
        }
        return pos;
    pos++;
    }
return -1;
}

int ClientesArchivo::contarRegistros(){
    FILE *p = fopen(_nombreArchivo,"rb");
    if (p==nullptr) return false;
    fseek(p,0,SEEK_END);
    int tamanio=ftell(p);
    fclose(p);
    int cantidadRegistros = tamanio/sizeof(Clientes);
    return cantidadRegistros;
}

int ClientesArchivo::generarNuevoID(){
    return contarRegistros()+1;
}

//cargar cadena------------------------------------------
void ClientesArchivo::cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0; i < tam; i++){
        palabra[i] = cin.get();
        if (palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}
/*----------------------------------------------------*/

bool ClientesArchivo::cargarClientes(){
/*
- ID: int
- nombre: char [20]
- apellido: char [20]
- DNI: char [15]
- _direccion: Direccion
- telefono: char [20]
- email: char[40]
- estado: bool
- idCliente??
*/
    Clientes reg;
    char nombre[20];
    char apellido[30];
    char DNI[15];
    Direccion direccion;
    char telefono[20];
    char email[40];


    cout<<"INGRESE NOMBRE DE CLIENTE: "<<endl;
    cargarCadena(nombre,sizeof(nombre));
    cin>>reg.setNombre(nombre);

    cout<<"INGRESE APELLIDO DEL CLIENTE: "<<endl;
    cargarCadena(apellido,sizeof(apellido));
    cin>>reg.setApellido(apellido);

    cout<<"INGRESE DNI: "<<endl;
    cargarCadena(DNI,sizeof(DNI));
    cin>>reg.setDNI(DNI); //Creo que podemos poner directamente reg.setdni y ya se carga.

    cout<<"INGRESE DIRECCION DEL CLIENTE: "<<endl;
    cin>> ///Aca creo que podríamos poner un cargarDireccion para que pida directamente todos los datos de direccion.

    cout<<"INGRESE EL TELEFONO: "<<endl;
    cargarCadena(telefono,sizeof(telefono));
    cin>>reg.setTelefono(telefono);

    cout<<"EMAIL: "<<endl;
    cargarCadena(email,sizeof(email));
    cin>>reg.setEmail(email);
}
