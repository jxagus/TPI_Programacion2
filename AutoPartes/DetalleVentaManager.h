#pragma once
#include "VentaManager.h"
#include "DetalleVentaArchivo.h"
#include "AutoparteManager.h"
#include "Validaciones.h"

class DetalleVentaManager {
private:
    DetalleVentaArchivo _archivo;
    AutoparteArchivo _archAuto;
    Validaciones _validaciones;
public:
    DetalleVenta cargarDetalle(int idVenta);
    void mostrarDetalleVenta(int idVenta);
    void mostrarListaDeDetalles(DetalleVenta& det);
};
