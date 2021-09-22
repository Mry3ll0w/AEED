#ifndef TAD_COCINA_H
#define TAD_COCINA_H
#include "ListaEnla.h"
#include <iostream>


class cocina
{

public:
    typedef struct{
        size_t id;
        double anchura;
        double posicion;
    }mueble;

    cocina(double longitud=1):longitud_(longitud){}
    
    ~cocina();
private:
    double longitud_;
    size_t colocados_;
    ListaEnla<mueble>muebles;
    ListaEnla<mueble>::posicion cabe(const mueble&);
};

ListaEnla<cocina::mueble> cocina::cabe(const mueble& m){

}

#endif  