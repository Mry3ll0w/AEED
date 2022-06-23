#include <iostream>
#include "tads/pila_enla.h"
#include <cassert>

typedef int vagon;

class tren{
private:
    PilaEnla<vagon> pder, pizq;
    //El tope de la pila derecha es el que va a tener el activo
public:
    
    tren()=default;
    ~tren()=default;
    //Desplaza el vagon activo a la derecha, el que esta a la izquierda es el nuevo activo (si no hay ninguno no se ejecuta)
    void desp_derecha();
    
    //Igual que el de arriba, no se hace si la pila derecha esta vacia
    void desp_izqda();
    
    //Inserta el nuevo vagon activo desplazando todos a la 
    void insertar_activo(vagon v);
    
    //Devuelve el vagon activo (representado con un numero que lo identifica)
    vagon activo();
    
    //Elimina el vagon activo y si la pder queda vacia despues de eso, se inserta el de la pizq, si no existe el tren queda vacio.
    void eliminar_activo();
    
    bool vacio(){return !pder.vacia();}
};

vagon tren::activo(){
    return pder.tope();
}

void tren::insertar_activo(vagon v){
    //Insertamos el activo en la pila derecha
    pder.push(v);
}

void tren::desp_derecha(){

    assert(!vacio());//El tren no puede estar vacio, en ese caso no podemos desplazar nada

    //Si no esta vacia se hace
    if (!pizq.vacia())
    {
        //Extraemos en t el tope de la pila derecha
        vagon t = pizq.tope();
        pizq.pop();
        pder.push(t);
    }
    

}

void tren::desp_izqda(){
    assert(!vacio());
    
    if (!pder.vacia())
    {
        pizq.push(pder.tope());
        pder.pop();
    }
    
}

void tren::eliminar_activo(){
    assert(!vacio());

    pder.pop();//elimino el activo

    if (!pizq.vacia())
    {
        pder.push(pizq.tope());
        pizq.pop();
    }
    

}