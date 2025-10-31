#pragma once
#include "PersonalManager.h"

class PersonalMenu
{
  public:
    PersonalMenu();
    void mostrar();

  protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

  private:
  PersonalManager _personalManager;
  int _cantidadOpciones;
};
