#include "Venta.h"
#include "DetalleVentaArchivo.h"
#include <iostream>
#include <cstring>
using namespace std;

Venta::Venta() {
    _idVenta = 0;
    strcpy(_fechaEntrega, "");
    _idCliente = 0;
    _importeTotal = 0;
    _idPersonal = 0;
}

Venta::Venta(int idVenta, string fecha, int idCliente, int idPersonal, float importeTotal) {
    _idVenta = idVenta;
    strncpy(_fechaEntrega, fecha.c_str(), 10);
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

string Venta::getFechaEntrega()  {
     return _fechaEntrega;
    }
void Venta::setFechaEntrega(string fecha) {
    strncpy(_fechaEntrega, fecha.c_str(), sizeof(_fechaEntrega));
    _fechaEntrega[sizeof(_fechaEntrega) - 1] = '\0'; // seguridad
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

