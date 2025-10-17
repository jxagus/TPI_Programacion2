#pragma once
#include "DetalleVentaArchivo.h"

class DetalleVentaManager {
private:
    DetalleVentaArchivo _archivo;

public:
    void agregarDetalleVenta();
    void listarDetalles();
    void listarPorIdVenta(int idVenta);
    float calcularTotalPorVenta(int idVenta);
};
