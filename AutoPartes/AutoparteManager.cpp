#include <iostream>
#include <cstring>
#include "AutoparteManager.h"


using namespace std;



AutoparteManager::AutoparteManager(){

}

void AutoparteManager::cargarAutoparte(){
    int id, tipo, pos;
    float precioUnitario;
    string nombre;

    id = _autoparte.getIDAutoparte();
    nombre = _autoparte.getNombre ();
    tipo = _autoparte.getTipo();
    precioUnitario = _autoparte.getPrecioUnitario();

    cout << "Ingresar ID: " << endl;
    cin >> id;

    pos = _repor.buscarID(id);

    while (true) {
        if (pos == -1) {
            break;
        } else {
            cout << "ID ingresado ya está en uso. Intente nuevamente..." << endl;
        }
    }

    cout << "Ingresar Nombre del Autoparte: " << endl;
    cin >> nombre;
    cout << "Ingresar tipo: " << endl;
    cout << "1 = motor " << endl;
    cout << "2 = Tren Delantero "  << endl;
    cout << "3 = Suspencion y Frenos " << endl;
    cout << "4 = Carroceria/Chapa " << endl;
    cout << "5 = Interior " << endl;
    cout << "6 = Encendido " << endl;
    cout << "-----------------------------" << endl;
    cout << "Ej: Kit Distribucion, 1 ..." << endl;
    cout << "-----------------------------" << endl;
    cin >> tipo;
    cout << "Ingresar Precio P/U" << endl;
    cin >> precioUnitario;


    Autoparte autoparte (nombre,id,tipo, 0,precioUnitario);

      if (_repor.guardarAutoparte(autoparte))
  {
    cout << "Autoparte guardada exitosamente." << endl;
  }
  else
  {
    cout << "Error al guardar el autoparte." << endl;
  }

}

void AutoparteManager::cargarStock (){
   int stockActual = _autoparte.getStock();

    if (stockActual != 0) {
        cout << "Stock actual del autoparte ID " << _autoparte.getIDAutoparte() << ": " << stockActual << endl;
        cout << "Ingrese cantidad a sumar: ";

        int cantidadSumar;
        cin >> cantidadSumar;

        int nuevoStock = stockActual + cantidadSumar;
        _autoparte.setStock(nuevoStock);

        cout << "Nuevo stock: " << nuevoStock << endl;

    }
     else {
        int stockNuevo;
        cout << "Ingresar Stock del autoparte ID " << _autoparte.getIDAutoparte() << ": ";
        cin >> stockNuevo;

        _autoparte.setStock(stockNuevo);
    }
}

void AutoparteManager::mostrarAutoparte (Autoparte autoparte){
    cout << "ID: " << _autoparte.getIDAutoparte() << endl;
    cout << "Nombre: " <<_autoparte.getNombre() << endl;
    cout << "Tipo: " <<_autoparte.getTipo () << endl;
    cout << "Precio Unitario" <<_autoparte.getPrecioUnitario() << endl;
}
void AutoparteManager::listar(){
    int cant = _repor.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    Autoparte *vec = new Autoparte[cant];
    _repor.leerTodos(vec, cant);
    for (int i = 0; i < cant; i++) {
        mostrarAutoparte(vec[i]);
    }

    delete[] vec;
}

void AutoparteManager::BuscarPorID() {
    int id;
    cout << "Ingrese ID de venta a buscar: ";
    cin >> id;

    int pos = _repor.buscarID(id);
    if (pos == -1) {
        cout << "No se encontro el autoparte\n";
        return;
    }
    _autoparte = _repor.leer(pos);

    mostrarAutoparte(_autoparte);
}


