#include <iostream>
#include <cassert>
#include <string>
#include "tads/ListaEnla.h"
#include "tads/listavec.h"

struct paciente {
    
    std::string c;
    
    int gravedad;
    
    paciente(std::string s="", int i=0 ):c(s),gravedad(i){}
    
    bool operator <(paciente p){
        return gravedad < p.gravedad;
    }

    bool operator >(paciente p){
        return gravedad > p.gravedad;
    }

    bool operator == (paciente p){
        return (p.c == c) && (p.gravedad==gravedad); 
    }


};


class Hospital{
private:
    listavec<paciente> uci,planta;
    ListaEnla<paciente> morgue;
    int cap_uci, cap_planta;
    
    //Extrae de la lista el paciente de menor gravedad, es decir el de p.gravedad de mayor numero
    paciente extrae_menor_gravedad(listavec<paciente> l, int& capacidad);

public:
    
    Hospital(int c_uci, int c_planta):cap_uci(c_uci),cap_planta(c_planta),
    uci(listavec<paciente>(c_uci)), planta(listavec<paciente>(c_planta)),morgue(ListaEnla<paciente>()){}
    
    ~Hospital(){}

    //Entiendo que desde planta, o UCI
    void dar_alta(paciente & p);
    void ingreso(paciente &p);
    void muerte(paciente& p);
    void pacientes_gravedad(int g);
    paciente* pacientes_uci();//Me da pereza
    paciente* pacientes_planta();
    paciente* pacientes_morgue();



};

paciente Hospital::extrae_menor_gravedad(listavec<paciente> l, int& capacidad){
    assert(capacidad == 0);//La capacidad de la lista debe ser 0, ya que solo se usará si no hay hueco
    
    paciente p(l.elemento(l.primera()));

    for (auto i = l.primera(); i != l.fin(); i = l.siguiente(i)){
        if(p < l.elemento(i))
            p = l.elemento(i);

    }
    //Tras obtener el paciente de menor gravedad, lo sacamos de la lista y lo devolvemos
    l.eliminar(l.buscar(p));
    return p;
}

void Hospital::ingreso(paciente & p){

    //Insertar en la UCI
    if (p.gravedad >= 1 && p.gravedad <=5)
    {
        //Caso 1: Hay espacio en la UCI
        if (cap_uci > 0)
        {
            //Insertamos en la UCI
            uci.insertar(p,uci.fin());
            cap_uci--;
        }
        else{
            //No hay espacio en la UCI
            //Comprobamos si hay espacio en planta
            if (cap_planta > 0)
            {
                //Insertamos el paciente de menor gravedad de la uci en planta
                planta.insertar(extrae_menor_gravedad(uci,cap_uci),planta.fin());
                cap_planta--;
                //Insertamos el nuevo paciente en la UCI
                uci.insertar(p,uci.fin());
                cap_uci=0;//La capacidad de la uci se queda en 0, ya que se saca uno y se mete otro
            }
            else{
                //Sacamos el de menor gravedad de la UCI y lo metemos en planta
                //En planta no hay espacio ,asi que sacamos al menor gravedad de planta 
                //y metemos el extraido

                //Caso 2 no hay espacio en planta ni uci
                paciente t = extrae_menor_gravedad(uci,cap_uci);
                uci.insertar(p,uci.fin());

                extrae_menor_gravedad(planta, cap_planta);
                planta.insertar(t,planta.fin());


            }

            
        }
    }
    else if (p.gravedad >= 6 && p.gravedad <= 9 ){
        if (cap_planta > 0)
        {
            planta.insertar(p,planta.fin());
        }
        else
            extrae_menor_gravedad(planta,cap_planta);
            planta.insertar(p,planta.fin());
        
    }
    else
        morgue.insertar(p,morgue.fin());

}

void Hospital::dar_alta(paciente &p){
    
    auto pos = uci.buscar(p);
    if (pos != uci.fin())
    {
        uci.eliminar(pos);
        cap_uci ++;
    }
    else{
        auto p_planta = planta.buscar(p);
        if (p_planta != planta.fin())
        {
            planta.eliminar(p_planta);
            cap_planta++;
        }
    }
    
    

}

void Hospital::muerte(paciente & p){
    auto pos = uci.buscar(p);
    if (pos != uci.fin())
    {
        uci.eliminar(pos);
        morgue.insertar(p,morgue.fin());
        cap_uci ++;
    }
    else{
        auto p_planta = planta.buscar(p);
        if (p_planta != planta.fin())
        {
            planta.eliminar(p_planta);
            cap_planta++;
            morgue.insertar(p,morgue.fin());
        }
    }
}

void Hospital::pacientes_gravedad(int g){

    if(g >= 1 && g<=6){
        for(auto i = uci.primera(); i != uci.fin();i = uci.siguiente(i)){
            if (uci.elemento(i).gravedad == g)
            {
                std::cout<<uci.elemento(i).c<<std::endl;
            }
            
        }
    }
    else if(g > 6 && g <= 9 ){
        for(auto i = planta.primera(); i != planta.fin();i = planta.siguiente(i)){
            
            if (planta.elemento(i).gravedad == g)
            {
                std::cout<<planta.elemento(i).c<<std::endl;
            }
            
        }
    }

}