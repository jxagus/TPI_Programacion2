#include <iostream>
#include "SubMenu.h"



using namespace std;
//menu llama a...

SubMenu::SubMenu(){
}

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

void SubMenu::AutoparteMenuMostrar () {
    cout << "======== MENU AUTOPARTES ========\n";
    cout << "1. Agregar Autoparte\n";
    cout << "2. Stock on hand\n"; //consulta
    cout << "3. Buscar Autoparte por ID\n"; //consulta
    cout << "4. Reposicion de stock\n"; //listado
    cout << "0. Volver\n";
}

void SubMenu::AutoparteMenuEjecutar(){
    int opcion;
    do {
        AutoparteMenuMostrar();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
            case 1:
                _managerAutoparte.cargarAutoparte();
                 break;
            case 2:
                _managerAutoparte.listar();
                break;
            case 3:
                _managerAutoparte.BuscarPorID();
            break;
             case 4:
                 _managerAutoparte.cargarStock();
                 break;
            case 0:
                break;
            default: cout << "Opcion invalida.\n";
        }
        cout << endl;
    } while (opcion != 0);
}
void SubMenu::PersonalMenuMostrar () {
    cout << "======== MENU PERSONAL ========\n";
    cout << "1. Agregar personal\n";
    cout << "2. Listado del personal\n";
    cout << "0. Volver\n";
}
void SubMenu::PersonalMenuEjecutar(){
    int opcion;
    do {
        PersonalMenuMostrar();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
            case 1:
                //_managerAutoparte.cargarAutoparte();
                 break;
            case 2:
                //_managerAutoparte.listar();
                break;
            case 0:
                break;
            default: cout << "Opcion invalida.\n";
        }
        cout << endl;
    } while (opcion != 0);
}
