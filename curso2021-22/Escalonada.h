#ifndef CURSO2021_22_ESCALONADA_H
#define CURSO2021_22_ESCALONADA_H

#include <iostream>
#include "tads_profesorado/ListaEnla.h"


struct funcion{
    size_t x;
    size_t y;
    funcion(const size_t& x_ = 0, const size_t& y_ = 0):x(x_),y(y_){}
    bool operator ==(const funcion& f){
        return x == f.x && y == f.y;
    }
};
class Escalonada{
private:
    ListaEnla<funcion>grafica;
public:

    //No dice nada asi que se crea lista vacia;
    Escalonada(const size_t& x, const size_t& y){
        auto pos = grafica.fin();
        grafica.insertar(funcion(x,y),pos);
    }
    ~Escalonada()=default;
    //Se inserta en la ultima x ya que es una escalonada, por tanto solo se necesita el
    void insertar_salto(const size_t& f);

    //Eliminar el salto y extender la funcion anterior
    void eliminar_salto(const size_t& x);

    const size_t maximo()const;

    const size_t minimo()const;

    void translacion(const size_t& x, const size_t& y,const size_t & t);

    void show_grafica(){
        auto i = grafica.primera();
        while (i != grafica.fin()){
            std::cout << grafica.elemento(i).x <<", "<<grafica.elemento(i).y <<std::endl;
            i = grafica.siguiente(i);
        }

    }

};

void Escalonada::insertar_salto(const size_t &f) {

    //insertamos en la ultima x
    auto fin = grafica.fin();
    auto p_elemento_final = grafica.anterior(fin);

    //Se inserta donde acaba la ultima funcion
    grafica.insertar(funcion(grafica.elemento(p_elemento_final).y,f),fin);

}

void Escalonada::eliminar_salto(const size_t &x) {

    //Eliminamos la posicion dada tras localizarla
    auto i = grafica.primera();
    while (i != grafica.fin()){
        if (grafica.elemento(i).x==x)
            break;
        i = grafica.siguiente(i);
    }

    //si es el final entonces no lo ha encontrado
    if (i != grafica.fin()){

        //Si no es la primera se tiene q rectificar, si no no
        if (i != grafica.primera()){
            auto p_anterior = grafica.anterior(i);
            grafica.elemento(p_anterior).y = grafica.elemento(i).y;
            //Tras actualizar la longitud borramos
            grafica.eliminar(i);

        }
    }
    else{//simplemente la eliminamos si es la primera
        grafica.eliminar(i);
    }

}

const size_t Escalonada::maximo() const {
    auto it = grafica.primera();
    size_t max = grafica.elemento(it).y;
    //miramos a partir de la siguiente de la primera
    it = grafica.siguiente(it);
    while (it != grafica.fin()){

        if (max < grafica.elemento(it).y)
            max = grafica.elemento(it).y;

        it = grafica.siguiente(it);
    }
return max;
}

const size_t Escalonada::minimo() const {
    auto it = grafica.primera();
    size_t min = grafica.elemento(it).y;
    //miramos a partir de la siguiente de la primera
    it = grafica.siguiente(it);
    while (it != grafica.fin()){

        if (min > grafica.elemento(it).y)
            min = grafica.elemento(it).y;

        it = grafica.siguiente(it);
    }
    return min;
}

void Escalonada::translacion(const size_t &x, const size_t &y, const size_t & t) {

    //Si es 0 no se hace nada
    if(t != 0){
        //Obtenemos la posicion en la lista del tramo buscado
        auto p = grafica.buscar(funcion(x,y));
        //2) Transladamos los anteriores si t <= -1 o los posteriores t >= 1
        if(t < 0){
            //traslado anteriores
            while(p != grafica.primera()){

                grafica.elemento(p).x+=t; grafica.elemento(p).y+=t;

                p=grafica.anterior(p);
            }

        }
        else{
            while(p != grafica.fin()){

                grafica.elemento(p).x+=t; grafica.elemento(p).y+=t;

                p= grafica.siguiente(p);
            }
        }

    }

}


#endif //CURSO2021_22_ESCALONADA_H
