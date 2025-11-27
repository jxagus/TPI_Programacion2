#pragma once
#include "AutoparteArchivo.h"
#include "Autoparte.h"
#include "Validaciones.h"


class AutoparteManager{
    public:
        AutoparteManager();
        void cargarAutoparte ();
        void cargarStock ();
        void mostrarAutoparte (Autoparte autoparte);
        void listar ();
        void BuscarPorID ();
        void BuscarPorTipo ();
        void BuscarPorNombre ();
        void ordenarAutopartes(Autoparte* vec, int cant, int campo, bool asc);
        std::string  mostrarTipo (int tipo);

    private:
        AutoparteArchivo _repor;
        Autoparte _autoparte;
        Validaciones _validaciones;
};


