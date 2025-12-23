#include <iostream>
#include <iomanip>
#include "Reportes.h"

using namespace std;

void Reportes::stockCritico(int limite) {
    int cantidad = _archivo.getCantidadRegistros();

    cout << "--------------------- STOCK CRITICO  -------------------------"<< endl;
    cout << left
    <<setw(5) << "ID"
    <<setw(29) << "NOMBRE"
    <<setw(12) << "STOCK"
    <<setw(9) <<  "PRECIO"
    << endl;
    cout << "---------------------------------------------------------------"<< endl;

    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Autoparte a = _archivo.leer(i);

        if (a.getStock() <= limite) {
            encontrado = true;
            cout << left << setw(6) << a.getIDAutoparte()
                      <<setw(30) << a.getNombre()
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

    opcionAnio = _validaciones.leerIntEnRango("Seleccione el anio: ", 1, 3);

    int anio;
    switch (opcionAnio) {
        case 1: anio = 2023; break;
        case 2: anio = 2024; break;
        case 3: anio = 2025; break;
        default:
            cout << "Opcion invalida." << endl;
            return 0;
    }

    // Cargar ventas
    int cantVentas = _archivoventas.getCantidadRegistros();
    if (cantVentas == 0) {
        cout << "No hay ventas registradas." << endl;
        return 0;
    }

    // Reservar memoria
    Venta* ventas = new Venta[cantVentas];

    if (!_archivoventas.leerTodos(ventas, cantVentas)) {
        cout << "ERROR al leer ventas." << endl;
        delete[] ventas;
        return 0;
    }

    float total = 0;
    bool encontrado = false;

    // Recorrer ventas
    for (int i = 0; i < cantVentas; i++) {

        string fechaStr = ventas[i].getFechaEntrega(); // "DD/MM/AAAA"

        int dia, mes, anioVenta;
        char sep1, sep2;

        stringstream ss(fechaStr);  //convertir numeros a texto (ej. int a string) y viceversa,
        ss >> dia >> sep1 >> mes >> sep2 >> anioVenta;

        if (anioVenta == anio) {
            total += ventas[i].getImporteTotal();
            encontrado = true;
        }
    }

    delete[] ventas;

    if (!encontrado) {
        cout << "No se encontraron ventas del anio " << anio << "." << endl;
        return 0;
    }

    system ("cls");
    cout << fixed << setprecision(2);
    cout << "---------------------------------------" <<endl;
    cout << "RECAUDACION TOTAL EN " << anio << ": $" << total << endl;
    cout << "---------------------------------------" <<endl;

    return total;
}

float Reportes::recaudacionCliente(){
    int idCliente, ventasRealizadas;

    idCliente = _validaciones.leerInt("Ingrese el ID del cliente: ");


    int cantVentas = _archivo.getCantidadRegistros();
    if (cantVentas <= 0) {
        cout << "No hay ventas registradas." << endl;
        return 0;
    }

    Venta* ventas = new Venta[cantVentas];

    // leer todos los registros
    if (!_archivoventas.leerTodos(ventas, cantVentas)) {
        cout << "Error al leer las ventas desde el archivo." << endl;
        delete[] ventas;
        return 0;
    }

    float total = 0;
       bool encontrado = false;   //para validar si el ID existe

        // Recorrer ventas
        for (int i = 0; i < cantVentas; i++) {
            if (ventas[i].getIdCliente() == idCliente) {
                total += ventas[i].getImporteTotal();
                encontrado = true;
                ventasRealizadas ++;
            }
        }

        // id no encontrado
        if (!encontrado) {
            cout << "--------------------------------------" << endl;
            cout << "No se encontro ninguna venta del cliente con ID "<< idCliente << endl;
            cout << "--------------------------------------" << endl;
            return 0;
        }

    ClienteArchivo archClientes;
    int posCli = archClientes.buscarID(idCliente);

    string nombreCliente = "DESCONOCIDO";
    if (posCli != -1) {
        Clientes cli = archClientes.leer(posCli);
        nombreCliente = cli.getNombre();
    }

    // Salida formateada
    system ("cls");
    cout << fixed << setprecision(2);
    cout << "---------------------------------------" <<endl;
    cout << "RECAUDACION DE: " << nombreCliente << endl;
    cout << "TOTAL: $" << total << endl;
    cout << "TOTAL DE VENTA/S: " << ventasRealizadas  << endl;
    cout << "---------------------------------------" <<endl;

        // Liberar memoria
    delete[] ventas;

    return total;
}

float Reportes::recaudacionPorAutoparte() {
    int idAutoparte;

    idAutoparte = _validaciones.leerInt("Ingrese el ID de la autoparte a consultar: ");

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

    system ("cls");
    cout << fixed << setprecision(2);
    cout << "------------------------------------------------------------------" <<endl;
    cout << "Recaudacion total del autoparte (" << nombre << "): $" << total << endl;
    cout << "------------------------------------------------------------------" <<endl;

    // liberar memoria
    delete[] detalles;
    delete[] autopartes;

    return total;
}


