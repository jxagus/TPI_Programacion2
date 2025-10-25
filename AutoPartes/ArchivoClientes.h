#pragma once
#include "Clientes.h"

using namespace std;

class ArchivoClientes
{
    public:
        ArchivoClientes(string _nombreArchivo = "Clientes.dat");

        bool guardarCliente();
        bool modificarCliente (Clientes modificar, int pos);
        int buscarID (int id);

        Clientes leer (int pos);
        void leerTodos (Clientes cliente[],int cantidad);
        void getCantidadRegistros();
        void getNuevoID ();


    private:
       string _nombreArchivo;
       Clientes _registro;
};


