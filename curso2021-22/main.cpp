#include <iostream>
#include "p3.hpp"
#include "p4.hpp"
#include "p5.h"
#include "p6.h"
#include "Escalonada.h"
#include "texto.h"
#include "ej4_parcial2022.h"
#include "texto_feb21.h"
#include "cubilete.h"

int main() {
//srand(time(0));//SOLO DEBE SER LLAMADA UNA Única vez por mainº
//solitario();
//solitario_reyes();
PilaEnla<cubilete> p;
p=ejercicio_cubilete();
while (!p.vacia()){
    std::cout<<p.tope().anchura<<std::endl;
    p.pop();
}
return 0;
}

