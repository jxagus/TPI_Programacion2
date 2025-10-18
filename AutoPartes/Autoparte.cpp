#include <iostream>
#include <cstring>
#include "Autoparte.h"

using namespace std;


Autoparte::Autoparte(){
    strcpy (_nombre, "Vacio");
    _idAutoparte = 0;
    _tipo = 0;
    _stock = 0;
    _precioUnitario = 0;

}

Autoparte::Autoparte (string Nombre, int idAutoparte,int Tipo,int Stock,float precioUnitario){
    strncpy (_nombre, Nombre.c_str(), sizeof (_nombre));
    _idAutoparte = idAutoparte;
    _tipo = Tipo;
    _stock = Stock;
    _precioUnitario = precioUnitario;
}
string Autoparte::getNombre (){
    return _nombre;
}

void Autoparte::setNombre (string Nombre){
    strncpy (_nombre, Nombre.c_str(), sizeof (_nombre));
}

int Autoparte::getIDAutoparte (){
    return _idAutoparte;
}
void Autoparte::setIDAutoparte (int idAutoparte){
    _idAutoparte = idAutoparte;
}
int Autoparte::getTipo (){
    return _tipo;
}
void Autoparte::setTipo(int Tipo){
    _tipo = Tipo;
}
int Autoparte::getStock (){
    return _stock;
}
void Autoparte::setStock(int Stock){
    _stock = Stock;
}
float Autoparte::getPrecioUnitario(){
    return _precioUnitario;
}
void Autoparte::setPrecioUnitario(float precioUnitario){
    _precioUnitario = precioUnitario;
}



