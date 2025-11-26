#include <iostream>
#include "PersonalManager.h"
#include "Personal.h"

using namespace std;

PersonalManager::PersonalManager(){
}

void PersonalManager::cargarPersonal(){
    int DNI, id, pos;
    string Nombre, Apellido, Telefono, Mail;

    cout << "Ingresar ID: ";
    cin >> id;

    pos = _repor.buscarID(id);

    while (pos != -1) {
        cout << "ID ingresado ya está en uso. Intente nuevamente... ";
        cin >> id;
        pos = _repor.buscarID(id);
    }

    cout <<"Ingresar Nombre: ";
    cin >> Nombre;
    cout <<"Ingresar Apellido: ";
    cin >> Apellido;
    cout <<"Ingresar DNI: ";
    cin >> DNI;
    cout <<"Ingresar Telefono: ";
    cin >> Telefono;
    cout <<"Ingresar Mail: ";
    cin >> Mail;

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
