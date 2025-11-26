#include <iostream>
#include "ClientesMenu.h"
using namespace std;

ClientesMenu::ClientesMenu(){

}

void ClientesMenu::MostrarMenu() {
    ClienteManager manager;
    int opcion;

    do {
        system("cls");
        cout << "===== MENU DE CLIENTES =====" << endl;
        cout << "1. Listar todos los clientes" << endl;
        cout << "2. Listar clientes por categoria" << endl;
        cout << "3. Buscar cliente por ID" << endl;
        cout << "4. Buscar cliente por nombre" << endl;
        cout << "5. Cargar nuevo cliente" << endl;
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
                cout << "Listar clientes por categoria" << endl;

                break;
            case 3:
                manager.BuscarID();
                break;
            case 4:
                cout << "buscar cliente por nombres" << endl;
                break;
            case 5:
                manager.cargarCliente();
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
