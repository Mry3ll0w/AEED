// Created by anton on 25/01/2021.
#ifndef EXAMENES_LINEACAJA_H
#define EXAMENES_LINEACAJA_H
#include "ListaEnla.h"
#include "string"
#include <cassert>
using namespace std;
typedef struct{
    int id_cajero,id_caja;
    bool status=false;//True Abierto, False cerrado
    float compras=0;
}Till;

class LineaCaja{
    public:
        LineaCaja();
        void add_till(Till);
        void open_till(int);
        float close_till(int);
        void change_cashier(int,int);
        float change_working_team();
        float working_team();
        float close_shop();
        ~LineaCaja();
    private:
        int n_cajas=0;
        float total_recaudation=0;
        ListaEnla<Till>cajas;
        bool exists(int);// Ver si existe esa caja en la lista

};

LineaCaja::LineaCaja() = default;

void LineaCaja::add_till(Till caja) {
    cajas.insertar(caja,cajas.fin());
    n_cajas++;
}

bool LineaCaja::exists(int searched) {
    ListaEnla<Till>::posicion pos=cajas.primera();
    while (pos!=cajas.fin()){
        if (cajas.elemento(pos).id_caja == searched){
            return true;
        }
        pos = cajas.siguiente(cajas.siguiente(pos));
    }
    return false;
}


void LineaCaja::open_till(int searched_caj) {
    assert(exists(searched_caj));
    ListaEnla<Till>::posicion pos=cajas.primera();
    while(pos!=cajas.fin()){
        if (cajas.elemento(pos).id_caja==searched_caj){
            cajas.elemento(pos).status=true;//abrimpos la caja
            break;
        }
        pos = cajas.siguiente(pos);
    }

}

float LineaCaja::close_till(int searched_caj) {
    assert(exists(searched_caj));
    ListaEnla<Till>::posicion pos=cajas.primera();
    while(pos!=cajas.fin()){
        if (cajas.elemento(pos).id_caja==searched_caj){
            cajas.elemento(pos).status=false;//abrimos la caja
            float aux = cajas.elemento(pos).compras;
            cajas.elemento(pos).compras=0;//se elimina el dinero existente en la maquina registradora
            return aux;
        }
        pos = cajas.siguiente(pos);
    }
}

void LineaCaja::change_cashier(int searched_caj, int new_cashier) {
    assert(exists(searched_caj));//si existe la caja
    ListaEnla<Till>::posicion pos=cajas.primera();
    while(pos!=cajas.fin()){
        if (cajas.elemento(pos).id_caja==searched_caj){
            cajas.elemento(pos).id_cajero=new_cashier;
        }
        pos = cajas.siguiente(pos);
    }
}


LineaCaja::~LineaCaja() {
    cajas.~ListaEnla();
}

float LineaCaja::change_working_team() {
    ListaEnla<Till>::posicion pos=cajas.primera();
    float aux=0;
    while(pos!=cajas.fin()){
        aux+=cajas.elemento(pos).compras;
        cajas.elemento(pos).status=false;
        cajas.elemento(pos).compras=0;
        pos = cajas.siguiente(pos);
    }
    total_recaudation+=aux;
    return aux;//devuelve el dinero total recaudado en ese turno
}

float LineaCaja::close_shop() {
    change_working_team();
    return total_recaudation;
}

#endif //EXAMENES_LINEACAJA_H
