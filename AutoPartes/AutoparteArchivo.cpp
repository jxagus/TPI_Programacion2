#include <iostream>
#include <cstring>
#include <cstdio>
#include "Autoparte.h"
#include "AutoparteArchivo.h"

using namespace std;


AutoparteArchivo::AutoparteArchivo(const char *nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool AutoparteArchivo::guardarAutoparte (Autoparte _registro){
    FILE *pfile;
    bool result;

    pfile = fopen (_nombreArchivo,"ab");

    if (pfile == nullptr){
        return false;
    }

    result = fwrite (&_registro,sizeof (Autoparte), 1, pfile);

    fclose (pfile);

    return result;
}

bool AutoparteArchivo::ModificarAutoparte (int pos,Autoparte modificar){
    FILE *pfile;
    bool result;

    pfile  = fopen (_nombreArchivo,"rb+");

    if (pfile == nullptr){
        return false;
    }

    fseek (pfile,pos * sizeof (Autoparte), SEEK_SET);

    result = fwrite (&modificar, sizeof (Autoparte), 1, pfile);

    fclose (pfile);

    return result;
}

bool AutoparteArchivo::leerTodos (Autoparte *autoparte, int cantidad){
    FILE *pfile = fopen(_nombreArchivo, "rb");
    if (pfile == nullptr) return false;

    size_t leidos = fread(autoparte, sizeof(Autoparte), cantidad, pfile);

    fclose(pfile);
    return leidos == cantidad;
}

Autoparte AutoparteArchivo::leer (int pos){
    FILE *pfile;

    pfile = fopen(_nombreArchivo,"rb");

    if (pfile == nullptr){
        _registro.setIDAutoparte(-1);
        return _registro;
    }

    fseek (pfile,pos * sizeof (Autoparte),SEEK_SET);

    if(!fread(&_registro,sizeof (Autoparte),1, pfile)){
        _registro.setIDAutoparte (-1);
    }

    fclose (pfile);

    return _registro;
}

int AutoparteArchivo::getCantidadRegistros() {
    FILE *pfile = fopen(_nombreArchivo, "rb");
    if (pfile == nullptr) return 0;

    fseek(pfile, 0, SEEK_END);
    int cantidad = ftell(pfile) / sizeof(Autoparte);

    fclose(pfile);
    return cantidad;
}

int AutoparteArchivo::getNuevoID(){

    if (getCantidadRegistros()==0){
        return 1;
    }

    return leer (getCantidadRegistros () - 1).getIDAutoparte()+1;
}


int AutoparteArchivo::buscarID (int id){
    FILE *pfile;
    int pos = -1;

    pfile = fopen(_nombreArchivo, "rb");

    if(pfile == nullptr){
        return -1;
    }

    while (fread(&_registro,sizeof (Autoparte), 1, pfile)){
        if (_registro.getIDAutoparte() == id){
            pos = ftell(pfile)/sizeof (Autoparte)-1;
            break;
        }
    }

        fclose (pfile);

        return pos;

}
int AutoparteArchivo::buscarTipo(int tipo){
    FILE *pfile;
    int pos = -1;

    pfile = fopen(_nombreArchivo, "rb");

    if(pfile == nullptr){
        return -1;
    }

    while (fread(&_registro,sizeof (Autoparte), 1, pfile)){
        if (_registro.getTipo() == tipo){
            pos = ftell(pfile)/sizeof (Autoparte)-1;
            break;
        }
    }

        fclose (pfile);

        return pos;

}
