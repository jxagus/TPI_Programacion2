#include <iostream>
#include "AutoparteMenu.h"
using namespace std;


void AutoparteMenuMostrar () {
    cout << "======== MENU AUTOPARTES ========\n";
    cout << "1. Agregar Autoparte\n";
    cout << "2. Stock on hand\n"; //consulta
    cout << "3. Buscar Autoparte por ID\n"; //consulta
    cout << "4. Reposicion de stock\n"; //listado
    cout << "0. Volver\n";
}

void AutoparteMenuEjecutar(){
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
