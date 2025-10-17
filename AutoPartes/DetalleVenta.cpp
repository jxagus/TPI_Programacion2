#include "DetalleVenta.h"
#include <iostream>
using namespace std;

DetalleVenta::DetalleVenta(int idDetalle, int idVenta, int idAutoparte, int cantidad, float precio) {
    _idDetalle = idDetalle;
    _idVenta = idVenta;
    _idAutoparte = idAutoparte;
    _cantidad = cantidad;
    _precio = precio;
}

int DetalleVenta::getIdDetalle(){
     return _idDetalle;
     }
int DetalleVenta::getIdVenta(){
    return _idVenta;
     }
int DetalleVenta::getIdAutoparte(){
     return _idAutoparte;
    }
int DetalleVenta::getCantidad(){
     return _cantidad;
    }
float DetalleVenta::getPrecio(){
    return _precio;
    }

void DetalleVenta::setIdDetalle(int idDetalle) {
     _idDetalle = idDetalle;
     }
void DetalleVenta::setIdVenta(int idVenta){
     _idVenta = idVenta;
     }
void DetalleVenta::setIdAutoparte(int idAutoparte){
    _idAutoparte = idAutoparte;
    }
void DetalleVenta::setCantidad(int cantidad){
     _cantidad = cantidad;
     }
void DetalleVenta::setPrecio(float precio){
     _precio = precio;
     }

void DetalleVenta::mostrar()  {
    cout << "ID Detalle: " << _idDetalle << " | ID Venta: " << _idVenta
         << " | ID Autoparte: " << _idAutoparte << " | Cantidad: " << _cantidad
         << " | Precio: $" << _precio << endl;
}
