#ifndef TAD_TREN_HPP
#define TAD_TREN_HPP
#include <iostream>
#include <cassert>
#include "tads implementados profesorado/pila_enla.h"

typedef struct{
    size_t id;
}vagon;

class tren
{
private:
    PilaEnla<vagon>atras,delante;
public:
    tren(){}//crea un tren vacio

    ~tren()=default;//Elimina el tren a traves de la clase pila

    void insertar_vagon_activo(const vagon&);

    void desplazar_dcha();

    void desplazar_izqda();

    const size_t observar_activo()const{
        return delante.tope().id;
    }

    bool t_vacio(){
        return delante.vacia();
    }//Ya que si la pila derecha esta vacia no existen vagones activos ==> no existe tren

    void eliminar_vagon(){
        assert(t_vacio()!=true);
        delante.pop();
    }

};

void tren::insertar_vagon_activo(const vagon& v){
    delante.push(v);
}

void tren::desplazar_dcha(){
    assert(atras.vacia()!=true);
    delante.push(atras.tope());
    atras.pop();
}

void tren::desplazar_izqda(){
    assert(!t_vacio());
	atras.push(delante.tope());
	delante.pop();
	if(delante.vacia())//si dejamos a la pila activa vacia tras esto entonces no hacemos nada, es decir revertimos lo realizado
	{
		delante.push(atras.tope());
		atras.pop();
	}
}


#endif