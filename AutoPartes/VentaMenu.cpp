#include "VentaMenu.h"
#include <iostream>
using namespace std;

void VentaMenu::mostrarOpciones() {
    cout << "======== MENU VENTAS ========\n";
    cout << "1. Agregar venta\n";
    cout << "2. Listar ventas\n";
    cout << "3. Buscar venta por ID\n";
    cout << "0. Volver\n";
}

void VentaMenu::ejecutar() {
    int opcion;
    do {
        mostrarOpciones();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
            case 1: _manager.agregarVenta(); break;
            case 2: _manager.listarVentas(); break;
            case 3: _manager.buscarVentaPorID(); break;
            case 0: break;
            default: cout << "Opcion invalida.\n";
        }
        cout << endl;
    } while (opcion != 0);
}
