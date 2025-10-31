#pragma once
#include "Autoparte.h"

using namespace std;


class AutoparteArchivo{
    public:
        AutoparteArchivo(string _nombreArchivo = "Autoparte.dat");

        bool guardarAutoparte(Autoparte registro);
        bool ModificarAutoparte(int pos, Autoparte modificar);
        int  buscarID(int id);

        Autoparte leer(int pos);
        int leerTodos(Autoparte autoparte[], int cantidad);
        int getCantidadRegistros();
        int getNuevoID();


    private:
        string _nombreArchivo;
        Autoparte _registro;
};


