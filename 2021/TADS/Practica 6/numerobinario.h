//
// Created by anton on 20/12/2020.
//
#ifndef PRACTICA_6_NUMEROBINARIO_H
#include <cassert>
#include <string>
using namespace std;
class num_binario{
    public:
        num_binario(string n); //Constructor
        void NOT();
        void OR (string);
        void AND(string);
        void desp_derecha(unsigned);
        void desp_izquierda(unsigned);
        void show_num(){cout<<numero<<endl;}
    private:
        string numero;
};

num_binario::num_binario(string n):numero(n) {
}

void num_binario::AND(string n2) {
    for (int i = 0; i <n2.size() ; ++i) {
        if((numero[i]=='1'&& n2[i]=='0')||(n2[i]=='1' && numero[i]=='0')){
            numero[i]='0';
        }
    }
}

void num_binario::OR(string n2) {
    for (int i = 0; i <n2.size() ; ++i) {
        if(numero[i]!=n2[i]){
            numero[i]='1';
        }
    }
}

void num_binario::NOT() {
    for (int i = 0; i <numero.size() ; ++i) {
        if(numero[i]=='1'){
           numero[i]='0';
        }
        else{
            numero[i]='1';
        }
    }
}

void num_binario::desp_derecha(unsigned int cant) {
    assert(cant<=numero.size()-1);
    numero[cant-1]=numero[cant];
}

void num_binario::desp_izquierda(unsigned int cant) {
    assert(cant<= numero.size()-1);
    numero[cant]=numero[cant-1];
}


#define PRACTICA_6_NUMEROBINARIO_H

#endif //PRACTICA_6_NUMEROBINARIO_H
