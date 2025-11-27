#include "DetalleVentaArchivo.h"
#include <iostream>

using namespace std;

bool DetalleVentaArchivo::guardar(const DetalleVenta& reg) {
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) {
        cout << "ERROR: No se pudo abrir el archivo para guardar." << endl;
        return false;
    }

    bool ok = fwrite(&reg, sizeof(DetalleVenta), 1, p);
    fclose(p);

    return ok;
}
/*
bool DetalleVentaArchivo::AgregarDetalleVenta(const DetalleVenta& reg) {
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return ok;
}    */

bool DetalleVentaArchivo::leer(DetalleVenta& reg, int pos) {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(DetalleVenta), SEEK_SET);
    bool ok = fread(&reg, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return ok;
}
int DetalleVentaArchivo::buscarPorID(int idVenta) {
    DetalleVenta reg;
    FILE *p = fopen("detalleventas.dat", "rb");
    if (p == NULL) return -1;

    int pos = 0;

    while (fread(&reg, sizeof reg, 1, p)) {
        if (reg.getIdVenta() == idVenta) {
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
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
/*
DetalleVenta DetalleVentaArchivo::leerPorId(int idDetalle) {
    DetalleVenta reg;
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        leer(reg, i);
        if (reg.getIdDetalle() == idDetalle) return reg;
    }
    return DetalleVenta(); // devuelve vacío si no lo encuentra
}*/

bool DetalleVentaArchivo::leerTodos(DetalleVenta* vec, int cantidad) {
    FILE* pfile = fopen(_nombreArchivo, "rb");
    if (pfile == nullptr) return false;

    size_t leidos = fread(vec, sizeof(DetalleVenta), cantidad, pfile);
    fclose(pfile);

    return leidos == cantidad;
}
