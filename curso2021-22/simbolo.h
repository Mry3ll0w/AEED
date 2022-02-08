#ifndef CURSO2021_22_SIMBOLO_H
#define CURSO2021_22_SIMBOLO_H

#include <iostream>
#include <cassert>
#include "tads_profesorado/ListaEnla.h"

typedef ListaEnla<char> trazo;//Admitidos  = { Arriba (a), Abajo (b), Derecho (d), Izquierda (i) }

class simbolo{

private:

    trazo ls;
    size_t n_trazos;
public:

    simbolo()=default;
    ~simbolo()=default;
    void add_trazo(const char& t);
    void deshacer_trazos(size_t& n);
    void simetria_x(const char& t);
    void simetria_y(const char& t);

};

void simbolo::add_trazo(const char &t) {
    auto pos_fin = ls.fin();
    ls.insertar(t,pos_fin);
    n_trazos++;
}


void simbolo::deshacer_trazos(size_t &n) {
    assert(n <= n_trazos);
    ListaEnla<char>::posicion p = ls.anterior(ls.fin());

    while(n > 0 && p != ls.primera()){
        auto q = p;
        p=ls.anterior(p);//Actualizo p
        ls.eliminar(q);//la elimino
        --n;
    }

}

void simbolo::simetria_x(const char &t) {

    auto p = ls.primera();
    while(p != ls.fin()){

        if(ls.elemento(p) == 'a'){//Se cambian arriba o abajo (se invierten)
            ls.elemento(p)= 'b';
        }
        else if (ls.elemento(p)=='b'){
            ls.elemento(p)= 'a';
        }

        p = ls.siguiente(p);
    }

}

void simbolo::simetria_y(const char &t) {
    auto p = ls.primera();
    while(p != ls.fin()){

        if(ls.elemento(p) == 'd'){//Se cambian arriba o abajo (se invierten)
            ls.elemento(p)= 'i';
        }
        else if (ls.elemento(p)=='i'){
            ls.elemento(p)= 'd';
        }

        p = ls.siguiente(p);
    }
}

#endif //CURSO2021_22_SIMBOLO_H
