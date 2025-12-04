# include<iostream>
# include<cstdlib>
# include<cstring>
# include "DetalleFacturaArchivo.h"
# include "ProductosYserviciosArchivo.h"

using namespace std;


const char* DetalleFacturaArchivo::getNombreArchivo(){
return _nombreArchivo;
}

int DetalleFacturaArchivo::generarNuevoID(){
    return contarRegistros() + 1;
}
/*----------------------------------------------------------*/
//enviamos el id del detalle para buscar
int DetalleFacturaArchivo::buscarPorIdDetalle(int id){
DetalleFactura reg;
int pos=0;
FILE* p=fopen(_nombreArchivo,"rb");
if(p==nullptr)return -1;
while(fread(&reg,sizeof(DetalleFactura),1,p)){
    if(reg.getIdFactura()==id){
        fclose(p);
        return pos;
    }
    pos++;
}
return -1;
}
/*---------------------------------------------------------*/
//enviamos el id de factura para buscar
bool DetalleFacturaArchivo::buscarPorIdFactura(int idFactura) {
    DetalleFactura reg;
    FILE*p=fopen(_nombreArchivo, "rb");
    if (p==nullptr) return false;

    while(fread(&reg,sizeof(reg),1,p)) {
        if (reg.getIdFactura()==idFactura) {
            fclose(p);
            return true;
        }
    }

    fclose(p);
    return false;
}


/*---------------------------------------------------------*/
int DetalleFacturaArchivo::contarRegistros(){
    DetalleFactura reg;
    FILE* p=fopen(_nombreArchivo,"rb");
    if (p==nullptr) return 0;
    fseek(p,0,SEEK_END);
    int cantidadRegistros = ftell(p) / sizeof(reg);
    fclose(p);
    return cantidadRegistros;
}
/*-----------------------------------------------------------*/
bool DetalleFacturaArchivo::cargarDetalle(const DetalleFactura &reg){
    FILE*p=fopen(_nombreArchivo,"ab");
    if(p == nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO DE DETALLE DE FACTURA."<<endl;
        return false;
    }
    bool ok=fwrite(&reg,sizeof(DetalleFactura),1,p);
    fclose(p);
    return ok;
}
/*----------------------------------------------------------*/
float DetalleFacturaArchivo::cargarDetalle(int idFactura){
     DetalleFactura reg;
     ProductosYServiciosArchivo archivoProductos;


    int idProducto, cantidad;
    float precioUnitario;

    cout << "=== CARGA DE DETALLE DE FACTURA ===" << endl;
    int idDetalle = generarNuevoID();
    reg.setIdDetalle(idDetalle);
    cout << "ID DETALLE ASIGNADO AUTOMATICAMENTE: " << idDetalle << endl;

    cout << "ID DE FACTURA: "<< idFactura<< endl;
    reg.setIdFactura(idFactura);

    cout << "CARGA DE PRODUCTOS: "<< endl;
    archivoProductos.listarProductos();

    cout<< "SELECCIONE EL ID" << endl;
    cin >> idProducto;
    reg.setIdProducto(idProducto);


    precioUnitario=archivoProductos.precioProducto(idProducto);
    cout << "PRECIO UNITARIO: "<<precioUnitario<<endl;
    reg.setPrecioUnitario(precioUnitario);

    cout << "INGRESE CANTIDAD: ";
    cin >> cantidad;
    reg.setCantidad(cantidad);

/*   cout << "PRECIO UNITARIO: ";
    cin >> precioUnitario;
    reg.setPrecioUnitario(precioUnitario);
*/
    cout << "SUBTOTAL: "<<precioUnitario*cantidad<<endl;
    reg.setEstado(true);

    if (cargarDetalle(reg)) {
        cout << "DETALLE GUARDADO EXITOSAMENTE." << endl;
        return true;
    } else {
        cout << "ERROR AL GUARDAR EL DETALLE." << endl;
        return false;
    }
}
/*----------------------------------------------------------*/
void DetalleFacturaArchivo::listarTodos(){
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO DE DETALLE DE FACTURA."<<endl;
        return;
    }
    DetalleFactura reg;
    int pos=0;

    cout<<"=== LISTADO DE DETALLES DE FACTURA ==="<<endl;

    while(fread(&reg, sizeof(DetalleFactura),1,p)==1){
        cout<<"-----------------------------"<<endl;
        cout<<"REGISTRO #"<<pos+1<<endl;
        cout<<"ID DETALLE: "<<reg.getIdDetalle()<<endl;
        cout<<"ID PRODUCTO: "<<reg.getIdProducto()<<endl;
        cout<<"ID FACTURA: " <<reg.getIdFactura()<<endl;
        cout<<"CANTIDAD: "<<reg.getCantidad()<<endl;
        cout<<"PRECIO UNITARIO: $"<<reg.getPrecioUnitario()<<endl;
        pos++;
    }
    fclose(p);
}
/*-------------------------------------------------------------------*/
void DetalleFacturaArchivo::mostrarPorIdDetalle(int idDetalle) {
    FILE*p=fopen(_nombreArchivo,"rb");
    if (p == nullptr) {
        cout << "ERROR AL ABRIR EL ARCHIVO DE DETALLE DE FACTURA." << endl;
        return;
    }

    DetalleFactura reg;
    bool encontrado=false;

    while(fread(&reg,sizeof(DetalleFactura),1,p)){
        if(reg.getIdDetalle()==idDetalle){
            cout<<"=== DETALLE #"<<idDetalle<<" ==="<<endl;
            cout<<"ID DETALLE: "<<reg.getIdDetalle()<<endl;
            cout<<"ID FACTURA: "<<reg.getIdFactura()<<endl;
            cout<<"ID PRODUCTO: "<<reg.getIdProducto()<<endl;
            cout<<"CANTIDAD: "<<reg.getCantidad()<<endl;
            cout<<"PRECIO UNITARIO: $"<<reg.getPrecioUnitario()<< endl;

            encontrado=true;
            break;
        }
    }

    if (!encontrado) {
        cout<<"NO SE ENCONTRO NINGUN DETALLE CON EL ID "<<idDetalle<<endl;
    }

    fclose(p);
}
/*---------------------------------------------------------------------*/
//mostrar detalle por id factura
void DetalleFacturaArchivo::mostrarPorIdFactura(int idFactura) {
    FILE* p=fopen(_nombreArchivo,"rb");
    if (p==nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO DE DETALLE DE FACTURA."<<endl;
        return;
    }

    DetalleFactura reg;
    bool encontrado=false;
    float total=0;

    cout<<"===DETALLES DE LA FACTURA #"<<idFactura<<"==="<<endl;

    while(fread(&reg,sizeof(DetalleFactura), 1,p)){
        if(reg.getIdFactura()==idFactura){
            cout<<"-----------------------------"<<endl;
            cout<<"ID DETALLE: "<<reg.getIdDetalle()<<endl;
            cout<<"ID PRODUCTO: "<<reg.getIdProducto()<<endl;
            cout<<"CANTIDAD: "<<reg.getCantidad()<<endl;
            cout<<"PRECIO UNITARIO: $"<<reg.getPrecioUnitario()<<endl;
            encontrado=true;
        }
    }

    if(encontrado){
        cout<<"-----------------------------"<<endl;
        cout<<"TOTAL FACTURA: $"<<total<<endl;
    }else{
        cout<<"NO SE ENCONTRARON DETALLES PARA LA FACTURA #"<<idFactura<<endl;
    }

    fclose(p);
}
/*------------------------------------------------------------------*/
bool DetalleFacturaArchivo::leerDetalle(int pos, DetalleFactura &reg) {
    FILE*p=fopen(_nombreArchivo,"rb");
    if(p == nullptr) return false;

    fseek(p,pos* sizeof(DetalleFactura),SEEK_SET);

    bool ok=fread(&reg,sizeof(DetalleFactura),1,p);
    fclose(p);

    return ok;
}
/*-------------------------------------------------------------------*/
bool DetalleFacturaArchivo::eliminar(int pos) {
    FILE *p=fopen(_nombreArchivo,"rb+");
    if(p==nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO DE DETALLES DE FACTURA."<<endl;
        return false;
    }

    DetalleFactura reg;

    //Posicionamos en el registro indicado
    fseek(p,pos*sizeof(DetalleFactura),SEEK_SET);

    //Leemos el registro existente
    if(fread(&reg, sizeof(DetalleFactura),1,p)!=1) {
        fclose(p);
        cout<<"NO SE PUDO LEER EL REGISTRO EN LA POSICION INDICADA."<<endl;
        return false;
    }

    //Modifica el estado a inactivo
    reg.setEstado(false);

    //Volver a posicionarnos en la misma posición para sobrescribir
    fseek(p,pos*sizeof(DetalleFactura),SEEK_SET);

    //Escribir el registro modificado
    bool ok=fwrite(&reg, sizeof(DetalleFactura),1,p);

    fclose(p);
    return ok;
}
/*--------------------------------------------------------*/
bool DetalleFacturaArchivo::modificarDetalleArchivo(int pos, const DetalleFactura &reg) {
    FILE *p=fopen(_nombreArchivo,"rb+");
    if(p==nullptr){
        cout << "ERROR AL ABRIR EL ARCHIVO DE DETALLES DE FACTURA." << endl;
        return false;
    }

    //Posicionarse en el registro indicado
    fseek(p,pos*sizeof(DetalleFactura),SEEK_SET);

    //Sobrescribir el registro con el nuevo contenido
    bool ok=fwrite(&reg, sizeof(DetalleFactura),1,p);

    fclose(p);
    return ok;
}
/*-----------------------------------------------------------*/

bool DetalleFacturaArchivo::modificar(int pos) {
    DetalleFactura reg;
    FILE *p =fopen(_nombreArchivo,"rb");
    if(p==nullptr) return false;

    //Leemos el registro actual
    if (!leerDetalle(pos,reg)){
        cout<<"NO SE PUDO LEER EL REGISTRO EN ESA POSICION."<<endl;
        return false;
    }

    // Mostramos datos actuales
    cout<<"MODIFICANDO DETALLE #"<<reg.getIdDetalle()<<endl;
    cout<<"ID FACTURA ACTUAL: "<<reg.getIdFactura()<<endl;
    cout<<"ID PRODUCTO ACTUAL: "<< reg.getIdProducto()<<endl;
    cout<<"CANTIDAD ACTUAL: "<<reg.getCantidad()<<endl;
    cout<<"PRECIO ACTUAL: "<<reg.getPrecioUnitario()<< endl;
    cout<<"------------------------------"<<endl;

    // Pedimos nuevos datos
    int opcion;
do {
    cout<<endl;
    cout<<"=== MENU DE MODIFICACION DE DETALLE ==="<< endl;
    cout<<"1. MODIFICAR ID FACTURA"<<endl;
    cout<<"2. MODIFICAR ID PRODUCTO"<<endl;
    cout<<"3. MODIFICAR CANTIDAD"<<endl;
    cout<<"4. MODIFICAR PRECIO UNITARIO"<<endl;
    cout<<"5. GUARDAR Y SALIR"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"SELECCIONE UNA OPCION: ";
    cin>>opcion;

    switch(opcion){
        case 1: {
            int idFactura;
            cout<<"INGRESE NUEVO ID DE FACTURA: ";
            cin>>idFactura;
            reg.setIdFactura(idFactura);
            cout<<"ID FACTURA MODIFICADO CORRECTAMENTE."<<endl;
            break;
        }
        case 2:{
            int idProducto;
            cout<<"INGRESE NUEVO ID DE PRODUCTO: ";
            cin>>idProducto;
            reg.setIdProducto(idProducto);
            cout<<"ID PRODUCTO MODIFICADO CORRECTAMENTE."<<endl;
            break;
        }
        case 3:{
            int cantidad;
            cout<<"INGRESE NUEVA CANTIDAD: ";
            cin>>cantidad;
            reg.setCantidad(cantidad);
            cout<<"CANTIDAD MODIFICADA CORRECTAMENTE."<<endl;
            break;
        }
        case 4:{
            float precioUnitario;
            cout<<"INGRESE NUEVO PRECIO UNITARIO: ";
            cin>>precioUnitario;
            reg.setPrecioUnitario(precioUnitario);
            cout<<"PRECIO UNITARIO MODIFICADO CORRECTAMENTE."<<endl;
            break;
        }
        case 5:
            cout<<"GUARDANDO CAMBIOS..."<<endl;
            break;

        default:
            cout<<"OPCION INVALIDA. INTENTE NUEVAMENTE."<<endl;
            break;
    }

} while(opcion != 5);


    // Usamos la función interna para sobrescribir
    return modificarDetalleArchivo(pos,reg);
}


