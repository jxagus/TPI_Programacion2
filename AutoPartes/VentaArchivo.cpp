#include "VentaArchivo.h"
#include <cstdio>

VentaArchivo::VentaArchivo(const char* nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool VentaArchivo::guardar(const Venta& reg) {
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Venta), 1, p);
    fclose(p);
    return ok;
}

Venta VentaArchivo::leer(int pos) {
    Venta reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return reg;
    fseek(p, pos * sizeof(Venta), SEEK_SET);
    fread(&reg, sizeof(Venta), 1, p);
    fclose(p);
    return reg;
}

int VentaArchivo::getCantidadRegistros() {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Venta);
}

int VentaArchivo::buscarPorID(int idVenta) {
    Venta reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return -1;
    int pos = 0;
    while (fread(&reg, sizeof(Venta), 1, p)) {
        if (reg.getIdVenta() == idVenta) {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool VentaArchivo::modificar(const Venta& reg, int pos) {
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Venta), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Venta), 1, p);
    fclose(p);
    return ok;
}

bool VentaArchivo::leerTodos(Venta* vec, int cantidad) {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return false;
    fread(vec, sizeof(Venta), cantidad, p);
    fclose(p);
    return true;
}
