#pragma once
#include "VentaManager.h"
#include "DetalleVentaArchivo.h"
#include "AutoparteManager.h"

class DetalleVentaManager {
private:
    DetalleVentaArchivo _archivo;
    AutoparteArchivo _archAuto;
public:
    DetalleVenta cargarDetalle(int idVenta);
    void mostrarDetalleVenta(int idVenta);
    void listarDetallesPorVenta (int idVenta);
};
