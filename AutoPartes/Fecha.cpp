#include <iostream>
#include <sstream>
#include <ctime>
#include "Fecha.h"

using namespace std;

Fecha::Fecha()
    :_dia(0), _mes(0), _anio(0){

}

Fecha::Fecha(int dia,int mes, int anio){
    setdia(dia);
    setmes(mes);
    setanio(anio);
}

int Fecha::getdia(){
    return _dia;
}

void Fecha::setdia(int dia){
    _dia = dia;
}

int Fecha::getmes(){
    return _mes;
}

void Fecha::setmes(int mes){
    _mes = mes;
}

int Fecha::getanio(){
    return _anio;
}

void Fecha::setanio(int anio){
    _anio = anio;
}

string Fecha::toString(){
    return to_string(_dia) + "/"+ to_string(_mes) + "/" + to_string(_anio);

    /*MODO DE USO::
    int fechaIngresada = ...;
    if (fechaValida(std::to_string(fechaIngresada))) {
     OK*/
}

bool Fecha::esBiciesto(int anio){
    if (anio % 400 == 0) return true;
    if (anio % 100 == 0) return false;
    if (anio % 4 == 0)   return true;

    return false;
}

bool Fecha::fechaValida(const string &fechastr){
    int dia, mes, anio;
    char sep1, sep2; //validamos las "/" dentro del tostring


    stringstream ss(fechastr);   //tratar un string como si fuera un stream

    if (!(ss >> dia >> sep1 >> mes >> sep2 >> anio)) {
        return false;  // Formato inválido
    }

    if (sep1 != '/' || sep2 != '/') { //verificamos si se ingreso el formato correctamente
        return false;
    }

    if (dia < 1 || dia > 31){
        return false;
    }
    if (mes < 1 || mes > 12) {
            return false;
        }
    if (anio < 1900 || anio > 2100) {
            return false;
        }

    int diasMes[] ={ 31,28,31,30,31,30,31,31,30,31,30,31 };

    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        diasMes[1] = 29;
    }
    if (dia > diasMes[mes - 1]){
            return false;
        }

    return true;
}

void Fecha::asignarFechaSistema() {
    time_t t = time(nullptr);
    tm* fechaActual = localtime(&t);

    _dia  = fechaActual->tm_mday;
    _mes  = fechaActual->tm_mon + 1;
    _anio = fechaActual->tm_year + 1900;

    cout << "FECHA ASIGNADA AUTOMATICAMENTE: "
         << this->toString() << endl;
}


