#pragma once
#include "Autoparte.h"


class ArchivoAutoparte{
    public:
        ArchivoAutoparte(std::string _nombreArchivo = "Autoparte.dat");
        bool guardar(Autoparte registro);
        bool guardar(int pos, Autoparte rep);
        int  buscarID(int id);
        bool eliminar(int pos);

    private:
        std::string _nombreArchivo;
};


