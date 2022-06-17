#include <iostream>
#include <vector>

#include "feb2022.hpp"

int main(){
    traduccion t("book");
    diccionario d;
    d.insertar_palabra("book", "mi libro");
    d.insertar_palabra("juan", "luna de pluton");

    d.erase_trad("mi libro", "book");
    auto dict = d.diccionario_completo();
    for(auto i = dict.primera(); i != dict.fin(); i = dict.siguiente(i)){
        std::cout<< dict.elemento(i).p_ing << ": "<<std::endl;
        for (auto j = dict.elemento(i).p_esp.primera(); j != dict.elemento(i).p_esp.fin();j= dict.elemento(i).p_esp.siguiente(j) )
        {
            std::cout<< dict.elemento(i).p_esp.elemento(j)<<", ";
        }
        std::cout<<std::endl;
    }
    return 0;
}