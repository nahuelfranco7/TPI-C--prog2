# include<iostream>
# include<cstdlib>
# include<cstring>
# include "Clientes.h"

using namespace std;
/*
int getIdCliente();
void setIdCliente();
*/

int Clientes::getIdCliente(){
return _idCliente;
}

void Clientes::setIdCliente(int id){
_idCliente=id;
}
