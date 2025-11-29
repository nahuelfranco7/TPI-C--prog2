# include<iostream>
# include<cstdlib>
# include<cstring>
#include "ClientesArchivo.h"
#include "ManagerFactura.h"
using namespace std;

void ManagerFactura::altaFactura() {
    FacturaArchivo arch;
    Factura reg;

    reg.setIdFactura( arch.contarRegistros() + 1 );
    reg.cargar();

    if (arch.cargarFactura(reg))
        cout << "Factura guardada.\n";
    else
        cout << "ERROR al guardar.\n";

    system("pause");
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
