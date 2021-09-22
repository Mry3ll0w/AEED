//
// Created by anton on 26/11/2020.
//
#ifndef COLA_GENERICA_COLA_H
#define COLA_GENERICA_COLA_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename typo>
class COLA {
    public:
        COLA(unsigned);
        typo pop();
        unsigned size(){return t_max;};
        unsigned curs(){return cursor;};
        void contenido();
        void push(typo);
        ~COLA();
    private:
        typo *cola;
        unsigned t_max,desplazamiento,cursor;
};

template<typename typo>
COLA<typo>::COLA(unsigned int size):t_max(size) {
    assert(size>0);
    cola = new typo[size];
    desplazamiento=0;
    cursor=-1;
}

template<typename typo>
COLA<typo>::~COLA() {
    delete [] cola;
}

template<typename typo>
void COLA<typo>::push(typo elemento) {
    assert(desplazamiento>=0);
    cola[desplazamiento]= elemento;
    desplazamiento+=1;
}

template<typename typo>
typo COLA<typo>::pop() {
    //assert(cursor<=t_max);
    cursor++;
    desplazamiento--;
    return cola[cursor];
}

template<typename typo>
void COLA<typo>::contenido() {
    for (int i = 0; i < t_max ; ++i) {
        cout<<cola[i]<<", ";
    }
    cout<<endl;
}

#endif //COLA_GENERICA_COLA_H
