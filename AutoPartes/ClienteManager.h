#pragma once
#include "Clientes.h"
#include "ArchivoClientes.h"

using namespace std;


class ManagerCliente
{
    public:
        ManagerCliente();

        void cargarCliente ();
        void mostrarCliente (Clientes clientes);
        void listar ();
        void BuscarID ();


    private:
        Clientes _clientes;
        ArchivoClientes _repor;
};


