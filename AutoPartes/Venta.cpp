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

Venta::Venta(int idVenta, int fecha, int idCliente, float importe, int idPersonal) {
    _idVenta = idVenta;
    _fechaEntrega = fecha;
    _idCliente = idCliente;
    _importeTotal = importe;
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
/*
void Venta::cargar() {
    cout << "ID Cliente: ";
    cin >> _idCliente;
    cout << "Fecha de entrega (AAAAMMDD): ";
    cin >> _fechaEntrega;
    cout << "Importe total: ";
    cin >> _importeTotal;
    cout << "ID Personal: ";
    cin >> _idPersonal;
}
*/

void Venta::cargar() {
    cout << "=== NUEVA VENTA ===" << endl;

    cout << "Ingrese fecha de entrega (AAAAMMDD): ";
    cin >> _fechaEntrega;

    cout << "Ingrese ID del cliente: ";
    cin >> _idCliente;

    cout << "Ingrese ID del personal responsable: ";
    cin >> _idPersonal;

    // Inicializamos importe total
    _importeTotal = 0;

    // Cargar artículos (detalles de venta)
    int cantidadDetalles;
    cout << "¿Cuántos artículos desea incluir en la venta? ";
    cin >> cantidadDetalles;

    DetalleVentaArchivo archivoDetalle;
    for (int i = 0; i < cantidadDetalles; i++) {
        cout << "\n--- Artículo " << i + 1 << " ---" << endl;

        DetalleVenta detalle;
        detalle.setIdDetalle(archivoDetalle.contarRegistros() + 1);
        detalle.setIdVenta(_idVenta);
        detalle.cargar(_idVenta);

        archivoDetalle.guardar(detalle);

        // Sumar al total
        _importeTotal += detalle.getPrecio() * detalle.getCantidad();
    }

    cout << "\nVenta cargada correctamente con " << cantidadDetalles
         << " artículos." << endl;
}
void Venta::mostrar()  {
    cout << "ID Venta: " << _idVenta << endl;
    cout << "Fecha entrega: " << _fechaEntrega << endl;
    cout << "ID Cliente: " << _idCliente << endl;
    cout << "Importe total: $" << _importeTotal << endl;
    cout << "ID Personal: " << _idPersonal << endl;
    cout << "---------------------------" << endl;
}
