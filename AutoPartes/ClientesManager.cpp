#include <iostream>
#include <cctype>
#include "ClienteManager.h"

using namespace std;

ClienteManager::ClienteManager() {}

void ClienteManager::cargarCliente() {
    int Telefono;
    string Nombre, Cuit, Categoria, Direccion, Mail;

    int idCliente = _repor.getNuevoID();
    cout << "ID asignado automaticamente: " << idCliente << endl;

    cout << "Ingresar Razon social: ";
    cin.ignore();
    getline(cin, Nombre);

    // VALIDAR CUIT
    do {
        bool valido = true;
        cout << "Ingresar CUIT (solo numeros): ";
        getline(cin, Cuit);

        for (char c : Cuit) {
            if (!isdigit(c)) {
                valido = false;
                cout << "Error: solo numeros.\n";
                break;
            }
        }

        if (valido && Cuit.size() != 10) {
            valido = false;
            cout << "Error: debe tener 10 digitos.\n";
        }

        if (valido) break;
    } while (true);

    // TELEFONO
    do {
        string temp;
        bool valido = true;
        cout << "Ingrese Telefono: ";
        getline(cin, temp);

        for (char c : temp) {
            if (!isdigit(c)) {
                valido = false;
                cout << "Error: solo numeros.\n";
                break;
            }
        }

        if (valido) {
            Telefono = stoi(temp);
            break;
        }
    } while (true);

    cout << "Ingresar Direccion: ";
    getline(cin, Direccion);

    // MAIL
    do {
        cout << "Ingresar Mail: ";
        getline(cin, Mail);
        if (Mail.find('@') != string::npos) break;
        cout << "Mail invalido.\n";
    } while (true);

    // CATEGORIA
    int op;
    cout << "1- Taller\n2- Concesionaria\n3- Fabrica\n4- Chapista\nOpcion: ";
    cin >> op;

    switch (op) {
        case 1: Categoria = "Taller"; break;
        case 2: Categoria = "Concesionaria"; break;
        case 3: Categoria = "Fabrica"; break;
        case 4: Categoria = "Chapista"; break;
        default: Categoria = "Otros";
    }

    Clientes cli(idCliente, Categoria, Direccion, Nombre, Telefono, Cuit, Mail);

    if (_repor.guardarCliente(cli))
        cout << "Cliente guardado correctamente.\n";
    else
        cout << "Error al guardar cliente.\n";
}

void ClienteManager::mostrarCliente(Clientes cliente) {
    cout << "--------------------------\n";
    cout << "ID: " << cliente.getIDCliente() << endl;
    cout << "Nombre: " << cliente.getNombre() << endl;
    cout << "CUIT: " << cliente.getCUIT() << endl;
    cout << "Telefono: " << cliente.getTelefono() << endl;
    cout << "Direccion: " << cliente.getDireccion() << endl;
    cout << "Mail: " << cliente.getMail() << endl;
    cout << "Categoria: " << cliente.getCategoria() << endl;
    cout << "Estado: " << (cliente.getEstado() ? "Activo" : "Baja") << endl;
    cout << "--------------------------\n";
}

void ClienteManager::listar() {
    int cant = _repor.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay clientes.\n";
        return;
    }

    Clientes* vec = new Clientes[cant];
    int leidos = _repor.leerTodos(vec, cant);

    for (int i = 0; i < leidos; i++) {
        if (vec[i].getEstado()) {
            mostrarCliente(vec[i]);
        }
    }

    delete[] vec;
}

void ClienteManager::listarPorNombre() {
    int cant = _repor.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay clientes.\n";
        return;
    }

    Clientes* vec = new Clientes[cant];
    int leidos = _repor.leerTodos(vec, cant);

    // Ordenamiento burbuja
    for (int i = 0; i < leidos - 1; i++) {
        for (int j = 0; j < leidos - i - 1; j++) {
            if (vec[j].getNombre() > vec[j + 1].getNombre()) {
                Clientes aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }

    for (int i = 0; i < leidos; i++) {
        if (vec[i].getEstado()) {
            mostrarCliente(vec[i]);
        }
    }

    delete[] vec;
}

void ClienteManager::listarPorCategoria() {
    int op;
    string categoria;

    cout << "1- Taller\n2- Concesionaria\n3- Fabrica\n4- Chapista\nOpcion: ";
    cin >> op;

    switch (op) {
        case 1: categoria = "Taller"; break;
        case 2: categoria = "Concesionaria"; break;
        case 3: categoria = "Fabrica"; break;
        case 4: categoria = "Chapista"; break;
        default:
            cout << "Opcion invalida.\n";
            return;
    }

    int cant = _repor.getCantidadRegistros();
    Clientes* vec = new Clientes[cant];
    int leidos = _repor.leerTodos(vec, cant);

    bool hay = false;

    for (int i = 0; i < leidos; i++) {
        if (vec[i].getEstado() && vec[i].getCategoria() == categoria) {
            mostrarCliente(vec[i]);
            hay = true;
        }
    }

    if (!hay) {
        cout << "No hay clientes en esa categoria.\n";
    }

    delete[] vec;
}

void ClienteManager::BuscarPorNombre() {
    string nombre;
    bool valido = false;

    while (valido == false) {
        cout << "Ingrese nombre a buscar: ";
        cin.ignore();
        getline(cin, nombre);

        valido = true;

        for (int i = 0; i < nombre.size(); i++) {
            if (!isalpha(nombre[i]) && nombre[i] != ' ') {
                valido = false;
            }
        }

        if (valido == false) {
            cout << "Error: solo se permiten letras y espacios.\n";
        }
    }

    int cant = _repor.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay clientes cargados.\n";
        return;
    }

    Clientes* vec = new Clientes[cant];
    int leidos = _repor.leerTodos(vec, cant);

    bool encontrado = false;

    for (int i = 0; i < leidos; i++) {
        if (vec[i].getEstado() == true &&
            vec[i].getNombre() == nombre) {

            mostrarCliente(vec[i]);
            encontrado = true;
        }
    }

    if (encontrado == false) {
        cout << "No se encontro el cliente.\n";
    }

    delete[] vec;
}

void ClienteManager::BuscarID() {
    string temp;
    bool valido = false;
    int id;

    while (valido == false) {
        cout << "Ingrese ID a buscar: ";
        cin >> temp;

        valido = true;

        for (int i = 0; i < temp.size(); i++) {
            if (!isdigit(temp[i])) {
                valido = false;
            }
        }

        if (valido == false) {
            cout << "Error: el ID debe contener solo numeros.\n";
        }
    }

    id = stoi(temp);

    int pos = _repor.buscarID(id);
    if (pos == -1) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    Clientes cli = _repor.leer(pos);

    if (cli.getEstado() == true) {
        mostrarCliente(cli);
    } else {
        cout << "El cliente esta dado de baja.\n";
    }
}

void ClienteManager::eliminarCliente() {
    int id;
    cout << "Ingrese ID del cliente a dar de baja: ";
    cin >> id;

    int pos = _repor.buscarID(id);
    if (pos == -1) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    Clientes cli = _repor.leer(pos);

    if (!cli.getEstado()) {
        cout << "El cliente ya esta dado de baja.\n";
        return;
    }

    mostrarCliente(cli);

    char op;
    cout << "Confirmar baja (s/n): ";
    cin >> op;

    if (op == 's' || op == 'S') {
        cli.setEstado(false);
        _repor.modificarCliente(cli, pos);
        cout << "Cliente dado de baja.\n";
    }
}

void ClienteManager::reactivarCliente() {
    int cant = _repor.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay clientes cargados." << endl;
        return;
    }

    Clientes* vec = new Clientes[cant];
    int leidos = _repor.leerTodos(vec, cant);

    bool hayBajas = false;

    cout << "=== CLIENTES DADOS DE BAJA ===" << endl;
    for (int i = 0; i < leidos; i++) {
        if (!vec[i].getEstado()) {
            cout << "ID: " << vec[i].getIDCliente()
                 << " | Nombre: " << vec[i].getNombre()
                 << " | CUIT: " << vec[i].getCUIT() << endl;
            hayBajas = true;
        }
    }

    if (!hayBajas) {
        cout << "No hay clientes dados de baja." << endl;
        delete[] vec;
        return;
    }

    //Validacion por id
    int id;
    string temp;

    do {
        bool valido = true;
        cout << "\nIngrese ID del cliente a reactivar (0 para cancelar): ";
        cin >> temp;

        for (char c : temp) {
            if (!isdigit(c)) {
                valido = false;
                cout << "Error: solo se permiten numeros." << endl;
                break;
            }
        }

        if (valido) {
            id = stoi(temp);
            break;
        }

    } while (true);

    if (id == 0) {
        cout << "Operacion cancelada." << endl;
        delete[] vec;
        return;
    }

    int pos = _repor.buscarID(id);
    if (pos == -1) {
        cout << "ID inexistente." << endl;
        delete[] vec;
        return;
    }

    Clientes cli = _repor.leer(pos);

    if (cli.getEstado()) {
        cout << "El cliente ya esta activo." << endl;
        delete[] vec;
        return;
    }

    cli.setEstado(true);
    _repor.modificarCliente(cli, pos);

    cout << "Cliente reactivado correctamente." << endl;

    delete[] vec;
}

