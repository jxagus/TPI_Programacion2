#pragma once
#include "ClientesMenu.h"
#include "AutoparteMenu.h"
#include "PersonalMenu.h"
#include "VentaMenu.h"


class Menu
{
    public:
        Menu();
        void run();

    protected:
        void mostrarOpciones();
        int seleccionOpcion();
        void ejecutarOpcion(int opcion);

    private:
        int _cantidadOpciones;
        ClientesMenu _clientesMenu;
        PersonalMenu _personalMenu;
        AutoparteMenu _autoparteMenu;
        VentaMenu _ventaMenu;

};


