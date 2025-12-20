#include <iostream>
#include "PersonalManager.h"
#include "Personal.h"

using namespace std;

PersonalManager::PersonalManager() {
}

int PersonalManager::generarNuevoID() {
    int cant = _repor.getcantidadRegistros();
    if (cant == 0) return 1;

    Personal ultimo = _repor.leer(cant - 1);
    return ultimo.getID() + 1;
}

void PersonalManager::cargarPersonal() {
    int DNI;
    string Nombre, Apellido, Telefono, Mail;

    // ID autogenerativo
    int id = generarNuevoID();

    // Nombre
    do {
        cout << "Ingresar Nombre: ";
        cin >> Nombre;

        bool ok = true;
        for (char c : Nombre) {
            if (!isalpha(c)) ok = false;
        }

        if (!ok) cout << "Error: el nombre solo debe contener letras.\n";
        else break;
    } while (true);

    // Apellido
    do {
        cout << "Ingresar Apellido: ";
        cin >> Apellido;

        bool ok = true;
        for (char c : Apellido) {
            if (!isalpha(c)) ok = false;
        }

        if (!ok) cout << "Error: el apellido solo debe contener letras.\n";
        else break;
    } while (true);

    // DNI
    string strDNI;
    do {
        cout << "Ingresar DNI: ";
        cin >> strDNI;

        bool ok = true;
        for (char c : strDNI) {
            if (!isdigit(c)) ok = false;
        }

        if (!ok) cout << "Error: el DNI debe ser numerico.\n";
        else break;
    } while (true);

    DNI = stoi(strDNI);

    // Telefono
    do {
        cout << "Ingresar Telefono: ";
        cin >> Telefono;

        bool ok = true;
        for (char c : Telefono) {
            if (!isdigit(c)) ok = false;
        }

        if (!ok) cout << "Error: el telefono debe contener solo numeros.\n";
        else break;
    } while (true);

    // Mail
    do {
        cout << "Ingresar Mail: ";
        cin >> Mail;

        if (Mail.find('@') == string::npos) {
            cout << "Error: el email debe contener '@'.\n";
        } else break;
    } while (true);

    Personal personal(id, DNI, Nombre, Apellido, Telefono, Mail);

    if (_repor.guardarPersonal(personal)) {
        cout << "Personal guardado exitosamente." << endl;
        cout << "ID asignado: " << id << endl;
    } else {
        cout << "Error al guardar el personal." << endl;
    }
}

void PersonalManager::mostrarPersonal(Personal personal) {
    cout << "ID: " << personal.getID() << endl;
    cout << "Nombre: " << personal.getNombre() << endl;
    cout << "Apellido: " << personal.getApellido() << endl;
    cout << "Telefono: " << personal.getTelefono() << endl;
    cout << "Mail: " << personal.getMail() << endl;
    cout << "Estado: " << (personal.getEstado() ? "Activo" : "Baja") << endl;
    cout << "---------------------------" << endl;
}

void PersonalManager::listar() {
    int cant = _repor.getcantidadRegistros();

    if (cant == 0) {
        cout << "No hay personal registrado.\n";
        return;
    }

    Personal *vec = new Personal[cant];
    if (vec == nullptr) {
        cout << "ERROR DE ASIGNACION DE MEMORIA\n";
        return;
    }

    int leidos = _repor.leerTodos(vec, cant);

    cout << "===== LISTADO DE PERSONAL =====\n";
    for (int i = 0; i < leidos; i++) {
        if (vec[i].getEstado()) {
            mostrarPersonal(vec[i]);
            cout << "---------------------------\n";
        }
    }

    delete[] vec;
}

void PersonalManager::listarPorApellido() {
    int cant = _repor.getcantidadRegistros();

    if (cant == 0) {
        cout << "No hay personal registrado.\n";
        return;
    }

    Personal *vec = new Personal[cant];
    if (vec == nullptr) {
        cout << "ERROR DE ASIGNACION DE MEMORIA\n";
        return;
    }

    int leidos = _repor.leerTodos(vec, cant);

    // Ordenamiento burbuja
    for (int i = 0; i < leidos - 1; i++) {
        for (int j = 0; j < leidos - i - 1; j++) {
            if (vec[j].getApellido() > vec[j + 1].getApellido()) {
                Personal temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }

    cout << "=== LISTADO DE PERSONAL ORDENADO POR APELLIDO ===\n";
    for (int i = 0; i < leidos; i++) {
        if (vec[i].getEstado()) {
            mostrarPersonal(vec[i]);
            cout << "---------------------------\n";
        }
    }

    delete[] vec;
}

void PersonalManager::listarPersonalBajado() {
    int cantidad = _repor.getcantidadRegistros();

    if (cantidad == 0) {
        cout << "No hay personal cargado." << endl;
        return;
    }

    bool hayBajados = false;
    Personal reg;

    for (int i = 0; i < cantidad; i++) {
        if (_repor.leer(reg, i)) {
            if (reg.getEstado() == false) {
                mostrarPersonal(reg);
                hayBajados = true;
            }
        }
    }

    if (!hayBajados) {
        cout << "No hay personal dado de baja." << endl;
    }
}

void PersonalManager::buscarID() {
    int id;
    cout << "Ingrese ID del personal: ";
    cin >> id;

    int pos = _repor.buscarID(id);
    if (pos == -1) {
        cout << "No existe registro." << endl;
        return;
    }

    Personal reg = _repor.leer(pos);

    if (!reg.getEstado()) {
        cout << "El registro existe pero está eliminado." << endl;
        return;
    }

    mostrarPersonal(reg);
}

void PersonalManager::eliminarPersonal() {
    int cant = _repor.getcantidadRegistros();
    if (cant == 0) {
        cout << "No hay personal cargado." << endl;
        return;
    }

    string strID;
    int id;

    do {
        cout << "Ingrese el ID del personal a eliminar: ";
        cin >> strID;

        bool valido = true;
        for (char c : strID) {
            if (!isdigit(c)) {
                valido = false;
                break;
            }
        }

        if (!valido) {
            cout << "Error: solo se permiten numeros." << endl;
        } else {
            id = stoi(strID);
            break;
        }

    } while (true);

    int pos = _repor.buscarID(id);
    if (pos == -1) {
        cout << "No existe personal con ese ID." << endl;
        return;
    }

    Personal reg = _repor.leer(pos);

    if (!reg.getEstado()) {
        cout << "El personal ya se encuentra eliminado." << endl;
        return;
    }

    reg.setEstado(false);

    if (_repor.modificarPersonal(reg, pos)) {
        cout << "Personal eliminado correctamente." << endl;
    } else {
        cout << "No se pudo eliminar el personal." << endl;
    }
}
