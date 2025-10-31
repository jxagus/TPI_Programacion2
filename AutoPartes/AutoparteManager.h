#pragma once
#include "AutoparteArchivo.h"
#include "Autoparte.h"


class ManagerAutoparte{
    public:
        ManagerAutoparte();

        void cargarAutoparte ();
        void cargarStock ();
        void mostrarAutoparte (Autoparte autoparte);
        void listar ();
        void BuscarPorID ();

    private:
        ArchivoAutoparte _repor;
        Autoparte _autoparte;
};


