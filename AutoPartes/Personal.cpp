#include <iostream>
#include <cstring>
#include "Personal.h"

using namespace std;



Personal::Personal(){

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

Personal::getNombre (){
    return _Nombre;
}

Personal::setNombre (string Nombre){

}
