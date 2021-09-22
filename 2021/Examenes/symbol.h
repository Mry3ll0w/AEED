//
// Created by anton on 24/01/2021.
//

#ifndef EXAMENES_SYMBOL_H
#include "Cola_Din.h"
using namespace std;

typedef struct {
    string ruta;
}trazo;

class simbolo{
    public:
        simbolo();
        void add_trazo(trazo);
        void erase_trazo(int);
        void simbolo_x();
        void simbolo_y();
        void simbolo_z();
        static void print_trazo(const trazo&);
        ~simbolo();
    private:

        unsigned n_simbolos;
        ColaDin<trazo> trazos;
};

simbolo::simbolo() {
    n_simbolos=0;// Se inicializa a 0 el numero de simbolos
}

void simbolo::print_trazo(const trazo& t) {
    if (t.ruta=="arriba"){
        cout<<"^"<<endl;
        cout<<"|"<<endl;
    }
    if (t.ruta=="derecha"){
        cout<<"->";
    }
    if (t.ruta=="izquierda"){
        cout<<"<-";
    }
    if (t.ruta=="abajo"){
        cout<<endl;
        cout<<"|";

    }
}

simbolo::~simbolo() {
    trazos.~ColaDin();
}

void simbolo::add_trazo(trazo t) {
    trazos.push(t);
    n_simbolos++;
}

void simbolo::simbolo_x() {
    //imprimir paralelo x
}

void simbolo::simbolo_y() {
    //imprimir paralelo y
}

void simbolo::simbolo_z() {
    //imprimir paralelos a z
}

void simbolo::erase_trazo(int n) {
    for (int i = 0; i < n; ++i) {
        n_simbolos--;
        trazos.pop();
    }
}

#define EXAMENES_SYMBOL_H

#endif //EXAMENES_SYMBOL_H
