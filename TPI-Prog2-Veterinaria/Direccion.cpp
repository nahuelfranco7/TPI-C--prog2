# include<iostream>
# include<cstdlib>
# include<cstring>
#include "Direccion.h"
using namespace std;

Direccion::Direccion() {
    _pais[0] = '\0';
    _provincia[0] = '\0';
    _ciudad[0] = '\0';
    _calle[0] = '\0';
    _altura = 0;
    _codPostal = 0;
}

//setters
const char* Direccion::getPais(){ return _pais;}
const char* Direccion::getProvincia(){ return _provincia;}
const char* Direccion::getCiudad(){return _ciudad;}
const char* Direccion::getCalle(){return _calle;}
int Direccion::getAltura(){return _altura;}
int Direccion::getCodPostal(){return _codPostal;}

// Setters con strncpy para limitar caracteres
void Direccion::setPais(const char* pais){
    strncpy(_pais, pais,39);
}

void Direccion::setProvincia(const char*provincia){
    strncpy(_provincia, provincia,29);
}

void Direccion::setCiudad(const char* ciudad){
    strncpy(_ciudad, ciudad,49);
}

void Direccion::setCalle(const char*calle){
    strncpy(_calle, calle, 49);
}

void Direccion::setAltura(int altura){
    _altura=altura;
}

void Direccion::setCodPostal(int codPostal){
    _codPostal=codPostal;
}
void Direccion::cargarCadena(char *palabra, int tam){

    int i;
    bool valido=false;

    while(!valido){
        fflush(stdin);
        i=0;

        cout<<"Ingrese (máximo "<<tam-1<<" caracteres): ";

        for(i=0;i<tam-1;i++){
            palabra[i]=cin.get();
            if(palabra[i]=='\n')break;
        }
        palabra[i]='\0';
        fflush(stdin);

        //Si el usuario paso el límite sin presionar enter
        if(i==tam-1 && palabra[i-1]!='\n'){
            cout<<"Error: no puede superar los "<<tam-1<<" caracteres.\n";

            //Limpiamos el resto de la cadena y descartamos lo que sobra en el buffer(almacenamiento)
            char basura;
            while((basura=cin.get())!='\n');

            // Borrar la cadena ingresada para que no quede basura
            palabra[0]='\0';
        }
        else {
            valido=true;
        }
    }

}

 void Direccion::cargarDireccion() {
        cout << "PAIS: ";
        cargarCadena(_pais, 40);
        cout << "PROVINCIA: ";
       cargarCadena(_provincia, 30);
        cout << "CIUDAD: ";
        cargarCadena(_ciudad, 50);
        cout << "CALLE: ";
        cargarCadena(_calle, 50);
        cout << "ALTURA: ";
        cin >> _altura;
        cout << "CODIGO POSTAL: ";
        cin >> _codPostal;

    }


