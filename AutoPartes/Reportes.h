#pragma once
#include "AutoparteArchivo.h"
#include "DetalleVentaArchivo.h"


class Reportes{
private:
    AutoparteArchivo _archivo;

public:
    float RecaudacionTotal ();
    float recaudacionCliente ();
    float recaudacionPorAutoparte ();
    void stockCritico(int limite = 5);
    float valorTotalInventario();
};


