#include "DetalleVentaManager.h"
#include <iostream>
using namespace std;

DetalleVenta DetalleVentaManager::cargarDetalle(int idVenta) {
    DetalleVenta det;
    det.setIdVenta(idVenta);

    int idAutoparte;
    cout << "Ingrese ID de la autoparte: ";
    cin >> idAutoparte;
    cin.clear();
    cin.ignore(1000,'\n');

    // Leer todos los registros en memoria
    int cant = _archAuto.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay autopartes registradas.\n";
        det.setIdAutoparte(-1);
        return det;
    }

    Autoparte* vec = new Autoparte[cant];
    _archAuto.leerTodos(vec, cant);

    // Buscar el ID en el vector
    Autoparte* encontrado = nullptr;
    for (int i = 0; i < cant; i++) {
        if (vec[i].getIDAutoparte() == idAutoparte) {
            encontrado = &vec[i];
            break;
        }
    }

    if (encontrado == nullptr) {
        cout << "ERROR: autoparte no encontrada.\n";
        det.setIdAutoparte(-1);
        delete[] vec;
        return det;
    }

    // Copiar datos a detalle
    det.setIdAutoparte(encontrado->getIDAutoparte());
    det.setPrecio(encontrado->getPrecioUnitario());

    delete[] vec; // liberar memoria

    // Pedir cantidad
    int cantidad;
    cout << "Ingrese cantidad: ";
    cin >> cantidad;
    cin.clear();
    cin.ignore(1000,'\n');
    det.setCantidad(cantidad);

    // Asignar idDetalle automático
    det.setIdDetalle(_archivo.contarRegistros() + 1);

    return det;
}

void DetalleVentaManager::listarDetallesPorVenta(int idVenta) {
    DetalleVentaArchivo archDetalle;
    int cant = archDetalle.contarRegistros();
    if (cant == 0) {
        cout << "No hay detalles registrados.\n";
        return;
    }

    DetalleVenta* vec = new DetalleVenta[cant];
    archDetalle.leerTodos(vec, cant);

    for (int i = 0; i < cant; i++) {
        // Filtrar solo los detalles de la venta actual
        if (vec[i].getIdVenta() != idVenta) continue;
        // Evitar mostrar registros vacíos
        if (vec[i].getIdAutoparte() == -1 || vec[i].getCantidad() <= 0) continue;

       // mostrarDetalleVenta(vec[i]);
    }

    delete[] vec;
}

void DetalleVentaManager::mostrarDetalleVenta(int idVenta) {
    DetalleVentaArchivo archDetalle;
    AutoparteArchivo archAuto;

    int cantDet = archDetalle.contarRegistros();
    if (cantDet == 0) {
        cout << "No hay detalles registrados.\n";
        return;
    }

    DetalleVenta* detalles = new DetalleVenta[cantDet];
    archDetalle.leerTodos(detalles, cantDet);

    // Cargar todas las autopartes en memoria
    int cantAuto = archAuto.getCantidadRegistros();
    Autoparte* autopartes = new Autoparte[cantAuto];
    archAuto.leerTodos(autopartes, cantAuto);

    for (int i = 0; i < cantDet; i++) {
        DetalleVenta det = detalles[i];

        // Filtrar solo los detalles de esta venta y válidos
        if (det.getIdVenta() != idVenta) continue;
        if (det.getIdAutoparte() == -1 || det.getCantidad() <= 0) continue;

        // Buscar la autoparte en memoria
        Autoparte* a = nullptr;
        for (int j = 0; j < cantAuto; j++) {
            if (autopartes[j].getIDAutoparte() == det.getIdAutoparte()) {
                a = &autopartes[j];
                break;
            }
        }

        if (!a) continue; // no encontrada, saltar

        cout << "ID Detalle: " << det.getIdDetalle() << endl;
        cout << "Autoparte: " << a->getNombre() << endl;
        cout << "Precio unitario: $" << det.getPrecio() << endl;
        cout << "Cantidad: " << det.getCantidad() << endl;
        cout << "Subtotal: $" << det.getCantidad() * det.getPrecio() << endl;
        cout << "---------------------------------" << endl;
    }

    delete[] detalles;
    delete[] autopartes;
}
