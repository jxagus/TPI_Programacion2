#pragma once
#include "ManagerAutoparte.h"
#include "ManagerCliente.h"
#include "ManagerPersonal.h"
#include "DetalleVentaManager.h"
#include "VentaManager.h"

class SubMenu
{
    public:
        SubMenu();
        void mostrar ();

    protected:
        void AutoparteMenuMostrar();
        void AutoparteMenuEjecutar();

        void ClientesMenuMostrar();
        void ClientesMenuEjecutar();

        void PersonalMenuMostrar();
        void PersonalMenuEjecutar();

        void VentaMenuMostrar();
        void VentaMenuEjecutar();

        void DetalleVentaMenuMostrar();
        void DetalleVentaMenuEjecutar();


    private:
        int _cantidadOpciones;
        ManagerAutoparte _managerAutoparte;
        ManagerCliente _managerCliente;
        ManagerPersonal _managerPersonal;
        VentaManager _managerVenta;
        DetalleVenta _managerDetalleVenta;

};


