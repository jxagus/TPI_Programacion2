#pragma once
#include "PersonalArchivo.h"

class PersonalManager {
private:
    PersonalArchivo _archivo;

public:
    void agregarPersonal();
    void listarPersonal();
    void buscarPorId();
    void modificarTelefono();
};
