#pragma once
#include "Clientes.h"
#include "ClientesArchivo.h"

using namespace std;


class ClienteManager
{
    public:
        ClienteManager();

        void cargarCliente ();
        void listar ();
        void listarPorNombre();
        void listarNoActivos();
        void listarPorCategoria();
        void BuscarID ();
        void BuscarPorNombre();
        void mostrarCliente (Clientes clientes);
        void eliminarCliente();
        void reactivarCliente();



    private:
        ClienteArchivo _repor;
};
