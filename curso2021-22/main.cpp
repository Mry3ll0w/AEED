#include <iostream>
#include "p3.hpp"
#include "p4.hpp"
#include <vector>
#include "p5.h"

int main() {
//srand(time(0));//SOLO DEBE SER LLAMADA UNA Única vez por mainº
//solitario();
std::vector <avioneta> v ={"brasil", "1234A","ElPEPE12","JFK360"};
aerodromo a(4);
for(auto i:v){
    a.accion('e',i);
}
a.accion('s',"1234A");
a.print_aerodromo();




return 0;
}
