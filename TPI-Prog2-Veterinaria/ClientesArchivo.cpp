#include <iostream>
#include <cstring>
#include "ClientesArchivo.h"

using namespace std;

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
    reg.setDNI(DNI);

    cout<<"INGRESE DIRECCION DEL CLIENTE: "<<endl;
    Direccion dir;
    dir.cargarDireccion();
    reg.setDireccion(dir);


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

void ClientesArchivo::listarTodos(){
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) {
        cout << "ERROR AL ABRIR EL ARCHIVO DE CLIENTES." << endl;
        return;
    }

    Clientes reg;
    int i = 0;

    cout << "=== LISTADO DE CLIENTES ===" << endl;

    while (fread(&reg, sizeof(Clientes), 1, p) == 1) {
        if (reg.getEstado() == true) {
            cout << "-----------------------------" << endl;
            cout << "REGISTRO N°: " << i + 1 << endl;
            cout << "ID CLIENTE: " << reg.getIdCliente() << endl;
            cout << "NOMBRE: " << reg.getNombre() << endl;
            cout << "APELLIDO: " << reg.getApellido() << endl;
            cout << "DNI: " << reg.getDNI() << endl;

            // mostrar dirección
            Direccion dir = reg.getDireccion();
            cout << "PAIS: " << dir.getPais() << endl;
            cout << "PROVINCIA: " << dir.getProvincia() << endl;
            cout << "CIUDAD: " << dir.getCiudad() << endl;
            cout << "CALLE: " << dir.getCalle() << " " << dir.getAltura() << endl;
            cout << "COD. POSTAL: " << dir.getCodPostal() << endl;

            cout << "TELEFONO: " << reg.getTelefono() << endl;
            cout << "EMAIL: " << reg.getEmail() << endl;
        }
        i++;
    }

    fclose(p);
}

bool ClientesArchivo::eliminar(int pos){
    FILE *p = fopen(_nombreArchivo,"rb+");
    if (p==nullptr){
            cout<<"ERROR AL ABRIR EL ARCHIVO DE CLIENTES"<<endl;
    }

    Clientes reg;

    fseek(p,pos*sizeof(Clientes),SEEK_SET);

    if (fread(&reg,sizeof(Clientes),1,p)!=1){
        fclose(p);
        cout<<"NO SE PUDO LEER EL REGISTRO EN LA POSICION INDICADA"<<endl;
        return false;
    }
    reg.setEstado(false);

    //Volver a posicionarse en la misma posición para sobrescribir
    fseek(p,pos*sizeof(Clientes),SEEK_SET);

    //Escribe en el registro modificado
    bool ok = fwrite(&reg,sizeof(Clientes),1,p);

    fclose(p);
    return ok;
}

void mostrarClientes(int pos, const Clientes &reg);
