#ifndef CURSO2021_22_CUBILETE_H
#define CURSO2021_22_CUBILETE_H

#include <iostream>
#include <random>
#include <string>
#include "tads_profesorado/pila_enla.h"

struct cubilete{

    int anchura;
    std::string posicion;
    cubilete(const int& a = 0, const std::string p=" "):anchura(a),posicion(p) {}

    bool operator!=(const cubilete& c) const{return anchura != c.anchura;}//Sobrecarga para ==
    bool operator > (const cubilete& c) const{return anchura > c.anchura;}//Sobrecarga para >, ya que al ser una pila
    bool operator < (const cubilete& c) const{return anchura < c.anchura;}//Sobrecarga para <, ya que al ser una pila
    //debe ser ordenada en orden inverso al solicitado
};

const cubilete mayor_cubilete(PilaEnla<cubilete> & p){

    //1)Obtenemos el cubilete de mayor anchura
    PilaEnla<cubilete> temp(p),t2;
    cubilete t = p.tope();
    while(!temp.vacia()){

        if (t < temp.tope())
            t = temp.tope();
        temp.pop();

    }

    //2) Eliminamos el cubilete encontrado de la pila de entrada
    while(!p.vacia()){

        if(p.tope()!= t)
            t2.push(p.tope());

        p.pop();
    }

    p = t2;

    return t;
}

PilaEnla<cubilete> ejercicio_cubilete(){
    //Inicilizamos una serie de cubiletes con posiciones y anchura aleatorias
    std::string pos []={"boca arriba","boca abajo","dentro boca arriba","dentro boca abajo",
                        "fuera boca arriba","fuera boca abajo"};
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 5),dist_anchura(4,41); // define the range

    PilaEnla<cubilete> input,salida;


    for(size_t i = 0; i < 8 ; ++i){
        input.push(cubilete(dist_anchura(gen),pos[distr(gen)]));
    }

    while(!input.vacia()){

        salida.push(mayor_cubilete(input));

    }


return salida;
}
#endif //CURSO2021_22_CUBILETE_H
