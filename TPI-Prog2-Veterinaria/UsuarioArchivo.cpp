# include<iostream>
# include<cstdlib>
# include<cstring>
# include<cstdio>
# include "UsuarioArchivo.h"

using namespace std;

//getter
const char* UsuarioArchivo::getNombreArchivo() {
    return _nombreArchivo;
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

Usuario UsuarioArchivo::leerRegistro(int pos) {
    Usuario reg;
    FILE *p = fopen("usuarios.dat", "rb");

    if (p == nullptr) {
        cout << "Error abriendo archivo usuarios.dat\n";
        return reg; // Devuelve algo vacío
    }

    fseek(p, pos * sizeof(Usuario), SEEK_SET);
    fread(&reg, sizeof(Usuario), 1, p);

    fclose(p);

    return reg;
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
            return pos;//si sale por acá lo encontro y devuelve la posición
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
    Usuario reg;
    int pos;
    char opcion;


    while (true) {
        pos = buscarPorId(id);
        if (pos== -1) {
            cout<<"No se encontró un usuario con ese ID."<< endl;
            cout<<"¿Desea intentar nuevamente? (S/N): ";
            cin>>opcion;

            if(opcion== 'S' || opcion== 's') {
                // si se cargan letras se buguea

                cout<<"Ingrese nuevamente el ID: ";
                cin>>id;


                    // arreglo para que si por error tome letras no haga un loop

                    while (!(cin >> id)) {
                    cin.clear();               // Limpiar el error
                    cin.ignore(1000, '\n');    // Vaciar buffer
                    cout << "Entrada inválida. Ingrese un número entero: ";
                    }

            }else{
                cout<<"Operación cancelada."<<endl;
                return false;
            }
        }else{
            break;// ID encontrado salimos del bucle
        }
    }

    if(!leerUsuario(pos, reg)){//leer usuario me carga en registro el obj traido del archivo binario
        cout << "Error al leer el registro." << endl;
        return false;
    }

    cout<<"=== MODIFICAR USUARIO ==="<<endl;
    cout<<"ID: " << reg.getIdUsuario()<<endl;

    int opcionMenu;
    do{
        cout<<"\n--- MENÚ DE MODIFICACIÓN ---\n";
        cout<<"1. Cambiar clave\n";
        cout<<"2. Cambiar nivel de seguridad\n";
        cout<<"3. Cambiar estado\n";
        cout<< "4. Guardar cambios y salir\n";
        cout<< "Seleccione una opción: ";
        cin>>opcionMenu;

        switch (opcionMenu){
            case 1:{
                char nuevaClave[5];
                cout << "Ingrese nueva clave: ";
                cargarCadena(nuevaClave,5);
                reg.setClave(nuevaClave);
                break;
            }
            case 2:{
                int nivel;
                do {
                    cout<<"Ingrese nuevo nivel de seguridad (1 a 4): ";
                    cin>>nivel;

                    if(nivel< 1 || nivel>4) {
                        cout<< "Valor inválido. Debe estar entre 1 y 4."<<endl;
                                             }else {
                        reg.setNivelSeguridad(nivel);
                        break;
                    }
                } while(true);
                break;
            }
            case 3: {
                int estado;
                do {
                    cout<<"Ingrese nuevo estado (1=Activo, 0=Inactivo): ";
                    cin>>estado;

                    if (estado != 0 && estado != 1) {
                        cout << "Valor inválido. Debe ser 0 o 1." <<endl;

                    }else{
                        reg.setEstado(estado);
                        break;
                    }
                }while(true);
                break;
            }
            case 4:
                cout<< "Guardando cambios..."<<endl;
                return modificarUsuario(pos,reg);
            default:
                cout<<"Opción inválida. Intente nuevamente."<<endl;
                break;
        }
    } while(true);

    return true;
}

bool UsuarioArchivo::validarContrasenaPorPos(int pos, const char* contrasena) {
    Usuario reg;

    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return false;

    // Ir a la posición exacta
    fseek(p, pos * sizeof(Usuario), SEEK_SET);

    // Leer el registro
    if (fread(&reg, sizeof(Usuario), 1, p) != 1) {
        fclose(p);
        return false;   // Error de lectura
    }

    fclose(p);

    // Comparar contraseñas
    return strcmp(reg.getClave(), contrasena) == 0;
}
