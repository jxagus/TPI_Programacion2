#include <iostream>
#include "PersonalManager.h"
#include "Personal.h"

using namespace std;

PersonalManager::PersonalManager(){
}

void PersonalManager::cargarPersonal() {
    int DNI, id, pos;
    string Nombre, Apellido, Telefono, Mail;

    //ID solo numeros + ID unico
    string strID;
    do {
        cout << "Ingresar ID: ";
        cin >> strID;

        bool ok = true;
        for (char c : strID) {
            if (!isdigit(c)) ok = false;
        }

        if (!ok) {
            cout << "Error: el ID debe contener solo numeros.\n";
            continue; // vuelve a pedir
        }

        // Convertimos a entero
        id = stoi(strID);

        // Validar ID único
        pos = _repor.buscarID(id);
        if (pos != -1) {
            cout << "Error: el ID ya está en uso. Intente nuevamente.\n";
            ok = false;
        }

        if (ok) break;
    } while (true);

    //Nombre
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

    //Apellido
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

    //DNI
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

    //Teléfono
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
    //Email
    do {
        cout << "Ingresar Mail: ";
        cin >> Mail;

        if (Mail.find('@') == string::npos) {
            cout << "Error: el email debe contener '@'.\n";
        }
        else break;

    } while (true);

    Personal personal(id, DNI, Nombre, Apellido, Telefono, Mail);

    if (_repor.guardarPersonal(personal)) {
        cout << "Personal guardado exitosamente." << endl;
    } else {
        cout << "Error al guardar el personal." << endl;
    }
}

void PersonalManager::mostrarPersonal(Personal personal){
    cout << "ID: " << personal.getID() << endl;
    cout << "Nombre: " << personal.getNombre() << endl;
    cout << "Apellido: " << personal.getApellido() << endl;
    cout << "Telefono: " << personal.getTelefono() << endl;
    cout << "Mail: " << personal.getMail() << endl;
    cout << "---------------------------" << endl;
}

void PersonalManager::listar() {
    int cant = _repor.getcantidadRegistros();

    if (cant == 0) {
        cout << "No hay personal registrado.\n";
        return;
    }
    Personal *vec = nullptr;
    vec = new Personal[cant];

    if (vec == nullptr) {
        cout << "ERROR DE ASIGNACION DE MEMORIA\n";
        return;
    }

    int leidos = _repor.leerTodos(vec, cant);
    cout << "===== LISTADO DE PERSONAL =====\n";
    for (int i = 0; i < leidos; i++) {
        if (vec[i].getID() != -1) {
            mostrarPersonal(vec[i]);
            cout << "----------------------------\n";
        }
    }
    delete[] vec;
}

void PersonalManager::listarPorApellido() {
    int cant = _repor.getcantidadRegistros();

    if (cant == 0) {
        cout << "No hay personal registrado." << endl;
        return;
    }
    Personal *vec = nullptr;
    vec = new Personal[cant];

    if (vec == nullptr) {
        cout << "ERROR DE ASIGNACION DE MEMORIA\n";
        return;
    }

    int leidos = _repor.leerTodos(vec, cant);
    for (int i = 0; i < leidos - 1; i++) {
        for (int j = 0; j < leidos - i - 1; j++) {
            if (vec[j].getApellido() > vec[j + 1].getApellido()) {
                Personal temp = vec[j];
                vec[j]     = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }

    cout << "=== LISTADO DE PERSONAL ORDENADO POR APELLIDO ===\n";
    for (int i = 0; i < leidos; i++) {
        if (vec[i].getID() != -1) {
            mostrarPersonal(vec[i]);
            cout << "---------------------------\n";
        }
    }
    delete[] vec;
}

void PersonalManager::buscarID() {
    int id;
    cout << "Ingrese ID del personal: ";
    cin >> id;

    int pos = _repor.buscarID(id);
    if(pos == -1) {
        cout << "No existe registro." << endl;
        return;
    }

    Personal reg = _repor.leer(pos);
    mostrarPersonal(reg);
}

void PersonalManager::eliminarPersonal() {
    int id;
    system("cls");
    cout << "=== ELIMINAR PERSONAL ===" << endl;
    cout << "Ingrese el ID del personal a eliminar: ";
    cin >> id;

    int pos = _repor.buscarID(id);

    if (pos == -1) {
        cout << "No existe registro con ese ID." << endl;
        return;
    }

    Personal reg = _repor.leer(pos);

    reg.setID(-1);

    if (_repor.modificarPersonal(reg, pos)) {
        cout << "Registro eliminado correctamente." << endl;
    } else {
        cout << "No se pudo eliminar." << endl;
    }
}
