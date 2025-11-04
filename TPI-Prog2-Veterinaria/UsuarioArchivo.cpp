# include<iostream>
# include<cstdlib>
# include<cstring>
# include<cstdio>
# include "UsuarioArchivo.h"

using namespace std;
/*
    //getters
    const char* getNombreArchivo();
    //setters
    void setNombreArchivo(const char nomberArchivo);
    //métodos
    bool cargarUsuario(const Usuario &reg);
    bool modificarUsuario(int pos,const Usuario &reg);
    bool leerUsuario(int pos, Usuario &reg);
    void mostrarUsuario(int pos);
    int buscarPorId(int id);
    int contarRegistros();
    void listarTodos();
    bool eliminar(int id);
    bool modificar(int id);
*/
//getter
const char* UsuarioArchivo::getNombreArchivo() {
    return _nombreArchivo;
}
//setter
void UsuarioArchivo::setNombreArchivo(const char* nombreArchivo) {
    strncpy(_nombreArchivo,nombreArchivo,29);
    _nombreArchivo[29] = '\0';
}
//cargar cadena------------------------------------------
void UsuarioArchivo::cargarCadena(char *palabra, int tam){
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

//metodos
bool UsuarioArchivo::cargarUsuario(const Usuario &reg) {
    FILE* p=fopen(_nombreArchivo, "ab");
    if (p==nullptr) return false;
    bool escribio=fwrite(&reg,sizeof(Usuario),1,p);
    fclose(p);
    return escribio;
}

bool UsuarioArchivo::modificarUsuario(int pos,const Usuario &reg) {
    FILE* p = fopen(_nombreArchivo,"rb+");
    if (p == nullptr) return false;
    fseek(p, pos* sizeof(Usuario),SEEK_SET);
    bool escribio=fwrite(&reg, sizeof(Usuario),1,p);
    fclose(p);
    return escribio;
}

bool UsuarioArchivo::leerUsuario(int pos,Usuario &reg) {
    FILE* p=fopen(_nombreArchivo,"rb");
    if (p==nullptr) return false;
    fseek(p, pos* sizeof(Usuario), SEEK_SET);
    bool leyo=fread(&reg, sizeof(Usuario),1,p);
    fclose(p);
    return leyo;
}

void UsuarioArchivo::mostrarUsuario(int pos) {
    Usuario reg;
    if (leerUsuario(pos, reg)) {
        cout<<"ID: "<<reg.getIdUsuario()<<endl;
        cout<<"Clave: "<<reg.getClave()<<endl;
        cout<<"Nivel de seguridad: "<<reg.getNivelSeguridad()<<endl;
        cout<<"Estado: "<<(reg.getEstado() ? "Activo" : "Inactivo")<<endl;//operador ternario selecciona uno u otro dependiendo de getEstado
        cout<<"--------------------------------------"<<endl;
    }
}

int UsuarioArchivo::buscarPorId(int id) {
    Usuario reg;
    int pos=0;
    FILE* p=fopen(_nombreArchivo,"rb");
    if (p == nullptr)return -1;
    while(fread(&reg,sizeof(Usuario),1,p)){
        if (reg.getIdUsuario()==id){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;//Si sale por acá no lo encontró
}

int UsuarioArchivo::contarRegistros(){
    FILE* p=fopen(_nombreArchivo,"rb");
    if (p==nullptr) return -1;
    fseek(p,0,SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    int cantidadRegistros=bytes/sizeof(Usuario);
    return cantidadRegistros;
}

void UsuarioArchivo::listarTodos() {
    int cantidadReg=contarRegistros();
    for (int i=0;i<cantidadReg;i++) {
        mostrarUsuario(i);
        cout << "-----------------------"<<endl;
    }
}

bool UsuarioArchivo::eliminar(int id) {
    int pos=buscarPorId(id);
    if (pos==-1) return false;

    Usuario reg;
    if (!leerUsuario(pos, reg)) return false;
    reg.setEstado(false); // suponiendo que Usuario tiene _estado

    return modificarUsuario(pos, reg);
}

bool UsuarioArchivo::modificar(int id) {
    int pos = buscarPorId(id);
    if (pos == -1) {
        cout << "No se encontró un usuario con ese ID." << endl;
        return false;
    }

    Usuario reg;
    if (!leerUsuario(pos, reg)) {
        cout << "Error al leer el registro." << endl;
        return false;
    }

    cout << "=== MODIFICAR USUARIO ===" << endl;
    cout << "ID: " << reg.getIdUsuario() << endl;

    // Cambiar clave

    char nuevaClave[5];
cout << "Ingrese nueva clave: ";
cargarCadena(nuevaClave, 5);
reg.setClave(nuevaClave);

    // Cambiar nivel de seguridad (1 a 4)
    int nivel;
    do {
        cout << "Ingrese nuevo nivel de seguridad (1 a 4): ";
        cin >> nivel;

        if (cin.fail() || nivel < 1 || nivel > 4) {
            cout << "Valor inválido. Debe estar entre 1 y 4." << endl;
            cin.clear();
            cin.ignore(100, '\n');
        } else {
            reg.setNivelSeguridad(nivel);
            break;
        }
    } while (true);

    // Cambiar estado (1 o 0)
    int estado;
    do {
        cout << "Ingrese nuevo estado (1=Activo, 0=Inactivo): ";
        cin >> estado;

        if (cin.fail() || (estado != 0 && estado != 1)) {
            cout << "Valor inválido. Debe ser 0 o 1." << endl;
            cin.clear();
            cin.ignore(100, '\n');
        } else {
            reg.setEstado(estado);
            break;
        }
    } while (true);

    return modificarUsuario(pos, reg);
}
