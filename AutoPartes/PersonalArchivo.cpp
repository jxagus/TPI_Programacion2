#include <iostream>
#include "PersonalArchivo.h"

using namespace std;

ArchivoPersonal::ArchivoPersonal(string NombreArchivo) : _nombreArchivo(NombreArchivo) {
}

bool ArchivoPersonal::guardarPersonal(Personal personal) {
    FILE* pfile = fopen(_nombreArchivo.c_str(), "ab");
    if (pfile == nullptr) return false;

    bool result = fwrite(&personal, sizeof(Personal), 1, pfile);

    fclose(pfile);
    return result;
}

bool ArchivoPersonal::modificarPersonal(Personal modificar, int pos) {
    FILE* pfile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pfile == nullptr) return false;

    fseek(pfile, pos * sizeof(Personal), SEEK_SET);

    bool result = fwrite(&modificar, sizeof(Personal), 1, pfile);

    fclose(pfile);
    return result;
}

bool ArchivoPersonal::eliminarPersonal(int pos) {
    Personal reg = leer(pos);

    if (reg.getID() == -1) return false;

    reg.setID(-1);
    return modificarPersonal(reg, pos);
}

Personal ArchivoPersonal::leer(int pos) {
    Personal registro;
    FILE *pfile;

    pfile = fopen(_nombreArchivo.c_str(), "rb");

    if (pfile == nullptr) {
        registro.setID(-1);
        return registro;
    }

    fseek(pfile, pos * sizeof(Personal), SEEK_SET);

    if (!fread(&registro, sizeof(Personal), 1, pfile)) {
        registro.setID(-1);
    }

    fclose(pfile);
    return registro;
}


int ArchivoPersonal::getcantidadRegistros() {
    FILE* pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr) return 0;

    fseek(pfile, 0, SEEK_END);
    int cantidad = ftell(pfile) / sizeof(Personal);

    fclose(pfile);
    return cantidad;
}

int ArchivoPersonal::getNuevoID() {
    int cant = getcantidadRegistros();
    if (cant == 0) return 1;

    return leer(cant - 1).getID() + 1;
}

int ArchivoPersonal::buscarID(int id) {
    Personal reg;
    int pos = 0;

    FILE *p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return -1;

    while (fread(&reg, sizeof(Personal), 1, p) == 1) {
        if (reg.getID() == id) {
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}

int ArchivoPersonal::leerTodos(Personal personales[], int cantidad) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) return 0;

    int result = fread(personales, sizeof(Personal), cantidad, pFile);

    fclose(pFile);
    return result;
}
