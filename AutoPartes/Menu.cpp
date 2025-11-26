#include <iostream>
#include "Menu.h"

using namespace std;

Menu::Menu(){
    _cantidadOpciones =5;
}
void Menu::run(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionOpcion();
    system("cls");
    ejecutarOpcion(opcion);
  }while(opcion != 0);
}

void Menu::mostrarOpciones(){
  cout << "--- MENU PRINCIPAL ---" << endl;
  cout << "1- CLIENTES "<<endl;
  cout << "2- PERSONAL "<<endl;
  cout << "3- AUTOPARTES "<<endl;
  cout << "4- VENTAS "<<endl;
  cout << "5- REPORTES "<<endl;
  cout << "-----------------" << endl;
  cout << "0- Salir "<<endl;
}

int Menu::seleccionOpcion(){
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

void Menu::ejecutarOpcion(int opcion){
    switch(opcion){
        case 1:
            _clientesMenu.MostrarMenu();
            break;
        case 2:
            _personalMenu.mostrarMenu();
            break;
        case 3:
            _autoparteMenu.mostrarMenu();
            break;
        case 4:
            _ventaMenu.mostrarMenu();
            break;
        case 5:
            _reportesMenu.MostrarMenu();
            break;
  case 0:
    cout << "Gracias por utilizar mi APP :) " << endl;
    break;
  }
}
