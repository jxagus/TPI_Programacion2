#pragma once
#include "Personal.h"
#include "PersonalArchivo.h"


class PersonalManager
{
public:
    PersonalManager();

    void cargarPersonal();
    void mostrarPersonal(Personal personal);
    void listar();
    void eliminarPersonal();
    void buscarID();

private:
    ArchivoPersonal _repor;
};
