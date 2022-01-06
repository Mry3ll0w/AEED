#include <iostream>
#include "p3.hpp"
#include "p4.hpp"
#include "p5.h"
#include "p6.h"
#include "Escalonada.h"

int main() {
//srand(time(0));//SOLO DEBE SER LLAMADA UNA Única vez por mainº
//solitario();
//solitario_reyes();

Escalonada e(0,2);
e.insertar_salto(12);
e.insertar_salto(2);
e.show_grafica();std::cout <<std::endl;
e.eliminar_salto(2);
e.show_grafica();
return 0;
}

