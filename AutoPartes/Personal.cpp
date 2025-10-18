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

// Setters
void Personal::setId(int id){
    _id = id;
    }
void Personal::setNombre(string& nombre){
    _nombre = nombre;
    }
void Personal::setApellido(string& apellido){
    _apellido = apellido;
    }
void Personal::setDni(int dni){
    _dni = dni;
    }
void Personal::setRol(string& rol){
    _rol = rol;
    }
void Personal::setTelefono(string& telefono){
    _telefono = telefono;
    }
void Personal::setMail(string& mail){
    _mail = mail;
    }

// Getters
int Personal::getId(){
    return _id;
    }
string Personal::getNombre(){
    return _nombre;
    }
string Personal::getApellido(){
    return _apellido;
    }
int Personal::getDni(){
    return _dni;
    }
string Personal::getRol(){
    return _rol;
    }
string Personal::getTelefono(){
    return _telefono;
    }
string Personal::getMail(){
    return _mail;
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
