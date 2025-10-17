#include <iostream>
#include <cstring>
#include "Clientes.h"

using namespace std;



Clientes::Clientes(){
    strcpy (_nombre,"vacio");
    strcpy (_cuit,"vacio");
    strcpy (_categoria, "vacio");
    strcpy (_direccion, "vacio");
    strcpy (_mail, "vacio");
   _idCliente = 0;
   _telefono = 0;
}

Clientes::Clientes (string Nombre, string Cuit, string Categoria, string Direccion,string Mail, int idCliente, int Telefono){
    strncpy (_nombre ,Nombre .c_str ,sizeof (_nombre) );
    strncpy (_cuit , Cuit.c_str ,sizeof (_cuit) );
    strncpy (_categoria , Categoria.c_str ,sizeof (_categoria) );
    strncpy (_direccion , Direccion.c_str ,sizeof (_direccion) );
    strncpy (_mail , Mail.c_str ,sizeof (_mail) );
    _idCliente  = idCliente ;
    _telefono = Telefono;
}

Clientes::~Clientes(){
    //dtor
}

void Clientes::setNombre (string Nombre){
    strncpy (_nombre ,Nombre .c_str ,sizeof (_nombre));
}
string Clientes::getNombre (){
      return  _nombre;
}
void Clientes::setCuit (string Cuit){
    strncpy (_cuit , Cuit.c_str ,sizeof (_cuit) );
}
string Clientes::getCuit (){
     return  _cuit;
}
void Clientes::setCategoria (string Categoria){
    strncpy (_categoria , Categoria.c_str ,sizeof (_categoria) );
}
string Clientes::getCategoria (){
     return  _categoria;
}
void Clientes::setDireccion (string Direccion){
    strncpy (_direccion , Direccion.c_str ,sizeof (_direccion) );
}
string Clientes::getDireccion (){
     return  _direccion;
}
void Clientes::setMail (string Mail){
    strncpy (_mail , Mail.c_str ,sizeof (_mail) );
}
string Clientes::getMail(){
    return  _mail;
}
void Clientes::setidCliente (int idCliente){
    _idCliente = idCliente;
}
int  Clientes::getidCliente(){
    return  _idCliente;
}
void Clientes::setTelefono (int Telefono){
    _telefono = Telefono;
}
int  Clientes::getTelefono(){
    return  _telefono;
}


