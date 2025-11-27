#include <iostream>
#include <cstdlib>      // para system("cls") y system("pause")
#include "VentaMenu.h"

using namespace std;

void VentaMenu::mostrarMenu() {
    VentaManager manager;
    int opcion;

    do {
        system("cls");
        cout << "===== MENU DE VENTAS =====" << endl;
        cout << "1. Listar ventas" << endl;
        cout << "2. Buscar venta por ID" << endl;
        cout << "3. Buscar venta por Cliente" << endl;
        cout << "4. Buscar venta por Autoparte" << endl;
        cout << "5. Buscar venta por Fecha" << endl;
        cout << "6. Agregar nueva venta" << endl;
        cout << "0. Volver al menu anterior" << endl;
        cout << "--------------------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        cin.clear();
        system("cls");

        switch (opcion) {
            case 1:
               manager.listarVentas();
                break;
            case 2:
               manager.buscarVentaPorID();
                break;
            case 3:
                manager.buscarVentaPorCliente();
                break;
            case 4:
                manager.buscarVentaPorAutopartes();
                break;
            case 5:
                manager.buscarVentasPorFecha();
                break;
            case 6:
                manager.agregarVenta();
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
        }

        if (opcion != 0) {
            cout << endl;
            system("pause");
        }

    } while (opcion != 0);
}
