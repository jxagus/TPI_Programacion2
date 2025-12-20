#pragma once
#include "Personal.h"
#include <string>

using namespace std;

class ArchivoPersonal
{
public:
    ArchivoPersonal(string nombreArchivo = "Personal.dat");

    bool guardarPersonal(Personal personal);
    bool modificarPersonal(Personal modificar, int pos);

    Personal leer(int pos);
    bool leer(Personal &reg, int pos);

    int buscarID(int id);
    int leerTodos(Personal personales[], int cantidad);
    int getcantidadRegistros();

private:
    string _nombreArchivo;
};
