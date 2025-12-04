# include<iostream>
# include<cstdlib>
# include<cstring>
# include "FacturaArchivo.h"

using namespace std;

const char* FacturaArchivo::getNombreArchivo() {
    return _nombreArchivo;
}


//                          CARGA BÁSICA

bool FacturaArchivo::cargarFactura(const Factura &reg) {
    FILE *p=fopen(_nombreArchivo,"ab");
    if (p==nullptr) return false;

    bool ok=fwrite(&reg,sizeof(Factura), 1, p);
    fclose(p);
    return ok;
}

void FacturaArchivo::cargarCadena(char *palabra,int tam){
    int i=0;
    fflush(stdin);
    for (i= 0;i<tam;i++){
        palabra[i]=cin.get();
        if(palabra[i]=='\n') break;
    }
    palabra[i]='\0';
    fflush(stdin);
}

bool FacturaArchivo::cargarFactura() {
    Factura reg;
    Fecha fecha;
    int idCliente, idUsuario;
    float importe;

    reg.setIdFactura(generarNuevoID());

    cout<<"INGRESE ID CLIENTE: ";
    cin>>idCliente;
    reg.setIdCliente(idCliente);

    cout<<"INGRESE ID USUARIO: ";
    cin>>idUsuario;
    reg.setIdUsuario(idUsuario);

    cout<<"FECHA DE LA FACTURA:"<<endl;
    fecha.cargar();
    reg.setFechaFactura(fecha);

    cout<<"DESDEA CARGAR LOS DETALLES DE FACTURA?";

    cout<<"IMPORTE TOTAL: ";
    cin>>importe;
    reg.setImporteTotalFactura(importe);

    reg.setEstadoFactura(true);

    if (cargarFactura(reg)){
        cout<<"FACTURA GUARDADA.\n";
        return true;
    }
    cout<<"ERROR AL GUARDAR FACTURA.\n";
    return false;
}


//                              LECTURA

bool FacturaArchivo::leerFactura(int pos,Factura &reg) {
    FILE *p=fopen(_nombreArchivo,"rb");
    if (p == nullptr) return false;

    fseek(p,pos*sizeof(Factura),SEEK_SET);
    bool ok=fread(&reg,sizeof(Factura),1,p);
    fclose(p);

    return ok;
}


//                         MOSTRAR FACTURA

void FacturaArchivo::mostrarFactura(int pos, const Factura &reg) {
    cout<<"---------------------------------"<<endl;
    cout<<"POSICION: "<< pos << endl;
    cout<<"ID FACTURA: "<<reg.getIdFactura()<<endl;
    cout<<"ID CLIENTE: "<<reg.getIdCliente()<<endl;
    cout<<"ID USUARIO: "<<reg.getIdUsuario()<<endl;

    cout<<"FECHA: ";
    reg.getFechaFactura().mostrar();
    cout<<endl;

    cout<<"IMPORTE TOTAL: "<< reg.getImporteTotalFactura()<<endl;

    cout<<"ESTADO: " <<(reg.getEstadoFactura() ? "ACTIVA" : "INACTIVA")<<endl;
    cout<<"---------------------------------"<<endl;
}

//                          BÚSQUEDA

int FacturaArchivo::buscarPorId(int id) {
    Factura reg;
    int pos=0;
    FILE *p=fopen(_nombreArchivo, "rb");
    if(p==nullptr) return -1;

    while(fread(&reg, sizeof(Factura),1,p)) {
        if (reg.getIdFactura()==id){
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}


//                   CONTAR / GENERAR ID

int FacturaArchivo::contarRegistros(){
    FILE *p=fopen(_nombreArchivo,"rb");
    if (p==nullptr) return -1;

    fseek(p,0,SEEK_END);
    int bytes=ftell(p);
    fclose(p);
    int cantidad;
    cantidad=bytes/sizeof(Factura);
    return cantidad;
}

int FacturaArchivo::generarNuevoID() {
    return contarRegistros()+1;
}

//                        LISTAR TODAS

void FacturaArchivo::listarTodos() {
    Factura reg;
    int pos=0;

    FILE *p=fopen(_nombreArchivo, "rb");
    if(p==nullptr) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO\n";
        return;
    }

    while(fread(&reg, sizeof(Factura), 1, p)) {
        mostrarFactura(pos,reg);
        pos++;
    }

    fclose(p);
}


//                             ELIMINAR

bool FacturaArchivo::eliminar(int pos){
    Factura reg;

    if (!leerFactura(pos,reg))return false;

    reg.setEstadoFactura(false);

    return modificarFactura(pos,reg);
}


//                            MODIFICAR

bool FacturaArchivo::modificar(int pos){
    Factura reg;

    if (!leerFactura(pos, reg))return false;

    int opcion;
    do {
        cout<<"\n=== MENU DE MODIFICACION ===\n";
        cout<<"1. ID CLIENTE\n";
        cout<<"2. ID USUARIO\n";
        cout<<"3. FECHA\n";
        cout<<"4. IMPORTE TOTAL\n";
        cout<<"5. GUARDAR Y SALIR\n";
        cout<<"SELECCIONE: ";
        cin>>opcion;

        switch(opcion){
            case 1:{
                int idCliente;
                cout<<"Nuevo ID Cliente: ";
                cin>>idCliente;
                reg.setIdCliente(idCliente);
                break;
            }
            case 2: {
                int idUsuario;
                cout << "Nuevo ID Usuario: ";
                cin >> idUsuario;
                reg.setIdUsuario(idUsuario);
                break;
            }
            case 3: {
                Fecha f;
                cout << "Nueva Fecha:\n";
                f.cargar();
                reg.setFechaFactura(f);
                break;
            }
            case 4: {
                float imp;
                cout << "Nuevo Importe: ";
                cin >> imp;
                reg.setImporteTotalFactura(imp);
                break;
            }
            case 5:
                break;

            default:
                cout << "Opcion incorrecta.\n";
        }

    } while (opcion!=5);

    return modificarFactura(pos,reg);
}

bool FacturaArchivo::modificarFactura(int pos,const Factura &reg) {
    FILE *p=fopen(_nombreArchivo,"rb+");
    if (p==nullptr) return false;

    fseek(p,pos*sizeof(Factura),SEEK_SET);
    bool ok = fwrite(&reg,sizeof(Factura),1,p);

    fclose(p);
    return ok;
}


//                      FILTROS POR FECHA


bool FacturaArchivo::fechaEsMayorIgual(Fecha a, Fecha b) {
    if (a.getAnio() > b.getAnio()) return true;
    if (a.getAnio() < b.getAnio()) return false;

    if (a.getMes() > b.getMes()) return true;
    if (a.getMes() < b.getMes()) return false;

    return a.getDia() >= b.getDia();
}

bool FacturaArchivo::fechaEsMenorIgual(Fecha a, Fecha b) {
    if (a.getAnio() < b.getAnio()) return true;
    if (a.getAnio() > b.getAnio()) return false;

    if (a.getMes() < b.getMes()) return true;
    if (a.getMes() > b.getMes()) return false;

    return a.getDia() <= b.getDia();
}

Fecha FacturaArchivo::sumarDias(Fecha f, int dias) {
    Fecha aux = f;

    for (int i = 0; i < dias; i++) {
        aux.setDia(aux.getDia() + 1);

        int dia = aux.getDia();
        int mes = aux.getMes();
        int anio = aux.getAnio();

        int diasMes;

        switch (mes) {
            case 4: case 6: case 9: case 11:
                diasMes = 30; break;
            case 2:
                diasMes = 28; break;
            default:
                diasMes = 31;
        }

        if (dia > diasMes) {
            aux.setDia(1);
            aux.setMes(mes + 1);
            if (mes + 1 > 12) {
                aux.setMes(1);
                aux.setAnio(anio + 1);
            }
        }
    }

    return aux;
}

void FacturaArchivo::mostrarPorFecha(Fecha fecha) {
    Factura reg;
    int pos = 0;

    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return;

    while (fread(&reg, sizeof(Factura), 1, p)) {
        Fecha f = reg.getFechaFactura();
        if (f.getDia() == fecha.getDia() &&
            f.getMes() == fecha.getMes() &&
            f.getAnio() == fecha.getAnio())
        {
            mostrarFactura(pos, reg);
        }
        pos++;
    }

    fclose(p);
}

void FacturaArchivo::mostrarPorSemana(Fecha inicio) {
    Factura reg;
    Fecha fin=sumarDias(inicio, 7);
    int pos=0;

    FILE *p=fopen(_nombreArchivo,"rb");
    if (p==nullptr) return;

    while (fread(&reg,sizeof(Factura),1,p)) {
        Fecha f = reg.getFechaFactura();

        if (fechaEsMayorIgual(f, inicio)&&fechaEsMenorIgual(f,fin)) {
            mostrarFactura(pos,reg);
        }

        pos++;
    }

    fclose(p);
}

void FacturaArchivo::mostrarPorMes(Fecha fecha) {
    Factura reg;
    int pos = 0;

    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==nullptr) return;

    while (fread(&reg,sizeof(Factura),1,p)){
        Fecha f=reg.getFechaFactura();

        if (f.getMes()==fecha.getMes()&&
            f.getAnio()==fecha.getAnio())
        {
            mostrarFactura(pos, reg);
        }
        pos++;
    }

    fclose(p);
}
