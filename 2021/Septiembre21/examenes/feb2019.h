// Created by Mr3Y3ll0w on 02/08/2021.
#ifndef SEPTIEMBRE21_FEB2019_H
#define SEPTIEMBRE21_FEB2019_H
#include "../tads p/pila_enla.h"
#include <iostream>
#include <string>
#include <sstream>

double post_fijo(PilaEnla<std::string>p){
    PilaEnla<double>temp;
    while (!p.vacia()){
        if ((p.tope()!= "+") && (p.tope()!= "-") && (p.tope()!="*") && (p.tope()!= "/")){
            temp.push(std::stof(p.tope()));
        }
        else if (p.tope() == "+" ){
            double a,b;

            a= std::stof(temp.tope());
            //primer elemento a double
            temp.pop();
            b = std::stof(temp.tope());//Guardamos en la
            temp.pop();
            std::cout <<a <<"   "<<b<<std::endl;
            temp.push(a+b);
        }

        p.pop();
    }
    return std::stof(temp.tope());
}
#endif //SEPTIEMBRE21_FEB2019_H
