#pragma once
#include "Autoparte.h"
#include "Clientes.h"
#include "Personal.h"

class DetalleVenta{
    public:
        DetalleVenta();
        virtual ~DetalleVenta();


    protected:

    private:
        int _IDDetalle;
        int _IDVenta;
        int _IDAutoparte;
        int _Cantidad;
        float _precio;
};


