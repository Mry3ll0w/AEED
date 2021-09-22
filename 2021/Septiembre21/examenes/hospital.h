#ifndef SEPTIEMBRE21_HOSPITAL_H
#define SEPTIEMBRE21_HOSPITAL_H
#include <iostream>
#include "../tads p/ListaEnla.h"
#include <vector>
class paciente{
    size_t id;
    size_t gravedad;
public:
    explicit paciente(size_t id_=1, size_t gravedad_=-1):id(id_), gravedad(gravedad_) {}
    size_t gr()const{return gravedad;}
    size_t get_id()const{return id;}
};
//de 1 a 5 en la uci, de 6 a 9 en planta
class hospital{
    ListaEnla<paciente> uci, planta;
    size_t s_uci,s_planta;
    paciente min_gravedad(ListaEnla<paciente>& l);

    public:
    hospital(const size_t size_uci, const size_t size_planta):s_uci(size_uci),s_planta(size_planta){}
    void ingresar_paciente(const paciente& p);
    void muerte(const paciente& p);
    void alta(const paciente& p);
    void list_uci();
    void list_planta();
    void list_gravity(size_t,size_t);
    ~hospital()=default;
};

paciente hospital::min_gravedad(ListaEnla<paciente> &l) {
    paciente p = l.elemento(l.primera());
    for (auto i = l.primera(); i != l.fin(); i=l.siguiente(i)) {
        if (p.gr() > l.elemento(i).gr())
            p = l.elemento(i);
    }
    return p;
}

void hospital::ingresar_paciente(const paciente &p) {
    if (p.gr() <=5 ){
        if (s_uci <=0){//No hay espacio en uci, meted en la planta
            paciente temp = min_gravedad(uci);
            planta.insertar(temp , planta.fin());//Metemos en planta el paciente de menor gravedad de la uci
            ListaEnla<paciente>::posicion i;
            for (i = uci.primera(); i !=uci.anterior(uci.fin()) || uci.elemento(i).get_id() == temp.get_id(); i=uci.siguiente(i));
            //Avanzamos el iterador hasta el paciente buscado
            uci.eliminar(uci.anterior(i));// y lo elimnamos de la uci
            ++s_uci;
            --s_planta;
        }
        else{
            uci.insertar(p, uci.fin());
            --s_uci;
        }
    }
    if (p.gr()>=6){
        if(s_planta <=0){
            paciente temp = min_gravedad(planta);
            ListaEnla<paciente>::posicion i;
            for (i = planta.primera(); i !=planta.anterior(planta.fin()) || planta.elemento(i).get_id() == temp.get_id(); i=planta.siguiente(i));
            //Avanzamos el iterador hasta el paciente buscado
            planta.eliminar(i);
            ++s_planta;
        }
        else{
            --s_planta;
            planta.insertar(p,planta.fin());
        }
    }

}

void hospital::muerte(const paciente &p) {
    ListaEnla<paciente>::posicion i;
    //Buscamos el paciente en planta
    for (i = planta.primera(); i !=planta.fin() || planta.elemento(i).get_id() == p.get_id(); i=planta.siguiente(i));
    if (i == planta.fin()){
        //Buscamos el paciente en uci, ya que no esta en planta
        for (i = uci.primera(); i !=uci.fin() || uci.elemento(i).get_id() == p.get_id(); i=uci.siguiente(i));
        if (i == uci.fin())
            throw std::runtime_error("El paciente buscado no existe en el hospital");
        else{//Esta en la uci
            uci.eliminar(i);
        }
    }
    else{//esta en planta
        planta.eliminar(i);
    }
}

void hospital::alta(const paciente &p) {
    muerte(p); //Llamamos a muerte ya que hace a efectos del hospital lo mismo
}

void hospital::list_uci() {
    std::cout<<"ESTADO DE LA UCI"<<std::endl;
    for(auto i = uci.primera(); i !=uci.fin(); i=uci.siguiente(i)){
        std::cout<<uci.elemento(i).get_id()<<"\t"<<uci.elemento(i).gr()<<std::endl;
    }
}

void hospital::list_planta() {
    std::cout<<"ESTADO DE LA PLANTA"<<std::endl;
    for(auto i = planta.primera(); i !=planta.fin(); i=planta.siguiente(i)){
        std::cout<<planta.elemento(i).get_id()<<"\t"<<planta.elemento(i).gr()<<std::endl;
    }
}

void hospital::list_gravity(size_t gravedad, size_t lugar) {
    assert(lugar == 1 || lugar == 2);
    if (lugar == 1 ){
        //listamos la uci
        for(auto i = uci.primera(); i !=uci.fin(); i=uci.siguiente(i)){
            if (uci.elemento(i).gr()==gravedad){
                std::cout<<uci.elemento(i).get_id()<<std::endl;
            }
        }
    }
    else{//si no es 1 es 2 por assert
        for(auto i = planta.primera(); i !=planta.fin(); i=planta.siguiente(i)){
            if (planta.elemento(i).gr()==gravedad){
                std::cout<<planta.elemento(i).get_id()<<std::endl;
            }
        }
    }

}


#endif //SEPTIEMBRE21_HOSPITAL_H
