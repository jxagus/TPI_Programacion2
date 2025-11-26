#include <iostream>
#include <vector>
#include <algorithm>
#include "ClienteManager.h"

using namespace std;

ClienteManager::ClienteManager() {}

void ClienteManager::cargarCliente() {
    int idCliente, Telefono, pos;
    string Nombre, Cuit, Categoria, Direccion, Mail;

    do {
        cout << "Ingresar ID: ";
        cin >> idCliente;
        cin.ignore(); // Limpiar buffer

        pos = _repor.buscarID(idCliente);
        if (pos != -1) {
            cout << "ID ingresado ya está en uso. Intente nuevamente..." << endl;
        }
    } while (pos != -1);

    cout << "Ingresar Razon social: ";
    getline(cin, Nombre);

    cout << "Ingresar Cuit: ";
    getline(cin, Cuit);

    cout << "Ingresar Telefono: ";
    cin >> Telefono;
    cin.ignore();

    cout << "Ingresar Direccion: ";
    getline(cin, Direccion);

    cout << "Ingresar Mail: ";
    getline(cin, Mail);

    int opcionCategoria;
    cout << "Seleccionar una Categoria:" << endl;
    cout << "1- Taller" << endl;
    cout << "2- Concesionaria" << endl;
    cout << "3- Fabrica" << endl;
    cout << "4- Chapista" << endl;
    cout << "-----------------------------" << endl;
    cout << "Ingrese opción (1-4): ";
    cin >> opcionCategoria;
    cin.ignore();

    switch(opcionCategoria) {
        case 1: Categoria = "Taller"; break;
        case 2: Categoria = "Concesionaria"; break;
        case 3: Categoria = "Fabrica"; break;
        case 4: Categoria = "Chapista"; break;
        default: Categoria = "Otros"; break;
    }

    Clientes clientes(idCliente, Categoria, Direccion, Nombre, Telefono, Cuit, Mail);

    if (_repor.guardarCliente(clientes)) {
        cout << "Cliente guardado exitosamente." << endl;
    } else {
        cout << "Error al guardar el cliente." << endl;
    }
}

// Mostrar datos de un cliente
void ClienteManager::mostrarCliente(Clientes cliente){
    cout << "---------------------------\n";
    cout << "ID : " << cliente.getIDCliente() << endl;
    cout << "Nombre: " << cliente.getNombre() << endl;
    cout << "CUIT : " << cliente.getCUIT() << endl;
    cout << "Telefono: " << cliente.getTelefono() << endl;
    cout << "Direccion: " << cliente.getDireccion() << endl;
    cout << "Mail : " << cliente.getMail() << endl;
    cout << "Categoria : " << cliente.getCategoria() << endl;
    cout << "---------------------------\n";
}

void ClienteManager::listar() {
    int cant = _repor.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay clientes registrados.\n";
        return;
    }

    Clientes *vec = new Clientes[cant];
    int leidos = _repor.leerTodos(vec, cant);

    for (int i = 0; i < leidos; i++) {
        mostrarCliente(vec[i]);
    }

    delete[] vec;
}

void ClienteManager::listarPorNombre() {
    vector<Clientes> lista;
    int cant = _repor.getCantidadRegistros();

    for (int pos = 0; pos < cant; pos++) {
        Clientes reg = _repor.leer(pos);
        if (reg.getIDCliente() != -1) {
            lista.push_back(reg);
        }
    }

    if (lista.empty()) {
        cout << "No hay clientes cargados." << endl;
        return;
    }

    sort(lista.begin(), lista.end(),
         [](const Clientes &a, const Clientes &b) {
             return a.getNombre() < b.getNombre();
         });

    cout << "=== LISTADO ORDENADO POR NOMBRE (A-Z) ===\n";
    for (auto &p : lista) {
        mostrarCliente(p);
    }
}

void ClienteManager::BuscarID() {
    int id;
    cout << "Ingrese ID del cliente a buscar: ";
    cin >> id;

    int pos = _repor.buscarID(id);
    if (pos == -1) {
        cout << "No se encontro el cliente.\n";
        return;
    }

    Clientes cliente = _repor.leer(pos);
    mostrarCliente(cliente);
}
