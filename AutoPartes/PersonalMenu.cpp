#include <iostream>
#include "PersonalMenu.h"
#include "PersonalArchivo.h"
using namespace std;

PersonalMenu::PersonalMenu(){
}

void PersonalMenu::mostrarMenu() {
   int opcion;

    do {
        system("cls");
        cout << "===== MENU PERSONAL =====" << endl;
        cout << "1. Listar personal" << endl;
        cout << "2. Listar personal por Apellido" << endl;
        cout << "3. Buscar personal por ID" << endl;
        cout << "4. Agregar nuevo personal" << endl;
        cout << "5. Eliminar personal" << endl;
        cout << "6. Listar personal bajado" << endl;
        cout << "0. Volver al menu anterior" << endl;
        cout << "-----------------------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        cin.clear();

        system("cls");

        switch (opcion) {
            case 1:
                _Manager.listar();
                break;
            case 2:
                _Manager.listarPorApellido();
                break;
            case 3:
                _Manager.buscarID();
                break;
            case 4:
                _Manager.cargarPersonal();
                break;
            case 5:
                _Manager.eliminarPersonal();
                break;
            case 6:
                _Manager.listarPersonalBajado();
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
