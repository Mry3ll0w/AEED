//
// Created by anton on 08/01/2021.
//

#ifndef EXAMENES_COCINA_H
#include <cassert>
#include "ListaEnla.h"
typedef struct {
    int posicion;
    int longitud;
}mueble;
class Cocina {
    public:
        Cocina(int); //Constructor de clase
        bool colocable(int);
        void add_mueble(mueble,int);
        mueble return_mueble(int);
        void remove_mueble(int);
        void join_mueble(int);
        ~Cocina();// Destructor de clase
        void espacio_restante();
    private:
        int libre;//Con esto comprobaremos si es posible colocar muebles en el espacio libre
        ListaEnla<mueble> mobiliario;
        ListaEnla <mueble>::posicion buscar(int);
};

Cocina::Cocina(int longitud):libre(longitud) {
    // se asigna a libre la longitud total de la cocina, es espacio vacio sin muebles aun
}

Cocina::~Cocina() {
    mobiliario.~ListaEnla(); // Borramos la lista de muebles para eliminar la memoria ocupada
}

bool Cocina::colocable(int posi) {
    ListaEnla<mueble>::posicion pos = mobiliario.primera();
    while (pos != mobiliario.fin()){
        if((mobiliario.elemento(pos).posicion == posi)&&(mobiliario.elemento(pos).posicion > libre)){ // si el espacio libre
            return false; // Ha encontrado un elemento en esa posicion
        }
        pos = mobiliario.siguiente(pos);// pos ++
    }
    return true;// Es colocable en esa posicion
}

void Cocina::espacio_restante() {
    cout << libre << endl;
}

void Cocina::add_mueble(mueble m, int posi) {
    assert(colocable(posi));
    mobiliario.insertar(m,mobiliario.fin());
    libre-=m.longitud;
}



mueble Cocina::return_mueble(int posi) {
    return mobiliario.elemento(buscar(posi));
}

void Cocina::remove_mueble(int posi) {
    libre+=mobiliario.elemento(buscar(posi)).longitud;
    mobiliario.eliminar(buscar(posi));
}

ListaEnla<mueble>::posicion Cocina::buscar(int posi) {
    assert(!colocable(posi));
    ListaEnla<mueble>::posicion pos = mobiliario.primera();
    while (pos != mobiliario.fin()){
        if(mobiliario.elemento(pos).posicion == posi){
            return pos; // Ha encontrado un elemento en esa posicion
        }
        pos = mobiliario.siguiente(pos);// pos ++
    }
}

void Cocina::join_mueble(int posi) {
    assert(!colocable(posi));
    ListaEnla <mueble>:: posicion pos = mobiliario.primera();
    
    while (pos != mobiliario.anterior(mobiliario.fin())){
        if(mobiliario.elemento(pos).posicion != (mobiliario.elemento(mobiliario.siguiente(pos)).posicion)+1){
            mobiliario.elemento(mobiliario.siguiente(pos)).posicion-=1;
        }
        pos = mobiliario.siguiente(pos);
    }
}


#define EXAMENES_COCINA_H

#endif //EXAMENES_COCINA_H
