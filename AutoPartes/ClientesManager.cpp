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
    int cant = _repor.getCantidadRegistros();

    if (cant == 0) {
        cout << "No hay clientes registrados." << endl;
        return;
    }

    Clientes *vec = new Clientes[cant];
    int leidos = _repor.leerTodos(vec, cant);

    for (int i = 0; i < leidos - 1; i++) {
        for (int j = 0; j < leidos - i - 1; j++) {
            if (vec[j].getNombre() > vec[j + 1].getNombre()) {
                Clientes temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }

    cout << "=== LISTADO DE CLIENTES ORDENADO POR NOMBRE ===\n";
    for (int i = 0; i < leidos; i++) {
        mostrarCliente(vec[i]);
    }

    delete[] vec;
}

void ClienteManager::listarPorCategoria() {
    string categoria;
    cout << "Ingrese la categoria a listar (Taller, Concesionaria, Fabrica, Chapista, Otros): ";
    cin.ignore();
    getline(cin, categoria);

    int cant = _repor.getCantidadRegistros();

    if (cant == 0) {
        cout << "No hay clientes registrados." << endl;
        return;
    }

    Clientes *vec = new Clientes[cant];
    int leidos = _repor.leerTodos(vec, cant);

    bool hay = false;

    cout << "=== LISTADO DE CLIENTES EN LA CATEGORIA: " << categoria << " ===\n";

    for (int i = 0; i < leidos; i++) {
        if (vec[i].getCategoria() == categoria) {
            mostrarCliente(vec[i]);
            hay = true;
        }
    }

    if (!hay) {
        cout << "No hay clientes en esta categoria." << endl;
    }

    delete[] vec;
}

void ClienteManager::BuscarPorNombre() {
    string nombreBuscado;
    cout << "Ingrese el nombre a buscar: ";
    cin.ignore();
    getline(cin, nombreBuscado);

    int cant = _repor.getCantidadRegistros();

    if (cant == 0) {
        cout << "No hay clientes registrados." << endl;
        return;
    }

    Clientes *vec = new Clientes[cant];
    int leidos = _repor.leerTodos(vec, cant);

    bool encontrado = false;

    for (int i = 0; i < leidos; i++) {
        if (vec[i].getNombre() == nombreBuscado) {
            mostrarCliente(vec[i]);
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron clientes con el nombre: " << nombreBuscado << endl;
    }

    delete[] vec;
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
