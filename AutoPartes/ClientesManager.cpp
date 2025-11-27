#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>  // Para isdigit
#include "ClienteManager.h"

using namespace std;

ClienteManager::ClienteManager() {}

void ClienteManager::cargarCliente() {
    int idCliente, Telefono, pos;
    string Nombre, Cuit, Categoria, Direccion, Mail;

    // VALIDAR ID
    do {
        string temp;
        bool valido = false;

        do {
            cout << "Ingresar ID (solo numeros): ";
            cin >> temp;
            valido = true;
            for (size_t i = 0; i < temp.size(); i++) {
                if (!isdigit(temp[i])) {
                    valido = false;
                    cout << "Error: solo se permiten numeros." << endl;
                    break;
                }
            }
        } while (!valido);

        idCliente = stoi(temp);
        cin.ignore(); // Limpiar buffer

        pos = _repor.buscarID(idCliente);
        if (pos != -1) {
            cout << "ID ingresado ya está en uso. Intente nuevamente..." << endl;
        }
    } while (pos != -1);

    // Razon social
    cout << "Ingresar Razon social: ";
    getline(cin, Nombre);

    // VALIDAR CUIT
    do {
        bool valido = true;
        cout << "Ingresar CUIT (solo numeros): ";
        getline(cin, Cuit);
        for (size_t i = 0; i < Cuit.size(); i++) {
            if (!isdigit(Cuit[i])) {
                valido = false;
                cout << "Error: solo se permiten numeros." << endl;
                break;
            }
        }
        if (valido && (Cuit.size() != 10)) {
            valido = false;
            cout << "Error: CUIT debe tener 10 digitos." << endl;
        }
        if (valido) break;
    } while (true);

    // VALIDAR TELEFONO
    do {
        string temp;
        bool valido = false;
        do {
            cout << "Ingresar Telefono (solo numeros): ";
            cin >> temp;
            valido = true;
            for (size_t i = 0; i < temp.size(); i++) {
                if (!isdigit(temp[i])) {
                    valido = false;
                    cout << "Error: solo se permiten numeros." << endl;
                    break;
                }
            }
        } while (!valido);
        Telefono = stoi(temp);
        cin.ignore();
        break;
    } while (true);

    // Direccion (sin validacion)
    cout << "Ingresar Direccion: ";
    getline(cin, Direccion);

    // VALIDAR MAIL
    do {
        cout << "Ingresar Mail (debe contener @): ";
        getline(cin, Mail);
        if (Mail.find('@') != string::npos) break;
        cout << "Error: el mail debe contener '@'." << endl;
    } while (true);

    // Categoria
    int opcionCategoria;
    cout << "Seleccionar una Categoria:" << endl;
    cout << "1- Taller" << endl;
    cout << "2- Concesionaria" << endl;
    cout << "3- Fabrica" << endl;
    cout << "4- Chapista" << endl;
    cout << "-----------------------------" << endl;
    cout << "Ingrese opcion (1-4): ";
    cin >> opcionCategoria;
    cin.ignore();

    switch(opcionCategoria) {
        case 1: Categoria = "Taller"; break;
        case 2: Categoria = "Concesionaria"; break;
        case 3: Categoria = "Fabrica"; break;
        case 4: Categoria = "Chapista"; break;
        default: Categoria = "Otros"; break;
    }

    // Crear cliente y guardar
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
    Clientes *vec = nullptr;
    vec = new Clientes[cant];
    if (vec == nullptr) {
        cout << "ERROR DE ASIGNACION DE MEMORIA\n";
        return;
    }

    int leidos = _repor.leerTodos(vec, cant);

    for (int i = 0; i < leidos; i++) {
        if (vec[i].getIDCliente() != -1) { // id -1
            mostrarCliente(vec[i]);
        }
    }

    delete[] vec;
}

void ClienteManager::listarPorNombre() {
    int cant = _repor.getCantidadRegistros();

    if (cant == 0) {
        cout << "No hay clientes registrados." << endl;
        return;
    }

    Clientes *vec = nullptr;
    vec = new Clientes[cant];
    if (vec == nullptr) {
        cout << "ERROR DE ASIGNACION DE MEMORIA\n";
        return;
    }

    int leidos = _repor.leerTodos(vec, cant);

    //Ordenamiento
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
        if (vec[i].getIDCliente() != -1) {   // id -1 elimina2
            mostrarCliente(vec[i]);
        }
    }
    delete[] vec;
}

void ClienteManager::listarPorCategoria() {
    int opcion;
    string categoria;

    do {
        cout << "Seleccionar una Categoria:" << endl;
        cout << "1- Taller" << endl;
        cout << "2- Concesionaria" << endl;
        cout << "3- Fabrica" << endl;
        cout << "4- Chapista" << endl;
        cout << "5- Cancelar" << endl;
        cout << "Ingrese opcion (1-5): ";
        cin >> opcion;
        cin.ignore();

        if (opcion < 1 || opcion > 5) {
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion < 1 || opcion > 5);

    if (opcion == 5) {
        cout << "Operacion cancelada." << endl;
        return;
    }

    switch(opcion) {
        case 1: categoria = "Taller"; break;
        case 2: categoria = "Concesionaria"; break;
        case 3: categoria = "Fabrica"; break;
        case 4: categoria = "Chapista"; break;
    }

    int cant = _repor.getCantidadRegistros();

    if (cant == 0) {
        cout << "No hay clientes registrados." << endl;
        return;
    }

    Clientes *vec = nullptr;
    vec = new Clientes[cant];

    if (vec == nullptr) {
        cout << "ERROR DE ASIGNACION DE MEMORIA\n";
        return;
    }

    int leidos = _repor.leerTodos(vec, cant);

    bool hay = false;

    cout << "=== LISTADO DE CLIENTES EN LA CATEGORIA: "
         << categoria << " ===\n";

    for (int i = 0; i < leidos; i++) {
        if (vec[i].getIDCliente() != -1 &&
            vec[i].getCategoria() == categoria) {

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

    Clientes *vec = nullptr;
    vec = new Clientes[cant];

    if (vec == nullptr) {
        cout << "ERROR DE ASIGNACION DE MEMORIA\n";
        return;
    }

    int leidos = _repor.leerTodos(vec, cant);

    bool encontrado = false;

    for (int i = 0; i < leidos; i++) {
        if (vec[i].getIDCliente() != -1 &&
            vec[i].getNombre() == nombreBuscado) {

            mostrarCliente(vec[i]);
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron clientes con el nombre: "
             << nombreBuscado << endl;
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

void ClienteManager::eliminarCliente() {
    int id;
    cout << "Ingrese el ID del cliente a eliminar: ";
    cin >> id;

    int pos = _repor.buscarID(id);

    if (pos == -1) {
        cout << "No se encontró ningún cliente con ese ID." << endl;
        return;
    }

    Clientes cliente = _repor.leer(pos);

    cout << "Se eliminará el siguiente cliente:" << endl;
    mostrarCliente(cliente);

    char opcion;
    cout << "¿Está seguro? (s/n): ";
    cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        cliente.setIDCliente(-1);
        if (_repor.modificarCliente(cliente, pos)) {
            cout << "Cliente eliminado correctamente." << endl;
        } else {
            cout << "Error al eliminar el cliente." << endl;
        }
    } else {
        cout << "Operación cancelada." << endl;
    }
}
