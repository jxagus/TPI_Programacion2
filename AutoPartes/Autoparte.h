#pragma once
using namespace std;

class Autoparte{
    public:
        Autoparte();
        Autoparte (std::string Nombre,int idAutoparte, int Tipo, int stock, float precioUnitario);
        virtual ~Stock();

        int getIDAutoparte();
        int getTipo ();
        int getStock ();
        float getPrecioUnitario ();
        std::string getNombre ();

        void  setIDAutoparte (int idAutoparte) ;
        void  setTipo (int Tipo) ;
        void  setStock (int Stock) ;
        void  setPrecioUnitario (float PrecioUnitario) ;
        void  setNombre (std::string Nombre) ;

    private:
        int _idAutoparte ;
        int _tipo;
        int _stock;
        float _precioUnitario;
        char _nombre [20];
};

