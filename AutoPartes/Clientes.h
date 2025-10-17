#pragma once
using namespace std;

class Clientes{
    public:
        Clientes();
        Clientes (int idCliente, int Telefono, string Nombre,string Cuit,string Direccion,string Mail);
        virtual ~Clientes();

        string getNombre();
        void setNombre (string Nombre);
        string getCuit ();
        void setCuit (string Cuit);
        string getCategoria();
        void setCategoria (string Categoria);
        string getDireccion();
        void setDireccion (string Direccion);
        string getMail ();
        void setMail (string Mail);
        int getidCliente ();
        void setidCliente (int idCliente);
        int getTelefono ();
        void setTelefono (int Telefono);

    private:
        char _nombre [20];
        char _cuit  [10];
        char _categoria  [10];
        char _direccion  [50];
        char _mail [40];
        int _idCliente;
        int _telefono;
};


