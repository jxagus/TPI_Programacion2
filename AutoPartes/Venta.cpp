#include "Venta.h"
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

int Venta::getIdVenta() const { return _idVenta; }
void Venta::setIdVenta(int id) { _idVenta = id; }

int Venta::getFechaEntrega() const { return _fechaEntrega; }
void Venta::setFechaEntrega(int fecha) { _fechaEntrega = fecha; }

int Venta::getIdCliente() const { return _idCliente; }
void Venta::setIdCliente(int idCliente) { _idCliente = idCliente; }

float Venta::getImporteTotal() const { return _importeTotal; }
void Venta::setImporteTotal(float importe) { _importeTotal = importe; }

int Venta::getIdPersonal() const { return _idPersonal; }
void Venta::setIdPersonal(int idPersonal) { _idPersonal = idPersonal; }

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

void Venta::mostrar() const {
    cout << "ID Venta: " << _idVenta << endl;
    cout << "Fecha entrega: " << _fechaEntrega << endl;
    cout << "ID Cliente: " << _idCliente << endl;
    cout << "Importe total: $" << _importeTotal << endl;
    cout << "ID Personal: " << _idPersonal << endl;
    cout << "---------------------------" << endl;
}
