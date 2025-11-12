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
        if (reg.getIdCliente()==id){
            fclose(p);
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

/*----------------------------------------------------*/
bool ClientesArchivo::cargarClientes(const Clientes &reg){
    FILE *p = fopen(_nombreArchivo, "ab");
    if (p == nullptr){
        cout << "ERROR AL ABRIR EL ARCHIVO DE CLIENTES." << endl;
        return false;
    }

    bool escribio = fwrite(&reg, sizeof(Clientes), 1, p);
    fclose(p);

    return escribio;
}
/*--------------------------------------------------------------------*/
bool ClientesArchivo::cargarClientes(){
    Clientes reg;
    char nombre[20];
    char apellido[20];
    char DNI[20];
    Direccion direccion;
    char telefono[15];
    char email[40];

    reg.setIdCliente(generarNuevoID());
    cout<< "ID ASIGNADO AUTOMATICAMENTE: "<<reg.getIdCliente()<<endl;

    cout<<"INGRESE NOMBRE DE CLIENTE: "<<endl;
    cargarCadena(nombre,20);
    reg.setNombre(nombre);

    cout<<"INGRESE APELLIDO DEL CLIENTE: "<<endl;
    cargarCadena(apellido,20);
    reg.setApellido(apellido);

    cout<<"INGRESE DNI: "<<endl;
    cargarCadena(DNI,19);
    reg.setDNI(DNI); //Creo que podemos poner directamente reg.setdni y ya se carga.

    cout<<"INGRESE DIRECCION DEL CLIENTE: "<<endl;
    /*cin>> ///Aca creo que podríamos poner un cargarDireccion para que pida directamente todos los datos de direccion.*/

    cout<<"INGRESE EL TELEFONO: "<<endl;
    cargarCadena(telefono,14);
    reg.setTelefono(telefono);

    cout<<"EMAIL: "<<endl;
    cargarCadena(email,sizeof(email));
    reg.setEmail(email);

    reg.setEstado(true); // activo por defecto
    if (cargarClientes(reg)){
        cout << "CLIENTE GUARDADO EXITOSAMENTE." << endl;
        return true;
    } else {
        cout << "ERROR AL GUARDAR EL CLIENTE." << endl;
        return false;
    }
}
