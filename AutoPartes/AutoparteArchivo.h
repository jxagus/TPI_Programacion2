#pragma once
#include "Autoparte.h"

using namespace std;

class AutoparteArchivo{
    public:
        AutoparteArchivo(const char *nombreArchivo = "Autopartes.dat");

        bool guardarAutoparte(Autoparte registro);
        bool ModificarAutoparte(int pos, Autoparte modificar);
        int  buscarID(int id);
        int  buscarTipo (int tipo);

        Autoparte leer(int pos);
        bool leerTodos(Autoparte autoparte[], int cantidad);
        int getCantidadRegistros();


    private:
        const char *_nombreArchivo;
        Autoparte _registro;
};


