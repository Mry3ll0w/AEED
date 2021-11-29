#include <iostream>
#include "p3.hpp"
#include "p4.hpp"

int main() {
//srand(time(0));//SOLO DEBE SER LLAMADA UNA Única vez por mainº
    linea_texto l("El pepe");
    l.cursor_start();
    l.insert_in_cursor('#');
    std::cout<<l.texto_getter()<<std::endl;


return 0;
}
