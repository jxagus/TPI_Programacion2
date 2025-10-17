#include "VentaManager.h"
#include <iostream>
using namespace std;

void VentaManager::agregarVenta() {
    Venta reg;
    reg.cargar();

    // Asignar ID automático
    int cant = _archivo.getCantidadRegistros();
    reg.setIdVenta(cant + 1);

    if (_archivo.guardar(reg)) cout << "Venta guardada correctamente.\n";
    else cout << "Error al guardar la venta.\n";
}

void VentaManager::listarVentas() {
    int cant = _archivo.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    Venta* vec = new Venta[cant];
    _archivo.leerTodos(vec, cant);
    for (int i = 0; i < cant; i++) vec[i].mostrar();
    delete[] vec;
}

void VentaManager::buscarVentaPorID() {
    int id;
    cout << "Ingrese ID de venta a buscar: ";
    cin >> id;

    int pos = _archivo.buscarPorID(id);
    if (pos == -1) {
        cout << "No se encontro la venta.\n";
        return;
    }
    Venta v = _archivo.leer(pos);
    v.mostrar();
}
