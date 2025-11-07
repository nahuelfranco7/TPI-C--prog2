# include<iostream>
# include<cstdlib>
# include<cstring>
# include "MascotaArchivo.h"

/*
    const char* getNombreArchivo();

    int buscarPorId(int id);
    int contarRegistros();

    void cargarCadena(char *palabra, int tam);
    void listarTodos();
    void eliminar(int pos);
    void mostrarMascota(int pos, const Mascota &reg);

    bool modificar(int pos);
    bool cargarMascota(const Mascota &reg);      // 🔹 Faltaba "&" antes del parámetro reg
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
