#include <iostream>
#include <cstring>
#include "AutoparteManager.h"


using namespace std;



AutoparteManager::AutoparteManager(){

}

void AutoparteManager::cargarAutoparte(){
    int id, tipo, pos;
    float precioUnitario;
    string nombre;

    while (true) {
        cout << "Ingresar ID: " << endl;
        cin >> id;
        pos = _repor.buscarID(id);
        if (pos == -1) {
            break;
        }
        cout << "ID ingresado ya esta en uso. Intente nuevamente..." << endl;
    }

    cout << "Ingresar Nombre del Autoparte: " << endl;
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese la categoria de autoparte a buscar:" << endl;
    cout << "======================" << endl;
    cout << "1 = Motor" << endl;
    cout << "2 = Tren Delantero" << endl;
    cout << "3 = Suspension y Frenos" << endl;
    cout << "4 = Carroceria / Chapa" << endl;
    cout << "5 = Interior" << endl;
    cout << "6 = Encendido" << endl;
    cout << "======================" << endl;
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "Ej: Kit Distribucion, 1 ..." << endl;
    cout << "-----------------------------" << endl;
    cin >> tipo;
    while (tipo < 1 || tipo > 6) {
    cout << "Tipo invalido. Ingrese un numero entre 1 y 6: ";
    cin >> tipo;
    }

    cout << "Ingresar Precio P/U" << endl;
    while (!(cin >> precioUnitario) || precioUnitario <= 0) {
    cout << "Precio invalido. Intente nuevamente: ";
    cin.clear();
    }


    Autoparte autoparte (nombre, id, tipo, 0, precioUnitario);

    if (_repor.guardarAutoparte(autoparte))
    {
        cout << "Autoparte guardada exitosamente." << endl;
    }
    else
    {
        cout << "Error al guardar el autoparte." << endl;
    }
}

void AutoparteManager::cargarStock() {
    // pedir ID
    int id;
    cout << "Ingresar ID del autoparte a modificar stock: ";
    if (!(cin >> id)) {
        cout << "ID invalido.\n";
        cin.clear();
        return;
    }

    int pos = _repor.buscarID(id);
    if (pos == -1) {
        cout << "No existe una autoparte con ese ID.\n";
        return;
    }

    // leer la autoparte desde el repo
    _autoparte = _repor.leer(pos);
    int stockActual = _autoparte.getStock();
    cout << "Stock actual del autoparte ID " << _autoparte.getIDAutoparte() << ": " << stockActual << endl;

    cout << "Ingrese cantidad de Stock fisico: ";
    int cantidad;
    if (!(cin >> cantidad && cantidad > 0)) {
        cout << "Cantidad invalida.\n";
        cin.clear();

        return;
    }

    int nuevoStock = stockActual + cantidad;
    if (nuevoStock < 0) {
        cout << "Operación invalida: el stock no puede quedar negativo.\n";
        return;
    }

    _autoparte.setStock(nuevoStock);

    // guardar el cambio en el repositorio (modificar en la posición pos)
    if (_repor.ModificarAutoparte(pos, _autoparte)) {
        cout << "Stock actualizado. Nuevo stock: " << nuevoStock << endl;
    } else {
        cout << "Error al actualizar el stock.";
    }
}

void AutoparteManager::mostrarAutoparte (Autoparte autoparte){
    cout << "ID: " << autoparte.getIDAutoparte() << endl;
    cout << "Nombre: " << autoparte.getNombre() << endl;
    cout << "Tipo: " << autoparte.getTipo() << endl;
    cout << "Precio Unitario: " << autoparte.getPrecioUnitario() << endl;
    cout << "Stock: " << autoparte.getStock() << endl;
}
void AutoparteManager::listar(){
    int cant = _repor.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay Autopartes registradas.\n";
        return;
    }

    Autoparte *vec = new Autoparte[cant];
    _repor.leerTodos(vec, cant);
    for (int i = 0; i < cant; i++) {
        cout << "==============================" << endl;
        mostrarAutoparte(vec[i]);
        cout << "==============================" << endl;
    }

    delete[] vec;
}

void AutoparteManager::BuscarPorID() {
    int id;
    cout << "Ingrese ID de Autoparte a buscar: ";
    cin >> id;

    int pos = _repor.buscarID(id);
    if (pos == -1) {
        cout << "No se encontro el autoparte\n";
        return;
    }
    _autoparte = _repor.leer(pos);

    mostrarAutoparte(_autoparte);
}
string AutoparteManager::mostrarTipo(int tipo) {
    string nombreTipo;

    switch (tipo) {
        case 1:
            nombreTipo = "Motor";
            break;
        case 2:
            nombreTipo = "Tren Delantero";
            break;
        case 3:
            nombreTipo = "Suspensión y Frenos";
            break;
        case 4:
            nombreTipo = "Carrocería / Chapa";
            break;
        case 5:
            nombreTipo = "Interior";
            break;
        case 6:
            nombreTipo = "Encendido";
            break;
    }
    return nombreTipo;
}

void AutoparteManager::BuscarPorTipo() {
    int tipo;

    cout << "Ingrese la categoria de autoparte a buscar:" << endl;
    cout << "======================" << endl;
    cout << "1 = Motor" << endl;
    cout << "2 = Tren Delantero" << endl;
    cout << "3 = Suspension y Frenos" << endl;
    cout << "4 = Carroceria / Chapa" << endl;
    cout << "5 = Interior" << endl;
    cout << "6 = Encendido" << endl;
    cout << "======================" << endl;
    cin >> tipo;

    while (tipo < 1 || tipo > 6) {
        cout << "Tipo invalido. Ingrese un numero entre 1 y 6: ";
        cin.clear();
        cin >> tipo;
    }

    int cant = _repor.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay autopartes registradas." << endl;
        return;
    }

    Autoparte autoparte;
    bool encontrado = false;

    cout << "Categoria filtrada: " << mostrarTipo (tipo) << endl;
    cout << "=========================" << endl;

    for (int i = 0; i < cant; i++) {
        autoparte = _repor.leer(i);

        if (autoparte.getTipo() == tipo) {
            mostrarAutoparte(autoparte);
            cout << "=========================" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron autopartes de ese tipo." << endl;
    }
}




