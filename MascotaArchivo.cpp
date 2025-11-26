# include <iostream>
# include <cstdlib>
# include <cstring>
# include "MascotaArchivo.h"


using namespace std;

const char* MascotaArchivo::getNombreArchivo(){
return _nombreArchivo;
}

int MascotaArchivo::buscarPorId(int id){
    Mascota reg;
    int pos=0;
    FILE* p=fopen(_nombreArchivo,"rb");
    if(p==nullptr)return -1;
    while(fread(&reg,sizeof(Mascota),1,p)){
        if(reg.getIdMascota()==id){
            fclose(p);
            return pos;
        }
        pos++;
    }
return -1;
}

int MascotaArchivo::contarRegistros(){

    FILE* p=fopen(_nombreArchivo,"rb");
    if (p==nullptr) return -1;
    fseek(p,0,SEEK_END);
    int tamanio=ftell(p);
    fclose(p);
    int cantidadRegistros=tamanio/sizeof(Mascota);
    return cantidadRegistros;
}

int MascotaArchivo::generarNuevoID() {
    return contarRegistros() + 1;
}


//cargar cadena------------------------------------------
void MascotaArchivo::cargarCadena(char *palabra, int tam){
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

bool MascotaArchivo::guardarMascota(const Mascota &reg) {
    FILE *p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) {
            cout<<"Error al cargar";
            return false;}

    bool ok = fwrite(&reg, sizeof(Mascota), 1, p);
    fclose(p);
    return ok;
}
int MascotaArchivo::calcularEdad(int dia, int mes, int anio) {
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

bool MascotaArchivo::cargarMascota(int dni) {
    Mascota reg;
    char nombre[20];
    Fecha fecha;

    char sexo;

    reg.setDniClienteDueno(dni);

    reg.setIdMascota(generarNuevoID());

    cout << "Nombre de la mascota: ";
    cargarCadena(nombre, sizeof(nombre));
    reg.setNombreMascota(nombre);//validar

    cout << "Fecha de nacimiento:\n";

    cout << "Fecha de nacimiento (DD MM AAAA): ";
        int d, m, a;
        cin >> d >> m >> a;
        //comprobamos si es correcta la fecha
        while (!fecha.fechaValida(d, m, a)) {
        cout << "Fecha INVALIDA. Coloque otra fecha respetando el formato.\n";
        cout << "Ingrese nuevamente (DD MM AAAA): ";
        cin >> d >> m >> a;

        }
        fecha.setDia(d);
        fecha.setMes(m);
        fecha.setAnio(a);
        reg.setFechaNac(fecha);

        // Calculo de edad de forma automática
        int edad = calcularEdad(d, m, a);
        cout << "Edad: " << edad << endl;
        reg.setEdad(edad);

       reg.setFechaNac(fecha);
       cout << "Ingrese sexo de Mascota (M/H): ";

        cin >> sexo;




    if (sexo != 'M' && sexo != 'H') {
    cout << "Sexo inválido, guardando como 'M' por defecto.\n";
    sexo = 'M';
    }

reg.setSexoAnimal(sexo);



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

    if (animal == 0) continue; // vuelve a lo anterior

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
}while (animal != 1 && animal != 2);


    reg.setEstadoMascota(true);


    if (guardarMascota(reg)) {

        cout << "\nMascota guardada correctamente.\n";
        system("pause");
        return true;
    } else {
        cout << "\nError al guardar la mascota.\n";
        system("pause");
        return false;
    }




    cout<<"------------------------------------------"<<endl;
   cout<<"ID Mascota: "<<reg.getIdMascota()<<endl;
    cout<<"Nombre Mascota: "<<reg.getNombreMascota()<<endl;

    cout<<"Fecha de Nacimiento: ";
    reg.getFechaNac().mostrar();
    cout<<endl;

    cout<<"ID Raza: "<<reg.getIdRaza()<<endl;
    cout<< "Sexo: "<<reg.getSexoAnimal()<< endl;
    cout<<"ID Cliente Dueño: "<<reg.getIdClienteDueno()<<endl;
    cout<<"DNI Cliente Dueño: "<<reg.getDniClienteDueno()<<endl;
    cout<<"Estado Mascota: "<<(reg.getEstadoMascota() ? "Activo" : "Inactivo")<<endl;
    cout<<"------------------------------------------"<<endl;
}

void MascotaArchivo::mostrarMascota(int pos, const Mascota &reg) {
    cout << "----------------------------------------" << endl;
    cout << "POSICION EN ARCHIVO: " << pos << endl;
    cout << "ID MASCOTA: " << reg.getIdMascota() << endl;
    cout << "NOMBRE: " << reg.getNombreMascota() << endl;

    cout << "FECHA DE NACIMIENTO: ";
    reg.getFechaNac().mostrar();
    cout << endl;

    cout << "ID RAZA: " << reg.getIdRaza() << endl;
    cout << "SEXO: " << reg.getSexoAnimal() << endl;
    cout << "ID CLIENTE DUEÑO: " << reg.getIdClienteDueno() << endl;
    cout << "DNI CLIENTE DUEÑO: " << reg.getDniClienteDueno() << endl;

    cout << "ESTADO: ";
    if (reg.getEstadoMascota()) {
        cout << "ACTIVA";
    } else {
        cout << "INACTIVA";
    }
    cout << endl;

    cout << "----------------------------------------" << endl;
}
/*----------------------------------------------------------------*/
bool MascotaArchivo::leerMascota(int pos, Mascota &reg) {
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return false;

    fseek(p, pos * sizeof(Mascota), SEEK_SET);
    bool ok = fread(&reg, sizeof(Mascota), 1, p);
    fclose(p);

    return ok;
}
/*----------------------------------------------------------------*/


bool MascotaArchivo::modificarMascota(int pos, const Mascota &reg) {
    FILE *p = fopen(_nombreArchivo, "rb+"); //lectura y escritura
    if (p == nullptr) return false;

    fseek(p, pos * sizeof(Mascota), SEEK_SET); //Nos movemos a la posición exacta

    bool escribio = fwrite(&reg, sizeof(Mascota), 1, p); //Sobrescribe el registro

    fclose(p);
    return escribio;
}
bool MascotaArchivo::modificar(int pos) {
    Mascota reg;

    // 1) Lee registro existente
    if (!leerMascota(pos, reg)) {
        cout << "NO SE PUDO LEER EL REGISTRO." << endl;
        return false;
    }

    // 2) Mostramos los datos actuales
    cout << "===== MODIFICAR MASCOTA =====" << endl;
    mostrarMascota(pos, reg);

    int opcion;

    do {
        cout << "\n--- MENU MODIFICACION ---\n";
        cout << "1. Modificar nombre\n";
        cout << "2. Modificar fecha de nacimiento\n";
        cout << "3. Modificar ID raza\n";
        cout << "4. Modificar sexo\n";
        cout << "5. Modificar ID del dueño\n";
        cout << "6. Modificar DNI del dueño\n";
        cout << "7. Cambiar estado (activo/inactivo)\n";
        cout << "8. Guardar y salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1: {
            char nombre[20];
            cout << "Nuevo nombre: ";
            cargarCadena(nombre, 20);
            reg.setNombreMascota(nombre);
            break;
        }

        case 2: {
            Fecha f;
            cout << "Nueva fecha de nacimiento:\n";
            f.cargar();
            reg.setFechaNac(f);
            break;
        }

        case 3: {
            int idRaza;
            cout << "Nuevo ID de raza: ";
            cin >> idRaza;
            reg.setIdRaza(idRaza);
            break;
        }

        case 4: {
            char sexo;
            cout << "Nuevo sexo (M/H): ";
            cin >> sexo;

            if (sexo == 'M' || sexo == 'H')
                reg.setSexoAnimal(sexo);
            else
                cout << "Valor inválido, no se modifica.\n";

            break;
        }

        case 5: {
            int idC;
            cout << "Nuevo ID de dueño: ";
            cin >> idC;
            reg.setIdClienteDueno(idC);
            break;
        }

        case 6: {
            int dnidueno;
            cout << "Nuevo DNI de dueño: ";
            cin >> dnidueno;
            reg.setDniClienteDueno(dnidueno);

            break;
        }

        case 7: {
            bool nuevoEstado;
            cout << "Estado (1 = activo, 0 = inactivo): ";
            cin >> nuevoEstado;
            reg.setEstadoMascota(nuevoEstado);
            break;
        }
        case 8:
            cout << "Guardando cambios...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
            break;
        }

    } while (opcion != 7);

    // 3) Guardamos los cambios en archivo
    return modificarMascota(pos, reg);
}
/*--------------------------------------------------------*/
void MascotaArchivo::listarTodos() {
    int cant=contarRegistros();
    if (cant==-1) {
        cout << "No se pudo abrir el archivo de mascotas.\n";
        return;
    }

    Mascota reg;

    for (int i = 0; i < cant; i++) {
        if (leerMascota(i, reg)) {
            if (reg.getEstadoMascota()) {   // solo activas
                mostrarMascota(i, reg);
            }
        }
    }

    system("pause");
}
/*------------------------------------------------------------------*/
void MascotaArchivo::listarMascotaporDueno(int dniDueno) {
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) {
        cout << "NO PUDO ABRIR EL ARCHIVO MASCOTAS\n";
        return;
    }

    Mascota r;
    bool encontrado = false;

    while (fread(&r, sizeof(Mascota), 1, p) == 1) {

        if (r.getDniClienteDueno() == dniDueno && r.getEstadoMascota()) {

            cout << "Nombre Mascota: " << r.getNombreMascota() << endl;
            cout << "Fecha nacimiento: "
                 << r.getFechaNac().getDia() << "/"
                 << r.getFechaNac().getMes() << "/"
                 << r.getFechaNac().getAnio() << endl;

            cout << "Sexo: " << r.getSexoAnimal() << endl;
            cout << "ID Mascota: " << r.getIdMascota() << endl;
            cout << "ID Raza: " << r.getIdRaza() << endl;
            cout << "--------------------------" << endl;

            encontrado = true;
        }
    }

    fclose(p);

    if (!encontrado) {
        cout << "El cliente no tiene mascotas registradas o activas.\n";
    }
}



/*------------------------------------------------------------------*/
bool MascotaArchivo::eliminar(int pos) {
    Mascota reg;

    // 1) Leemos primero el registro
    if (!leerMascota(pos, reg)) {
        cout << "NO SE PUDO LEER EL REGISTRO." << endl;
        return false;
    }

    // 2) Cambiar el estado
    reg.setEstadoMascota(false);

    // 3) Sobrescribimos el registro con el estado actualizado
    if (!modificarMascota(pos, reg)) {
        cout << "NO SE PUDO ESCRIBIR EL REGISTRO." << endl;
        return false;
    }

    cout << "MASCOTA ELIMINADA (ESTADO = FALSE)." << endl;
    return true;
}

