#include <iostream>
#include <cstring>
#include "ClientesArchivo.h"

using namespace std;



ArchivoClientes::ArchivoClientes(string NombreArchivo):_nombreArchivo(NombreArchivo){


}
bool ArchivoClientes::guardarCliente (Clientes registro){
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

Clientes ArchivoClientes::leer(int pos){
    FILE  *pfile;

    pfile = fopen (_nombreArchivo.c_str(),"rb");

    if (pfile == nullptr){
        _registro.setidCliente(-1);
        return _registro;
    }

    fseek (pfile,pos *sizeof (Clientes), SEEK_SET);

    if(!fread(&_registro,sizeof (Clientes),1, pfile)){
        _registro.setidCliente (-1);
    }

    pclose (pfile);

    return _registro;
}

int ArchivoClientes::leerTodos(Clientes clientes[], int cantidad){
    FILE  *pfile;
    int result;

    pfile = fopen (_nombreArchivo.c_str(), "rb");

    if (pfile == nullptr){
        return 0;
    }

    fread(clientes,sizeof clientes,cantidad,pfile);

    fclose (pfile);

    return result;
}

int ArchivoClientes::getCantidadRegistros(){
    FILE  *pfile;
    bool result;
    int cantidad;

    pfile = fopen (_nombreArchivo.c_str(),"rb");

    if (pfile == nullptr){
        return 0;
    }

    fseek (pfile, 0, SEEK_END);

    cantidad=ftell(pfile)/sizeof (Clientes);

    fclose (pfile);

    return cantidad;
}

int ArchivoClientes::getNuevoID (){
    if (getCantidadRegistros()==0){
        return 1;
    }

    return leer (getCantidadRegistros () - 1).getidCliente()+1;

}

int ArchivoClientes::buscarID (int id){
    FILE *pfile;
    int pos = -1;

    pfile = fopen(_nombreArchivo.c_str(), "rb");

    if(pfile == nullptr){
        return -1;
    }

    while (fread(&_registro,sizeof (Clientes), 1, pfile)){
        if (_registro.getidCliente() == id){
            pos = ftell(pfile)/sizeof (Clientes)-1;
            break;
        }

        fclose (pfile);

        return pos;
    }

}


