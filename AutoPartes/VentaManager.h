#pragma once
#include "ClientesArchivo.h"
#include "ClienteManager.h"
#include "AutoparteArchivo.h"
#include "PersonalManager.h"
#include "VentaArchivo.h"
#include "Venta.h"
#include "DetalleVentaArchivo.h"
#include "DetalleVenta.h"
#include "DetalleVentaManager.h"

class VentaManager {
private:
    VentaArchivo _archivo;
    Venta _venta;
public:
    void agregarVenta(); //terminado
    void mostrarVenta (Venta venta); //terminado
    void listarVentas();  //terminado
    void buscarVentaPorID();  //terminado
    void buscarVentaPorCliente (); //terminado
    void buscarVentaPorAutopartes (); //termina2
    void buscarVentasPorFecha (); //terminado
    void ordenarVentas (Venta *vec,int cant, int aux, bool asc);
};

