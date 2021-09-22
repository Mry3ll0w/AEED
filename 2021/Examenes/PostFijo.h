//
// Created by anton on 24/01/2021.
//

#ifndef EXAMENES_POSTFIJO_H
#include <utility>
using namespace std;
#include "pila_enla.h"
template<typename typo>
class Post_Fijo{
    public:
        Post_Fijo(string);
        typo operar();
        ~Post_Fijo();
    private:
        PilaEnla<typo>operadores;
        char firstop,secondop,finalop;
        string computo;
};

template<typename typo>
Post_Fijo<typo>::Post_Fijo(string entrada):computo(entrada) {
    //Empezamos a hacer slice de la operacion a realizar
    cout<<endl;
    operadores.push(computo[0]-'0');//n1
    operadores.push(computo[1]-'0');//n2
    firstop = computo[2];
    operadores.push(computo[3]-'0');//n3
    operadores.push(computo[4]-'0');//n4
    secondop = computo[5];
    finalop = computo[6];
}

template<typename typo>
Post_Fijo<typo>::~Post_Fijo() {
    operadores.~PilaEnla();
}

template<typename typo>
typo Post_Fijo<typo>::operar() {
    typo res1,res2,n[4];
    for (int i = 3; i > -1; i--) {
        operadores.tope();
        n[i] = operadores.tope();
        operadores.pop();
    }
    switch(firstop){
        case '+':
            res1=n[0]+n[1];
            break;
        case '-':
            res1=n[0]-n[1];
            break;
        case '*':
            res1=n[0]*n[1];
            break;
        case '/':
            res1=n[0]/n[1];
            break;
    }
    switch(firstop){
        case '+':
            res1=n[0]+n[1];
            break;
        case '-':
            res1=n[0]-n[1];
            break;
        case '*':
            res1=n[0]*n[1];
            break;
        case '/':
            res1=n[0]/n[1];
            break;
    }
    switch(secondop){
        case '+':
            res2=n[3]+n[4];
            break;
        case '-':
            res2=n[3]-n[4];
            break;
        case '*':
            res2=n[3]*n[4];
            break;
        case '/':
            res2=n[3]/n[4];
            break;
    }
    switch (finalop) {
        case '+':
            return res1 + res2;
            break;
        case '-':
            return res1-res2;
            break;
        case '*':
            return res1*res2;
            break;
        case '/':
            return  res1/res2;
            break;
    }
}


#define EXAMENES_POSTFIJO_H

#endif //EXAMENES_POSTFIJO_H
