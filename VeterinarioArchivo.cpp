# include<iostream>
# include<cstdlib>
# include<cstring>
# include "VeterinarioArchivo.h"

using namespace std;

int VeterinarioArchivo::contarRegistros() {
    FILE* p=fopen(_nombreArchivo,"rb");
    if(p == nullptr) return -1;

    fseek(p, 0, SEEK_END);
    int tam = ftell(p);
    fclose(p);

    return tam/sizeof(Veterinario);
}

int VeterinarioArchivo::generarNuevoID() {
    return contarRegistros()+1;
}

void VeterinarioArchivo::cargarCadena(char *palabra, int tam){
    fflush(stdin);
    int i=0;
    for (i=0;i< tam;i++) {
        palabra[i]=cin.get();
        if (palabra[i]=='\n')break;
    }
    palabra[i]='\0';
    fflush(stdin);
}

bool VeterinarioArchivo::cargarVet(const Veterinario &reg) {
    FILE* p= fopen(_nombreArchivo, "ab");
    if(p==nullptr) return false;

    bool ok=fwrite(&reg,sizeof(Veterinario),1,p);
    fclose(p);
    return ok;
}
int VeterinarioArchivo::buscarMatriculaVet(int matVet){
    Veterinario reg;
    int pos = 0;
    FILE *p = fopen (_nombreArchivo,"rb");
    if (p==nullptr) return -1;
    while (fread(&reg, sizeof(Veterinario),1,p)){
        if (reg.getMatriculaVet()==matVet){
            fclose(p);
            return pos;
        }
    pos++;
    }
return -1;
}


int VeterinarioArchivo::buscarporDNI(int DNI){
    Veterinario reg;
    int pos = 0;
    FILE *p = fopen (_nombreArchivo,"rb");
    if (p==nullptr) return -1;
    while (fread(&reg, sizeof(Veterinario),1,p)){
        if (reg.getDNI()==DNI){
            fclose(p);
        }
        return pos;
    pos++;
    }
return -1;
}

int VeterinarioArchivo::buscarPorMatricula(int matricula){
    Veterinario reg;
    FILE *p = fopen(_nombreArchivo, "rb");
    if(p == NULL) return -1;

    int pos = 0;
    while(fread(&reg, sizeof reg, 1, p)){
        if(reg.getMatriculaVet() == matricula){
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}


bool VeterinarioArchivo::cargarVet() {
    Veterinario reg;
    char nombre[30],apellido[30],telefono[20],email[40];
    int dni;
    Direccion dir;
    Fecha fechaIngreso;
    int matricula;

    reg.setId(generarNuevoID());

    bool valido = false;

do {
    cout<<"DNI: ";
    cin >> dni;
    int auxDNI = buscarporDNI(dni);
    if(auxDNI==dni){
    reg.setDNI(dni);
    valido = true;
    } else{
    cout<<"EL VETERINARIO YA EXISTE.. "<<endl;
    }
} while(!valido);

    cout<<"NOMBRE: ";
    cargarCadena(nombre,30);
    reg.setNombre(nombre);

    cout<<"APELLIDO: ";
    cargarCadena(apellido,30);
    reg.setApellido(apellido);

    cout<<"DIRECCION:\n";
    dir.cargarDireccion();
    reg.setDireccion(dir);

    cout<<"TELEFONO: ";
    cargarCadena(telefono,20);
    reg.setTelefono(telefono);

    cout<<"EMAIL: ";
    cargarCadena(email,40);
    reg.setEmail(email);

    cout<<"MATRICULA: ";
    cin>>matricula;
    reg.setMatriculaVet(matricula);

    cout<<"FECHA DE INGRESO:\n";
    fechaIngreso.cargar();
    reg.setFechaIngresoVet(fechaIngreso);

    int idUsuario;
    cout << "ID del usuario asociado: ";
    cin >> idUsuario;
    reg.setIdUsuarioAsociado(idUsuario);

    reg.setEstado(true);

    if(cargarVet(reg)){
        cout<<"VETERINARIO GUARDADO.\n";
        return true;
    }

    cout<<"ERROR AL GUARDAR.\n";
    return false;
}

bool VeterinarioArchivo::leerVet(int pos, Veterinario &reg) {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return false;

    fseek(p,pos*sizeof(Veterinario),SEEK_SET);
    bool ok=fread(&reg,sizeof(Veterinario),1,p);

    fclose(p);

    return ok;
}

void VeterinarioArchivo::mostrarVeterinario(int pos, const Veterinario &reg) {
    cout<<"------------------------------\n";
    cout<<"POSICION: "<<pos<<endl;
    cout<<"ID VETERINARIO: "<<reg.getID()<<endl;
    cout<<"ID USUARIO ASOCIADO: "<<reg.getIdUsuarioAsociado()<<endl;
    cout<<"NOMBRE: "<<reg.getNombre()<<endl;
    cout<<"APELLIDO: "<<reg.getApellido()<<endl;
    cout<<"DNI: "<<reg.getDNI()<<endl;

    cout<<"FECHA DE INGRESO: ";
    reg.getFechaIngreso().mostrar();
    cout<<endl;

    cout<<"MATRICULA: "<<reg.getMatriculaVet()<<endl;

    cout<<"ESTADO: "<<(reg.getEstado() ? "ACTIVO" : "INACTIVO")<<endl;
    cout<<"------------------------------\n";
}

void VeterinarioArchivo::listarTodos() {
    Veterinario reg;
    FILE* p=fopen(_nombreArchivo, "rb");
    if (p==nullptr) {
        cout << "NO SE PUEDE ABRIR EL ARCHIVO.\n";
        return;
    }

    int pos=0;
    while (fread(&reg, sizeof(Veterinario),1,p)){
        if (reg.getEstado()){
            mostrarVeterinario(pos, reg);
        }
        pos++;
    }

    fclose(p);
}

int VeterinarioArchivo::buscarPorId(int id) {
    Veterinario reg;
    int pos = 0;

    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return -1;

    while (fread(&reg, sizeof(Veterinario), 1, p)) {
        if (reg.getID() == id) {
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1; // No encontrado
}


bool VeterinarioArchivo::modificarVet(int pos, const Veterinario &reg) {
    FILE* p=fopen(_nombreArchivo, "rb+");
    if (p==nullptr) return false;

    fseek(p,pos*sizeof(Veterinario),SEEK_SET);
    bool ok=fwrite(&reg,sizeof(Veterinario),1,p);

    fclose(p);
    return ok;
}


bool VeterinarioArchivo::eliminar(int pos) {
    Veterinario reg;

    if(!leerVet(pos,reg))return false;

    reg.setEstado(false);

    return modificarVet(pos,reg);
}

bool VeterinarioArchivo::modificar(int pos) {
    Veterinario reg;

    //1) Leemos registro actual
    if (!leerVet(pos, reg)) {
        cout<<"NO SE PUDO LEER EL REGISTRO."<<endl;
        return false;
    }

    //2) Mostramos datos actuales
    cout<<"===== MODIFICAR VETERINARIO ====="<<endl;
    mostrarVeterinario(pos, reg);

    int opcion;

    do {
        cout<<"\n--- MENU DE MODIFICACION ---\n";
        cout<<"1. Modificar nombre\n";
        cout<<"2. Modificar apellido\n";
        cout<<"3. Modificar DNI\n";
        cout<<"4. Modificar direccion\n";
        cout<<"5. Modificar telefono\n";
        cout<<"6. Modificar email\n";
        cout<<"7. Modificar matricula\n";
        cout<<"8. Modificar fecha de ingreso\n";
        cout<<"9. Cambiar estado (activo/inactivo)\n";
        cout<<"10. Modificar ID de usuario asociado\n";
        cout<<"11. Guardar y salir\n";
        cout<<"Seleccione opcion: ";
        cin>>opcion;

        switch(opcion){

        case 1:{
            char nombre[30];
            cout<<"Nuevo nombre: ";
            cargarCadena(nombre, 30);
            reg.setNombre(nombre);
            break;
        }

        case 2:{
            char apellido[30];
            cout<<"Nuevo apellido: ";
            cargarCadena(apellido,30);
            reg.setApellido(apellido);
            break;
        }

        case 3:{
            int dni;
            cout << "Nuevo DNI: ";
            cin >> dni;
            reg.setDNI(dni);
            break;
        }

        case 4: {
            Direccion dir;
            cout<<"Nueva direccion:\n";
            dir.cargarDireccion();
            reg.setDireccion(dir);
            break;
        }

        case 5:{
            char telefono[20];
            cout<<"Nuevo telefono: ";
            cargarCadena(telefono, 20);
            reg.setTelefono(telefono);
            break;
        }

        case 6:{
            char email[40];
            cout<<"Nuevo email: ";
            cargarCadena(email,40);
            reg.setEmail(email);
            break;
        }

        case 7:{
            int matricula;
            cout<<"Nueva matricula: ";
            cin>>matricula;
            reg.setMatriculaVet(matricula);
            break;
        }

        case 8:{
            Fecha f;
            cout<<"Nueva fecha de ingreso:\n";
            f.cargar();
            reg.setFechaIngresoVet(f);
            break;
        }

        case 9:{
            bool estado;
            cout<<"Estado (1 = activo, 0 = inactivo): ";
            cin>>estado;
            reg.setEstado(estado);
            break;
        }

        case 10: {

            int nuevoIDU;
            cout << "Nuevo ID de usuario asociado: ";
            cin >> nuevoIDU;
            reg.setIdUsuarioAsociado(nuevoIDU);
            break;
            }

            case 11:
            cout<<"Guardando cambios...\n";
            break;

        default:
            cout<<"OPCION INVALIDA. Intente otra vez.\n";
            break;
        }

    } while(opcion != 11);

    //3) Guardamos cambios
    return modificarVet(pos,reg);
}

void VeterinarioArchivo::listarVetporDNI(int dniVet){
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) {
        cout << "NO PUDO ABRIR EL ARCHIVO VETERINARIOS\n";
        return;
}
    Veterinario r;
    bool encontrado = false;

    system ("cls");
    while (fread(&r, sizeof(Veterinario), 1, p) == 1){
        if (r.getDNI()==dniVet){
           cout << "Estado Veterinario: " << (r.getEstado() ? "Activo" : "Inactivo")  << endl;
           cout << "Nombre Veterinario: " << r.getNombre() << endl;
           cout << "Apellido Veterinario: " << r.getApellido() << endl;
           cout << "DNI Veterinario: " << r.getDNI() << endl;
           cout << "Matricula veterinario: " << r.getMatriculaVet() << endl;
           cout << "ID Veterinario: " << r.getID() << endl;
           cout << "Telefono Veterinario: " << r.getTelefono() << endl;
           cout << "Email: " << r.getEmail() << endl;
           cout << "Fecha de ingreso: " << r.getFechaIngreso().getDia() << "/" << r.getFechaIngreso().getMes() << "/" << r.getFechaIngreso().getAnio() << endl;
           // Direccion
           Direccion dir = r.getDireccion();
           cout << "Direccion Veterinario: " << endl;
           cout << "Ciudad: " << dir.getCiudad() << endl;
           cout << "Calle: " << dir.getCalle() << "Altura: " << dir.getAltura() << endl;
           cout << "Cod. Postal: " << dir.getCodPostal() << endl;


            encontrado = true;
        }
    }

    fclose(p);
    if(!encontrado){
        cout << "No se encontro veterinario con ese dni" << endl;
        system ("pause");
        return;
    }
    system ("pause");
}


void VeterinarioArchivo::listarVetporID(int idVet){
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) {
        cout << "NO PUDO ABRIR EL ARCHIVO VETERINARIOS\n";
        return;
}
    Veterinario r;
    bool encontrado = false;

    system ("cls");
    while (fread(&r, sizeof(Veterinario), 1, p) == 1){
        if (r.getID()==idVet){
           cout << "Estado Veterinario: " << (r.getEstado() ? "Activo" : "Inactivo")  << endl;
           cout << "Nombre Veterinario: " << r.getNombre() << endl;
           cout << "Apellido Veterinario: " << r.getApellido() << endl;
           cout << "DNI Veterinario: " << r.getDNI() << endl;
           cout << "Matricula veterinario: " << r.getMatriculaVet() << endl;
           cout << "ID Veterinario: " << r.getID() << endl;
           cout << "Telefono Veterinario: " << r.getTelefono() << endl;
           cout << "Email: " << r.getEmail() << endl;
           cout << "Fecha de ingreso: " << r.getFechaIngreso().getDia() << "/" << r.getFechaIngreso().getMes() << "/" << r.getFechaIngreso().getAnio() << endl;
           // Direccion
           Direccion dir = r.getDireccion();
           cout << "Direccion Veterinario: " << endl;
           cout << "Ciudad: " << dir.getCiudad() << endl;
           cout << "Calle: " << dir.getCalle() << "Altura: " << dir.getAltura() << endl;
           cout << "Cod. Postal: " << dir.getCodPostal() << endl;


            encontrado = true;
        }
    }

    fclose(p);
    if(!encontrado){
        cout << "No se encontro veterinario con ese ID" << endl;
        system ("pause");
        return;
    }
    system ("pause");
}

void VeterinarioArchivo::listarVetporMat(int MatVet){
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) {
        cout << "NO PUDO ABRIR EL ARCHIVO VETERINARIOS\n";
        return;
}
    Veterinario r;
    bool encontrado = false;

    system ("cls");
    while (fread(&r, sizeof(Veterinario), 1, p) == 1){
        if (r.getMatriculaVet()==MatVet){
           cout << "Estado Veterinario: " << (r.getEstado() ? "Activo" : "Inactivo")  << endl;
           cout << "Nombre Veterinario: " << r.getNombre() << endl;
           cout << "Apellido Veterinario: " << r.getApellido() << endl;
           cout << "DNI Veterinario: " << r.getDNI() << endl;
           cout << "Matricula veterinario: " << r.getMatriculaVet() << endl;
           cout << "ID Veterinario: " << r.getID() << endl;
           cout << "Telefono Veterinario: " << r.getTelefono() << endl;
           cout << "Email: " << r.getEmail() << endl;
           cout << "Fecha de ingreso: " << r.getFechaIngreso().getDia() << "/" << r.getFechaIngreso().getMes() << "/" << r.getFechaIngreso().getAnio() << endl;
           // Direccion
           Direccion dir = r.getDireccion();
           cout << "Direccion Veterinario: " << endl;
           cout << "Ciudad: " << dir.getCiudad() << endl;
           cout << "Calle: " << dir.getCalle() << "Altura: " << dir.getAltura() << endl;
           cout << "Cod. Postal: " << dir.getCodPostal() << endl;


            encontrado = true;
        }
    }

    fclose(p);
    if(!encontrado){
        cout << "No se encontro veterinario con esa matricula" << endl;
        system ("pause");
        return;
    }
    system ("pause");
}

void VeterinarioArchivo::listarVetporEstado(bool estadoVet){
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) {
        cout << "NO PUDO ABRIR EL ARCHIVO VETERINARIOS\n";
        return;
}
    Veterinario r;
    bool encontrado = false;

    system ("cls");
    while (fread(&r, sizeof(Veterinario), 1, p) == 1){
        if (r.getEstado()==estadoVet){
           cout << "Estado Veterinario: " << (r.getEstado() ? "Activo" : "Inactivo") << endl;
           cout << "Nombre Veterinario: " << r.getNombre() << endl;
           cout << "Apellido Veterinario: " << r.getApellido() << endl;
           cout << "DNI Veterinario: " << r.getDNI() << endl;
           cout << "Matricula veterinario: " << r.getMatriculaVet() << endl;
           cout << "ID Veterinario: " << r.getID() << endl;
           cout << "Telefono Veterinario: " << r.getTelefono() << endl;
           cout << "Email: " << r.getEmail() << endl;
           cout << "Fecha de ingreso: " << r.getFechaIngreso().getDia() << "/" << r.getFechaIngreso().getMes() << "/" << r.getFechaIngreso().getAnio() << endl;
           // Direccion
           Direccion dir = r.getDireccion();
           cout << "Direccion Veterinario: " << endl;
           cout << "Ciudad: " << dir.getCiudad() << endl;
           cout << "Calle: " << dir.getCalle() << "Altura: " << dir.getAltura() << endl;
           cout << "Cod. Postal: " << dir.getCodPostal() << endl;
           cout << "====================================" << endl;


            encontrado = true;
        }
    }

    fclose(p);
    if(!encontrado){
        cout << "No se encontro veterinario con ese estado" << endl;
        system ("pause");
        return;
    }
    system ("pause");
}

void VeterinarioArchivo::listarVetporFechaIng(Fecha fechaIngresoVet){
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) {
        cout << "NO PUDO ABRIR EL ARCHIVO VETERINARIOS\n";
        return;
}
    Veterinario r;
    bool encontrado = false;

    system ("cls");
    while (fread(&r, sizeof(Veterinario), 1, p) == 1){
        if (r.getFechaIngreso().getDia() == fechaIngresoVet.getDia() &&
            r.getFechaIngreso().getMes() == fechaIngresoVet.getMes() &&
            r.getFechaIngreso().getAnio() == fechaIngresoVet.getAnio()
            ){
           cout << "Estado Veterinario: " << (r.getEstado() ? "Activo" : "Inactivo")  << endl;
           cout << "Nombre Veterinario: " << r.getNombre() << endl;
           cout << "Apellido Veterinario: " << r.getApellido() << endl;
           cout << "DNI Veterinario: " << r.getDNI() << endl;
           cout << "Matricula veterinario: " << r.getMatriculaVet() << endl;
           cout << "ID Veterinario: " << r.getID() << endl;
           cout << "Telefono Veterinario: " << r.getTelefono() << endl;
           cout << "Email: " << r.getEmail() << endl;
           cout << "Fecha de ingreso: " << r.getFechaIngreso().getDia() << "/" << r.getFechaIngreso().getMes() << "/" << r.getFechaIngreso().getAnio() << endl;
           // Direccion
           Direccion dir = r.getDireccion();
           cout << "Direccion Veterinario: " << endl;
           cout << "Ciudad: " << dir.getCiudad() << endl;
           cout << "Calle: " << dir.getCalle() << "Altura: " << dir.getAltura() << endl;
           cout << "Cod. Postal: " << dir.getCodPostal() << endl;


            encontrado = true;
        }
    }

    fclose(p);
    if(!encontrado){
        cout << "No se encontró veterinario con esa fecha de ingreso" << endl;
        system ("pause");
        return;
    }
    system ("pause");
}
