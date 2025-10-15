#pragma once

class Personal
{
    public:
        Personal();
        Personal (std::string Nombre, std::string Apellido, std::string Rol, std::string Telefono, std::string Mail, int DNI, int id);
        virtual ~Personal();

        std::string getNombre ();
        std::string getApellido ();
        std::string getRol ();
        std::string getTelefono ();
        std::string getMail ();
        int getDNI ();
        int getID ();

        void setNombre (std::string Nombre);
        void setApellido (std::string Apellido);
        void setRol (std::string Rol);
        void setTelefono (std::string Telefono);
        void setMail (std Mail);
        void setDNI (int DNI);
        void setID (int id);

    private:
        char _Nombnre [20];
        char _Apellido [20];
        char _Rol [20];
        char _Telefono [15];
        char _Mail [40];
        int _DNI;
        int _id;
};

