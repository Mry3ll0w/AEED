#ifndef CURSO2021_22_TEXTO_H
#define CURSO2021_22_TEXTO_H

#include <iostream>
#include "tads_profesorado/pila_enla.h"
#include "tads_profesorado/ListaEnla.h"
#include <string>
#include <algorithm>

class texto{
private:
    ListaEnla<std::string> t;
public:
    texto(ListaEnla<std::string>& input);
    ~texto()=default;
    void mostrar_texto();
};

texto::texto(ListaEnla<std::string> &input) {


    auto it_input = input.primera();
    for(;it_input != input.fin();it_input = input.siguiente(it_input)){

        //Comprobamos que no tengan # ya que si los tienen
        if( input.elemento(it_input).find('#') == std::string::npos ){
            auto final_t= t.fin();
            //Comprobamos que no tengan @
            if (input.elemento(it_input).find('@') != std::string::npos){
                std::string temp = input.elemento(it_input);
                PilaEnla<char>p;
                for(auto i: temp){
                    if (i != '@'){
                        p.push(i);
                    }
                    else{//Si es igual que @ sacamos el anterior
                        p.pop();
                    }
                }
                //Damos la vuelta al contenido de la pila
                std::string final;
                while(!p.vacia()){
                    final+=p.tope();
                    p.pop();
                }
                std::reverse(final.begin(),final.end());
                t.insertar(final,final_t);
            }
            else{//Si no contiene nada entonces simplemente la insertamos

                t.insertar(input.elemento(it_input),final_t);
            }

        }

    }

}

void texto::mostrar_texto() {
    auto p = t.primera();
    while (p != t.fin()){
        std::cout<<t.elemento(p)<<std::endl;
        p = t.siguiente(p);
    }
}

#endif //CURSO2021_22_TEXTO_H
