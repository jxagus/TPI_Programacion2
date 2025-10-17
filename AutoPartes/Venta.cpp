#include <iostream>
#include <Venta.h>
using namespace std;

class Venta {
private:
    int _idVenta;
    int _fechaEntrega;
    int _idCliente;
    float _importeTotal;
    int _idPersonal;

public:
    int getIdVenta() const;
    void setIdVenta(int);
    int getFechaEntrega() const;
    void setFechaEntrega(int);
    int getIdCliente() const;
    void setIdCliente(int);
    float getImporteTotal() const;
    void setImporteTotal(float);
    int getIdPersonal() const;
    void setIdPersonal(int);

    std::string toString() const;

    Venta();
    Venta(int, int, int, float, int);
};
