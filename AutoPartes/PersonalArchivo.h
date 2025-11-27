#pragma once
#include "Personal.h"

using namespace std;


class ArchivoPersonal
{
    public:
        ArchivoPersonal(string _nombreArchivo = "Personal.dat");

        bool guardarPersonal (Personal personal);
        bool leer(Personal &reg, int pos);

        bool modificarPersonal (Personal modificar,int pos);
        bool eliminarPersonal (int pos);

        Personal leer (int pos);

        int buscarID (int id);
        int leerTodos(Personal tareas[], int cantidad);
        int getcantidadRegistros ();
        int getNuevoID ();
        int cantidadRegistros();

    private:
        string _nombreArchivo;
        Personal _registro;
};
