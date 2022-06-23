#include <iostream>
#include "tads/pila_enla.h"
#include <string>

struct cubilete{
    
    int anchura;
    std::string posicion;

    cubilete(int a = 0):anchura(a){}

};


PilaEnla<cubilete> p_o; //Supuestamente recibe cubiletes

//Extrae el minimo de la pila
cubilete extrae_menor_cubilete(PilaEnla<cubilete> & p){
    cubilete c = p.tope();

    //Obtenemos el menor
    auto pt = p;

    while(!pt.vacia()){
        if (c.anchura > pt.tope().anchura)
        {
            c = pt.tope();
        }
        pt.pop();//pt ++
    }

    // p = 4 5 6 7  88 2    pt=___
    // c = 2
    //p = 4 5 6 7 88 
    // pt = 4 5 7 88 

    //Eliminamos de la pila original el menor 
    while (!p.vacia()){
        
        if (p.tope().anchura != c.anchura)
        {
            pt.push(p.tope());
        }
        
        p.pop();
    }
    //p = __ pt = 4 5 7 88
    p = pt;// p = pt = 4 5 6 7 88
    c.posicion = "boca abajo";
    return c;

}


PilaEnla<cubilete> objetivo(PilaEnla<cubilete> & p){
    PilaEnla<cubilete> final;
    while (!p.vacia())
    {
        final.push(extrae_menor_cubilete(p));
    }
    
return final;// 88 7 6 5 4
}

