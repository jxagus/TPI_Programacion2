#include <iostream>
#include <cstring>
#include <ctype.h> //permite usar funcion isdigir, usada para validar que se ingresan solo numeros en el id
#include "AutoparteManager.h"


using namespace std;



AutoparteManager::AutoparteManager(){

}

void AutoparteManager::cargarAutoparte(){
    int id, tipo, pos;
    float precioUnitario;
    string nombre;

    while (true) {
        cout << "Ingresar ID: " << endl;
        string entrada;
        cin >> entrada;

        if (entrada.size() > 10) {
            cout << "ERROR: El numero excede la cantidad de digitos permitidos." << endl; // maximo digitos permitidos son 10, salta error al ingresar numeros muy altos
            continue;
        }

        // Validar que todos los caracteres sean dígitos
        bool esNumero = true;
        for (char c : entrada) { // al usar char c : entrada pasamos a recorrer cada caracter dentro de entrada, esto es equivalente a usar un for (int i = 0; i < sizeof(entrada); i++)
            if (!isdigit(c)) {
                esNumero = false;
                break;
            }
        }

        if (!esNumero) {
            cout << "ERROR: Solo se permiten numeros positivos. Intente nuevamente..." << endl;
            continue;
        }

        // usamos funcion stoi para convertir un string (cadena de caracteres) a entero y luego verificamos si es negativo
        int id = stoi(entrada); //stoi es una función de la biblioteca estándar de C++ que significa "string to integer" (cadena a entero) y se utiliza para convertir un objeto de cadena en un número entero

        if (id < 0) {
            cout << "ERROR: El numero no puede ser negativo. Intente nuevamente..." << endl;
            continue;
        }
        pos = _repor.buscarID(id);
        if (pos == -1) {
            break;
        }
        cout << "ERROR: ID ingresado ya esta en uso. Intente nuevamente..." << endl;
    }

    cout << "Ingresar Nombre del Autoparte: " << endl;
    cin.ignore();
    getline(cin, nombre);

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
    cin >> tipo;
    while (tipo < 1 || tipo > 6) {
    cout << "Tipo invalido. Ingrese un numero entre 1 y 6: ";
    cin >> tipo;
    }

    cout << "Ingresar Precio P/U" << endl;
    while (!(cin >> precioUnitario) || precioUnitario <= 0) {
    cout << "Precio invalido. Intente nuevamente: ";
    cin.clear();
    }


    Autoparte autoparte (nombre, id, tipo, 0, precioUnitario);

    if (_repor.guardarAutoparte(autoparte))
    {
        cout << "Autoparte guardada exitosamente." << endl;
    }
    else
    {
        cout << "Error al guardar el autoparte." << endl;
    }
}

void AutoparteManager::cargarStock() {

    int id;

    while (true) {
        cout << "Ingresar ID del autoparte a modificar stock: ";

        string entrada;
        cin >> entrada;
        if (entrada.size() > 10) {
            cout << "ERROR: El numero excede la cantidad de digitos permitidos." << endl;
            continue;
        }

        bool esNumero = true;
        for (char c : entrada) {
            if (!isdigit(c)) {
                esNumero = false;
                break;
            }
        }

        if (!esNumero) {
            cout << "ERROR: Solo se permiten numeros positivos. Intente nuevamente...\n";
            continue;
        }

        id = stoi(entrada);

        if (id < 0) {
            cout << "ERROR: El numero no puede ser negativo. Intente nuevamente...\n";
            continue;
        }

        break;
    }

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

    cout << "Ingresar cantidad de Stock fisico a agregar: ";

    string entradaCantidad;
    cin >> entradaCantidad;

    if (entradaCantidad.size() > 10) {
        cout << "ERROR: El numero excede la cantidad de digitos permitidos." << endl;
        return;
    }
    // Validar que sean solo números
    bool esNumero = true;
    for (char c : entradaCantidad) {
        if (!isdigit(c)) {
            esNumero = false;
            break;
        }
    }

    if (!esNumero) {
        cout << "Cantidad invalida.\n";
        return;
    }

    int cantidad = stoi(entradaCantidad);

    if (cantidad <= 0) {
        cout << "Cantidad invalida.\n";
        return;
    }

    // marcamos el nuevo stock
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
void AutoparteManager::listar(){
    int cant = _repor.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay Autopartes registradas.\n";
        return;
    }
    int campo, modo;
    while (true){
    cout << "ORDENAR SEGUN: : " << endl;
    cout << "1- ID"  << endl;
    cout << "2- NOMBRE" << endl;
    cout << "3- TIPO " << endl;
    cout << "4- PRECIO UNITARIO" << endl;
    string entrada;
    cin >> entrada;

    if (entrada.size() > 10) {
        cout << "ERROR: El numero excede la cantidad de digitos permitidos." << endl;
        continue;
    }

    bool esNumero = true;
        for (char c : entrada)
            if (!isdigit (c)) esNumero = false;

        if (!esNumero){
            cout << "ERROR: ingrese un numero entre 1 y 4" << endl;
            continue;
        }

        campo = stoi(entrada);
        if (campo < 1 || campo > 4){
            cout << "ERROR: Opción inválida. Intente nuevamente.\n";
            continue;
        }
        break;
    }

    while (true){
    cout << "MODO:" << endl;
    cout <<"1- ASCENDENTE " << endl;
    cout <<"2- DESCENDENTE " << endl;
    string entrada;
    cin >> entrada;

    if (entrada.size() > 10) {
        cout << "ERROR: El numero excede la cantidad de digitos permitidos." << endl;
        continue;
    }

    bool esNumero = true;
        for (char c : entrada)
            if (!isdigit(c)) esNumero = false;

        if (!esNumero) {
            cout << "ERROR: Ingrese 1 o 2.\n";
            continue;
        }

        modo = stoi(entrada);
        if (modo != 1 && modo != 2) {
            cout << "ERROR: Opción inválida.\n";
            continue;
        }

        break;
    }
    bool asc = (modo == 1);

    Autoparte *vec = new Autoparte[cant];
    _repor.leerTodos(vec, cant);

    ordenarAutopartes (vec, cant, campo, asc);

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

        string entrada;
        cin >> entrada;

        if (entrada.size() > 10) {
            cout << "ERROR: El numero excede la cantidad de digitos permitidos." << endl;
            continue;
        }
        bool esNumero = true;
        for (char c : entrada) {
            if (!isdigit(c)) {
                esNumero = false;
                break;
            }
        }

        if (!esNumero) {
            cout << "ERROR: Solo se permiten numeros. Intente nuevamente.\n";
            continue;
        }

        tipo = stoi(entrada);

        if (tipo < 1 || tipo > 6) {
            cout << "Tipo invalido. Debe estar entre 1 y 6.\n";
            continue;
        }

        break; // tipo valido
    }

    int cant = _repor.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay autopartes registradas." << endl;
        return;
    }

    Autoparte autoparte;
    bool encontrado = false;

    cout << "Categoria filtrada: " << mostrarTipo (tipo) << endl;
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

void AutoparteManager::BuscarPorNombre(){
    Autoparte autoparte;
    bool encontrado = false;
    string Nombre;
        cin.ignore();
        cout << "Ingresar Nombre del autoparte: ";
        getline(cin, Nombre);



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




