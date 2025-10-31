#pragma once
#include "Personal.h"
#include "ArchivoPersonal.h"

using namespace std;


class ManagerPersonal
{
    public:
        ManagerPersonal();

        void cargarPersonal ();
        void mostrarPersonal (Personal personal);
        void listar ();
        void buscarID ();
        void eliminarPersonal ();


    private:
        Personal _personal;
        ArchivoPersonal _repor;
};

