#include "DetalleVentaArchivo.h"

bool DetalleVentaArchivo::guardar(const DetalleVenta& reg) {
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return ok;
}

bool DetalleVentaArchivo::leer(DetalleVenta& reg, int pos) {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(DetalleVenta), SEEK_SET);
    bool ok = fread(&reg, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return ok;
}

int DetalleVentaArchivo::contarRegistros() {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int cantidad = ftell(p) / sizeof(DetalleVenta);
    fclose(p);
    return cantidad;
}

bool DetalleVentaArchivo::modificar(const DetalleVenta& reg, int pos) {
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(DetalleVenta), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return ok;
}

DetalleVenta DetalleVentaArchivo::leerPorId(int idDetalle) {
    DetalleVenta reg;
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        leer(reg, i);
        if (reg.getIdDetalle() == idDetalle) return reg;
    }
    return DetalleVenta(); // devuelve vacío si no lo encuentra
}

void DetalleVentaArchivo::listarTodos() {
    int cant = contarRegistros();
    DetalleVenta reg;
    for (int i = 0; i < cant; i++) {
        leer(reg, i);
        reg.mostrar();
    }
}
