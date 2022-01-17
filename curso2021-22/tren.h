#ifndef CURSO2021_22_TREN_H
#define CURSO2021_22_TREN_H

#include <iostream>
#include <cassert>
#include <string>
#include "tads_profesorado/pila_enla.h"

typedef std::string vagon;//Definimos un vagon como un string

class tren{

private:
    PilaEnla<vagon>lado_izq,lado_der;

public:
    //El tren los definiremos como dos pilas enfrentadas entre si, donde el vagon izquierdo sera
    //donde se inserta el vagon activo
    tren()=default;
    ~tren()=default;
    void insertar_vagon(const vagon& v);
    void desp_der();
    void desp_izq();
    void eliminar_activo();
    void show_activo(){std::cout<<lado_izq.tope()<<std::endl;}
    bool vacio(){return lado_der.vacia() && lado_izq.vacia();}


};


void tren::insertar_vagon(const vagon &v) {
    assert(v != " ");
    //Caso 1==> Pila izquierda vacia, no se desplaza nada a la derecha
    if (lado_izq.vacia())
        lado_izq.push(v);

    else{//Caso general==> La pila izquierda esta llena, hay que desplazar el actual hacia la derecha
        vagon t = lado_izq.tope();
        lado_izq.pop();
        lado_izq.push(v);//metemos el activo
        lado_der.push(t);//desplazamos el antiguo activo hacia la derecha
    }
}

void tren::eliminar_activo() {
    lado_izq.pop();//Simplemente sacamos el activo
}

void tren::desp_der() {
    //Si desplazamos hacia la derecha entonces sacamos de la izquierda a la derecha
    assert(!lado_izq.vacia());//No puede estar vacia, ya que si no como voy a desplazar
    vagon t = lado_izq.tope();
    lado_izq.pop();
    lado_der.push(t);//desplazamos el antiguo activo hacia la derecha
}

//Simetrico al anterior
void tren::desp_izq() {
    assert(!lado_der.vacia());
    vagon t = lado_der.tope();
    lado_der.pop();
    lado_izq.push(t);
}

#endif //CURSO2021_22_TREN_H
