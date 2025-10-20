#include <iostream>
#include <cstring>
#include "ArchivoClientes.h"

using namespace std;



ArchivoClientes::ArchivoClientes(string NombreArchivo):_nombreArchivo(NombreArchivo){


}
bool ArchivoClientes::guardarCliente (){
    FILE *pfile;
    bool result;

    pfile = fopen (_nombreArchivo.c_str(),"ab");

    if (pfile == nullptr){
        return false;
    }

    result = fwrite (&_registro,sizeof (Clientes),1,pfile);

    fclose (pfile);

    return result;
}

bool ArchivoClientes::modificarCliente (Clientes modificar,int pos){
    FILE *pfile;
    bool result;

    pfile = fopen (_nombreArchivo.c_str(),"rn+");

    if (pfile == nullptr){
        return false;
    }

    fseek (pfile,pos *sizeof (Clientes),SEEK_SET);

    result = fwrite (&_registro,sizeof (Clientes), 1,pfile);

    fclose (pfile);

    return result;
}



