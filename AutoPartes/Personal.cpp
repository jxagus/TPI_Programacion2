#include "Personal.h"
#include <cstring>

using namespace std;
Personal::Personal()
{
    _id = -1;
    _dni = 0;
    _nombre[0] = '\0';
    _apellido[0] = '\0';
    _telefono[0] = '\0';
    _mail[0] = '\0';
    //_estado = -1;
}

Personal::Personal(int id, int dni, const string &nombre,const string &apellido, const string &telefono, const string &mail)
{
    setID(id);
    setDNI(dni);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setMail(mail);

}

//Setters
void Personal::setID(int id) { _id = id; }
void Personal::setDNI(int dni) { _dni = dni; }

void Personal::setNombre(const string &nombre)
{
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
}

void Personal::setApellido(const string &apellido)
{
    strncpy(_apellido, apellido.c_str(), sizeof(_apellido) - 1);
    _apellido[sizeof(_apellido) - 1] = '\0';
}

void Personal::setTelefono(const string &telefono)
{
    strncpy(_telefono, telefono.c_str(), sizeof(_telefono) - 1);
    _telefono[sizeof(_telefono) - 1] = '\0';
}

void Personal::setMail(const string &mail)
{
    strncpy(_mail, mail.c_str(), sizeof(_mail) - 1);
    _mail[sizeof(_mail) - 1] = '\0';
}

// getters
int Personal::getID() const { return _id; }
int Personal::getDNI() const { return _dni; }

string Personal::getNombre() const { return string(_nombre); }
string Personal::getApellido() const { return string(_apellido); }
string Personal::getTelefono() const { return string(_telefono); }
string Personal::getMail() const { return string(_mail); }

