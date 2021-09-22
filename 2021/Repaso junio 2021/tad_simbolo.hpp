#ifndef TAD_SIMBOLO_HPP
#define TAD_SIMBOLO_HPP

#include <iostream>
#include <cassert>
#include "tads implementados profesorado/pila_enla.h"

typedef struct {
    char p_relativa;
    char sentido;
}dibujo;

class simbolo
{
private:
    PilaEnla<dibujo>simbolos;
    size_t n_simbolos;
public:
    simbolo():n_simbolos(0){}
    void add_simbolo(dibujo d){
        assert(d.sentido=='a'||d.sentido=='b'||d.sentido=='i');
        simbolos.push(d);
        n_simbolos++;
    }
    
    void deshacer_simbolo(size_t t){
        assert(n_simbolos-t>0);
        for (size_t i = 0; i < t; i++)
        {
            simbolos.pop();
        }
    }
    PilaEnla<dibujo> simetria_y();
    ~simbolo()=default;
};

PilaEnla<dibujo> simbolo::simetria_y(){
    PilaEnla<dibujo>p=simbolos,q;//Para no modificar el registro de simbolos original
    
    while (p.vacia()!=true)
    {
        dibujo d;
        if (p.tope().sentido=='a')
        {
            d.sentido='b';
        }
        if(p.tope().sentido=='b'){
            d.sentido='a';
        }   
        if(p.tope().sentido=='d'){
            d.sentido='i';
        }
        if(p.tope().sentido=='i'){
            d.sentido='d';
        }
        //POSICION RELATIVA DE TOPE()
        if (p.tope().p_relativa=='a')
        {
            d.p_relativa='b';
        }
        if(p.tope().p_relativa=='b'){
            d.p_relativa='a';
        }
        if(p.tope().p_relativa=='d'){
            d.p_relativa='i';
        }
        if(p.tope().p_relativa=='i'){
            d.p_relativa='d';
        }
        q.push(d);
        p.pop();
    }
    return q;
}


#endif