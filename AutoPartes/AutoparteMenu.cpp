#include <iostream>
#include <cstdlib>
#include "AutoparteMenu.h"

using namespace std;

void AutoparteMenu::mostrarMenu() {
    AutoparteManager manager;
    int opcion;

    do {
        system("cls"); // limpia pantalla (en Windows)
        cout << "===== MENU DE AUTOPARTES =====" << endl;
        cout << "1. Listar autopartes" << endl;
        cout << "2. Buscar autoparte por ID" << endl;
        cout << "3. Cargar nueva autoparte" << endl;
        cout << "4. Cargar stock" << endl;
        cout << "5. Buscar autopartes por categoria" <<endl;
        cout << "0. Volver al menu anterior" << endl;
        cout << "-----------------------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        // Evita que quede basura en el buffer
        cin.clear();

        system("cls");

        switch (opcion) {
            case 1:
                manager.listar();
                break;
            case 2:
                manager.BuscarPorID();
                break;
            case 3:
                manager.cargarAutoparte();
                break;
            case 4:
                manager.cargarStock();
                break;
            case 5:
                manager.BuscarPorTipo();
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
            system("pause"); // pausa hasta que el usuario presione una tecla
        }

    } while (opcion != 0);
}
