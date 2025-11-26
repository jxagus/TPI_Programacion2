#include "Clientes.h"
#include <cstring>

using namespace std;

Clientes::Clientes()
{
    _idCliente = -1;
    _categoria[0] = '\0';
    _direccion[0] = '\0';
    _nombre[0] = '\0';
    _telefono = 0;
    _cuit[0] = '\0';
    _mail[0] = '\0';
}

Clientes::Clientes(int idCliente, const string &categoria, const string &direccion, const string &nombre, int telefono, const string &cuit, const string &mail)
{
    setIDCliente(idCliente);
    setCategoria(categoria);
    setDireccion(direccion);
    setNombre(nombre);
    setTelefono(telefono);
    setCUIT(cuit);
    setMail(mail);
}

// Setters
void Clientes::setIDCliente(int idCliente) { _idCliente = idCliente; }

void Clientes::setCategoria(const string &categoria)
{
    strncpy(_categoria, categoria.c_str(), sizeof(_categoria) - 1);
    _categoria[sizeof(_categoria) - 1] = '\0';
}

void Clientes::setDireccion(const string &direccion)
{
    strncpy(_direccion, direccion.c_str(), sizeof(_direccion) - 1);
    _direccion[sizeof(_direccion) - 1] = '\0';
}

void Clientes::setNombre(const string &nombre)
{
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
}

void Clientes::setTelefono(int telefono)
{
    _telefono = telefono;
}

void Clientes::setCUIT(const string &cuit)
{
    strncpy(_cuit, cuit.c_str(), sizeof(_cuit) - 1);
    _cuit[sizeof(_cuit) - 1] = '\0';
}

void Clientes::setMail(const string &mail)
{
    strncpy(_mail, mail.c_str(), sizeof(_mail) - 1);
    _mail[sizeof(_mail) - 1] = '\0';
}

// Getters
int Clientes::getIDCliente() const { return _idCliente; }

string Clientes::getCategoria() const { return string(_categoria); }
string Clientes::getDireccion() const { return string(_direccion); }
string Clientes::getNombre() const { return string(_nombre); }
int Clientes::getTelefono() const { return _telefono; }
string Clientes::getCUIT() const { return string(_cuit); }
string Clientes::getMail() const { return string(_mail); }

