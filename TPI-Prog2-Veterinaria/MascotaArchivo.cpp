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

bool MascotaArchivo::cargarMascota(const Mascota &reg) {
    FILE *p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Mascota), 1, p);
    fclose(p);
    return ok;
}


bool MascotaArchivo::cargarMascota() {
    Mascota reg;
    char nombre[20];
    Fecha fecha;
    int idRaza;
    char sexo;
    int idDueno;

    reg.setIdMascota(generarNuevoID());

    cout << "Nombre de la mascota: ";
    cargarCadena(nombre, sizeof(nombre));
    reg.setNombreMascota(nombre);//validar

    cout << "Fecha de nacimiento:\n";
    fecha.cargar();//validar

    reg.setFechaNac(fecha);

    // id de raza
    cout << "ID de raza: ";
    cin >> idRaza;//validar

    reg.setIdRaza(idRaza);

    // sexo
    cout << "Sexo del animal (M/H): ";
    cin >> sexo;//validar

    if (sexo != 'M' && sexo != 'H') {
        cout << "Sexo inválido, guardando como 'M' por defecto.\n";
        sexo = 'M';
    }
    reg.setSexoAnimal(sexo);

    // id dueño
    cout << "ID del cliente duenio: ";
    cin >> idDueno;//validar

    reg.setIdClienteDueno(idDueno);

    reg.setEstadoMascota(true);


    if (cargarMascota(reg)) {
        cout << "\nMascota guardada correctamente.\n";
        return true;
    } else {
        cout << "\nError al guardar la mascota.\n";
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

    // 1) Leer registro existente
    if (!leerMascota(pos, reg)) {
        cout << "NO SE PUDO LEER EL REGISTRO." << endl;
        return false;
    }

    // 2) Mostrar datos actuales
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
        cout << "6. Cambiar estado (activo/inactivo)\n";
        cout << "7. Guardar y salir\n";
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
            bool nuevoEstado;
            cout << "Estado (1 = activo, 0 = inactivo): ";
            cin >> nuevoEstado;
            reg.setEstadoMascota(nuevoEstado);
            break;
        }

        case 7:
            cout << "Guardando cambios...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
            break;
        }

    } while (opcion != 7);

    // 3) Guardar cambios en archivo
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

bool MascotaArchivo::eliminar(int pos) {
    Mascota reg;

    // 1) Leer el registro
    if (!leerMascota(pos, reg)) {
        cout << "NO SE PUDO LEER EL REGISTRO." << endl;
        return false;
    }

    // 2) Cambiar su estado
    reg.setEstadoMascota(false);

    // 3) Sobrescribir el registro con el estado actualizado
    if (!modificarMascota(pos, reg)) {
        cout << "NO SE PUDO ESCRIBIR EL REGISTRO." << endl;
        return false;
    }

    cout << "MASCOTA ELIMINADA (ESTADO = FALSE)." << endl;
    return true;
}

