#include "Personal.h"
#include <cstring>

// ===== CONSTRUCTOR POR DEFECTO =====
Personal::Personal()
{
    _id = -1;
    _dni = 0;

    _nombre[0] = '\0';
    _apellido[0] = '\0';
    _telefono[0] = '\0';
    _mail[0] = '\0';
}

// ===== CONSTRUCTOR CON PARÁMETROS =====
Personal::Personal(int id, int dni, const std::string &nombre,
                   const std::string &apellido, const std::string &telefono,
                   const std::string &mail)
{
    setID(id);
    setDNI(dni);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setMail(mail);
}

// ===== SETTERS =====
void Personal::setID(int id) { _id = id; }
void Personal::setDNI(int dni) { _dni = dni; }

void Personal::setNombre(const std::string &nombre)
{
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
}

void Personal::setApellido(const std::string &apellido)
{
    strncpy(_apellido, apellido.c_str(), sizeof(_apellido) - 1);
    _apellido[sizeof(_apellido) - 1] = '\0';
}

void Personal::setTelefono(const std::string &telefono)
{
    strncpy(_telefono, telefono.c_str(), sizeof(_telefono) - 1);
    _telefono[sizeof(_telefono) - 1] = '\0';
}

void Personal::setMail(const std::string &mail)
{
    strncpy(_mail, mail.c_str(), sizeof(_mail) - 1);
    _mail[sizeof(_mail) - 1] = '\0';
}

// ===== GETTERS =====
int Personal::getID() const { return _id; }
int Personal::getDNI() const { return _dni; }

std::string Personal::getNombre() const { return std::string(_nombre); }
std::string Personal::getApellido() const { return std::string(_apellido); }
std::string Personal::getTelefono() const { return std::string(_telefono); }
std::string Personal::getMail() const { return std::string(_mail); }

