#pragma once
#include "AutoparteArchivo.h"
#include "Autoparte.h"


class AutoparteManager{
    public:
        AutoparteManager();
        void cargarAutoparte ();
        void cargarStock ();
        void mostrarAutoparte (Autoparte autoparte);
        void listar ();
        void BuscarPorID ();
        void BuscarPorTipo ();
        std::string  mostrarTipo (int tipo);

    private:
        AutoparteArchivo _repor;
        Autoparte _autoparte;
};


