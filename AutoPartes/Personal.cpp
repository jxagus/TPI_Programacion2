#include "Personal.h"
#include <cstring>
#include <iostream>
using namespace std;

Personal::Personal() {
    _id = 0;
    _dni = 0;
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_rol, "");
    strcpy(_telefono, "");
    strcpy(_mail, "");
}

// Getters
int Personal::getId(){
    return _id;
    }
char* Personal::getNombre(){
    return _nombre;
    }
char* Personal::getApellido(){
    return _apellido;
    }
int Personal::getDni(){
    return _dni;
}
char* Personal::getRol(){
    return _rol;
    }
char* Personal::getTelefono(){
    return _telefono;
    }
char* Personal::getMail(){
    return _mail;
    }

// Setters
void Personal::setId(int id){
    _id = id;
    }
void Personal::setNombre(char* nombre){
    strcpy(_nombre, nombre);
    }
void Personal::setApellido( char* apellido){
    strcpy(_apellido, apellido);
    }
void Personal::setDni(int dni){
     _dni = dni;
     }
void Personal::setRol( char* rol){
    strcpy(_rol, rol);
    }
void Personal::setTelefono( char* telefono){
    strcpy(_telefono, telefono);
    }
void Personal::setMail( char* mail){
    strcpy(_mail, mail);
    }

// Mostrar
void Personal::mostrar() const {
    cout << "ID: " << _id << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "DNI: " << _dni << endl;
    cout << "Rol: " << _rol << endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "Mail: " << _mail << endl;
}
