#ifndef SEPTIEMBRE21_ESTACION_TREN_H
#define SEPTIEMBRE21_ESTACION_TREN_H
#include "../tads p/ListaEnla.h"
#include <bits/stdc++.h>
struct tren{
    tren(size_t matricula= SIZE_MAX, size_t h= SIZE_MAX, size_t min= SIZE_MAX):mat(matricula),horas(h),minutos(min){}
    size_t mat, horas, minutos;
};
struct via_t{
    via_t (size_t id_= SIZE_MAX):id(id_){}
    tren t;
    size_t id;
};
class estacion{
    ListaEnla<via_t>transito;
    ListaEnla<tren>estacionamiento, maniobra; //Espacio ilimitado
    ListaEnla<tren>salidas; //Para llevar conteo de trenes que han dejado la via de transito
    size_t n_transito;
public:
    estacion(const size_t n_):n_transito(n_){
        for (int i = 0; i < n_ ; ++i) {
            transito.insertar(via_t(i),transito.fin());
        }//Inserta n vias de transito
    }
    ~estacion()=default;

    void llegada(const tren& t, const char v);
    void sacar_transito(size_t id);
    void est_transito(const tren& t);
    via_t& locacion(size_t id_t)const;
    ListaEnla<via_t>& transito_getter()const{
        return const_cast<ListaEnla<struct via_t> &>(transito);
    }
    ListaEnla<tren> estacionamiento_getter()const{return const_cast<ListaEnla<tren> &>(estacionamiento);}
    ListaEnla<tren> maniobra_getter()const{return const_cast<ListaEnla<tren> &>(maniobra);}
    ListaEnla<tren> salidas_getter()const{return const_cast<ListaEnla<tren> &>(salidas);}

    size_t tren_en_via(size_t id_v)const;
};

void estacion::llegada(const tren &t, const char v) {
    auto i = transito.primera();
    for (; i != transito.fin(); i=transito.siguiente(i)) {
        via_t temp = transito.elemento(i);
        if(v == temp.id){
            if(temp.t.mat == SIZE_MAX){
                //SI es size max esta hueco
                temp.t = t;
            }
            else{
                throw std::runtime_error("Esa via esta llena, no es posible meter en transito el tren");
            }
        }
    }
    if(i == transito.fin())
        throw std::runtime_error("Esa via no existe");
}

void estacion::sacar_transito(size_t id) {
    auto i = transito.primera();
    while(i != transito.fin() || transito.elemento(i).id == id){
        i = transito.siguiente(i);
    }
    if(transito.elemento(i).id == id){
        salidas.insertar(transito.elemento(i).t,salidas.fin());
        transito.elemento(i).t.mat = SIZE_MAX;//Sacamos de transito igualando al max
    }
    else if(i == transito.fin())
        throw std::runtime_error("Esa via no existe");
}

void estacion::est_transito(const tren& t) {
    auto i = estacionamiento.primera();
    while(i != estacionamiento.fin()||estacionamiento.elemento(i).mat == t.mat ){
        i = estacionamiento.siguiente(i);
    }
    if(estacionamiento.elemento(i).mat == t.mat){
        auto j = transito.primera();
        while(j != transito.fin() ||transito.elemento(j).t.mat == SIZE_MAX );
        if(j != transito.fin() ){
            //Ha encontrado un hueco
            transito.elemento(j).t =t;
        }
        else{
            throw std::runtime_error("Las vias de transito estan llenas");
        }
    }
    if(i == estacionamiento.fin()){
        throw std::runtime_error("Ese tren no esta en el estacionamiento");
    }
}

via_t &estacion::locacion(size_t id_t) const {
    //Primero vemos transito
    auto ti = transito.primera();
    for(ti; ti != transito.fin()|| transito.elemento(ti).t.mat == id_t;ti = transito.siguiente(ti));
    if(ti != transito.fin()){
        //Esta en transito
        return const_cast<via_t &>(transito.elemento(ti));
    }
    else{
        throw std::runtime_error("No esta en transito");
    }
}

size_t estacion::tren_en_via(size_t id_v) const {
    auto ti = transito.primera();
    for(ti; ti != transito.fin()|| transito.elemento(ti).t.mat == id_v;ti = transito.siguiente(ti));
    if(ti != transito.fin()){
        //Esta en transito
        return transito.elemento(ti).id;
    }
    else{
        throw std::runtime_error("Esa via no existe");
    }
}

//Apartado B) Funcion dado una hora y minutos diga el estado de las vias
void estado_vias(const estacion& est, size_t horas, size_t minutos){
    ListaEnla<via_t> temp_transito= est.transito_getter();
    ListaEnla<tren> salidas= est.salidas_getter();

    auto it_transito= temp_transito.primera();
    std::cout<<"Trenes en transito: "<<std::endl;
    while (it_transito != temp_transito.fin()){
        tren t_temp;
        t_temp = temp_transito.elemento(it_transito).t;
        if(t_temp.horas == horas && t_temp.minutos == minutos){
            //Muestra los trenes en transito en ese momento
            std::cout<<t_temp.mat<<", ";
        }
        it_transito = temp_transito.siguiente(it_transito);
    }
    std::cout<<std::endl;
    std::cout<<"Trenes que ya han salido"<<std::endl;
    auto it_salidas = salidas.primera();
    while (it_salidas != salidas.fin()){
        tren t_temp;
        t_temp = salidas.elemento(it_salidas);
        if(horas <= t_temp.horas || horas == t_temp.horas && minutos <= t_temp.minutos){
            std::cout<<t_temp.mat<<", ";
        }
        it_salidas = salidas.siguiente(it_salidas);
    }
    std::cout<<std::endl;
}


#endif //SEPTIEMBRE21_ESTACION_TREN_H
