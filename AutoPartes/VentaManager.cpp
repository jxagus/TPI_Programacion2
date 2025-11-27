#include "VentaManager.h"
#include <iostream>
#include <ctime>

using namespace std;
void VentaManager::agregarVenta() {
     int idVenta, fecha, idCliente, idPersonal;
     float importeTotal = 0.0;

    cout <<"INGRESAR ID DE LA VENTA" << endl;
    cin >> idVenta;
    time_t t = time(nullptr);
    tm* fechaActual = localtime(&t);

    int dia = fechaActual->tm_mday;
    int mes = fechaActual->tm_mon + 1;     // tm_mon va de 0 a 11
    int anio = fechaActual->tm_year + 1900; // tm_year cuenta desde 1900

    cout << "FECHA ASIGNADA AUTOMATICAMENTE: "
         << dia << "/" << mes << "/" << anio << endl;

    fecha = anio * 10000 + mes * 100 + dia;


    int posCliente;
    ClienteArchivo archClientes;
    do {
        cout << "INGRESAR ID CLIENTE: ";
        cin >> idCliente;

        posCliente = archClientes.buscarID(idCliente);

        if (posCliente == -1) {
            cout << "ERROR: Cliente NO encontrado. Reintente.\n";
        }
        else {
            cout << "Cliente encontrado:\n";
            Clientes cli = archClientes.leer(posCliente);
            ClienteManager clientesM;
            clientesM.mostrarCliente(cli);
        }

    } while (posCliente == -1);
    ArchivoPersonal archPersonal;
    int posPersonal;

    do {
        cout << "INGRESAR ID PERSONAL: ";
        cin >> idPersonal;

        posPersonal = archPersonal.buscarID(idPersonal);

        if (posPersonal == -1) {
            cout << "ERROR: Personal NO encontrado. Reintente.\n";
        }
        else {
            cout << "Personal encontrado:\n";
            Personal personal = archPersonal.leer(posPersonal);
            PersonalManager personalM;
            personalM.mostrarPersonal(personal);
        }

    } while (posPersonal == -1);
    //Cargar los detalles de la venta
    DetalleVentaArchivo archDetalle;
      int opcion;

    do {
        cout <<  "--- Cargando detalle ---" << endl;

        DetalleVentaManager detalleventaM;
        DetalleVenta det = detalleventaM.cargarDetalle(idVenta);
        // Carga idAutoparte, cantidad
        //if (det.getIdAutoparte() == -1) {
        //cout << "No se guardó el detalle porque la autoparte no existe." << endl;
        //break;   // <-- vuelve al inicio del ciclo
        //}

        importeTotal += det.getCantidad() * det.getPrecio();

        if (archDetalle.guardar(det) && det.getCantidad() > 0) {
            cout << "Detalle guardado correctamente." << endl;
        }
        else {
            cout << "Error al guardar el detalle." << endl;
            break;
        }

        cout <<  "¿Agregar otro autoparte a la venta? (1= si/0 = no): " << endl;
        cin >> opcion;

    } while (opcion == 1);

    cout << "TOTAL DE LA VENTA: $" << importeTotal << endl;

    Venta venta (idVenta, fecha, idCliente, idPersonal, importeTotal);
    int cant = _archivo.getCantidadRegistros();
    if (_archivo.guardar(venta)) {
        cout << "Venta guardada correctamente.\n";


    }
    else {
        cout << "Error al guardar la venta.\n";
    }
}

void VentaManager::mostrarVenta(Venta venta){
    cout <<"ID: " << venta.getIdVenta()<< endl;
    cout <<"FECHA: " <<venta.getFechaEntrega() << endl;
    cout <<"ID CLIENTE: " <<venta.getIdCliente() << endl;
    cout <<"ID PERSONAL ENCARGADO: " <<venta.getIdPersonal() << endl;
    cout <<"IMPORTE TOTAL: " <<venta.getImporteTotal() << endl;
}

void VentaManager::listarVentas() {
    int cant = _archivo.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay ventas registradas.\n";
        return;
    }
    DetalleVenta detalleventa;
    DetalleVentaManager detalleventaM;
    Venta* vec = new Venta[cant];
    _archivo.leerTodos(vec, cant);

    //ordenarVentas()


    for (int i = 0; i < cant; i++) {
        cout << "==============================" << endl;
        mostrarVenta (vec[i]);
        cout << "==============DETALLES DE VENTA================" << endl;
        detalleventaM.mostrarDetalleVenta(vec[i].getIdVenta());
        cout << "==============================" << endl;
    }

    delete[] vec;
}

void VentaManager::buscarVentaPorID() {
    int idVenta;
    cout << "Ingrese el ID de la venta a buscar: ";
    cin >> idVenta;

    int pos = _archivo.buscarPorID(idVenta);

    if (pos == -1) {
        cout << "No se encontro la venta con ese ID." << endl;
        return;
    }

    // Mostrar la venta
    Venta venta = _archivo.leer(pos);
    cout << "\n=== DATOS DE LA VENTA ===" << endl;
    mostrarVenta(venta);

    // Mostrar detalles asociados
    DetalleVentaManager detManager;
    detManager.listarDetallesPorVenta(idVenta);
}

void VentaManager::buscarVentaPorCliente (){
    int id;

    cout << "INGRESAR ID DE CLIENTE..." << endl;
    cin >> id;
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
            cout << "=========================" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron ventas de ese tipo." << endl;
    }
}

void VentaManager::buscarVentasPorFecha (){
    int fecha;

    cout << "INGRESAR FECHA (AAAA/MM/DD)..." << endl;
    cin >> fecha;
    cout << "MOSTRANDO VENTAS ASOCIADAS A LA FECHA: " << fecha <<endl;
    int cantidad = _archivo.getCantidadRegistros ();
    if (cantidad == 0) {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    Venta venta;
    bool encontrado = false;

    for (int i = 0; i < cantidad;i++){
        venta = _archivo.leer (i);

        if(venta.getFechaEntrega() == fecha){
            mostrarVenta(venta);
            cout << "=========================" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron ventas en esa fecha." << endl;
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
                        ordenar = vec[j].getFechaEntrega() > vec[i].getFechaEntrega();
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
