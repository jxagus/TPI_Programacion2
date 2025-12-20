#include <iostream>
#include "PersonalArchivo.h"

using namespace std;

ArchivoPersonal::ArchivoPersonal(string nombreArchivo)
    : _nombreArchivo(nombreArchivo) {
}

bool ArchivoPersonal::guardarPersonal(Personal personal) {
    FILE* pfile = fopen(_nombreArchivo.c_str(), "ab");
    if (pfile == nullptr) return false;

    bool ok = fwrite(&personal, sizeof(Personal), 1, pfile);

    fclose(pfile);
    return ok;
}

bool ArchivoPersonal::modificarPersonal(Personal modificar, int pos) {
    FILE* pfile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pfile == nullptr) return false;

    fseek(pfile, pos * sizeof(Personal), SEEK_SET);

    bool ok = fwrite(&modificar, sizeof(Personal), 1, pfile);

    fclose(pfile);
    return ok;
}

Personal ArchivoPersonal::leer(int pos) {
    Personal registro;
    FILE* pfile = fopen(_nombreArchivo.c_str(), "rb");

    if (pfile == nullptr) {
        return registro;
    }

    fseek(pfile, pos * sizeof(Personal), SEEK_SET);
    fread(&registro, sizeof(Personal), 1, pfile);

    fclose(pfile);
    return registro;
}

bool ArchivoPersonal::leer(Personal &reg, int pos) {
    FILE* pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr) return false;

    fseek(pfile, pos * sizeof(Personal), SEEK_SET);
    bool ok = fread(&reg, sizeof(Personal), 1, pfile);

    fclose(pfile);
    return ok;
}

int ArchivoPersonal::getcantidadRegistros() {
    FILE* pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr) return 0;

    fseek(pfile, 0, SEEK_END);
    int cantidad = ftell(pfile) / sizeof(Personal);

    fclose(pfile);
    return cantidad;
}

int ArchivoPersonal::buscarID(int id) {
    Personal reg;
    int pos = 0;

    FILE* pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr) return -1;

    while (fread(&reg, sizeof(Personal), 1, pfile) == 1) {
        if (reg.getID() == id) {
            fclose(pfile);
            return pos;
        }
        pos++;
    }

    fclose(pfile);
    return -1;
}

int ArchivoPersonal::leerTodos(Personal personales[], int cantidad) {
    FILE* pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr) return 0;

    int leidos = fread(personales, sizeof(Personal), cantidad, pfile);

    fclose(pfile);
    return leidos;
}
