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
        cout << "3. Listar cliente por nombre" << endl;
        cout << "4. Buscar cliente por ID" << endl;
        cout << "5. Buscar cliente por Nombre" << endl;
        cout << "6. Cargar nuevo cliente" << endl;
        cout << "7. Dar de baja al cliente" << endl;
        cout << "0. Volver al menu anterior" << endl;
        cout << "-----------------------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.clear();

        system("cls");

        switch (opcion) {
            case 1:
                manager.listar();
                break;
            case 2:
                manager.listarPorCategoria();
                break;
            case 3:
                manager.listarPorNombre();
                break;
            case 4:
                manager.BuscarID();
                break;
            case 5:
                manager.BuscarPorNombre();
                break;
            case 6:
                manager.cargarCliente();
                break;
            case 7:
                manager.eliminarCliente();
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
