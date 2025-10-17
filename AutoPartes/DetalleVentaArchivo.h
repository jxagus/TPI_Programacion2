#pragma once
#include "DetalleVenta.h"
#include <iostream>
#include <cstdio>
using namespace std;

class DetalleVentaArchivo {
private:
    const char* _nombreArchivo = "detalleVentas.dat";

public:
    bool guardar(const DetalleVenta& reg);
    bool leer(DetalleVenta& reg, int pos);
    int contarRegistros();
    bool modificar(const DetalleVenta& reg, int pos);
    DetalleVenta leerPorId(int idDetalle);
    void listarTodos();
};
