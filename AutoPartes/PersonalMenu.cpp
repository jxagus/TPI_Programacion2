#include <iostream>
#include "PersonalMenu.h"
using namespace std;

void PersonalMenuMostrar () {
    cout << "======== MENU PERSONAL ========\n";
    cout << "1. Agregar personal\n";
    cout << "2. Listado del personal\n";
    cout << "0. Volver\n";
}
void PersonalMenuEjecutar(){
    int opcion;
    do {
        PersonalMenuMostrar();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
            case 1:
                //_managerAutoparte.cargarAutoparte();
                 break;
            case 2:
                //_managerAutoparte.listar();
                break;
            case 0:
                break;
            default: cout << "Opcion invalida.\n";
        }
        cout << endl;
    } while (opcion != 0);
}
void PersonalMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
 //   _personalManager.cargar();
  break;
  case 2:
   // _personalManager.mostrar();
  break;
  case 3:

  break;
  case 4:

  break;
  }
}


int PersonalMenu::seleccionOpcion(){
  int opcion;
  mostrarOpciones();
  cout << "---------------" << endl;
  cout << "Opcion: ";
  cin >> opcion;

  while(opcion < 0 || opcion > _cantidadOpciones){
    cout << "Opcion incorrecta..."<<endl;
    cout << "Opcion: ";
    cin >> opcion;
  }
  return opcion;
}
