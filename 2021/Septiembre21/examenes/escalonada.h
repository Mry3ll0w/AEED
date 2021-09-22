#ifndef SEPTIEMBRE21_ESCALONADA_H
#define SEPTIEMBRE21_ESCALONADA_H
#include <iostream>
#include "../tads p/ListaEnla.h"

struct trozo{
    size_t inicio;
    size_t altura;
    trozo(size_t i, size_t al):inicio(i), altura(al) {}

};
class escalonada{
    ListaEnla<trozo>l;
public:
    escalonada(size_t i, size_t x){
        l.insertar(trozo(i, x), l.fin());
    }
    ListaEnla<trozo>::posicion buscar(const size_t x);
    void add_trozo(const size_t x, const size_t y);
    void eliminar(const size_t x);
    size_t valor_en_punto(const size_t alt);
    size_t min();
    size_t max();
    void transladar(const size_t x,const size_t y);
    ~escalonada()=default;
};

ListaEnla<trozo>::posicion escalonada::buscar(const size_t x) {
    bool find=false;
    auto i = l.primera();
    for (; i!= i.fin() && !find ; i=l.siguiente(i)) {
        if (x == l.elemento(i))
            find=true;
    }
    return i;
}

void escalonada::add_trozo(const size_t x,const size_t y) {
    if (buscar(x)!=l.fin()){
        l.elemento(buscar(x)).altura =y ;
    }//SI ya existe el elemento simplemente lo reposiciono
    else{//No existe
        if (l.vacia())
            l.insertar(trozo(x,y),l.primera());
        else{
            auto i = l.primera();
            for (; i!= i.fin() && l.elemento(i).inicio < x ; i=l.siguiente(i));//recorro hasta encontrar sitio de insercion
            l.insertar(trozo(x,y),i);
        }
    }
}

void escalonada::eliminar(const size_t x) {
    assert(buscar(x)!=l.fin());// buscar no puede ser fin si no salta
    l.eliminar(buscar(x));
}

void escalonada::transladar(const size_t x, const size_t y) {

    for (auto i = l.primera(); i!= i.fin(); i=l.siguiente(i)) {
        l.elemento(i).inicio+=x;
        l.elemento(i).altura+=y;
    }
}

size_t escalonada::valor_en_punto(const size_t alt) {
    for (auto i = l.primera(); i!= i.fin(); i=l.siguiente(i)) {
        if (alt==l.elemento(i).altura)
            return l.elemento(i).inicio; //si encuentra esa altura devuelve f(x)
    }
}

size_t escalonada::min() {
    size_t min = l.elemento(l.primera()).inicio;
    for (auto i = l.primera(); i!= i.fin(); i=l.siguiente(i)) {
        if (l.elemento(i).inicio < min)
            min = l.elemento(i).inicio;
    }
    return min;
}

size_t escalonada::max() {
    size_t max = l.elemento(l.primera()).inicio;
    for (auto i = l.primera(); i!= i.fin(); i=l.siguiente(i)) {
        if (l.elemento(i).inicio > max)
            max = l.elemento(i).inicio;
    }
    return max;
}


#endif //SEPTIEMBRE21_ESCALONADA_H
