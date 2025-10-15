#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H


class DetalleVenta
{
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

#endif // DETALLEVENTA_H
