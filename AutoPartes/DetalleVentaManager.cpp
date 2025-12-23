#include "DetalleVentaManager.h"
#include <iostream>
using namespace std;

DetalleVenta DetalleVentaManager::cargarDetalle(int idVenta) {
    DetalleVenta det;
    det.setIdVenta(idVenta);

    int cant = _archAuto.getCantidadRegistros();
    if (cant == 0) {
        det.setCantidad(0);
        return det;
    }

    Autoparte* vec = new Autoparte[cant];
    _archAuto.leerTodos(vec, cant);

    int idAutoparte;
    Autoparte* encontrado = nullptr;

    do {
        system("cls");
        encontrado = nullptr;
        idAutoparte = _validaciones.leerInt("Ingrese ID de autoparte: ");

        for (int i = 0; i < cant; i++) {
            if (vec[i].getIDAutoparte() == idAutoparte) {
                encontrado = &vec[i];
                break;
            }
        }

        if (!encontrado) {
            cout << "ERROR: Autoparte no encontrada. Reintente.\n";
            system("pause");
            continue;
        }

        if (encontrado->getStock() == 0) {
            cout << "ERROR: Autoparte sin stock. Elija otra.\n";
            encontrado = nullptr;
            system("pause");
            continue;
        }

    } while (!encontrado);

    det.setIdAutoparte(encontrado->getIDAutoparte());
    det.setPrecio(encontrado->getPrecioUnitario());

    mostrarListaDeDetalles(det);

    int cantidad = _validaciones.leerIntEnRango(
        "INGRESAR CANTIDAD: ", 1, encontrado->getStock()
    );

    det.setCantidad(cantidad);
    det.setIdDetalle(_archivo.contarRegistros() + 1);

    int pos = _archAuto.buscarID(encontrado->getIDAutoparte());
    encontrado->setStock(encontrado->getStock() - cantidad);
    _archAuto.ModificarAutoparte(pos, *encontrado);

    delete[] vec;
    return det;
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

        //cout << "ID Detalle: " << det.getIdDetalle() << endl;
        cout << "Autoparte: " << a->getNombre() << endl;
        //cout << "Precio unitario: $" << det.getPrecio() << endl;
        cout << "Cantidad: " << det.getCantidad() << endl;
        cout << "Subtotal: $" << det.getCantidad() * det.getPrecio() << endl;
    }

    delete[] detalles;
    delete[] autopartes;
}

void DetalleVentaManager::mostrarListaDeDetalles(DetalleVenta& det) {
    AutoparteArchivo autoparteA;
    int pos = autoparteA.buscarID(det.getIdAutoparte());
    Autoparte autoparte = autoparteA.leer(pos);

    cout << "Nombre del autoparte: " << autoparte.getNombre() << endl;
    cout << "Precio unitario: $" << det.getPrecio() << endl;
    cout << "Stock: " << autoparte.getStock() << endl;
    cout << "------------------------------" << endl;
}
