#pragma once

#include <iostream>
using namespace std;

class Venta {
private:
    int _idVenta;
    int _fechaEntrega;
    int _idCliente;
    float _importeTotal;
    int _idPersonal;

public:
    // Constructores
    Venta();
    Venta(int idVenta, int fecha, int idCliente, float importe, int idPersonal);

    // Getters y Setters
    int getIdVenta() const;
    void setIdVenta(int id);
    int getFechaEntrega() const;
    void setFechaEntrega(int fecha);
    int getIdCliente() const;
    void setIdCliente(int idCliente);
    float getImporteTotal() const;
    void setImporteTotal(float importe);
    int getIdPersonal() const;
    void setIdPersonal(int idPersonal);

    // Otros métodos
    void cargar();
    void mostrar() const;
};
