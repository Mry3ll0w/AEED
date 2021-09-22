//
// Created by anton on 11/01/2021.
//

#ifndef EXAMENES_TREN_H
#include <cassert>
#include "ListaEnla.h"
typedef struct{
    int ID;
    bool active=true;
}wagon;
class Tren{
    public:
        Tren();
        void insert_wagon(wagon);
        void shif_left(ListaEnla<wagon>::posicion);
        void shif_right(ListaEnla<wagon>::posicion);
        void observe_active();
        bool empty();
        void erase_active();
        ListaEnla<wagon>::posicion active_wagon();
        ~Tren();
    private:
        ListaEnla<wagon>::posicion pos_active;
        ListaEnla<wagon> vagones;
        bool emptyness = true;
};

Tren::Tren() {
    // se ha inicializado la lista en la posicion activa
}

Tren::~Tren() {
    vagones.~ListaEnla(); //elimina las ocurrencias de la lista de vagones
}

void Tren::insert_wagon(wagon v) {
    vagones.insertar(v,vagones.fin());
    pos_active = vagones.anterior(vagones.fin());
    if(emptyness){
        emptyness = true;
    }
    ListaEnla<wagon>::posicion pos = vagones.primera();
    while (pos != vagones.anterior(vagones.fin())){
        if (vagones.elemento(pos).active){
            vagones.elemento(pos).active =false;
        }
        pos = vagones.siguiente(pos);//pos++
    }
}

void Tren::shif_left(ListaEnla<wagon>::posicion p) {
    assert(vagones.elemento(p).active==true);
    wagon v_aux = vagones.elemento(p);
    vagones.elemento(p).active = false;
    // intercambio de vagones
    vagones.elemento(p) = v_aux;
    vagones.elemento(p) = vagones.elemento(vagones.anterior(p));
    vagones.elemento(vagones.anterior(p)) = v_aux;
    vagones.elemento(vagones.anterior(p)).active = true;
    pos_active = vagones.anterior(p);
}

ListaEnla<wagon>::posicion Tren::active_wagon() {
    return pos_active;
}

void Tren::shif_right(ListaEnla<wagon>::posicion p) {

    wagon v_aux = vagones.elemento(p);
    vagones.elemento(p).active = false;
    // intercambio de vagones
    vagones.elemento(p) = v_aux;
    vagones.elemento(p) = vagones.elemento(vagones.siguiente(p));
    vagones.elemento(vagones.siguiente(p))=v_aux;
    vagones.elemento(vagones.siguiente(p)).active = true;
}

void Tren::observe_active() {
    cout << vagones.elemento(pos_active).ID << endl;
}

bool Tren::empty() {
    if (emptyness){
        return true;
    }
    else{
        return false;
    }
}

void Tren::erase_active() {
    assert(vagones.elemento(pos_active).active==true);
    if (pos_active == vagones.primera() ){
        vagones.elemento(vagones.anterior(vagones.fin())).active = true;
    }
    else{
        vagones.elemento(vagones.anterior(pos_active)).active =true;
    }
    vagones.eliminar(pos_active);

}

#define EXAMENES_TREN_H

#endif //EXAMENES_TREN_H
