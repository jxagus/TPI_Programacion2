#include "VentaManager.h"
#include <iostream>
#include <ctime>
#include <iomanip>

//usamos _validar en cada ingreso por teclado del usuario con el fin de validar correctamente lo que se ingresa

using namespace std;
void VentaManager::agregarVenta() {
    ClienteManager clienteM;
    AutoparteManager autoparteM;
    PersonalManager personalM;
    ClienteArchivo archClientes;

    int idVenta, idCliente, idPersonal;
    int cantidadDetalles = 0;
    float importeTotal = 0.0;
    string fecha;

    int posCliente;
    do {
        cout << "_____LISTA DE CLIENTES ACTIVOS_____"<< endl;
        cout << endl;
        clienteM.listar();
        idCliente = _validar.leerInt("INGRESAR ID CLIENTE: ");

        posCliente = archClientes.buscarID(idCliente);
        Clientes cli;

        if (posCliente == -1) {
            cout << "ERROR: Cliente NO encontrado. Reintente.\n";
            system ("pause");
        }
        else {
            system ("cls");
            cout << "Cliente encontrado:" << endl;
            cout <<" DATOS: " <<endl;

            Clientes cli = archClientes.leer(posCliente);
            ClienteManager clientesM;
            clientesM.mostrarCliente(cli);
            system ("pause");
        }

    } while (posCliente == -1);
    ArchivoPersonal archPersonal;
    int posPersonal;

    do {
        system ("cls");
        cout << "____LISTA DE COLABORADORES____ " << endl;
        cout << endl;
        personalM.listar();
        idPersonal = _validar.leerInt("INGRESAR ID PERSONAL: ");

        posPersonal = archPersonal.buscarID(idPersonal);

        if (posPersonal == -1) {
            cout << "ERROR: Personal NO encontrado. Reintente.\n";
            system ("pause");
        }
        else {
            system ("cls");
            cout << "Personal encontrado:\n";
            cout <<" DATOS: " <<endl;
            Personal personal = archPersonal.leer(posPersonal);
            PersonalManager personalM;
            personalM.mostrarPersonal(personal);
            system ("pause");
        }

    } while (posPersonal == -1);
    //Cargar los detalles de la venta
    DetalleVentaArchivo archDetalle;

        system ("cls");
        cout <<  "--- Cargando detalle ---" << endl;

        idVenta = _archivo.getCantidadRegistros() + 1;
        DetalleVentaManager detalleventaM;
        DetalleVenta det;
    int opcion;
    do {
        det = detalleventaM.cargarDetalle(idVenta);

        float subtotal = det.getCantidad() * det.getPrecio();

        if (det.getCantidad() == 0){
            break;
        }
        // Intentar guardar el detalle
        if (archDetalle.guardar(det)) {
            cout << "Detalle guardado correctamente." << endl;
            cantidadDetalles++;
            importeTotal += subtotal;
        }
        else {
            cout << "ERROR: No se pudo guardar el detalle." << endl;
            continue;
            // Podés decidir si romper o permitir reintentar
        }

        // Preguntar si quiere agregar otro (opcional, porque puede usar id=0 para salir)
        opcion = _validar.leerInt("¿Agregar otro detalle? (1=si / 0=no): ");
    } while (opcion == 1);

    if (cantidadDetalles == 0){
        return;
    }
    Fecha f;
    f.asignarFechaSistema();
    fecha = f.toString();

    Venta venta (idVenta, fecha, idCliente, idPersonal, importeTotal);
    int cant = _archivo.getCantidadRegistros();

    if (_archivo.guardar(venta)){
        system ("cls");
        cout << fixed << setprecision(2);
        cout << "TOTAL DE LA VENTA: $" << importeTotal << endl;
        cout << "Venta guardada correctamente.\n";
    }
    else {
        system ("cls");
        cout << "Error al guardar la venta.\n";
    }
}

void VentaManager::mostrarVenta(Venta venta) {
    DetalleVentaManager detM;
    // --- CARGAR CLIENTES ---
    ClienteArchivo archClientes;
    int cantCli = archClientes.getCantidadRegistros();
    Clientes* clientes = new Clientes[cantCli];
    archClientes.leerTodos(clientes, cantCli);

    // --- CARGAR PERSONAL ---
    ArchivoPersonal archPersonal;
    int cantPer = archPersonal.getcantidadRegistros();
    Personal* personal = new Personal[cantPer];
    archPersonal.leerTodos(personal, cantPer);

    // --- BUSCAR CLIENTE ---
    string nombreCliente = "DESCONOCIDO";
    for (int i = 0; i < cantCli; i++) {
        if (clientes[i].getIDCliente() == venta.getIdCliente()) {
            nombreCliente = clientes[i].getNombre();
            break;
        }
    }

    // --- BUSCAR PERSONAL ---
    string nombrePersonal = "DESCONOCIDO";
    for (int i = 0; i < cantPer; i++) {
        if (personal[i].getID() == venta.getIdPersonal()) {
            nombrePersonal = personal[i].getNombre();
            break;
        }
    }

    // --- MOSTRAR VENTA ---
    cout << "FECHA: " << venta.getFechaEntrega() << endl;
    cout << "CLIENTE: " << nombreCliente << endl;
    cout << "PERSONAL ENCARGADO: " << nombrePersonal << endl;
    cout << "IMPORTE TOTAL: $" << fixed << setprecision(2) << venta.getImporteTotal() << endl;
    cout << "==========================================" << endl;
    cout << ">>>> DETALLES VENTA: " << venta.getIdVenta() << endl;
    detM.mostrarDetalleVenta (venta.getIdVenta());

    // --- LIBERAR MEMORIA ---
    delete[] clientes;
    delete[] personal;
}

void VentaManager::obtenerNombresVenta(Venta &venta,string &nombreCliente,string &nombrePersonal){
    // --- CLIENTES ---
    ClienteArchivo archClientes;
    int cantCli = archClientes.getCantidadRegistros();
    Clientes* clientes = new Clientes[cantCli];
    archClientes.leerTodos(clientes, cantCli);

    nombreCliente = "DESCONOCIDO";
    for (int i = 0; i < cantCli; i++) {
        if (clientes[i].getIDCliente() == venta.getIdCliente()) {
            nombreCliente = clientes[i].getNombre();
            break;
        }
    }

    // --- PERSONAL ---
    ArchivoPersonal archPersonal;
    int cantPer = archPersonal.getcantidadRegistros();
    Personal* personal = new Personal[cantPer];
    archPersonal.leerTodos(personal, cantPer);

    nombrePersonal = "DESCONOCIDO";
    for (int i = 0; i < cantPer; i++) {
        if (personal[i].getID() == venta.getIdPersonal()) {
            nombrePersonal = personal[i].getNombre();
            break;
        }
    }

    delete[] clientes;
    delete[] personal;
}

void VentaManager::listarVentas() {
    int cant = _archivo.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    int campo, modo;

    cout << "ORDENAR SEGUN:\n";
    cout << "1- ID\n";
    cout << "2- FECHA\n";
    cout << "3- CLIENTE\n";
    campo = Validaciones::leerIntEnRango("Seleccione una opcion: ", 1, 3);

    cout << "MODO:\n";
    cout << "1- ASCENDENTE\n";
    cout << "2- DESCENDENTE\n";
    modo = Validaciones::leerIntEnRango("Seleccione una opcion: ", 1, 2);
    system ("cls");

    bool asc = (modo == 1);

    DetalleVentaManager detalleM;
    Venta* vec = new Venta[cant];
    _archivo.leerTodos(vec, cant);

    ordenarVentas(vec, cant, campo, asc);

    // ==============================
    //       ENCABEZADO TABLA
    // ==============================
    cout << "=================================================================================================================\n";
    cout << left
         << setw(8)  << "ID"
         << setw(15) << "FECHA"
         << setw(15) << "CLIENTE"
         << setw(15) << "PERSONAL"
         << setw(20) << "IMPORTE"
         //<< "DETALLES"
         << endl;
    cout << "=================================================================================================================\n";

    for (int i = 0; i < cant; i++) {

        // =======================================================
        //   PRIMERA FILA: datos de venta
        // =======================================================
        string nombreCliente, nombrePersonal;
        obtenerNombresVenta(vec[i], nombreCliente, nombrePersonal);
        cout << left
             << setw(8)  << vec[i].getIdVenta()
             << setw(15) << vec[i].getFechaEntrega()
             << setw(15) << nombreCliente
             << setw(15) << nombrePersonal
             << setw(15) << fixed << setprecision(2) << vec[i].getImporteTotal()
             //<< ">> DETALLES:"
             << endl;

        // =======================================================
        //   SEGUNDA PARTE: DETALLES EN FORMATO TABLA
        // =======================================================

        cout << "-----------------------------------------------------------------------------------------------------------------\n";
        cout << " >>>>DETALLES VENTA ID:" << vec[i].getIdVenta()<< endl;
        cout << "-----------------------------------------------------------------------------------------------------------------\n";

        detalleM.mostrarDetalleVenta(vec[i].getIdVenta());

        cout << "=================================================================================================================\n";
    }

    delete[] vec;
}

void VentaManager::buscarVentaPorID() {
    int idVenta;
    system ("cls");
    idVenta = _validar.leerInt("INGRESAR ID DE VENTA A FILTRAR: ");


    int pos = _archivo.buscarPorID(idVenta);

    system ("cls");
    if (pos == -1) {
        cout << "NO EXISTEN VENTAS CON ESE ID" << endl;
        return;
    }

    // se va a mostrar la venta la venta
    Venta venta = _archivo.leer(pos);
    cout << "=== VENTA " << idVenta << " ===" << endl;
    mostrarVenta(venta);
    cout << "==========================================" << endl;
}

void VentaManager::buscarVentaPorCliente (){
    int id;

    system ("cls");
    ClienteManager ClientesM;
    ClientesM.listar();

    id = _validar.leerInt("INGRESAR ID DEL CLIENTE: ");

    system ("cls");
    cout << "MOSTRANDO VENTAS ASOCIADAS A ID: " << id <<endl;
    int cantidad = _archivo.getCantidadRegistros ();
    if (cantidad == 0) {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    Venta venta;
    bool encontrado = false;

    for (int i = 0; i < cantidad;i++){
        venta = _archivo.leer (i);

        if(venta.getIdCliente() == id){
            mostrarVenta(venta);
            cout << "==========================================" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron ventas de ese tipo." << endl;
    }
}

void VentaManager::buscarVentasPorFecha() {
    string fechaBuscada;
    DetalleVentaManager detM;
    Fecha f;

    cout << "INGRESAR FECHA (DD/MM/AAAA): ";
    cin >> fechaBuscada;

    if (!f.fechaValida(fechaBuscada)) {
        cout << "ERROR: fecha invalida.\n";
        return;
    }

    cout << "MOSTRANDO VENTAS ASOCIADAS A LA FECHA: " << fechaBuscada << endl;

    int cantidad = _archivo.getCantidadRegistros();
    if (cantidad == 0) {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    Venta venta;
    bool encontrado = false;

    system ("cls");
    for (int i = 0; i < cantidad; i++) {
        venta = _archivo.leer(i);

        if (venta.getFechaEntrega() == fechaBuscada) {
            mostrarVenta(venta);
            cout << "==========================================" << endl;
            cout << endl;
            cout << "----------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron ventas en esa fecha." << endl;
    }
}

void VentaManager::buscarVentaPorAutopartes (){
    int idAutoparte;
    AutoparteManager autoM;

    system ("cls");

    autoM.listar ();
    idAutoparte = _validar.leerInt("INGRESAR ID DE UN AUTOPARTE ");

    system ("cls");

    AutoparteArchivo autoA;
    int pos = autoA.buscarID(idAutoparte);

    if (pos == -1) {
        cout << "No se encontro autoparte con ese ID." << endl;
        return;
    }

    int cantidad = _archivo.getCantidadRegistros ();
    if (cantidad == 0) {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    bool encontrado = false;

    Venta venta;
    DetalleVenta detalleV;
    DetalleVentaArchivo detalleA;
    DetalleVentaManager detalleM;

    for (int i = 0; i < cantidad; i++) {

        if (detalleA.leer(detalleV, i)) {

            if (detalleV.getIdAutoparte() == idAutoparte) {

                int idVenta = detalleV.getIdVenta();
                int posVenta = _archivo.buscarPorID(idVenta);

                if (posVenta != -1) {
                    venta = _archivo.leer(posVenta);
                    mostrarVenta(venta);
                    cout << "=========================================="  << endl;
                    encontrado = true;
                }
            }
        }
    }
    if (!encontrado) {
        cout << "No se encontraron ventas de ese tipo." << endl;
    }
}

void  VentaManager::ordenarVentas(Venta *vec, int cant, int campo, bool asc) {

    for (int i = 0; i < cant - 1; i++) {
        for (int j = i + 1; j < cant; j++) {

            bool ordenar = false;

            switch (campo) {

                case 1: // ID Venta
                    if (asc) {
                        ordenar = vec[j].getIdVenta() < vec[i].getIdVenta();
                    } else {
                        ordenar = vec[j].getIdVenta() > vec[i].getIdVenta();
                    }
                    break;

                case 2: // Fecha Entrega
                    if (asc) {
                        ordenar = vec[j].getFechaEntrega() < vec[i].getFechaEntrega();
                    } else {
                        ordenar = vec[j].getFechaEntrega() < vec[i].getFechaEntrega();
                    }
                    break;

                case 3: // ID Cliente
                    if (asc) {
                        ordenar = vec[j].getIdCliente() < vec[i].getIdCliente();
                    } else {
                        ordenar = vec[j].getIdCliente() > vec[i].getIdCliente();
                    }
                    break;

                case 4: // Importe Total
                    if (asc) {
                        ordenar = vec[j].getImporteTotal() < vec[i].getImporteTotal();
                    } else {
                        ordenar = vec[j].getImporteTotal() > vec[i].getImporteTotal();
                    }
                    break;

                case 5: // ID Personal
                    if (asc) {
                        ordenar = vec[j].getIdPersonal() < vec[i].getIdPersonal();
                    } else {
                        ordenar = vec[j].getIdPersonal() > vec[i].getIdPersonal();
                    }
                    break;
            }

            if (ordenar) {
                Venta aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}
