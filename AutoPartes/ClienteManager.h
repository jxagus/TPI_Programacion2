#pragma once
#include "Clientes.h"
#include "ClientesArchivo.h"

using namespace std;


class ClienteManager
{
    public:
        ClienteManager();

        void cargarCliente ();
        void listarPorNombre();
        void mostrarCliente (Clientes clientes);
        void listar ();
        void BuscarID ();
        void listarPorCategoria();
        void BuscarPorNombre();
        void eliminarCliente();



    private:
        Clientes _clientes;
        ClienteArchivo _repor;
};


