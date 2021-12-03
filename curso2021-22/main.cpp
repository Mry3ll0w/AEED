#include <iostream>
#include "p3.hpp"
#include "p4.hpp"

int main() {
//srand(time(0));//SOLO DEBE SER LLAMADA UNA Única vez por mainº
    linea_texto l("El pepe");
    PilaEnla<int>p;
    p.push(1);
    p.push(2);
    p.push(3);
    p.push(4);
    p.push(5);

    //l.cursor_end();
    //l.overwrite_cursor('#');
    //std::cout<<l.texto_getter()<<std::endl;
    std::cout<<ej3_p4(2,4,p)<<std::endl;

return 0;
}
