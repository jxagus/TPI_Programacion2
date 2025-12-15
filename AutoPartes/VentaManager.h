#pragma once
#include "Fecha.h"
#include "Validaciones.h"
#include "Clientes.h"
#include "ClientesArchivo.h"
#include "ClienteManager.h"
#include "AutoparteArchivo.h"
#include "AutoparteManager.h"
#include "PersonalManager.h"
#include "VentaArchivo.h"
#include "Venta.h"
#include "DetalleVentaArchivo.h"
#include "DetalleVenta.h"
#include "DetalleVentaManager.h"

using namespace std;

class VentaManager {
private:
    VentaArchivo _archivo;
    Venta _venta;
    Validaciones _validar;
public:
    void agregarVenta(); //terminado
    void mostrarVenta (Venta venta); //terminado
    void listarVentas();  //terminado
    void buscarVentaPorID();  //terminado
    void buscarVentaPorCliente (); //terminado
    void buscarVentaPorAutopartes (); //termina2
    void buscarVentasPorFecha (); //terminado
    void ordenarVentas (Venta *vec,int cant, int aux, bool asc);
    void obtenerNombresVenta( Venta &venta,string &nombreCliente,string &nombrePersonal);
};

