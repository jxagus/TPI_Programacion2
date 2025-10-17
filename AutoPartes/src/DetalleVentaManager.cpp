#include "DetalleVentaManager.h"
#include <iostream>
using namespace std;

void DetalleVentaManager::agregarDetalleVenta() {
    DetalleVenta reg;
    int idDetalle, idVenta, idAutoparte, cantidad;
    float precio;

    cout << "ID Detalle: ";
    cin >> idDetalle;
    cout << "ID Venta: ";
    cin >> idVenta;
    cout << "ID Autoparte: ";
    cin >> idAutoparte;
    cout << "Cantidad: ";
    cin >> cantidad;
    cout << "Precio unitario: ";
    cin >> precio;

    reg.setIdDetalle(idDetalle);
    reg.setIdVenta(idVenta);
    reg.setIdAutoparte(idAutoparte);
    reg.setCantidad(cantidad);
    reg.setPrecio(precio);

    if (_archivo.guardar(reg)) cout << "Detalle guardado correctamente.\n";
    else cout << "Error al guardar el detalle.\n";
}

void DetalleVentaManager::listarDetalles() {
    _archivo.listarTodos();
}

void DetalleVentaManager::listarPorIdVenta(int idVenta) {

}

float DetalleVentaManager::calcularTotalPorVenta(int idVenta) {

}
