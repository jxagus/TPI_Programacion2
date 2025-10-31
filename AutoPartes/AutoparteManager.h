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

    private:
        AutoparteArchivo _repor;
        Autoparte _autoparte;
};


