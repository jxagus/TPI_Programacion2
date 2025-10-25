#include <iostream>
#include <cstring>
#include "ManagerAutoparte.h"
#include "Autoparte.h"
#include "ArchivoAutoparte.h"

using namespace std;



ManagerAutoparte::ManagerAutoparte(){

}

void ManagerAutoparte::cargarAutoparte(){
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
        cout << "Ingrese ID: " << endl;
        cin >> id;

        pos = _repor.buscarID(id);

        if (pos == -1) {
            break;
        } else {
            cout << "ID ingresado ya está en uso. Intente nuevamente..." << endl;
        }
    }
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

void ManagerAutoparte::cargarStock (){
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

void ManagerAutoparte::mostrarAutoparte (Autoparte autoparte){
    cout << "ID: " << _autoparte.getIDAutoparte() << endl;
    cout << "Nombre: " <<_autoparte.getNombre() << endl;
    cout << "Tipo: " <<_autoparte.getTipo () << endl;
    cout << "Precio Unitario" <<_autoparte.getPrecioUnitario() << endl;
}


