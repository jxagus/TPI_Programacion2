#pragma once
#include "Personal.h"

using namespace std;


class ArchivoPersonal
{
    public:
        ArchivoPersonal(string _nombreArchivo = "Personal.dat");

        bool guardarPersonal ();
        bool modificarPersonal (Personal modificar,int pos);
        void eliminarPersonal (int pos);
        int bucarID (int id);

        Personal leer (int pos);
        void leerTodos (Personal personal[], int pos);
        void getcantidadRegistros ();
        void getNuevoID ();





    private:
        string _nombreArchivo;
        Personal _registro;
};
