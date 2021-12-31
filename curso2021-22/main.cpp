#include <iostream>
#include "p3.hpp"
#include "p4.hpp"
#include <vector>
#include "p5.h"
#include "p6.h"
int main() {
//srand(time(0));//SOLO DEBE SER LLAMADA UNA Única vez por mainº
//solitario();
//solitario_reyes();
std::vector<int> v = {2,1,4,2,5,6,2,8},v2 ={7,12,612,11,67,9};
ListaEnla<int> l,l2;
for(auto i: v)
    l.insertar(i,l.fin());

p6_ej5(l,l.siguiente(l.primera()));

return 0;
}

