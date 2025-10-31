#pragma once
#include "Personal.h"

using namespace std;


class ArchivoPersonal
{
    public:
        ArchivoPersonal(string _nombreArchivo = "Personal.dat");

        bool guardarPersonal (Personal personal);
        bool modificarPersonal (Personal modificar,int pos);
        bool eliminarPersonal (int pos);
        int bucarID (int id);

        Personal leer (int pos);
        int leerTodos (Personal personal[], int pos);
        int getcantidadRegistros ();
        int getNuevoID ();





    private:
        string _nombreArchivo;
        Personal _registro;
};
