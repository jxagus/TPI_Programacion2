#include <iostream>
#include "ClienteManager.h"

using namespace std;



ManagerCliente::ManagerCliente(){
}

void ManagerCliente::cargarCliente (){
    int idCliente,Telefono, pos;
    string Nombre,Cuit,Categoria,Direccion,Mail;

    idCliente = _clientes.getidCliente ();
    Telefono =  _clientes.getTelefono();
    Nombre = _clientes.getNombre () ;
    Cuit = _clientes.getCuit();
    Categoria = _clientes.getCategoria();
    Direccion = _clientes.getDireccion();
    Mail = _clientes.getMail();

   cout << "Ingresar ID: " << endl;
    cin >> idCliente;

    pos = _repor.buscarID(idCliente);

    while (true) {
        if (pos == -1) {
            break;
        } else {
            cout << "ID ingresado ya está en uso. Intente nuevamente..." << endl;
        }
    }
    cout << "Ingresar Razon social: " << endl;
    cin >> Nombre;
    cout << "Ingresar Cuit: " << endl;
    cin >> Cuit;
    cout << "Ingresar Telefono: " << endl;
    cin >> Telefono;
    cout << "ingresar Direccion: " << endl;
    cin >> Direccion;
    cout << "Ingresar Mail: " << endl;
    cin >> Mail;
    cout << "Seleccionar una Categoria: " << endl;
    cout << "1- Taller " << endl;
    cout << "2- Concesionaria " << endl;
    cout << "3- Fabrica" << endl;
    cout << "4- Chapista" << endl;
    cout << "-----------------------------" << endl;
    cout << "Ej: TALLER HERNANDEZ'S, 1..." << endl;
    cout << "-----------------------------" << endl;
    cin >> Categoria;

    Clientes clientes(idCliente, Telefono, Nombre, Cuit, Categoria, Direccion, Mail);

    if (_repor.guardarCliente(clientes))
  {
    cout << "Autoparte guardada exitosamente." << endl;
  }
  else
  {
    cout << "Error al guardar el autoparte." << endl;
  }
}

void ManagerCliente::mostrarCliente(Clientes cliente){
     cout << "ID : " << cliente.getidCliente() <<endl;
     cout << "Nombre: " << cliente.getNombre() <<endl;
     cout << "CUIT : " << cliente.getCuit() <<endl;
     cout << "Telefono: " <<cliente.getTelefono() <<endl;
     cout << "Direccion: " << cliente.getDireccion() <<endl;
     cout << "Mail : " <<cliente.getMail () <<endl;
     cout << "Categoria : " <<cliente.getCategoria() <<endl;
}

void ManagerCliente::listar (){
    int cant = _repor.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay clientes registradas.\n";
        return;
    }

    Clientes *vec = new Clientes[cant];
    _repor.leerTodos(vec, cant);
    for (int i = 0; i < cant; i++) {
        mostrarCliente(vec[i]);
    }

    delete[] vec;
}

void ManagerCliente::BuscarID() {
    int id;
    cout << "Ingrese ID de venta a buscar: ";
    cin >> id;

    int pos = _repor.buscarID(id);
    if (pos == -1) {
        cout << "No se encontro el venta\n";
        return;
    }
    _clientes = _repor.leer(pos);

    mostrarCliente(_clientes);
}

