#include <iostream>
#include <cstring>
#include "Autoparte.h"
#include "AutoparteArchivo.h"

using namespace std;


ArchivoAutoparte::ArchivoAutoparte(string NombreArchivo):_nombreArchivo(NombreArchivo){

}

bool ArchivoAutoparte::guardarAutoparte (Autoparte _registro){
    FILE *pfile;
    bool result;

    pfile = fopen (_nombreArchivo.c_str(),"ab");

    if (pfile == nullptr){
        return false;
    }

    result = fwrite (&_registro,sizeof (Autoparte), 1, pfile);

    fclose (pfile);

    return result;
}

bool ArchivoAutoparte::ModificarAutoparte (int pos,Autoparte modificar){
    FILE *pfile;
    bool result;

    pfile  = fopen (_nombreArchivo.c_str(),"rb+");

    if (pfile == nullptr){
        return false;
    }

    fseek (pfile,pos * sizeof (Autoparte), SEEK_SET);

    result = fwrite (&modificar, sizeof (Autoparte), 1, pfile);

    fclose (pfile);

    return result;
}

int ArchivoAutoparte::leerTodos (Autoparte autoparte[], int cantidad){
    FILE *pfile;
    int result;

    pfile = fopen (_nombreArchivo.c_str(),"rb");

    if (pfile == nullptr){
        return 0;
    }

    result = fread (autoparte,sizeof (Autoparte), cantidad, pfile);

    fclose (pfile);

    return result;
}

Autoparte ArchivoAutoparte::leer (int pos){
    FILE *pfile;

    pfile = fopen(_nombreArchivo.c_str(),"rb");

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

int ArchivoAutoparte::getCantidadRegistros(){
    FILE *pfile;
    bool result;
    int cantidad;

    pfile = fopen(_nombreArchivo.c_str(),"rb");

    if (pfile == nullptr){
        return 0;
    }

    fseek (pfile, 0, SEEK_END);

    cantidad=ftell(pfile)/sizeof (Autoparte);

    fclose (pfile);

    return cantidad;
}

int ArchivoAutoparte::getNuevoID(){

    if (getCantidadRegistros()==0){
        return 1;
    }

    return leer (getCantidadRegistros () - 1).getIDAutoparte()+1;
}


int ArchivoAutoparte::buscarID (int id){
    FILE *pfile;
    int pos = -1;

    pfile = fopen(_nombreArchivo.c_str(), "rb");

    if(pfile == nullptr){
        return -1;
    }

    while (fread(&_registro,sizeof (Autoparte), 1, pfile)){
        if (_registro.getIDAutoparte() == id){
            pos = ftell(pfile)/sizeof (Autoparte)-1;
            break;
        }

        fclose (pfile);

        return pos;
    }

}
