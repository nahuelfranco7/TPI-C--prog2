#include <iostream>
#include "ProductosYServiciosArchivo.h"

using namespace std;

/*

    int buscarporID(int id); ok
    int contarRegistros(); ok
    int generarNuevoID(); ok
    void cargarCadena(char *palabra, int tam); ok pero con la forma vieja, sino hay que reemplazar

    bool cargarProducto(); ok
    bool cargarProducto(const ProductosYservicios &reg); ok
    bool modificarProducto(int pos, const ProductosYservicios &reg);ok
    bool modificar();ok
    bool leerProducto (int pos, const ProductosYservicios &reg); ok
    int precio (int valor); estos dos no hacen falta creo, ya con modificar estamos.
    int modificarPrecio(int valor);

*/

const char* ProductosYServiciosArchivo::getNombrearchivo(){
return _nombreArchivo;
}

int ProductosYServiciosArchivo::buscarporID(int id){
    ProductosYservicios reg;
    int pos=0;
    FILE* p=fopen(_nombreArchivo,"rb");
    if(p==nullptr)return -1;
    while(fread(&reg,sizeof(ProductosYservicios),1,p)){
        if(reg.getIdProducto()==id){
            fclose(p);
            return pos;
        }
        pos++;
    }
return -1;
}

int ProductosYServiciosArchivo::contarRegistros(){

    FILE* p=fopen(_nombreArchivo,"rb");
    if (p==nullptr) return -1;
    fseek(p,0,SEEK_END);
    int tamanio=ftell(p);
    fclose(p);
    int cantidadRegistros=tamanio/sizeof(ProductosYservicios);
    return cantidadRegistros;
}

int ProductosYServiciosArchivo::generarNuevoID() {
    return contarRegistros() + 1;
}

void ProductosYServiciosArchivo::cargarCadena(char *palabra, int tam){
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

bool ProductosYServiciosArchivo::cargarProducto(const ProductosYservicios &reg) {
    FILE *p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(ProductosYservicios), 1, p);
    fclose(p);
    return ok;
}

bool ProductosYServiciosArchivo::cargarProducto(){
    ProductosYservicios reg;
    int id;
    char descripcionProd[50];
    float costo;


    cout <<"INGRESE ID DE PRODUCTO: "<< endl;
    cin >> id; ///validar?
    reg.setIdProducto(id);

    cout <<"INGRESE DESCRIPCION DEL PRODUCTO: "<< endl;
    cargarCadena(descripcionProd,50);
    reg.setDescripcion(descripcionProd);

    cout <<"INGRESE COSTO DEL PRODUCTO: "<< endl;
    cin >> costo;
    reg.setCostoProdServ(costo);

    reg.setEstado(true);

    if (cargarProducto(reg)){
        cout <<"PRODUCTO CARGADO CORRECTAMENTE. "<<endl;
        return true;
        } else
        cout <<"ERROR AL CARGAR EL PRODUCTO. "<<endl;
        return false;

    cout<<"------------------------------------------"<<endl;
    cout<<"ID DEL PRODUCTO: "<< reg.getIdProducto() <<endl;
    cout<<"DESCRIPCION DEL PRODUCTO: "<< reg.getDescripcion() <<endl;
    cout<<"COSTO DEL PRODUCTO: "<< reg.getCostoProdServ() <<endl;

}

bool ProductosYServiciosArchivo::modificarProducto(int pos, const ProductosYservicios &reg) {
    FILE *p = fopen(_nombreArchivo, "rb+"); //lectura y escritura
    if (p == nullptr) return false;

    fseek(p, pos * sizeof(ProductosYservicios), SEEK_SET); //Nos movemos a la posición exacta

    bool escribio = fwrite(&reg, sizeof(ProductosYservicios), 1, p); //Sobrescribe el registro

    fclose(p);
    return escribio;
}

bool ProductosYServiciosArchivo::modificarProducto(int pos) {
    ProductosYservicios reg;

    // 1) Leer registro existente
    if (!leerProducto(pos, reg)) {
        cout << "NO SE PUDO LEER EL REGISTRO." << endl;
        return false;
    }

  /*  // 2) Mostrar datos actuales
    cout << "===== MODIFICAR PRODUCTO =====" << endl;
    mostrarProducto(pos, reg);
    */

    int opcion;

    do {
        cout << "\n--- MENU PRODUCTOS ---\n";
        cout << "1. Modificar descripcion\n";
        cout << "2. Modificar precio\n";
        cout << "3. Cambiar estado (activo/inactivo)\n";
        cout << "4. Guardar y salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1: {
            char descripcion[50];
            cout << "Nueva descripcion: ";
            cargarCadena(descripcion, 50);
            reg.setDescripcion(descripcion);
            break;
        }

        case 2: {
            float precio;
            cout << "Nuevo precio:\n";
            cin >> precio;
            reg.setCostoProdServ(precio);
            break;
        }

        case 3: {
            bool nuevoEstado;
            cout << "Estado (1 = activo, 0 = inactivo): ";
            cin >> nuevoEstado;
            reg.setEstado(nuevoEstado);
            break;
        }

        case 4:
            cout << "Guardando cambios...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
            break;
        }

    } while (opcion != 4);

    // 3) Guardar cambios en archivo
    return modificarProducto(pos, reg);
}

bool ProductosYServiciosArchivo::leerProducto(int pos, ProductosYservicios &reg) {
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return false;

    fseek(p, pos * sizeof(ProductosYservicios), SEEK_SET);
    bool ok = fread(&reg, sizeof(ProductosYservicios), 1, p);
    fclose(p);

    return ok;
}
