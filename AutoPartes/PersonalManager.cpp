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

    Personal personal(Nombre, Apellido, Telefono, Mail, DNI, id);

    if (_repor.guardarPersonal(personal)) {
        cout << "Personal guardado exitosamente." << endl;
    } else {
        cout << "Error al guardar el personal." << endl;
    }
}

void PersonalManager::mostrarPersonal(Personal personal){
    cout <<"ID: "<< personal.getID() <<endl;
    cout <<"Nombre: "<< personal.getNombre() <<endl;
    cout <<"Apellido: "<< personal.getApellido()  <<endl;
    cout <<"Telefono: "<< personal.getTelefono()  <<endl;
    cout <<"Mail: "<< personal.getMail() <<endl;
}


void PersonalManager::listar(){
    int cant = _repor.getcantidadRegistros();
    if (cant == 0) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    Personal *vec = new Personal[cant];
    _repor.leerTodos(vec, cant);
    for (int i = 0; i < cant; i++) {
        mostrarPersonal(vec[i]);
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

    // Marcar como eliminad0
    reg.setID(-1);

    if (_repor.modificarPersonal(reg, pos)) {
        cout << "Registro eliminado correctamente." << endl;
    } else {
        cout << "No se pudo eliminar." << endl;
    }
}




