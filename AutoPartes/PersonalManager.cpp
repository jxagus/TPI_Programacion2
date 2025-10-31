#include <iostream>
#include "PersonalManager.h"


using namespace std;

ManagerPersonal::ManagerPersonal(){
}

void ManagerPersonal::cargarPersonal(){
    int DNI, id, pos;
    string Nombre, Apellido, Rol, Telefono, Mail;

    DNI = _personal.getDNI();
    id = _personal.getID();
    Nombre = _personal.getNombre();
    Apellido = _personal.getApellido();
    Rol = _personal.getRol();
    Telefono = _personal.getTelefono();
    Mail = _personal.getMail();

    cout << "Ingresar ID: " << endl;
    cin >> id;

    pos = _repor.bucarID (id);

    while (true) {
        if (pos == -1) {
            break;
        } else {
            cout << "ID ingresado ya está en uso. Intente nuevamente..." << endl;
        }
    }
    cout <<"Ingresar Nombre:"<< endl;
    cin >> Nombre;
    cout <<"Ingresar Apellido:"<< endl;
    cin >> Apellido;
    cout <<"Ingresar DNI:"<< endl;
    cin >> DNI;
    cout <<"Ingresar Telefono:"<< endl;
    cin >> Telefono;
    cout <<"Ingresar Mail:"<< endl;
    cin >> Mail;
    cout <<"Ingresar Rol:"<< endl;
    cout <<"1- Usuario:"<< endl;
    cout <<"2- Admin: " << endl;
    cin >> Rol;

    Personal personal(Nombre,Apellido,Rol,Telefono,Mail,DNI,id);

        if (_repor.guardarPersonal(personal))
  {
    cout << "Autoparte guardada exitosamente." << endl;
  }
  else
  {
    cout << "Error al guardar el autoparte." << endl;
  }
}

void ManagerPersonal::mostrarPersonal(Personal personal){
    cout <<"ID: "<< _personal.getID() <<endl;
    cout <<"Nombre: "<< _personal.getNombre() <<endl;
    cout <<"Apellido: "<<_personal.getApellido()  <<endl;
    cout <<"Rol: "<<_personal.getRol()  <<endl;
    cout <<"Telefono: "<<_personal.getTelefono()  <<endl;
    cout <<"Mail: "<<_personal.getMail()<<endl;
}

void ManagerPersonal::listar(){
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

void ManagerPersonal::buscarID(){
    int id;
    cout << "Ingrese ID de venta a buscar: ";
    cin >> id;

    int pos = _repor.bucarID(id);
    if (pos == -1) {
        cout << "No se encontro el autoparte\n";
        return;
    }
    _personal = _repor.leer(pos);

    mostrarPersonal(_personal);
}

void ManagerPersonal::eliminarPersonal(){

}

