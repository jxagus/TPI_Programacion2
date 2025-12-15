#pragma once
#include <iostream>

using namespace std;

class Fecha
{
    public:
        Fecha();
        Fecha (int dia, int mes, int anio);

        int getdia();
        void setdia(int dia);
        int getmes();
        void setmes(int mes);
        int getanio ();
        void setanio(int anio);

        bool fechaValida(const string &fechaStr);
        bool esBiciesto(int anio);
        void asignarFechaSistema();
        string toString();

    private:
        int _dia;
        int _mes;
        int _anio;
};

