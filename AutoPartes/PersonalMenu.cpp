#include "PersonalMenu.h"
#include <iostream>
using namespace std;

void PersonalMenu::mostrarMenu() {
    int opcion;
    do {
        cout << "\n=== MENU PERSONAL ===\n";
        cout << "1. Agregar personal\n";
        cout << "2. Listar personal\n";
        cout << "3. Buscar por ID\n";
        cout << "4. Modificar telefono\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: _manager.agregarPersonal(); break;
        case 2: _manager.listarPersonal(); break;
        case 3: _manager.buscarPorId(); break;
        case 4: _manager.modificarTelefono(); break;
        case 0: break;
        default: cout << "Opcion invalida.\n"; break;
        }
    } while (opcion != 0);
}
