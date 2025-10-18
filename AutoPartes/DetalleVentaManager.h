#pragma once
#include "DetalleVentaArchivo.h"

class DetalleVentaManager {

public:
    void agregarDetalleVenta();
    void listarDetalles();
    void listarPorIdVenta(int idVenta);
    float calcularTotalPorVenta(int idVenta);

private:
    DetalleVentaArchivo _archivo;

};
