#pragma once
#include "SubMenu.h"


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

};


