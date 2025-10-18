#pragma once
#include "Personal.h"

class PersonalArchivo {
public:
    bool guardar(Personal& reg);
    bool leer(Personal& reg, int pos);
    int contarRegistros();
    bool modificar(Personal& reg, int pos);
    Personal leerPorId(int id);
    void listarTodos();
private:
    char* _nombreArchivo = "personal.dat";

};
