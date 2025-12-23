#pragma once
#include <string>

class Validaciones{
public:
    static int leerInt(const char* mensaje);
    static int leerIntEnRango(const char* mensaje, int min, int max);

    static float leerFloat(const char* mensaje);

    static char leerChar(const char* mensaje);
    static char leerCharOpciones(const char* mensaje, const char* opciones);

    static std::string leerString(const char* mensaje);
    static std::string leerLinea(const char* mensaje);
    static std::string leerTexto (const char* mensaje);

    static bool confirmar(const char* mensaje);
};
