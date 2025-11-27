#include <iostream>
#include <iomanip>
#include "Reportes.h"

using namespace std;

void Reportes::stockCritico(int limite) {
    int cantidad = _archivo.getCantidadRegistros();

    cout << "------------- STOCK CRITICO  -------------\n";
    cout << "ID    NOMBRE                STOCK     PRECIO\n";
    cout << "---------------------------------------------------------------\n";

    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Autoparte a = _archivo.leer(i);

        if (a.getStock() <= limite) {
            encontrado = true;
            cout << left << setw(6) << a.getIDAutoparte()
                      <<setw(20) << a.getNombre()
                      << setw(10) << a.getStock()
                      << setw(10) << a.getPrecioUnitario()
                      << "\n";
        }
    }

    if (!encontrado) {
        cout << "No hay autopartes con stock crítico.\n";
    }

    cout << "---------------------------------------------------------------\n";
}

float Reportes::valorTotalInventario() {
    AutoparteArchivo archivo("autopartes.dat");
    int cantidad = archivo.getCantidadRegistros();
    float total = 0.0;

    for (int i = 0; i < cantidad; i++) {
        Autoparte a = archivo.leer(i);
        float valorAutoparte = a.getStock() * a.getPrecioUnitario();
        total += valorAutoparte;
    }

cout << "========================================" << endl;
cout << "VALOR TOTAL DEL INVENTARIO / DEPOSITO" << endl;
cout << "========================================" << endl;
cout << "Valor total: $" << fixed << setprecision(2) << total << endl;
cout << "========================================" << endl;
}


float Reportes::recaudacionTotalPorAnio() {
    int opcionAnio;

    cout << "=== RECAUDACION TOTAL POR ANIO ===" << endl;
    cout << "1. 2023" << endl;
    cout << "2. 2024" << endl;
    cout << "3. 2025" << endl;
    cout << "Seleccione el anio: ";
    cin >> opcionAnio;

    int anio;
    switch (opcionAnio) {
        case 1:
            anio = 2023;
            break;
        case 2:
            anio = 2024;
            break;
        case 3:
            anio = 2025;
            break;
        default:
            cout << "Opcion invalida." << endl;
            return 0; // corta la ejecución
    }

    // === Cargar cantidad de ventas ===
    int cantVentas = _archivo.getCantidadRegistros();
    if (cantVentas == 0) {
        cout << "No hay ventas registradas." << endl;
        return 0;
    }

    // === Reservar memoria dinámica ===
    Venta* ventas = new Venta[cantVentas];

    // === Leer todas las ventas ===
    if (!_archivoventas.leerTodos(ventas, cantVentas)) {
        cout << "ERROR al leer ventas." << endl;
        delete[] ventas;
        return 0;
    }

    float total = 0;
    bool encontrado = false;

    // === Recorrer ventas ===
    for (int i = 0; i < cantVentas; i++) {
        int anioVenta = ventas[i].getFechaEntrega() / 10000; // AAAAMMDD -> obtiene AAAA

        if (anioVenta == anio) {
            total += ventas[i].getImporteTotal();
            encontrado = true;
        }
    }

    delete[] ventas;  // liberar memoria

    if (!encontrado) {
        cout << "No se encontraron ventas del anio " << anio << "." << endl;
        return 0;
    }

    cout << fixed << setprecision(2);
    cout << "Recaudacion total del anio " << anio << ": $" << total << endl;

    return total;
}

float Reportes::recaudacionCliente(){
    int idCliente;

    cout << "Ingrese el ID del cliente: ";
    cin >> idCliente;
    cin.clear();
    cin.ignore(1000, '\n');

    int cantVentas = _archivo.getCantidadRegistros();
    if (cantVentas <= 0) {
        cout << "No hay ventas registradas." << endl;
        return 0;
    }

    // Reserva dinámica
    Venta* ventas = new Venta[cantVentas];

    // Leer todos los registros
    if (!_archivoventas.leerTodos(ventas, cantVentas)) {
        cout << "Error al leer las ventas desde el archivo.\n";
        delete[] ventas;
        return 0;
    }

    float total = 0;
       bool encontrado = false;   // <<< NUEVO: para validar si el ID existe

        // Recorrer ventas
        for (int i = 0; i < cantVentas; i++) {
            if (ventas[i].getIdCliente() == idCliente) {
                total += ventas[i].getImporteTotal();
                encontrado = true;   // <<< Se encontró al menos 1 venta del cliente
            }
        }

        delete[] ventas;

        // Validación: ID no encontrado
        if (!encontrado) {
            cout << "---------------------------------------\n";
            cout << "No se encontró ninguna venta del cliente con ID "
                 << idCliente << ".\n";
            cout << "---------------------------------------\n";
            return 0;
        }

    // Liberar memoria
    delete[] ventas;

    // Salida formateada
    cout << fixed << setprecision(2);
    cout << "---------------------------------------\n";
    cout << "RECAUDACION DEL CLIENTE (ID " << idCliente << ")\n";
    cout << "TOTAL: $" << total << endl;
    cout << "---------------------------------------\n";

    return total;
}

float Reportes::recaudacionPorAutoparte() {
    int idAutoparte;
    cout << "Ingrese el ID de la autoparte a consultar: ";
    cin >> idAutoparte;
    cin.clear();
    cin.ignore(1000, '\n');

    DetalleVentaArchivo archDet;
    AutoparteArchivo archAuto;

    int cantDet = archDet.contarRegistros();
    int cantAuto = archAuto.getCantidadRegistros();

    if (cantDet == 0 || cantAuto == 0) {
        cout << "No hay datos suficientes para calcular la recaudacion.\n";
        return 0.0f;      // ⬅ debe devolver float
    }

    // Reservar memoria
    DetalleVenta* detalles = new DetalleVenta[cantDet];
    archDet.leerTodos(detalles, cantDet);

    Autoparte* autopartes = new Autoparte[cantAuto];
    archAuto.leerTodos(autopartes, cantAuto);

    // Calcular total
    float total = 0.0;

    for (int i = 0; i < cantDet; i++) {
        if (detalles[i].getIdAutoparte() == idAutoparte) {
            total += detalles[i].getCantidad() * detalles[i].getPrecio();
        }
    }

    // Obtener nombre de la autoparte
    string nombre = "Desconocida";
    for (int j = 0; j < cantAuto; j++) {
        if (autopartes[j].getIDAutoparte() == idAutoparte) {
            nombre = autopartes[j].getNombre();
            break;
        }
    }

    // Mostrar resultado
    cout << fixed << setprecision(2);
    cout << "Recaudacion total de la autoparte " << nombre
         << " (ID " << idAutoparte << "): $" << total << endl;

    // Liberar memoria
    delete[] detalles;
    delete[] autopartes;

    return total;   // ⬅ OBLIGATORIO, tu función devuelve float
}


