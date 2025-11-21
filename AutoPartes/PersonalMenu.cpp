#include <iostream>
#include "PersonalMenu.h"
#include "PersonalArchivo.h"
using namespace std;

PersonalMenu::PersonalMenu(){
}

void PersonalMenu::mostrarMenu() {
   int opcion;

    do {
        system("cls"); // limpia pantalla (en Windows)
        cout << "===== MENU PERSONAL =====" << endl;
        cout << "1. Listar personal" << endl;
        cout << "2. Buscar personal por ID" << endl;
        cout << "3. Agregar nuevo personal" << endl;
        cout << "4. Eliminar personal" << endl;
        cout << "0. Volver al menu anterior" << endl;
        cout << "-----------------------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        //- basura en el buffer
        cin.clear();

        system("cls");

        switch (opcion) {
            case 1:
                _Manager.listar();
                break;
            case 2:
                _Manager.buscarID();
                break;
            case 3:
                _Manager.cargarPersonal();
                break;
            case 4:
                _Manager.eliminarPersonal();
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
