#include <iostream>
#include "VentaMenu.h"
using namespace std;

void SubMenu::VentaMenuMostrar() {
    cout << "======== MENU VENTAS ========\n";
    cout << "1. Agregar venta\n"; //
    cout << "2. Listar ventas\n"; //1. listado
    cout << "3. Buscar venta por ID\n";//2. consultas
    cout << "4. ordenar por ID/fecha/ "; //3consulta
    cout << "0. Volver\n";
}

void SubMenu::VentaMenuEjecutar() {
    int opcion;
    do {
        VentaMenuMostrar();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
            case 1: _managerVenta.agregarVenta(); break;
            case 2: _managerVenta.listarVentas(); break;
            case 3: _managerVenta.buscarVentaPorID(); break;
            case 0: break;
            default: cout << "Opcion invalida.\n";
        }
        cout << endl;
    } while (opcion != 0);
}
