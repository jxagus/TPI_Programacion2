#include <iostream>
#include "PersonalArchivo.h"

using namespace std;


ArchivoPersonal::ArchivoPersonal(string NombreArchivo): _nombreArchivo(NombreArchivo){
}

bool ArchivoPersonal::guardarPersonal (Personal personal){
    FILE *pfile;
    bool result;

    pfile = fopen (_nombreArchivo.c_str(),"ab");

    if (pfile == nullptr){
        return false;
    }

    result = fwrite (&_registro,sizeof (Personal),1,pfile);

    fclose (pfile);

    return result;
}

bool ArchivoPersonal::modificarPersonal (Personal modificar,int pos){
    FILE *pfile;
    bool result;

    pfile = fopen (_nombreArchivo.c_str(),"rn+");

    if (pfile == nullptr){
        return false;
    }

    fseek (pfile,pos *sizeof (Personal),SEEK_SET);

    result = fwrite (&_registro,sizeof (Personal), 1,pfile);

    fclose (pfile);

    return result;
}

bool ArchivoPersonal::eliminarPersonal(int pos){
    _registro = leer(pos);

    // Si falla la lectura
    if(_registro.getID() == -1)
        return false;
    _registro.setID(-1);
    return modificarPersonal(_registro, pos);
}

Personal ArchivoPersonal::leer (int pos){
    FILE *pfile;

    pfile = fopen(_nombreArchivo.c_str(),"rb");

    if (pfile == nullptr){
        _registro.setID(-1);
        return _registro;
    }

    fseek (pfile,pos * sizeof (Personal),SEEK_SET);

    if(!fread(&_registro,sizeof (Personal),1, pfile)){
        _registro.setID (-1);
    }

    fclose (pfile);

    return _registro;
}

int ArchivoPersonal::leerTodos (Personal personal[], int cantidad){
    FILE *pfile;
    int result;

    pfile = fopen (_nombreArchivo.c_str(),"rb");

    if (pfile == nullptr){
        return 0;
    }

    result = fread (personal,sizeof (Personal), cantidad, pfile);

    fclose (pfile);

    return result;
}

int ArchivoPersonal::getcantidadRegistros(){
    FILE *pfile;
    bool result;
    int cantidad;

    pfile = fopen(_nombreArchivo.c_str(),"rb");

    if (pfile == nullptr){
        return 0;
    }

    fseek (pfile, 0, SEEK_END);

    cantidad=ftell(pfile)/sizeof (Personal);

    fclose (pfile);

    return cantidad;
}

int ArchivoPersonal::getNuevoID (){
        if (getcantidadRegistros()==0){
        return 1;
    }

    return leer (getcantidadRegistros () - 1).getID()+1;
}

int ArchivoPersonal::buscarID(int id) {
    Personal reg;
    int pos = 0;

    FILE *p = fopen(_nombreArchivo.c_str(), "rb");
    if(p == NULL) return -1;

    while(fread(&reg, sizeof(Personal), 1, p) == 1) {
        if(reg.getID() == id) {
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}

