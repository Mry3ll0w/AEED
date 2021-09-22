#ifndef SEPTIEMBRE21_CUBILETES_H
#define SEPTIEMBRE21_CUBILETES_H
#include <iostream>
#include <cassert>
#include "../tads p/pila_enla.h"
struct cubilete{
    double ancho;
    char pos; //a ==> boca arriba b==> boca abajo
    cubilete (const double ancho_,const char pos_='b'):ancho(ancho_),pos(pos_){}
};
cubilete max_cubilete(const PilaEnla<cubilete>& p){
    assert(p.vacia() && "La pila esta vacia");
    PilaEnla<cubilete> t(p);
    double ancho;
    ancho = p.tope().ancho;// p[0]
    t.pop(); //sacamos el primero que ya lo tenemos
    while (!t.vacia()){
        if (ancho < t.tope().ancho){
            ancho = t.tope().ancho;
        }
        t.pop();
    }
    return cubilete(ancho);
}
void eliminar_elemento(const double a, PilaEnla<cubilete>&p){
    assert(p.vacia() && "La pila esta vacia");
    PilaEnla<cubilete> t=p,final;
    while (!t.vacia()){
        if (a != t.tope().ancho)
            final.push(t.tope());
        t.pop();
    }
    p = final;
}

PilaEnla<cubilete> ordenar(const PilaEnla<cubilete>&p){
    //primero comprobamos el numero de elementos de la pila p
    PilaEnla<cubilete> origen = p, dest;
    while (!origen.vacia()){
        dest.push(max_cubilete(origen));//metemos los maximos
        eliminar(max_cubilete(origen).ancho, origen);
    }
    return dest;
}
#endif //SEPTIEMBRE21_CUBILETES_H
