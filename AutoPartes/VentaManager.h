#pragma once
#include "VentaArchivo.h"

class VentaManager {
private:
    VentaArchivo _archivo;
public:
    void agregarVenta();
    void listarVentas();
    void buscarVentaPorID();
};

