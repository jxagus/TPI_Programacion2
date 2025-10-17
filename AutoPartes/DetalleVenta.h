#pragma once
#include <iostream>
using namespace std;

class DetalleVenta {
private:
    int _idDetalle;
    int _idVenta;
    int _idAutoparte;
    int _cantidad;
    float _precio;

public:
    DetalleVenta(int idDetalle = 0, int idVenta = 0, int idAutoparte = 0, int cantidad = 0, float precio = 0);

    int getIdDetalle();
    int getIdVenta();
    int getIdAutoparte();
    int getCantidad();
    float getPrecio();

    void setIdDetalle(int idDetalle);
    void setIdVenta(int idVenta);
    void setIdAutoparte(int idAutoparte);
    void setCantidad(int cantidad);
    void setPrecio(float precio);

    void mostrar();
};
