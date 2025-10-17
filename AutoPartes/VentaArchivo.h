#ifndef VENTAARCHIVO_H_INCLUDED
#define VENTAARCHIVO_H_INCLUDED
#include "Venta.h"

class VentaArchivo {
private:
    const char* _nombreArchivo;
public:
    VentaArchivo(const char* nombreArchivo = "ventas.dat");

    bool guardar(const Venta& reg);
    Venta leer(int pos);
    int getCantidadRegistros();
    int buscarPorID(int idVenta);
    bool modificar(const Venta& reg, int pos);
    bool leerTodos(Venta* vec, int cantidad);
};

#endif // VENTAARCHIVO_H_INCLUDED
