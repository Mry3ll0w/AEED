// Created by anton on 21/01/2021.
#ifndef EXAMENES_TEXTO_H
#define EXAMENES_TEXTO_H
#include "ListaEnla.h"
#include <string>
#include <bits/stdc++.h>
using namespace std;



class Texto{
    public:
         Texto();
         void insert_word(string);
         void erase_word(string);
         void show_text();
        ~Texto();
    private:
        ListaEnla<string> pals;
};

Texto::Texto() {//Such emptyness
}

Texto::~Texto() {
    pals.~ListaEnla();
}

void Texto::show_text() {
    ListaEnla<string>::posicion pos=pals.primera();
    while(pos!=pals.fin()){
        cout<< pals.elemento(pos)<<" ";
        pos = pals.siguiente(pos);//pos ++
    }
}

void Texto::insert_word(string p_original) {
    bool corr=false;
    if (p_original.find('@')<p_original.size()) {//SI la posicion devuelta no es 0
        p_original.erase(p_original.find('@')-1 , p_original.find('@')-1);corr=true;
    }
    else if(p_original.find('#')<p_original.size()){
        p_original.replace(p_original.begin(),p_original.end()," ");corr=true;
    }
    pals.insertar(p_original, pals.fin());
    if(corr)(cout<<"La palabra ha sido corregida: "<<p_original<<endl);

}

void Texto::erase_word(string p_buscada) {
    ListaEnla<string>::posicion pos=pals.primera();
    while(pos!=pals.fin()){
        if(pals.elemento(pos)==p_buscada)(pals.eliminar(pos));
        pos = pals.siguiente(pos);//pos ++
    }
}

#endif //EXAMENES_TEXTO_H
