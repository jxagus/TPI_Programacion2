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

float Reportes::RecaudacionTotal (){
    DetalleVentaArchivo archivo;
    int cantidad = archivo.contarRegistros();
    float total = 0.0;

    for (int i = 0; i < cantidad; i++){
        DetalleVenta  d = archivo.leer(d, i);
        float recaudacion;
        recaudacion += d.getPrecio ();
    }
    cout << "========================================" << endl;
    cout << "GANANCIAS TOTALES REGISTRADAS" << endl;
    cout << "========================================" << endl;
    cout << "Total: $" << fixed << setprecision(2) << total << endl;
    cout << "========================================" << endl;

    return total;
}

