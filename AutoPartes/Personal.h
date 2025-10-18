#pragma once
using namespace std;

class Personal{
    public:
        Personal();
        Personal (string Nombre, string Apellido, string Rol, string Telefono, string Mail, int DNI, int id);
        virtual ~Personal();

        string getNombre ();
        string getApellido ();
        string getRol ();
        string getTelefono ();
        string getMail ();
        int getDNI ();
        int getID ();

        void setNombre (string Nombre);
        void setApellido (string Apellido);
        void setRol (string Rol);
        void setTelefono (string Telefono);
        void setMail (string Mail);
        void setDNI (int DNI);
        void setID (int id);

    private:
        char _Nombre [20];
        char _Apellido [20];
        char _Rol [20];
        char _Telefono [15];
        char _Mail [40];
        int _DNI;
        int _id;
};

