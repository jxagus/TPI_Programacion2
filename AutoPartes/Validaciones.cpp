#include <iostream>
#include "Validaciones.h"
#include <limits>


using namespace std;

int Validaciones::leerInt(const char* mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }


        cout << "Entrada invalida. Debe ingresar un numero." << endl;


        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int Validaciones::leerIntEnRango(const char* mensaje, int min, int max) {
    while (true) {
        int valor = leerInt(mensaje);
        if (valor >= min && valor <= max) return valor;


        cout << "El valor debe estar entre " << min << " y " << max << endl;

    }
}

float Validaciones::leerFloat(const char* mensaje) {
    float valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }


        cout << "Entrada invalida. Debe ingresar un numero decimal." << endl;


        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

char Validaciones::leerChar(const char* mensaje) {
    char c;
    while (true) {
        cout << mensaje;
        cin >> c;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return c;
        }

        cout << "Entrada invalida. Debe ingresar un solo caracter." << endl;


        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

char Validaciones::leerCharOpciones(const char* mensaje, const char* opciones) {
    while (true) {
        char c = leerChar(mensaje);

        for (int i = 0; opciones[i] != '\0'; i++) {
            if (c == opciones[i]) return c;
        }
        cout << "Caracter invalido. Opciones validas: " << opciones << endl;
    }
}

string Validaciones::leerString(const char* mensaje) {
    string s;

    while (true) {
        cout << mensaje;
        cin >> s;

        if (!cin.fail())
            return s;


        cout << "Entrada invalida." << endl;


        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string Validaciones::leerTexto(const char* mensaje) {
    string s;
    bool valido;

    do {
        valido = true;
        cout << mensaje;
        getline(cin, s);

        if (s.empty()) valido = false;

        for (char c : s) {
            if (!isalpha(c) && c != ' ') {
                valido = false;
                break;
            }
        }

        if (!valido)
            cout << "Solo se permiten letras y espacios.\n";

    } while (!valido);

    return s;
}

string Validaciones::leerLinea(const char* mensaje) {
    string s;

    cout << mensaje;
    getline(cin, s);

    while (s.size() == 0) {
        cout << mensaje;
        getline(cin, s);
    }

    return s;
}

bool Validaciones::confirmar(const char* mensaje) {
    char c = leerCharOpciones(mensaje, "sSnN");
    return (c == 's' || c == 'S');
}
