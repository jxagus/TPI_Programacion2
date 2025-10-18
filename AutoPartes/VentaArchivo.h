#pragma once
#include "Venta.h"

class VentaArchivo {

public:
    VentaArchivo(char* nombreArchivo = "ventas.dat");

    bool guardar(Venta& reg);
    Venta leer(int pos);
    int getCantidadRegistros();
    int buscarPorID(int idVenta);
    bool modificar(Venta& reg, int pos);
    bool leerTodos(Venta* vec, int cantidad);

private:
    char* _nombreArchivo;
};

