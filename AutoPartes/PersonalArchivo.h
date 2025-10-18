#pragma once
#include "Personal.h"

class PersonalArchivo {
private:
    const char* _nombreArchivo = "personal.dat";

public:
    bool guardar(const Personal& reg);
    bool leer(Personal& reg, int pos);
    int contarRegistros();
    bool modificar(const Personal& reg, int pos);
    Personal leerPorId(int id);
    void listarTodos();
};
