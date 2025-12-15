#pragma once

#include <iostream>
using namespace std;

class Venta {


public:
    Venta();
    Venta(int idVenta, string fecha, int idCliente, int idPersonal, float importeTotal);

    void setIdVenta(int id);
    int getIdVenta();

    void setFechaEntrega(string fecha);
    string getFechaEntrega();

    void setIdCliente(int idCliente);
    int getIdCliente();

    void setImporteTotal(float importe);
    float getImporteTotal();

    void setIdPersonal(int idPersonal);
    int getIdPersonal();

    private:
    int _idVenta;
    char _fechaEntrega [10];
    int _idCliente;
    int _idPersonal;
    float _importeTotal;
};
