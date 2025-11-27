#include <iostream>
#include <cstring>
#include "ClientesArchivo.h"

using namespace std;

ClienteArchivo::ClienteArchivo(string NombreArchivo) : _nombreArchivo(NombreArchivo) {}


bool ClienteArchivo::guardarCliente(Clientes registro) {
    FILE *pfile;
    pfile = fopen(_nombreArchivo.c_str(), "ab");
    if (pfile == nullptr) {
        return false;
    }

    bool result = fwrite(&registro, sizeof(Clientes), 1, pfile);
    fclose(pfile);

    return result;
}

bool ClienteArchivo::modificarCliente(Clientes modificar, int pos) {
    FILE *pfile;
    pfile = fopen(_nombreArchivo.c_str(), "r+b");
    if (pfile == nullptr) {
        return false;
    }

    fseek(pfile, pos * sizeof(Clientes), SEEK_SET);
    bool result = fwrite(&modificar, sizeof(Clientes), 1, pfile);
    fclose(pfile);

    return result;
}

Clientes ClienteArchivo::leer(int pos) {
    FILE *pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");
    Clientes temp;

    if (pfile == nullptr) {
        temp.setIDCliente(-1);
        return temp;
    }

    fseek(pfile, pos * sizeof(Clientes), SEEK_SET);
    if (!fread(&temp, sizeof(Clientes), 1, pfile)) {
        temp.setIDCliente(-1);
    }

    fclose(pfile);
    return temp;
}

int ClienteArchivo::leerTodos(Clientes clientes[], int cantidad) {
    FILE *pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr) {
        return 0;
    }

    int leidos = fread(clientes, sizeof(Clientes), cantidad, pfile);
    fclose(pfile);

    return leidos;
}

int ClienteArchivo::getCantidadRegistros() {
    FILE *pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr) {
        return 0;
    }

    fseek(pfile, 0, SEEK_END);
    int cantidad = ftell(pfile) / sizeof(Clientes);
    fclose(pfile);

    return cantidad;
}

int ClienteArchivo::getNuevoID() {
    int cantidad = getCantidadRegistros();
    if (cantidad == 0) {
        return 1;
    }

    return leer(cantidad - 1).getIDCliente() + 1;
}

int ClienteArchivo::buscarID(int id) {
    FILE *pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr) {
        return -1;
    }

    int pos = -1;
    int index = 0;
    Clientes temp;
    while (fread(&temp, sizeof(Clientes), 1, pfile)) {
        if (temp.getIDCliente() == id) {
            pos = index;
            break;
        }
        index++;
    }

    fclose(pfile);
    return pos;
}
