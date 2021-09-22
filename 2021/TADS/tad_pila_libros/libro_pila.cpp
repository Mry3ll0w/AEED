//
// Created by anton on 15/11/2020.
//
#include "libro_pila.h"



libros::libros(int size) :n_elementos(size){
    assert(size!=0);
    libross = new l [n_elementos];

}

void libros::push(const l &x) {
    libross[desplazamiento]=x;
    desplazamiento++;
}

void libros::pop() {
    assert(desplazamiento!=0);
    desplazamiento--;
}

unsigned libros::tope()const {
    return desplazamiento;
}

bool libros::vacia() const {
    if (desplazamiento<=0){return true;}
    else{return false;}
}
