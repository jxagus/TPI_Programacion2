#pragma once
#include "AutoparteArchivo.h"


class Reportes{
private:
    AutoparteArchivo _archivo;

public:
    void stockCritico(int limite = 5);
    float valorTotalInventario();
};


