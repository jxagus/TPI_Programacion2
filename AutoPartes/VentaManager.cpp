#include "VentaManager.h"
#include <iostream>
#include "DetalleVentaArchivo.h"
#include "DetalleVenta.h"
using namespace std;
void VentaManager::agregarVenta() {
    Venta reg;
    reg.cargar();

    // Asignar ID automático a la venta
    int cant = _archivo.getCantidadRegistros();
    reg.setIdVenta(cant + 1);

    if (_archivo.guardar(reg)) {
        cout << "Venta guardada correctamente.\n";

        //Cargar los detalles de la venta
        DetalleVentaArchivo archDetalle;
        int n;
        cout << "¿Cuántos artículos tiene esta venta? ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "\n--- Cargando detalle #" << (i + 1) << " ---" << endl;

            DetalleVenta det;
            det.cargar(reg.getIdVenta()); // Pide idAutoparte, cantidad, precio
            det.setIdDetalle(archDetalle.contarRegistros() + 1);

            if (archDetalle.guardar(det))
                cout << "Detalle guardado correctamente.\n";
            else
                cout << "Error al guardar el detalle.\n";
        }
    }
    else {
        cout << "Error al guardar la venta.\n";
    }
}

void VentaManager::listarVentas() {
    int cant = _archivo.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    Venta* vec = new Venta[cant];
    _archivo.leerTodos(vec, cant);

    DetalleVentaArchivo archDetalle;

    for (int i = 0; i < cant; i++) {
        cout << "==============================" << endl;
        vec[i].mostrar();
        cout << "Detalles de la venta:" << endl;
        archDetalle.listarPorIdVenta(vec[i].getIdVenta());
        cout << "==============================" << endl;
    }

    delete[] vec;
}

void VentaManager::buscarVentaPorID() {
    int id;
    cout << "Ingrese ID de venta a buscar: ";
    cin >> id;

    int pos = _archivo.buscarPorID(id);
    if (pos == -1) {
        cout << "No se encontró la venta.\n";
        return;
    }

    Venta v = _archivo.leer(pos);
    v.mostrar();

    cout << "\n--- Detalles asociados ---\n";
    DetalleVentaArchivo archDetalle;
    archDetalle.listarPorIdVenta(v.getIdVenta());
}
/*
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
*/
