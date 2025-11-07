# include <iostream>
# include <cstdlib>
# include <cstring>
# include "MascotaArchivo.h"


using namespace std;

/*
    const char* getNombreArchivo();

    int buscarPorId(int id);
    int contarRegistros();

    void cargarCadena(char *palabra, int tam);
    void listarTodos();
    void eliminar(int pos);
    void mostrarMascota(int pos, const Mascota &reg);

    bool modificar(int pos);
    bool cargarMascota(const Mascota &reg);
    bool modificarMascota(int pos, const Mascota &reg);
*/
const char* MascotaArchivo::getNombreArchivo(){
return _nombreArchivo;
}

int MascotaArchivo::buscarPorId(int id){
    Mascota reg;
    int pos=0;
    FILE* p=fopen(_nombreArchivo,"rb");
    if(p==nullptr)return 1;
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
    reg.setNombreMascota(nombre);

    cout << "Fecha de nacimiento:\n";
    fecha.cargar();
    reg.setFechaNac(fecha);

    // id de raza
    cout << "ID de raza: ";
    cin >> idRaza;
    reg.setIdRaza(idRaza);

    // sexo
    cout << "Sexo del animal (M/H): ";
    cin >> sexo;
    if (sexo != 'M' && sexo != 'H') {
        cout << "Sexo inválido, guardando como 'M' por defecto.\n";
        sexo = 'M';
    }
    reg.setSexoAnimal(sexo);

    // id dueño
    cout << "ID del cliente duenio: ";
    cin >> idDueno;
    reg.setIdClienteDueno(idDueno);

    reg.setEstadoMascota(true);


    if (cargarMascota()) {
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


bool MascotaArchivo::modificar(int pos) {
    Mascota reg;
    FILE *p=fopen("Mascotas.dat", "rb+"); //Abre el archivo para lectura+escritura
    if (p==nullptr) return false;//si no lo puede abrir da falso

    fseek(p,pos*sizeof(Mascota),SEEK_SET);//va a la posición del reg en el archivo
    fread(&reg, sizeof(Mascota), 1, p);// lo lee y lo carga en reg

    //Muestra el reg que vamos a modificar********* tengo que crear
    cout << "Registro actual:\n";
    mostrarMascota(pos, reg);

    cout << "\nIngrese los nuevos datos:\n";
    cargarMascota();  //Tengo que crear***

    //va de nuevo posición del registro para sobrescribirlo
    fseek(p, pos * sizeof(Mascota), SEEK_SET);

    bool ok = fwrite(&reg, sizeof(Mascota), 1, p);//creo una var booleana para devolver si es que carga true o false

    fclose(p);
    return ok;
}
