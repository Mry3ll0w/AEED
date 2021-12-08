#include <iostream>
#include "p3.hpp"
#include "p4.hpp"
#include "p5.h"

int main() {
//srand(time(0));//SOLO DEBE SER LLAMADA UNA Única vez por mainº
//solitario();
ColaDin<int>c;
c.push(1);
c.push(2);
c.push(3);
c.push(4);
c.push(5);
c.push(6);
c.push(7);
p5_ej2(c,2,5);
std::cout<<c<<std::endl;




return 0;
}
