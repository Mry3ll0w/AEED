#include <iostream>
#include "tads/pila_enla.h"
#include <cassert>

typedef int vagon;

class tren{
private:
    PilaEnla<vagon> pder, pizq;
public:
    
    tren()=default;
    ~tren()=default;
    void desp_derecha();
    void desp_izqda();
    void insertar_activo();
    vagon activo();
    bool vacio(){return !pizq.vacia();}
};