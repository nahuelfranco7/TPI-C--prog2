#pragma once
# include <cstring>

class Usuario{
private:
    int _idUsuario = 0;
    char _clave[6] = {0};// 5 caracteres + '\0'
    int _nivelSeguridad = 0;
    bool _estado;

public:
    Usuario();
    Usuario(int id, const char* clave , int nivel, bool estado);

    //Getters
    int getIdUsuario();
    const char* getClave();
    int getNivelSeguridad();
    bool getEstado();
    //Setters
    void setIdUsuario(int id);
    void setClave(const char* clave);
    void setNivelSeguridad(int nivel);
    void setEstado(bool estado);
};
