#include <iostream>
#include <cstring>
#include <ctype.h> //permite usar funcion isdigir, usada para validar que se ingresan solo numeros en el id
#include "AutoparteManager.h"


using namespace std;



AutoparteManager::AutoparteManager(){

}

void AutoparteManager::cargarAutoparte() {
    int id, tipo, pos;
    float precioUnitario;
    string nombre;

    // Validación del ID
    while (true) {
        id = Validaciones::leerInt("Ingresar ID: ");

        pos = _repor.buscarID(id);
        if (pos != -1) { // ID ya existe
            cout << "ERROR: ID ingresado ya esta en uso. Intente nuevamente..." << endl;
        } else {
            break; // ID válido y no repetido
        }
    }

    // Nombre de la autoparte
    nombre = Validaciones::leerLinea("Ingresar Nombre del Autoparte: ");

    // Selección de tipo
    cout << "Ingrese la categoria de autoparte a buscar:" << endl;
    cout << "======================" << endl;
    cout << "1 = Motor" << endl;
    cout << "2 = Tren Delantero" << endl;
    cout << "3 = Suspension y Frenos" << endl;
    cout << "4 = Carroceria / Chapa" << endl;
    cout << "5 = Interior" << endl;
    cout << "6 = Encendido" << endl;
    cout << "======================" << endl;
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "Ej: Kit Distribucion, 1 ..." << endl;
    cout << "-----------------------------" << endl;

    tipo = Validaciones::leerIntEnRango("Ingrese el tipo de autoparte: ", 1, 6);

    // Precio unitario
    precioUnitario = Validaciones::leerFloat("Ingresar Precio P/U: ");
    while (precioUnitario <= 0) {
        cout << "Precio invalido. Intente nuevamente: ";
        precioUnitario = Validaciones::leerFloat("");
    }

    // Crear la autoparte
    Autoparte autoparte(nombre, id, tipo, 0, precioUnitario);

    // Guardar la autoparte en el repositorio
    if (_repor.guardarAutoparte(autoparte)) {
        cout << "Autoparte guardada exitosamente." << endl;
    } else {
        cout << "Error al guardar el autoparte." << endl;
    }
}

void AutoparteManager::cargarStock() {
    int id;

    // Validación del ID
        id = Validaciones::leerIntEnRango("Ingresar ID del autoparte a modificar stock: ",1,700);


    int pos = _repor.buscarID(id);
    if (pos == -1) {
        cout << "No existe una autoparte con ese ID.\n";
        return;
    }

    _autoparte = _repor.leer(pos);

    float stockActual = _autoparte.getStock();
    cout << "AUTOPARTE ENCOTRADO " << _autoparte.getNombre() << endl;
    cout << "ID: " << id << endl;
    cout << "STOCK: " << stockActual << endl;

    // Validación de cantidad a agregar
    int cantidad = 0;
        cantidad = Validaciones::leerIntEnRango("Ingresar cantidad de Stock fisico a agregar: ",1,1000);
    // Actualizar stock
    float nuevoStock = stockActual + cantidad;
    _autoparte.setStock(nuevoStock);

    if (_repor.ModificarAutoparte(pos, _autoparte)) {
        cout << "Stock actualizado. Nuevo stock: " << nuevoStock << endl;
    } else {
        cout << "Error al actualizar el stock.\n";
    }
}

void AutoparteManager::mostrarAutoparte (Autoparte autoparte){
    cout << "ID: " << autoparte.getIDAutoparte() << endl;
    cout << "Nombre: " << autoparte.getNombre() << endl;
    cout << "Tipo: " << autoparte.getTipo() << endl;
    cout << "Precio Unitario: " << autoparte.getPrecioUnitario() << endl;
    cout << "Stock: " << autoparte.getStock() << endl;
}

void AutoparteManager::listar() {
    int cant = _repor.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay Autopartes registradas.\n";
        return;
    }

    int campo, modo;

    // Validación de campo de orden
        cout << "ORDENAR SEGUN: : " << endl;
        cout << "1- ID"  << endl;
        cout << "2- NOMBRE" << endl;
        cout << "3- CATEGORIA " << endl;
        cout << "4- PRECIO UNITARIO" << endl;

        campo = Validaciones::leerIntEnRango("Seleccione una opcion: ",1,4);

    // Validación de modo
        cout << "MODO:" << endl;
        cout << "1- ASCENDENTE " << endl;
        cout << "2- DESCENDENTE " << endl;

        modo = Validaciones::leerIntEnRango("Seleciione una opcion: ",1,2);

    bool asc = (modo == 1);

    // Leer todos los registros
    Autoparte *vec = new Autoparte[cant];
    _repor.leerTodos(vec, cant);

    // Ordenar
    ordenarAutopartes(vec, cant, campo, asc);

    // Mostrar
    for (int i = 0; i < cant; i++) {
        cout << "==============================" << endl;
        mostrarAutoparte(vec[i]);
        cout << "==============================" << endl;
    }

    delete[] vec;
}

void AutoparteManager::ordenarAutopartes(Autoparte* vec, int cant, int campo, bool asc) {

    for (int i = 0; i < cant - 1; i++) {
        for (int j = i + 1; j < cant; j++) {

            bool ordenar = false;

            switch (campo) {

                case 1:
                    if (asc) {
                        ordenar = vec[j].getIDAutoparte() < vec[i].getIDAutoparte();
                    } else {
                        ordenar = vec[j].getIDAutoparte() > vec[i].getIDAutoparte();
                    }
                    break;

                case 2:
                    if (asc) {
                        ordenar = vec[j].getNombre() < vec[i].getNombre();
                    } else {
                        ordenar = vec[j].getNombre() > vec[i].getNombre();
                    }
                    break;

                case 3: // Tipo
                    if (asc) {
                        ordenar = vec[j].getTipo() < vec[i].getTipo();
                    } else {
                        ordenar = vec[j].getTipo() > vec[i].getTipo();
                    }
                    break;

                case 4: // Precio
                    if (asc) {
                        ordenar = vec[j].getPrecioUnitario() < vec[i].getPrecioUnitario();
                    } else {
                        ordenar = vec[j].getPrecioUnitario() > vec[i].getPrecioUnitario();
                    }
                    break;
            }

            if (ordenar) {
                Autoparte aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}

void AutoparteManager::BuscarPorID() {
    int id;
    cout << "Ingrese ID de Autoparte a buscar: ";
    cin >> id;

    int pos = _repor.buscarID(id);
    if (pos == -1) {
        cout << "No se encontro el autoparte\n";
        return;
    }
    _autoparte = _repor.leer(pos);

    mostrarAutoparte(_autoparte);
}

string AutoparteManager::mostrarTipo(int tipo) {
    string nombreTipo;

    switch (tipo) {
        case 1:
            nombreTipo = "Motor";
            break;
        case 2:
            nombreTipo = "Tren Delantero";
            break;
        case 3:
            nombreTipo = "Suspensión y Frenos";
            break;
        case 4:
            nombreTipo = "Carrocería / Chapa";
            break;
        case 5:
            nombreTipo = "Interior";
            break;
        case 6:
            nombreTipo = "Encendido";
            break;
    }
    return nombreTipo;
}

void AutoparteManager::BuscarPorTipo() {
    int tipo;

    // Validación del tipo usando Validaciones
    while (true) {
        cout << "Ingrese la categoria de autoparte a buscar:" << endl;
        cout << "======================" << endl;
        cout << "1 = Motor" << endl;
        cout << "2 = Tren Delantero" << endl;
        cout << "3 = Suspension y Frenos" << endl;
        cout << "4 = Carroceria / Chapa" << endl;
        cout << "5 = Interior" << endl;
        cout << "6 = Encendido" << endl;
        cout << "======================" << endl;

    tipo = Validaciones::leerIntEnRango("Ingrese una opcion: ",1,6);

    int cant = _repor.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay autopartes registradas." << endl;
        return;
    }

    Autoparte autoparte;
    bool encontrado = false;

    cout << "Categoria filtrada: " << mostrarTipo(tipo) << endl;
    cout << "=========================" << endl;

    for (int i = 0; i < cant; i++) {
        autoparte = _repor.leer(i);

        if (autoparte.getTipo() == tipo) {
            mostrarAutoparte(autoparte);
            cout << "=========================" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron autopartes de ese tipo." << endl;
    }
    }
}

void AutoparteManager::BuscarPorNombre(){
    Autoparte autoparte;
    bool encontrado = false;
    string Nombre;

    Nombre = Validaciones::leerString ("Ingresar Nombre del Autoparte: ");

    int cant = _repor.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay autopartes registradas." << endl;
        return;
    }

    for (int i = 0; i < cant; i++) {
        autoparte = _repor.leer(i);

        if (autoparte.getNombre() == Nombre){
            cout << "=========================" << endl;
            mostrarAutoparte(autoparte);
            cout << "=========================" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron autopartes con ese nombre." << endl;
    }
}




