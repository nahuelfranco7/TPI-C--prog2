# include<iostream>
# include<cstdlib>
# include<cstring>
# include <ctime>
# include "Fecha.h"
# include "Mascota.h"
# include "UsuarioArchivo.h"

using namespace std;


//getters


int Mascota::getIdMascota()const{return _idMascota;}
const char* Mascota::getNombreMascota()const{return _nombreMascota;}
Fecha Mascota::getFechaNac()const{return _fechaNac;}
int Mascota::getIdRaza()const{return _idRaza;}
int Mascota::getEdad()const{return _edad;}
char Mascota::getSexoAnimal()const{return _sexoAnimal;}
int Mascota::getIdClienteDueno()const{return _idClienteDueno;}
int Mascota::getDniClienteDueno() const {return _dniClienteDueno;}
bool Mascota::getEstadoMascota()const{return _estadoMascota;}

void Mascota::setIdMascota(int id){
_idMascota=id;
}
void Mascota::setNombreMascota(const char* nombre){
strncpy(_nombreMascota,nombre,19);
}
void Mascota::setFechaNac(Fecha fecha){
_fechaNac=fecha;
}
void Mascota::setIdRaza(int id){
_idRaza=id;
}
void Mascota::setEdad(int edad){
_edad=edad;
}
void Mascota::setSexoAnimal(char sexo){
_sexoAnimal=sexo;
}
void Mascota::setIdClienteDueno(int id){
_idClienteDueno=id;
}
void Mascota::setDniClienteDueno(int dni){
_dniClienteDueno=dni;
}

void Mascota::setEstadoMascota(bool estado){
_estadoMascota=estado;
}


int Mascota::calcularEdad(int dia, int mes, int anio) {
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





// --- cargarCadena ---
void Mascota::cargarCadena(char *palabra, int tam) {
    int i = 0;
    fflush(stdin);
    for (i = 0; i < tam; i++) {
        palabra[i] = cin.get();
        if (palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}


void Mascota::cargar(int dni) {

        _dniClienteDueno = dni;

        cout << "Nombre mascota: ";
        cargarCadena(_nombreMascota, 20);

        cout << "Fecha nacimiento: \n";
               cout << "Fecha de nacimiento (DD MM AAAA): ";
        int d, m, a;
        cin >> d >> m >> a;
        //comprobamos si es correcta la fecha
        Fecha fecha;
        while (!fecha.fechaValida(d, m, a)) {
        cout << "Fecha INVALIDA. Coloque otra fecha respetando el formato.\n";
        cout << "Ingrese nuevamente (DD MM AAAA): ";
        cin >> d >> m >> a;
        }
        _fechaNac.setDia(d);
        _fechaNac.setMes(m);
        _fechaNac.setAnio(a);

        // Calculo de edad de forma automática
        int edad = calcularEdad(d, m, a);
        cout << "Edad: " << edad << endl;
        _edad = edad;



       /*cout << "Tipo (1-Perro, 2-Gato...): ";
        cin >> Reino;

        cout << "Raza: ";/+
        cargarCadena(Raza, 30);*/


        cout << "ID raza: ";
        cin >> _idRaza;

        cout << "Sexo (M/H): ";
        cin >> _sexoAnimal;

        _estadoMascota = true;
}

void Mascota::mostrar() {
    cout << "ID Mascota: " << _idMascota << endl;
    cout << "Nombre: " << _nombreMascota << endl;
    cout << "Fecha de nacimiento: ";
    _fechaNac.mostrar();
    cout << "ID raza: " << _idRaza << endl;
    cout << "Sexo: " << _sexoAnimal << endl;
    cout << "DNI cliente dueño: " << _dniClienteDueno << endl;
    cout << "Estado: " << (_estadoMascota ? "Activo" : "Inactivo") << endl;
}
