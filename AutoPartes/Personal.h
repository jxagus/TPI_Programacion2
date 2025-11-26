#pragma once
#include <string>

class Personal
{
public:
    Personal();
    Personal(int id, int dni, const std::string &nombre,
             const std::string &apellido, const std::string &telefono,
             const std::string &mail);

    // SETTERS
    void setID(int id);
    void setDNI(int dni);
    void setNombre(const std::string &nombre);
    void setApellido(const std::string &apellido);
    void setTelefono(const std::string &telefono);
    void setMail(const std::string &mail);

    // GETTERS
    int getID() const;
    int getDNI() const;
    std::string getNombre() const;
    std::string getApellido() const;
    std::string getTelefono() const;
    std::string getMail() const;

private:
    int _id;
    int _dni;

    char _nombre[40];
    char _apellido[40];
    char _telefono[20];
    char _mail[60];
};


