#ifndef TAD_HOSPITAL_HPP
#define TAD_HOSPITAL_HPP
#include <iostream>
#include <cassert>
#include "tads implementados profesorado/ListaEnla.h"

typedef struct {
    size_t gravedad;
    size_t id; 
}paciente;

class hospital
{
private:
    ListaEnla<paciente> uci_,planta_,morgue_;
    size_t size_uci_,size_planta_;
    const paciente menor_gravedad(ListaEnla<paciente>&l);
public:

/* ------------------------------- constructor ------------------------------ */
    hospital(size_t size_UCI,size_t size_planta):size_uci_(size_UCI),size_planta_(size_planta){}
    ~hospital(){size_uci_=0;size_planta_=0;}
    void ingreso(const paciente& p);
    void alta(const paciente&p){
        planta_.eliminar(planta_.buscar(p));
    }
    void pacientes_uci(){
        
        for (auto i = uci_.primera(); i !=uci_.fin(); i=uci_.siguiente(i))
        {
            std::cout<<"ID==>"<<uci_.elemento(i).id<<std::endl;
            std::cout<<"GRAVEDAD==>"<<uci_.elemento(i).gravedad<<std::endl;
        }
    }
    void pacientes_planta(){
        for (auto i = planta_.primera(); i !=planta_.fin(); i=planta_.siguiente(i))
        {
            std::cout<<"ID==>"<<planta_.elemento(i).id<<std::endl;
            std::cout<<"GRAVEDAD==>"<<planta_.elemento(i).gravedad<<std::endl;
        }
    }
    void pacientes_gravedad(size_t g,ListaEnla<paciente>l){
        for (auto i = l.primera(); i !=l.fin(); i=l.siguiente(i))
        {
            if (g==l.elemento(i).gravedad)
            {
                std::cout<<"ID==>"<<l.elemento(i).id<<std::endl;
                std::cout<<"GRAVEDAD==>"<<l.elemento(i).gravedad<<std::endl;
            }
        }
    }
    


};

const paciente hospital::menor_gravedad(ListaEnla<paciente>&l) {
    paciente menor;
    menor.gravedad=l.elemento(l.primera()).gravedad;
    menor.id=l.elemento(l.primera()).id;
    for (auto i = l.primera(); i !=l.fin(); i=l.siguiente(i))
    {
        if (menor.gravedad>l.elemento(i).gravedad)
        {
            menor.gravedad = l.elemento(i).gravedad;
            menor.id = l.elemento(i).id;
        }
    }
    
}

void hospital::ingreso(const paciente& p) {
    if (p.gravedad>=1 && p.gravedad<6)//Quiere entrar en la UCI
    {
        if (size_uci_<1)
        {
            if (size_planta_<1)
            {
                planta_.eliminar(planta_.buscar(menor_gravedad(planta_)));//Elimina el paciente de menor gravedad
                planta_.insertar(uci_.elemento(uci_.buscar(menor_gravedad(uci_))),planta_.fin());
                uci_.eliminar(uci_.buscar(menor_gravedad(uci_)));
                uci_.insertar(p,uci_.fin());
                size_planta_++;
                size_uci_++;
            }
            else
                planta_.insertar(uci_.elemento(uci_.buscar(menor_gravedad(uci_))),planta_.fin());
                uci_.eliminar(uci_.buscar(menor_gravedad(uci_)));
                uci_.insertar(p,uci_.fin());
                size_planta_++;
                size_uci_++;

        }
        else{
            uci_.insertar(p,uci_.fin());
        }
    }
    else if( p.gravedad >= 6 && p.gravedad < 10 ){
        if (size_planta_<1)
            {
                planta_.eliminar(planta_.buscar(menor_gravedad(planta_)));//Elimina el paciente de menor gravedad
                planta_.insertar(uci_.elemento(uci_.buscar(menor_gravedad(uci_))),planta_.fin());
            }
            else
                planta_.insertar(p,planta_.fin());
    }
}


#endif