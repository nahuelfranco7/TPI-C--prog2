# include<iostream>
# include<cstdlib>
# include<cstring>
#include <ctime>
#include "Fecha.h"
#include "ManagerMascota.h"
#include "UsuarioArchivo.h"
using namespace std;
    int ManagerMascota::calcularEdad(int dia, int mes, int anio) {
    time_t t = time(nullptr);
    tm* hoy = localtime(&t);

    int anioActual = hoy->tm_year + 1900;
    int mesActual  = hoy->tm_mon + 1;
    int diaActual  = hoy->tm_mday;

    int edad = anioActual - anio;

    // Si todavía no cumplio este año restar 1
    if (mesActual < mes || (mesActual == mes && diaActual < dia)) {
        edad--;
    }

    // Seguridad en caso de fechas futuras dentro del rango permitido
    if (edad < 0) edad = 0;

    return edad;
}

/*
void ManagerMascota::altaMascota() {


      MascotaArchivo arch;
      Mascota reg;
        ClientesArchivo a;

    cout << "=== ALTA DE MASCOTA ===\n";

    int dni;
    int posCliente = -1;

    // 1) Bucle para pedir DNI hasta encontrar uno válido o ingresar 0 para salir
    bool seguir = true;
    while (seguir) {

        cout << "DNI Cliente dueño (0 para volver): ";
        cin >> dni;

        if (dni == 0) {
            // El usuario quiere volver al menú anterior
            cout << "Operación cancelada.\n";
            system("pause");
            return;  // salimos directamente de altaMascota
        }

        posCliente = a.buscarporDNI(dni);

        if (posCliente == -1) {
            cout << "Cliente no encontrado. Ingrese un DNI válido o 0 para volver.\n";
            system("pause");
        }
        else {
            Clientes cli;
            a.leerClientes(posCliente, cli);

            if (!cli.getEstado()) {
                cout << "El cliente está INACTIVO. Reactívelo antes de continuar.\n";

                system("pause");
            }
            else {
                // DNI válido y cliente activo podemos seguir
                cout<<"El cliente dueno es: ";
                cli.mostrar();
                system("pause");
                seguir = false;
            }
        }
    }

    //CARGA DE LA MASCOTA
    //reg.cargar(dni);
    //reg.setEstadoMascota(true);
    reg.setIdMascota( arch.contarRegistros() + 1 );
    ///suplantamos por cargarMascota(dni)

   //if (arch.guardarMascota(reg)) {
      //  cout << "Mascota guardada!\n";
    //}
    //else {
      //  cout << "ERROR al guardar.\n";
    //}



        reg.setDniClienteDueno(dni);

        cout << "Nombre mascota: ";
        char nombre[20];

        reg.setNombreMascota(nombre);

        cout << "Fecha nacimiento: \n";
               cout << "Fecha de nacimiento (DD MM AAAA): ";
        int d, m, anio;
        cin >> d >> m >> anio;
        //comprobamos si es correcta la fecha
        Fecha fecha;
        while (!fecha.fechaValida(d, m, anio)) {
        cout << "Fecha INVALIDA. Coloque otra fecha respetando el formato.\n";
        cout << "Ingrese nuevamente (DD MM AAAA): ";
        cin >> d >> m >> anio;
        }
        fecha.setDia(d);
        fecha.setMes(m);
        fecha.setAnio(anio);
        reg.setFechaNac(fecha);

        // Calculo de edad de forma automática
        int edad = calcularEdad(d, m, anio);
        cout << "Edad: " << edad << endl;
       reg.setEdad(edad);

        char Raza[30];
        int animal, raza;

// BUCLE PRINCIPAL DE ANIMAL
do {
    cout << "Seleccionar animal:\n";
    cout << "1. Perro\n";
    cout << "2. Gato\n";
    cout << "0. Volver\n";
    cout << "Opción: ";
    cin >> animal;

    if (animal == 0) return; // vuelve a lo anterior

    switch (animal) {

    case 1:   // PERRO
        do {
            cout << "Seleccionaste PERRO\n";
            cout << "Elegir raza:\n";
            cout << "1. Pastor\n";
            cout << "2. Golden\n";
            cout << "3. Bulldog\n";
            cout << "0. Volver\n";
            cout << "Opción: ";
            cin >> raza;

            if (raza == 0) break; // vuelve al menú de animal

            switch (raza) {
            case 1: strcpy(Raza, "Pastor");
                    reg.setIdRaza(raza);
                    break;
            case 2: strcpy(Raza, "Golden");
                    reg.setIdRaza(raza);
                    break;
            case 3: strcpy(Raza, "Bulldog");
                    reg.setIdRaza(raza);
                    break;
            default:
                cout << "Opción inválida.\n";
                raza = -1; // fuerza repetir
            }

        } while (raza < 1 || raza > 3);

        if (raza != 0) cout << "Raza seleccionada: " << Raza << endl;
        break;


    case 2:   // GATO
        do {
            cout << "Seleccionaste GATO\n";
            cout << "Elegir raza:\n";
            cout << "1. Siamés\n";
            cout << "2. Persa\n";
            cout << "3. Bengalí\n";
            cout << "0. Volver\n";
            cout << "Opción: ";
            cin >> raza;

            if (raza == 0) break; // vuelve al menú de animal

            switch (raza) {
            case 1: strcpy(Raza, "Siames");
                    reg.setIdRaza(raza);
                    break;
            case 2: strcpy(Raza, "Persa");
                    reg.setIdRaza(raza);
                    break;
            case 3: strcpy(Raza, "Bengali");
                    reg.setIdRaza(raza);
                    break;
            default:
                cout << "Opción inválida.\n";
                raza = -1;
            }

        } while (raza < 1 || raza > 3);

        if (raza != 0) cout << "Raza seleccionada: " << Raza << endl;
        break;


    default:
        cout << "Opción inválida.\n";
    }

} while (animal != 1 && animal != 2);

        cout << "Sexo (M/H): ";
        char _sexoAnimal;
        cin >> _sexoAnimal;
        reg.setSexoAnimal(_sexoAnimal);

        reg.setEstadoMascota(true);

        if (arch.guardarMascota(reg)) {
        cout << "Mascota guardada!\n";
    }
    else {
        cout << "ERROR al guardar.\n";



}}
*/


void ManagerMascota::altaMascota() {

    MascotaArchivo arch;
    Mascota reg;
    ClientesArchivo a;

    cout << "=== ALTA DE MASCOTA ===\n";

    int dni;
    int posCliente = -1;

    /// ============================
    /// VALIDACIÓN DE DNI DEL CLIENTE
    /// ============================

    bool seguir = true;

    while (seguir) {
        cout << "DNI Cliente dueño (0 para volver): ";
        cin >> dni;

        if (dni == 0) {
            cout << "Operación cancelada.\n";
            system("pause");
            return;
        }

        posCliente = a.buscarporDNI(dni);

        if (posCliente == -1) {
            cout << "Cliente no encontrado. Ingrese un DNI válido o 0 para volver.\n";
            system("pause");
        }
        else {
            Clientes cli;
            a.leerClientes(posCliente, cli);

            if (!cli.getEstado()) {
                cout << "El cliente está INACTIVO. Reactívelo antes de continuar.\n";
                system("pause");
            }
            else {
                cout << "El cliente dueño es:\n";
                cli.mostrar();
                system("pause");
                seguir = false;
            }
        }
    }

    /// ============================
    /// CARGA DE DATOS DE LA MASCOTA
    /// ============================

    reg.setDniClienteDueno(dni);

    /// --- Nombre ---
    char nombre[20];
    cout << "Nombre mascota: ";
    cin.ignore();
    cin.getline(nombre, 20);
    reg.setNombreMascota(nombre);

    /// --- Fecha de nacimiento ---
    cout << "Fecha de nacimiento (DD MM AAAA): ";
    int d, m, anio;
    cin >> d >> m >> anio;

    Fecha fecha;

    while (!fecha.fechaValida(d, m, anio)) {
        cout << "Fecha INVALIDA. Ingrese nuevamente (DD MM AAAA): ";
        cin >> d >> m >> anio;
    }

    fecha.setDia(d);
    fecha.setMes(m);
    fecha.setAnio(anio);
    reg.setFechaNac(fecha);

    /// --- Edad ---
    int edad = calcularEdad(d, m, anio);
    cout << "Edad: " << edad << endl;
    reg.setEdad(edad);

    /// --- Selección de animal y raza ---
    char Raza[30];
    int animal = -1, raza = -1;

    do {
        cout << "Seleccionar animal:\n";
        cout << "1. Perro\n";
        cout << "2. Gato\n";
        cout << "0. Volver\n";
        cout << "Opción: ";
        cin >> animal;

        if (animal == 0) return;

        switch (animal) {

        case 1:
            do {
                cout << "Seleccionaste PERRO\n";
                cout << "Elegir raza:\n";
                cout << "1. Pastor\n";
                cout << "2. Golden\n";
                cout << "3. Bulldog\n";
                cout << "0. Volver\n";
                cout << "Opción: ";
                cin >> raza;

                if (raza == 0) break;

                if (raza == 1) strcpy(Raza, "Pastor");
                else if (raza == 2) strcpy(Raza, "Golden");
                else if (raza == 3) strcpy(Raza, "Bulldog");
                else {
                    cout << "Opción inválida.\n";
                    raza = -1;
                }

            } while (raza < 1 || raza > 3);

            break;

        case 2:
            do {
                cout << "Seleccionaste GATO\n";
                cout << "Elegir raza:\n";
                cout << "1. Siames\n";
                cout << "2. Persa\n";
                cout << "3. Bengali\n";
                cout << "0. Volver\n";
                cout << "Opción: ";
                cin >> raza;

                if (raza == 0) break;

                if (raza == 1) strcpy(Raza, "Siames");
                else if (raza == 2) strcpy(Raza, "Persa");
                else if (raza == 3) strcpy(Raza, "Bengali");
                else {
                    cout << "Opción inválida.\n";
                    raza = -1;
                }

            } while (raza < 1 || raza > 3);

            break;

        default:
            cout << "Opción inválida.\n";
        }

    } while (animal != 1 && animal != 2);

    reg.setIdRaza(raza);

    /// --- Sexo ---
    char sexo;
    cout << "Sexo (M/H): ";
    cin >> sexo;

    while (sexo != 'M' && sexo != 'H' && sexo != 'm' && sexo != 'h') {
        cout << "Valor inválido. Ingrese M o H: ";
        cin >> sexo;
    }

    reg.setSexoAnimal(sexo);

    /// --- ID de mascota ---
    reg.setIdMascota( arch.contarRegistros() + 1 );

    /// --- Estado ---
    reg.setEstadoMascota(true);

    /// ============================
    /// GUARDADO EN ARCHIVO
    /// ============================

    if (arch.guardarMascota(reg)) {
        cout << "Mascota guardada correctamente!\n";
    }
    else {
        cout << "ERROR al guardar.\n";
    }

    system("pause");
}





void ManagerMascota::modificarMascota() {
    MascotaArchivo arch;
    ClientesArchivo a;

    cout << "INGRESE DNI DEL CLIENTE DUENO (0 para volver): ";
    int dnicliente;
    cin >> dnicliente;

    if (dnicliente == 0) return;

    while (true) {

        int pos = a.buscarporDNI(dnicliente);
        if (pos == -1) {
            cout << "Cliente no encontrado. Ingrese uno valido o 0 para salir: ";
            cin >> dnicliente;
            if (dnicliente == 0) return;
            continue;
        }

        // Estado del cliente
        if (!a.estadoCliente(dnicliente)) {
            cout << "El cliente está INACTIVO. Reactívelo antes de continuar.\n";
            cout << "Ingrese otro DNI o 0 para salir: ";
            cin >> dnicliente;
            if (dnicliente == 0) return;
            continue;
        }

        // Listar mascotas
        cout << "\n--- MASCOTAS DEL CLIENTE ---\n";
        arch.listarMascotaporDueno(dnicliente);

        cout << "\nIngrese ID de la mascota a modificar (0 para salir): ";
        int idmascota;
        cin >> idmascota;

        if (idmascota == 0) return;

        int posMascota = arch.buscarPorId(idmascota);
        if (posMascota == -1) {
            cout << "ID de mascota inexistente.\n";
            continue;
        }

        Mascota reg;
        arch.leerMascota(posMascota, reg);

        cout << "\nMascota seleccionada:\n";
        arch.mostrarMascota(posMascota, reg);

        cout << "\nIngrese nuevos datos:\n";
        reg.cargar(dnicliente);

        if (arch.modificarMascota(posMascota, reg))
            cout << "Modificado OK.\n";
        else
            cout << "ERROR.\n";

        system("pause");
        return;
    }
}


void ManagerMascota::reactivarMascota() {
    MascotaArchivo arch;
    ClientesArchivo a;

    cout << "INGRESE DNI DEL CLIENTE DUENO (0 para volver): ";
    int dnicliente;
    cin >> dnicliente;

    if (dnicliente == 0) return;

    while (true) {

        //Validamos la existencia del cliente
        int posCliente = a.buscarporDNI(dnicliente);
        if (posCliente == -1) {
            cout << "Cliente no encontrado. Ingrese uno válido o 0 para salir: ";
            cin >> dnicliente;
            if (dnicliente == 0) return;
            continue;
        }

        //Validamos estado del cliente
        if (!a.estadoCliente(dnicliente)) {
            cout << "El cliente está INACTIVO. Reactívelo antes de continuar.\n";
            cout << "Ingrese otro DNI o 0 para salir: ";
            cin >> dnicliente;
            if (dnicliente == 0) return;
            continue;
        }

        //Listamos todas las mascotas del cliente
        cout << "\n--- MASCOTAS DEL CLIENTE ---\n";
        arch.listarMascotaporDueno(dnicliente);

        cout << "\nIngrese ID de la mascota a reactivar (0 para salir): ";
        int idMascota;
        cin >> idMascota;

        if (idMascota == 0) return;

        //Buscamos la mascota por ID
        int posMascota = arch.buscarPorId(idMascota);
        if (posMascota == -1) {
            cout << "ID de mascota inexistente.\n";
            continue;
        }

        Mascota reg;
        arch.leerMascota(posMascota, reg);

        //Verificamos que la mascota pertenece al cliente
        if (reg.getIdClienteDueno() != dnicliente) {
            cout << "La mascota NO pertenece a ese cliente.\n";
            continue;
        }

        //Verificamos que la mascota esté inactiva
        if (reg.getEstadoMascota()) {
                cout << "La mascota ya está ACTIVA.\n";
            continue;
        }

        cout << "\nMascota seleccionada:\n";
        arch.mostrarMascota(posMascota, reg);

        cout << "\n¿Confirmar reactivación? (1=SI / 0=NO): ";
        int confirmacion;
        cin >> confirmacion;

        if (confirmacion !=1) {
            cout << "Operación cancelada.\n";
            system("pause");
            return;
        }

        // Reactivar
        reg.setEstadoMascota(true);

        if (arch.modificarMascota(posMascota, reg))
            cout << "Mascota reactivada correctamente.\n";
        else
            cout << "ERROR al modificar el registro.\n";

        system("pause");
        return;
    }
}
/* LISTADO DE MASCOTAS ============================================================================ */

void ManagerMascota::menuListadoMascotas(){

    MascotaArchivo arch;
    int opc;
    do {
        system ("cls");
        cout << "----LISTADOS DE MASCOTAS----"<<endl;
        cout << "1. Listar mascotas por ID" << endl;
        cout << "2. Listar mascotas por fecha de nacimiento" << endl;
        cout << "3. Listar mascotas por ID de raza" << endl;
        cout << "4. Listar mascotas por sexo" << endl;
        cout << "5. Listar mascotas por DNI cliente" << endl;
        cout << "6. Listar mascotas por estado" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: " << endl;
        cin >> opc;

        switch (opc) {
            case 1:
                int idMascota;
                cout << "LISTAR MASCOTAS POR ID" << endl;
                cout << "Ingrese ID mascota: " << endl;
                cin >>idMascota;
                arch.listarMascotasporID(idMascota);
                break;
            case 2:
                Fecha fechaMascota;
                int dia, mes, anio;

                cout << "LISTAR MASCOTA POR FECHA DE NACIMIENTO" <<endl;
                cout << "Ingrese Fecha " << endl;
                cout << "Ingrese Dia:" << endl;
                cin >> dia;
                fechaMascota.setDia(dia);
                cout << "Ingrese Mes:" << endl;
                cin >> mes;
                fechaMascota.setMes(mes);
                cout << "Ingrese Anio:" << endl;
                cin >> anio;
                fechaMascota.setAnio(anio);
                arch.listarMascotasporFechaNac(fechaMascota);
                break;
            case 3:
                int idRaza;
                cout << "LISTAR MASCOTAS POR ID RAZA" << endl;
                cout << "Ingrese Id raza: " << endl;
                cin >>idRaza;
                arch.listarMascotasporIDraza(idRaza);
                break;
            case 4:
                {

                char sexo;
                bool valido = false;

                cout << "LISTAR MASCOTAS POR SEXO" << endl;

                do {
                cout << "Ingrese sexo (M/H): ";
                cin >> sexo;

                if (sexo == 'm') sexo = 'M';
                if (sexo == 'h') sexo = 'H';


                if (sexo == 'M' || sexo == 'H') {
                valido = true;
                }
                else {
                cout << "Sexo incorrecto. Intente nuevamente." << endl;
                system("pause");
                }

                } while (!valido);
                arch.listarMascotasporSexo(sexo);
                break;
                }

            case 5:
                int dni;
                cout << "LISTAR MASCOTAS POR DNI DUENO" << endl;
                cout << "Ingrese DNI del dueño: " << endl;
                cin >> dni;
                arch.listarMascotaporDueno(dni);
                break;

            case 6:
                bool estado;
                int aux;
                cout << "LISTAR MASCOTAS POR ESTADO" << endl;
                cout << "Ingrese estado: " << endl;
                cout << "1. Estado Inactivo" << endl;
                cout << "2. Estado Activo" << endl;
                cin >> aux;
                if(aux == 1 || aux == 2){
                estado = aux - 1 ;
                arch.listarMascotasporEstado(estado);}
                else {
                cout << "Estado incorrecto. Ingrese nuevamente" << endl;
                }
                break;
        }
    } while(opc != 0);

    system ("pause");
}

void ManagerMascota::listarMascotasporID(int idmascota){
    MascotaArchivo arch;
    arch.listarMascotasporID(idmascota);
}
void ManagerMascota::listarMascotasporFechaNac(Fecha fechaMascota){
    MascotaArchivo arch;
    arch.listarMascotasporFechaNac(fechaMascota);
}
void ManagerMascota::listarMascotasporIDraza(int idraza){
    MascotaArchivo arch;
    arch.listarMascotasporIDraza(idraza);
}
void ManagerMascota::listarMascotasporSexo(char sexo){
    MascotaArchivo arch;
    arch.listarMascotasporSexo(sexo);
}
void ManagerMascota::listarMascotasporEstado(bool estado){
    MascotaArchivo arch;
    arch.listarMascotasporEstado(estado);
}

void ManagerMascota::listarMascotas() {
    MascotaArchivo arch;
    arch.listarTodos();
    system("pause");
}

void ManagerMascota::listarMascotasporDni(int dniDueno){
    MascotaArchivo arch;
    arch.listarMascotaporDueno(dniDueno);
    system("pause");

}

void ManagerMascota::bajaMascota() {
    MascotaArchivo arch;
    ClientesArchivo a;

    cout << "INGRESE DNI DEL CLIENTE DUENO (0 para volver): ";
    int dnicliente;
    cin >> dnicliente;

    if (dnicliente == 0) return;

    while (true) {

        // Validar existencia del cliente
        int posCliente = a.buscarporDNI(dnicliente);
        if (posCliente == -1) {
            cout << "Cliente no encontrado. Ingrese uno valido o 0 para salir: ";
            cin >> dnicliente;
            if (dnicliente == 0) return;
            continue;
        }

        // Validar estado del cliente
        if (!a.estadoCliente(dnicliente)) {
            cout << "El cliente está INACTIVO. Reactívelo antes de continuar.\n";
            cout << "Ingrese otro DNI o 0 para salir: ";
            cin >> dnicliente;
            if (dnicliente == 0) return;
            continue;
        }

        // Listar mascotas del cliente
        cout << "\n--- MASCOTAS DEL CLIENTE ---\n";
        arch.listarMascotaporDueno(dnicliente);

        cout << "\nIngrese ID de la mascota a dar de baja (0 para salir): ";
        int idmascota;
        cin >> idmascota;

        if (idmascota == -1) return;

        // Buscar mascota por ID
        int posMascota = arch.buscarPorId(idmascota);
        if (posMascota == -1) {
            cout << "ID de mascota inexistente.\n";
            continue;
        }

        Mascota reg;
        arch.leerMascota(posMascota, reg);

        // Verificar si ya está inactiva
        if (!reg.getEstadoMascota()) {
            cout << "La mascota ya está INACTIVA.\n";
            continue;
        }

        cout << "\nMascota seleccionada:\n";
        arch.mostrarMascota(posMascota, reg);

        cout << "\n¿Confirmar baja? (1=SI / 0=NO): ";
        int confirmacion;
        cin >> confirmacion;

        if (confirmacion != 1) {
            cout << "Operación cancelada.\n";
            system("pause");
            return;
        }

        // Aplicar baja lógica
        reg.setEstadoMascota(false);

        if (arch.modificarMascota(posMascota, reg))
            cout << "Mascota dada de baja correctamente.\n";
        else
            cout << "ERROR al modificar el registro.\n";

        system("pause");
        return;
    }
}
