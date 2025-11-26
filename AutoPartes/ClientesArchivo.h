#pragma once
#include "Clientes.h"

using namespace std;

class ClienteArchivo
{
    public:
        ClienteArchivo(string _nombreArchivo = "Clientes.dat");

        bool guardarCliente(Clientes registro);
        bool modificarCliente (Clientes modificar, int pos);
        int buscarID (int id);

        Clientes leer (int pos);
        int leerTodos (Clientes cliente[],int cantidad);
        int getCantidadRegistros();
        int getNuevoID ();


    private:
       string _nombreArchivo;
       Clientes _registro;
};


