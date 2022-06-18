#include <iostream>
#include <vector>
#include "febrero2014.hpp"
#include "feb2022.hpp"
#include "texto.hpp"

int main(){
    std::string s = "12345@";
    std::string s2 = "23@@4@";
    std::string s3 = "#131313213";
    texto t;
    t.insertar_linea(s);
    t.insertar_linea(s2);
    t.insertar_linea(s3);
    std::cout<<t.mostrar_texto()<<std::endl;
    return 0;
    
}