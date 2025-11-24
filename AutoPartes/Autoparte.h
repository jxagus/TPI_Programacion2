#pragma once

using namespace std;

class Autoparte{
    public:
        Autoparte();
        Autoparte (string Nombre,int idAutoparte, int Tipo, float stock, float precioUnitario);

        int getIDAutoparte();
        int getTipo ();
        float getStock ();
        float getPrecioUnitario ();
        string getNombre ();
        void  setIDAutoparte (int idAutoparte) ;
        void  setTipo (int Tipo) ;
        void  setStock (float Stock) ;
        void  setPrecioUnitario (float PrecioUnitario) ;
        void  setNombre (string Nombre) ;

    private:
        int _idAutoparte ;
        int _tipo;
        float _stock;
        float _precioUnitario;
        char _nombre [50];
};

