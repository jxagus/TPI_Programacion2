#include "PersonalManager.h"
#include <iostream>
using namespace std;

void PersonalManager::agregarPersonal() {
    Personal reg;
    int id, dni;
    string nombre, apellido, rol, telefono, mail;

    cout << "ID: ";
    cin >> id;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Apellido: ";
    getline(cin, apellido);
    cout << "DNI: ";
    cin >> dni;
    cin.ignore();
    cout << "Rol: ";
    getline(cin, rol);
    cout << "Telefono: ";
    getline(cin, telefono);
    cout << "Mail: ";
    getline(cin, mail);

    reg.setId(id);
    reg.setNombre(nombre);
    reg.setApellido(apellido);
    reg.setDni(dni);
    reg.setRol(rol);
    reg.setTelefono(telefono);
    reg.setMail(mail);

    if (_archivo.guardar(reg)) cout << "Personal guardado correctamente.\n";
    else cout << "Error al guardar.\n";
}

void PersonalManager::listarPersonal() {
    cout << "\n--- LISTADO DE PERSONAL ---\n";
    _archivo.listarTodos();
}

void PersonalManager::buscarPorId() {
    int id;
    cout << "Ingrese ID del personal: ";
    cin >> id;

    Personal reg = _archivo.leerPorId(id);
    if (reg.getId() != 0) reg.mostrar();
    else cout << "No se encontro el personal con ese ID.\n";
}

void PersonalManager::modificarTelefono() {
    int id;
    cout << "Ingrese ID del personal a modificar: ";
    cin >> id;

    int cant = _archivo.contarRegistros();
    Personal reg;
    for (int i = 0; i < cant; i++) {
        _archivo.leer(reg, i);
        if (reg.getId() == id) {
            string nuevoTel;
            cout << "Telefono actual: " << reg.getTelefono() << endl;
            cout << "Ingrese nuevo telefono: ";
            cin.ignore();
            getline(cin, nuevoTel);
            reg.setTelefono(nuevoTel);
            _archivo.modificar(reg, i);
            cout << " Telefono actualizado correctamente.\n";
            return;
        }
    }

    cout << "No se encontro el ID especificado.\n";
}
