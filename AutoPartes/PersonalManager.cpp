#include <iostream>
#include <vector>
#include <algorithm>
#include "PersonalManager.h"
#include "Personal.h"

using namespace std;

PersonalManager::PersonalManager(){
}

void PersonalManager::cargarPersonal() {
    int DNI, id, pos;
    string Nombre, Apellido, Telefono, Mail;

    // === VALIDACION: ID solo numeros + ID unico ===
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

        if (ok) break; // si todo está bien, sale
    } while (true);


    // === VALIDACION: Nombre ===
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


    // === VALIDACION: Apellido ===
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


    // === VALIDACION: DNI ===
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


    // === VALIDACION: Teléfono ===
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


    // === VALIDACION: Email ===
    do {
        cout << "Ingresar Mail: ";
        cin >> Mail;

        if (Mail.find('@') == string::npos) {
            cout << "Error: el email debe contener '@'.\n";
        }
        else break;

    } while (true);


    // Crear el objeto
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

    cout << "===== LISTADO DE PERSONAL =====\n";

    for (int i = 0; i < cant; i++) {
        Personal reg = _repor.leer(i);

        if (reg.getID() != -1) { // no mostrar borrados
            mostrarPersonal(reg);
            cout << "----------------------------\n";
        }
    }
}

void PersonalManager::listarPorApellido() {
    vector<Personal> lista;
    Personal reg;
    int pos = 0;

    // Leer todos los registros
    while (_repor.leer(reg, pos)) {
        if (reg.getID() != -1) {   // evitar registros borrados
            lista.push_back(reg);
        }
        pos++;
    }

    if (lista.empty()) {
        cout << "No hay personal cargado." << endl;
        return;
    }

    // ORDENAR por apellido A-Z
    sort(lista.begin(), lista.end(),
         [](const Personal &a, const Personal &b) {
             return a.getApellido() < b.getApellido();
         });

    cout << "=== LISTADO ORDENADO POR APELLIDO (A-Z) ===\n";
    for (auto &p : lista) {
        cout << "ID: " << p.getID() << endl;
        cout << "Nombre: " << p.getNombre() << endl;
        cout << "Apellido: " << p.getApellido() << endl;
        cout << "Telefono: " << p.getTelefono() << endl;
        cout << "Mail: " << p.getMail() << endl;
        cout << "---------------------------\n";
    }
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

    reg.setID(-1); // marcar eliminado

    if (_repor.modificarPersonal(reg, pos)) {
        cout << "Registro eliminado correctamente." << endl;
    } else {
        cout << "No se pudo eliminar." << endl;
    }
}
