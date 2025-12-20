#pragma once
#include <string>

using namespace std;

class Personal
{
public:
    Personal();
    Personal(int id, int dni, const string &nombre,
             const string &apellido,
             const string &telefono,
             const string &mail);

    // SETTERS
    void setDNI(int dni);
    void setNombre(const string &nombre);
    void setApellido(const string &apellido);
    void setTelefono(const string &telefono);
    void setMail(const string &mail);
    void setEstado(bool estado);

    // GETTERS
    int getID() const;
    int getDNI() const;
    bool getEstado() const;
    string getNombre() const;
    string getApellido() const;
    string getTelefono() const;
    string getMail() const;

private:
    int _id;
    int _dni;
    bool _estado;   // true = activo/ false = eliminado

    char _nombre[40];
    char _apellido[40];
    char _telefono[20];
    char _mail[60];
};



