# include<iostream>
# include<cstdlib>
# include<cstring>
#include "ClientesArchivo.h"
#include "ManagerFactura.h"
#include "UsuarioArchivo.h"

using namespace std;

void ManagerFactura::altaFactura() {
    FacturaArchivo arch;
    Factura reg;
    ManagerFactura mgr;

    reg.setIdFactura( arch.contarRegistros() + 1 );
    // reg.cargar() //aca voy a llamar a la nueva función
    mgr.cargarFacturaMGR();

    /*if (arch.cargarFactura(mgr))
        cout << "Factura guardada.\n";
    else
        cout << "ERROR al guardar.\n"; */

    system("pause");
}
void ManagerFactura::recaudacionPorMes(){
    FacturaArchivo arch;

    Fecha fechaMesRec;
    int dia = 1, mes, anio;

    cout << "Recaudacion del mes" << endl;
    cout << "Ingrese mes" << endl;
    cin >> mes;
    fechaMesRec.setMes(mes);
    cout << "Ingrese anio" << endl;
    cin >> anio;
    fechaMesRec.setAnio(anio);
    if(fechaMesRec.fechaValida(dia,mes,anio)){
    arch.recaudacionPorMes(fechaMesRec);}
    else {
        cout << "Ingrese una fecha valida.." << endl;
        system("pause");
        return;
    }
}

void ManagerFactura::recaudacionPorVet(){
    FacturaArchivo arch;
    int idvet;
    cout << "Ingrese id del veterinario: " << endl;
    cin >> idvet;
    arch.recaudacionPorVet(idvet);
}

void ManagerFactura::recaudacionPorDia(){
    FacturaArchivo arch;
    Fecha fechaRec;

    int dia, mes, anio;
    cout << "Ingrese fecha de recaudacion" << endl;
    cout << "Ingrese dia: " << endl;
    cin >> dia;
    fechaRec.setDia(dia);
    cout << "Ingrese mes: " << endl;
    cin >> mes;
    fechaRec.setMes(mes);
    cout << "Ingrese anio: " << endl;
    cin >> anio;
    fechaRec.setAnio(anio);
    if(fechaRec.fechaValida(dia,mes,anio)){
    arch.recaudacionPorDia(fechaRec);}
    else {
    cout << "Ingrese una fecha valida.. " << endl;
    system("pause");
    return;
    }
}


void ManagerFactura::listarFacturas() {
    FacturaArchivo arch;
    arch.listarTodos();
    system("pause");
}

void ManagerFactura::menuListadoFacturas() {

    FacturaArchivo arch;
    int opc;

    do {
        system("cls");
        cout << "----LISTADOS DE FACTURAS----" << endl;
        cout << "1. Listar factura por ID" << endl;
        cout << "2. Listar facturas por DNI Cliente" << endl;
        cout << "3. Listar facturas por Fecha exacta" << endl;
        cout << "4. Listar facturas por Semana" << endl;
        cout << "5. Listar facturas por Mes" << endl;
        cout << "6. Listar todas" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch(opc) {

            case 1: {
                int id;
                cout << "Ingrese ID de factura: ";
                cin >> id;

                int pos = arch.buscarPorId(id);
                if (pos == -1) {
                    cout << "No existe una factura con ese ID.\n";
                } else {
                    Factura reg;
                    arch.leerFactura(pos, reg);
                    arch.mostrarFactura(pos, reg);
                }
                system("pause");
                break;
            }

           case 2: {
                int dni;
                cout << "Ingrese DNI del cliente: ";
                cin >> dni;

                //Buscamos el ID del cliente
                ClientesArchivo archCli;
                Clientes cli;
                int totalCli = archCli.contarRegistros();
                int idClienteEncontrado = -1;

                for (int i = 0; i < totalCli; i++) {
                    if (archCli.leerClientes(i, cli)) {
                        if (cli.getDNI() == dni) {
                            idClienteEncontrado = cli.getIdCliente();
                            break;
                        }
                    }
                }

                if (idClienteEncontrado == -1) {
                    cout << "No existe un cliente con ese DNI.\n";
                    system("pause");
                    break;
                }

                //Ahora si filtramos las facutras de ese cliente
                Factura reg;
                int pos = 0;

                FILE *p = fopen(arch.getNombreArchivo(), "rb");
                if (p == nullptr) {
                    cout << "No se pudo abrir el archivo.\n";
                    break;
                }

                cout << "\nFACTURAS DEL CLIENTE DNI: " << dni << endl;

                while (fread(&reg, sizeof(Factura), 1, p)) {
                    if (reg.getIdCliente() == idClienteEncontrado) {
                        arch.mostrarFactura(pos, reg);
                    }
                    pos++;
                }

                fclose(p);
                system("pause");
                break;
            }


            case 3: {
                Fecha f;
                cout << "Ingrese fecha (DD MM AAAA): ";
                int d, m, a;
                cin >> d >> m >> a;

                f.setDia(d);
                f.setMes(m);
                f.setAnio(a);

                arch.mostrarPorFecha(f);
                system("pause");
                break;
            }

            case 4: {
                Fecha inicio;
                cout << "Ingrese fecha inicial de la semana (DD MM AAAA): ";
                int d, m, a;
                cin >> d >> m >> a;

                inicio.setDia(d);
                inicio.setMes(m);
                inicio.setAnio(a);

                arch.mostrarPorSemana(inicio);
                system("pause");
                break;
            }

            case 5: {
                Fecha mes;
                cout << "Ingrese mes y año (MM AAAA): ";
                int m, a;
                cin >> m >> a;

                mes.setMes(m);
                mes.setAnio(a);
                mes.setDia(1);

                arch.mostrarPorMes(mes);
                system("pause");
                break;
            }

            case 6: {
                arch.listarTodos();
                system("pause");
                break;
            }
        }

    } while(opc != 0);

}

void ManagerFactura::cargarFacturaMGR(){//función nueva
    Factura factura;
    FacturaArchivo archivoFactura;
    DetalleFacturaArchivo detalle;
    UsuarioArchivo u;
    ClientesArchivo c;

    Fecha fecha;
    int idCliente, idUsuario,idFactura, dniCliente, dniUsuario;
    float importe;

    //id automático del registro factura
    idFactura=archivoFactura.generarNuevoID();
    factura.setIdFactura(idFactura);

    cout<<"INGRESE DNI CLIENTE: ";
    //pido dni y seteo id cliente
    cin>>dniCliente;
    if(c.buscarporDNI(dniCliente) >= 0 ){
    factura.setIdCliente(idCliente);}
    else {
        cout << "EL CLIENTE NO EXISTE .. \n";
        system("pause");
        return;
    }

    cout<<"INGRESE DNI USUARIO: ";
    //pido dni y seteo id usuario
    cin>>dniUsuario;
    if (u.buscarporDNI(dniUsuario) >= 0 ){
    factura.setIdUsuario(idUsuario);}
    else {
        cout << "EL USUARIO NO EXISTE \n";
        system("pause");
        return;
    }

    int d,m,a;
    cout<<"FECHA DE LA FACTURA:"<<endl;
    cout << "DIA: \n";
    cin >> d;
    cout << "MES: \n";
    cin >> m;
    cout << "ANIO: \n";
    cin >> a;
    if (fecha.fechaValida(d,m,a)){
    fecha.cargarPreCarga(d,m,a);
    factura.setFechaFactura(fecha);}
    else {
        cout << "INGRESE UNA FECHA VALIDA \n";
        system("pause");
        return;
    }


    cout << "DETALLES DE FACTURA" << endl;
    int opcion;
    do {
    importe += detalle.cargarDetalle(idFactura);//acumulamos

    cout << "Desea cargar mas detalles? (1=SI / 0=NO): ";
    cin >> opcion;

    while(opcion != 0 && opcion != 1){
        cout << "Opcion invalida. Ingresar 1 o 0: ";
        cin >> opcion;
    }

    } while(opcion == 1);

    cout << "IMPORTE TOTAL: $" << importe << endl;
    factura.setImporteTotalFactura(importe);

    factura.setEstadoFactura(true);

    if (archivoFactura.cargarFactura(factura)){
        cout<<"FACTURA GUARDADA.\n";

    }
    cout<<"ERROR AL GUARDAR FACTURA.\n";


}
