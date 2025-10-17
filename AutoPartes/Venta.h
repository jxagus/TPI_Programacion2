#pragma once

class Venta{
    public:
        Venta();
        virtual ~Venta();


    protected:

    private:
        int _IDVenta;
        int _FechaEntrega;
        int _IDCliente;
        int _IDPersonal;
        float _ImporteTotal;
};


