# include<iostream>
# include<cstdlib>
# include<cstring>
# include "DetalleFacturaArchivo.h"

using namespace std;

/*
    int buscarPorId(int id);//devuelve una posición
    int contarRegistros();
    int generarNuevoID();

    bool cargarDetalle();
    bool cargarDetalle(const DetalleFactura &reg);
    bool modificarDetalleArchivo(int pos,const DetalleFactura &reg);
    bool leerDetalle(int pos, const DetalleFactura &reg);
    bool eliminar(int pos);
    bool modificar(int pos);

    void mostrarDetalle(int, const DetalleFactura &reg);
    void listarTodos();

*/

const char* DetalleFacturaArchivo::getNombreArchivo(){
return _nombreArchivo;
}
/*
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
*/
int DetalleFacturaArchivo::buscarPorId(int id){
DetalleFactura reg;
int pos=0;
FILE* p=fopen(_nombreArchivo,"rb");
if(p==nullptr)return -1;
while(fread(&reg,sizeof(DetalleFactura),1,p)){
    if(reg.getIdFactura()==id){
        fclose(p);
        return pos;
    }
    pos++;
}
}
