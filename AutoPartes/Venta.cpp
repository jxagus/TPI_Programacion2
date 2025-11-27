#include "Venta.h"
#include "DetalleVentaArchivo.h"
#include <iostream>
using namespace std;

Venta::Venta() {
    _idVenta = 0;
    _fechaEntrega = 0;
    _idCliente = 0;
    _importeTotal = 0;
    _idPersonal = 0;
}

Venta::Venta(int idVenta, int fecha, int idCliente, int idPersonal, float importeTotal) {
    _idVenta = idVenta;
    _fechaEntrega = fecha;
    _idCliente = idCliente;
    _importeTotal = importeTotal;
    _idPersonal = idPersonal;
}

int Venta::getIdVenta() {
    return _idVenta;
    }
void Venta::setIdVenta(int id) {
     _idVenta = id;
     }

int Venta::getFechaEntrega()  {
     return _fechaEntrega;
    }
void Venta::setFechaEntrega(int fecha) {
     _fechaEntrega = fecha;
     }

int Venta::getIdCliente()  {
     return _idCliente;
     }
void Venta::setIdCliente(int idCliente) {
     _idCliente = idCliente;
    }

float Venta::getImporteTotal()  {
     return _importeTotal;
    }
void Venta::setImporteTotal(float importe) {
     _importeTotal = importe;
     }

int Venta::getIdPersonal()  {
    return _idPersonal;
    }
void Venta::setIdPersonal(int idPersonal) {
     _idPersonal = idPersonal;
    }

