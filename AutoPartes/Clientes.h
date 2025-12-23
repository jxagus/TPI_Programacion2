#pragma once
#include <string>
using namespace std;

class Clientes
{
private:
    int _idCliente;
    char _categoria[20];  // tipo de empresa: talleres, concesionaria, distribuidoras, otros
    char _direccion[50];
    char _nombre[20];
    int _telefono;
    char _cuit[10];
    char _mail[50];

public:
    // Constructores
    Clientes();
    Clientes(int idCliente, const string &categoria, const string &direccion,
            const string &nombre, int telefono, const string &cuit, const string &mail);

    // Setters
    void setIDCliente(int idCliente);
    void setCategoria(const string &categoria);
    void setDireccion(const string &direccion);
    void setNombre(const string &nombre);
    void setTelefono(int telefono);
    void setCUIT(const string &cuit);
    void setMail(const string &mail);

    // Getters
    int getIDCliente() const;
    string getCategoria() const;
    string getDireccion() const;
    string getNombre() const;
    int getTelefono() const;
    string getCUIT() const;
    string getMail() const;
};
