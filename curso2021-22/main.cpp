#include <iostream>
#include "p2_cronometro.hpp"

int main() {
    srand(time(0));//SOLO DEBE SER LLAMADA UNA Única vez por mainº
    int *v = nullptr;
    //std::cout << tiempo_intercambio() << std::endl;
    //std::cout << tiempo_seleccion() <<std::endl;
    for(auto i: ordenaciones_total()){
        std::cout << i << std::endl;
    }

    return 0;
}
