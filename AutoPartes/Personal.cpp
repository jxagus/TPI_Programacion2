#include <iostream>
#include <cstring>
#include "Personal.h"

using namespace std;



Personal::Personal(){
    strcpy (_Nombnre,"vacio");
    strcpy (_Apellido, "vacio");
    strcpy (_Rol, "vacio");
    strcpy (_Telefono,"00000");
    strcpy (_Mail, "vacio");
    _DNI = 0;
    _id = 0;
}

Personal::Personal (std::string Nombre, std::string Apellido, std::string Rol, std::string Telefono, std::string Mail, int DNI, int id){
    strncpy (_Nombnre, Nombre.c_str(),sizeof (_Nombre));
    strncpy (_Apellido, Apellido.c_str(),sizeof (_Apellido));
    strncpy (_Rol, Rol.c_str(),sizeof (_Rol));
    strncpy (_Telefono, Telefono.c_str(),sizeof (_Telefono));
    strncpy (_Mail, Mail.c_str(),sizeof (_Mail));
    _DNI = DNI;
    _id = id;
}

Personal::~Personal()
{
    //dtor
}

string Personal::getNombre (){
    return _Nombre;
}

void Personal::setNombre (string Nombre){
    strncpy (_Nombre,Nombre.c_str(), sizeof (_Nombre));
}

string Personal::getApellido () {
    return _Apellido;
}

void Personal::setApellido (string Apellido) {
    strncpy (_Apellido,Apellido.c_str(),sizeof (_Apellido));
}

string Personal::getRol (){
    return _Rol;
}

void Personal::setRol (string Rol){
    strncpy (_Rol, Rol.c_str(),sizeof (_Rol));
}

string Personal::getTelefono (){
    return _Telefono;
}

void Personal::setTelefono (string Telefono){
    strncpy (_Telefono, Telefono.c_str(),sizeof (_Telefono));
}

string Personal::getMail (){
    return _Mail;
}

void Personal::setMail (string Mail){
    strncpy (_Mail, Mail.c_str(),sizeof (_Mail));
}

int Personal::getDNI (){
    return _DNI;
}

void Personal::setDNI (int DNI){
    _DNI = DNI;
}

int Personal::getID (){
    return _id;
}

void Personal::setID (int id){
    _id = id;
}
