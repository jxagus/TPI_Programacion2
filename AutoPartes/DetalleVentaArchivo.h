#pragma once
#include "DetalleVenta.h"
#include <iostream>
#include <cstdio>
using namespace std;

class DetalleVentaArchivo {

public:
    bool guardar(DetalleVenta& reg);
    bool leer(DetalleVenta& reg, int pos);
    int contarRegistros();
    bool modificar(DetalleVenta& reg, int pos);
    DetalleVenta leerPorId(int idDetalle);
    void listarTodos();

private:
    char* _nombreArchivo = "detalleVentas.dat";

};
