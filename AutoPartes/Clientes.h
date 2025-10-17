#pragma once

class Clientes{
    public:
        Clientes();
        Clientes (int idCliente, int Telefono, std::string Nombre,std::string Cuit,std::string Direccion,std::string Mail);
        virtual ~Clientes();

        std::string getNombre();
        void setNombre (std::string Nombre);
        std::string getCuit ();
        void setCuit (std::string Cuit);
        std::string getCategoria();
        void setCategoria (std::string Categoria);
        std::string getDireccion();
        void setDireccion (std::string Direccion);
        std::string getMail ();
        void setMail (std::string Mail);
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


