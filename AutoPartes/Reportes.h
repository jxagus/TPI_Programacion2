#pragma once
#include "AutoparteArchivo.h"
#include "DetalleVentaArchivo.h"
#include "VentaManager.h"


class Reportes{
private:
    AutoparteArchivo _archivo;
    ClienteArchivo _archivocliente;
    VentaArchivo _archivoventas;

public:
    float recaudacionTotalPorAnio();
    float recaudacionCliente();
    float recaudacionPorAutoparte();
    void stockCritico(int limite = 5);
    float valorTotalInventario();
};


