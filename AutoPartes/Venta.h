#pragma once

#include <iostream>
using namespace std;

class Venta {


public:
    // Constructores
    Venta();
    Venta(int idVenta, int fecha, int idCliente, int idPersonal, float importeTotal);

    // Getters y Setters
    void setIdVenta(int id);
    int getIdVenta();

    void setFechaEntrega(int fecha);
    int getFechaEntrega();

    void setIdCliente(int idCliente);
    int getIdCliente();

    void setImporteTotal(float importe);
    float getImporteTotal();

    void setIdPersonal(int idPersonal);
    int getIdPersonal();

    private:
    int _idVenta;
    int _fechaEntrega;
    int _idCliente;
    int _idPersonal;
    float _importeTotal;
};
