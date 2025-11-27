#include "ReportesMenu.h"
#include <iostream>
#include <cctype>

using namespace std;

void ReportesMenu::MostrarMenu() {
    Reportes repor;
    int opcion;

    do {
        system("cls");

        cout << "===== MENU DE REPORTES =====" << endl;
        cout << "1. RECAUDACION TOTAL ANUAL" << endl;
        cout << "2. RECAUDACION POR CLIENTE" << endl;
        cout << "3. RECAUDACION POR AUTOPARTE" << endl;
        cout << "4. STOCK CRITICO" << endl;
        cout << "5. VALOR TOTAL DEL INVENTARIO" << endl;
        cout << "0. VOLVER AL MENU ANTERIOR" << endl;
        cout << "-----------------------------" << endl;

        string entrada;
        bool aux = false;

        while (!aux) {
            cout << "Opcion: ";
            cin >> entrada;

            if (entrada.size() > 10) {
                cout << "ERROR: El numero es demasiado largo..." << endl;
                break;
            }

            bool esNumero = true;
            for (char c : entrada) {
                if (!isdigit(c)) {
                    esNumero = false;
                    break;
                }
            }

            if (!esNumero) {
                cout << "ERROR: Solo se permiten numeros..." << endl;
                break;
            }

            opcion = stoi(entrada);
            aux = true;
        }

        switch (opcion) {
            case 1:
                repor.recaudacionTotalPorAnio();
                break;
            case 2:
                repor.recaudacionCliente();
                break;
            case 3:
                repor.recaudacionPorAutoparte();
                break;
            case 4:
                repor.stockCritico();
                break;
            case 5:
                repor.valorTotalInventario();
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;;
                break;
            default:
                cout << "Opcion invalida..." << endl;
                break;
        }

        if (opcion != 0) {
            cout << endl;
            system("pause");
        }

    } while (opcion != 0);
}

