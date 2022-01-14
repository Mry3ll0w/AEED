#ifndef CURSO2021_22_HOSPITAL_H
#define CURSO2021_22_HOSPITAL_H

#include "tads_profesorado/ListaEnla.h"
#include <iostream>
#include <string>
#include <utility>

struct paciente{
    std::string id;
    unsigned gravedad;
    paciente(std::string s=" ", unsigned gr=0):id(std::move(s)),gravedad(gr){}
    paciente& operator=(const paciente& other)=default;
    bool operator == (const paciente& other) const{return id == other.id;}
    bool operator < (const paciente& other) const{return gravedad < other.gravedad;}
};

class hospital{
private:

    ListaEnla<paciente> morgue,uci,planta;
    size_t libre_uci,libre_planta;

public:
    hospital(const size_t t_uci, const size_t t_planta):libre_uci(t_uci),libre_planta(t_planta){}
    void ingresar_paciente(const paciente& p);
    void alta_paciente(const paciente& p);
    void muerte(const paciente& p, const std::string& piso);
    void pacientes_uci();
    void pacientes_planta();
    void pacientes_gravedad(const unsigned& g);
    ~hospital()=default;
};

void hospital::pacientes_uci() {
    for(auto i = uci.primera(); i != uci.fin(); i = uci.siguiente(i) ){
        std::cout<<uci.elemento(i).id <<std::endl;
    }
}

void hospital::pacientes_planta() {
    for(auto i = planta.primera(); i != planta.fin(); i = planta.siguiente(i) ){
        std::cout<<planta.elemento(i).id <<std::endl;
    }
}

void hospital::muerte(const paciente &p, const std::string& piso) {
    if (piso == "uci"){
        uci.eliminar(uci.buscar(p));
    }
    else if(piso == "planta"){
        planta.eliminar(planta.buscar(p));
    }
}

void hospital::alta_paciente(const paciente &p) {
    planta.eliminar(planta.buscar(p));
}

void hospital::ingresar_paciente(const paciente &p) {

    //Primero vemos que gravedad tiene el cociente
    if (p.gravedad < 1){
        auto pos = morgue.fin();
        morgue.insertar(p,pos);
    }
    else if( p.gravedad > 1 && p.gravedad <= 5){

        if(libre_uci > 0){
            auto pos = uci.primera();
            //buscamos la posicion de insercion para tener una lista de menor a mayor
            for(;pos != uci.fin() && uci.elemento(pos).gravedad < p.gravedad;pos = uci.siguiente(pos));

            uci.insertar(p,pos);

            libre_uci --;
        }
        else{
            auto pos_final = uci.anterior(uci.fin());
            paciente menos_grave = uci.elemento(pos_final);//El menos grave lo sacamos y lo metemos en planta
            uci.eliminar(pos_final);//se elimina del sistema en cualquier caso
            //ya que si la planta esta llena se saca, y si no se inserta la copia

            //METEMOS EL PACIENTE NUEVO
            auto pos = uci.primera();
            for(;pos != uci.fin() && uci.elemento(pos).gravedad < p.gravedad;pos = uci.siguiente(pos));

            uci.insertar(p,pos);

            //Comprobamos si esta libre la planta
            if (libre_planta > 0 ){

                auto pos = planta.primera();

                for(;pos != planta.fin() && planta.elemento(pos).gravedad < p.gravedad;pos = planta.siguiente(pos));

                planta.insertar(menos_grave,pos);
                libre_planta --;//Decrementamos el espacio de planta
            }
        }

    }
    else if (p.gravedad >= 6 && p.gravedad <= 9){
        if(libre_planta > 0){
            auto pos = planta.primera();

            for(;pos != planta.fin() && planta.elemento(pos).gravedad < p.gravedad;pos = planta.siguiente(pos));

            planta.insertar(p,pos);

            libre_planta --;
        }
        else{
            std::cout<<"No existe espacio en el hospital "<<std::endl;
        }
    }

}


#endif //CURSO2021_22_HOSPITAL_H
