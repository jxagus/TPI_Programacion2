#include <iostream>
#include "Menu.h"
#include "windows.h"

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8); //forzamos que la consola muestre en consola la codificacion cp_utf8
    SetConsoleCP(CP_UTF8);  // lo mismo pero afecta a los cin

    Menu m;
    m.run();

}
