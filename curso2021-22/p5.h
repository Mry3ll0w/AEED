//
// Created by @mry3ll0w on 07/12/2021.
//
//PRACTICAS DE COLAS
#ifndef CURSO2021_22_P5_H
#define CURSO2021_22_P5_H

#include <iostream>
#include <cassert>//Para assert()
#include "tads_profesorado/Cola_Din.h"
#include "tads_profesorado/Cola_Cir.h"
#include "tads_profesorado/pila_enla.h"

template <class t>
std::ostream& operator<<(std::ostream& stream, ColaDin<t> c){
    while(!c.vacia()){
        stream << c.frente()<<", ";
        c.pop();
    }
    return stream;
}

/* EJERCICIO 1
 * Se dice que una pila es isomórfica a una cola cuando los elementos situados en posiciones
 * pares de la pila coinciden con los situados en posiciones impares de la cola.
 * Usando los TAD Pila y Cola, implemente una función que determine y devuelva si una
 * pila y una cola dadas son isomórficas o no.
 */
template <class t>
bool p5_ej1(ColaDin<t>c, PilaEnla<t>p){
    bool isomorfica=true;
    size_t pos=0;
    ColaDin<t>cola_impares,cola_pares;//Para mantener la distribucion original

    //Metemos los elementos de la cola
    for (int i = 0; !c.vacia() ; ++i) {
        if(i%2!=0){//Si no es divisible entre dos es par por tanto es impar
            cola_impares.push(c.frente());
        }
        c.pop();
    }
    //EN la pila deberemos obtener las posiciones impares tambien ya que al estar invertidas las pares seran impares
    for (int i = 0; !p.vacia() ; ++i) {
        if(i%2!=0){//Si no es divisible entre dos es par por tanto es impar
            cola_pares.push(c.frente());
        }
        c.pop();
    }
    //Comprobamos si coinciden
    while(!cola_impares.vacia() && !cola_pares.vacia() && isomorfica){
        if(cola_pares.frente() != cola_impares.frente())
            isomorfica = false;
        cola_impares.pop();
        cola_pares.pop();
    }

    return isomorfica;
}

/*
 * Escriba una función que dada una cola y dos elementos a y b, invierta la secuencia delimitada
 * por ambos dentro de ella. Dado que la cola puede tener elementos repetidos, se invertirá
 * la secuencia delimitada por la primera ocurrencia de a y b.
 *
 */
template <class t>
void p5_ej2(ColaDin<t>& c, const t& a, const t& b){
    assert(!c.vacia());//La cola no puede estar vacia
    PilaEnla<t>p_aux;
    ColaDin<t>c_antes_a;

    //Recorremos la cola hasta llegar al elemento buscado o acabar la pila
    while(!c.vacia()&& c.frente() != a){
        c_antes_a.push(c.frente());
        c.pop();
    }

    //Comprobamos que c no este vacia tras est
    while (!c.vacia() && c.frente()!=b){
        p_aux.push(c.frente());//metemos en la pila el intevalo entre a y b para invertirlo
        c.pop();
    }
    //Comprobamos que c no este vacia para meter b en la pila tambien

    if(!c.vacia()){
        p_aux.push(c.frente());//metemos b
        c.pop();
    }
    //metemos en ina cola auxiliar tras b
    ColaDin<t>tras_b;
    while(!c.vacia()){
        tras_b.push(c.frente());
        c.pop();
    }

    //Por ultimo copiamos el resto de contenidos en c (con [a.....b] invertidos
    while(!c_antes_a.vacia()){
        c.push(c_antes_a.frente());
        c_antes_a.pop();
    }

    //copiamos la inversion (en la pila0
    while(!p_aux.vacia()){
        c.push(p_aux.tope());
        p_aux.pop();
    }
    //metemos el resto tras b
    while(!tras_b.vacia()){
        c.push(tras_b.frente());
        tras_b.pop();
    }



}



#endif //CURSO2021_22_P5_H
