#include <iostream>
#include "tads/ListaEnla.h"
#include <string>
#include <cassert>

struct sala {
    int id_sala;
    ListaEnla<std::string> espectaculos;
    bool operator < (sala s){//para ordernarlo y no mostrar repeticion
        return id_sala < s.id_sala;
    }
    bool operator == (sala s){
        return id_sala == s.id_sala;
    }
};

class cartelera{

private:
    ListaEnla<sala> l;
public:
    cartelera()=default;
    ~cartelera()=default;
    void add_sala(sala s);
    void add_espectaculo(sala s, std::string espectaculo);
    void eliminar_sala(sala s);
    void eliminar_espectaculo(sala s, std::string e);
    void mostrar_salas(){
        //Ya estan preordenadas, al igual que los espectaculos
        for(auto p = l.primera(); p != l.fin(); p = l.siguiente(p)){
            std::cout<<l.elemento(p).id_sala<<", ";
        }
        std::cout<<std::endl;
    }
    void mostrar_espectaculos(sala s){
        
        auto p = l.buscar(s);
        if (p!= l.fin())
        {
            auto pos = l.elemento(p).espectaculos.primera();
            while(pos != l.elemento(p).espectaculos.fin()){
                std::cout<<l.elemento(p).espectaculos.elemento(pos)<<", ";
                pos = l.elemento(p).espectaculos.siguiente(pos);
            }
            std::cout<<std::endl;
        }
        else
            std::cout<<"Esa sala no existe"<<std::endl;
        

    }

    //Recibimos un conjunto de salas, por definicion un conjunto no tiene repeticion.
    void mostrar_espectaculos_conjunto_salas(salas s[]);

    void salas_ofrecen_espectaculo(std::string e);
};

void cartelera::add_sala(sala s){
    
    auto p = l.buscar(s);
    if (p == l.fin())//Si no existe la sala no hacemos nada
    {   
        auto pos = l.primera();
        //Insertamos en orden
        for(; pos != l.fin() && l.elemento(pos) < s; pos != l.fin());
        l.insertar(s,pos);
    }
    

}

void cartelera::add_espectaculo(sala s , std::string espectaculo){
    auto p = l.buscar(s);
    assert(p != l.fin() && "Esta sala no existe");//Si no se encuentra, no existe por tanto salimoss

    auto p_esp = l.elemento(p).espectaculos.buscar(espectaculo);
    if (p_esp != l.elemento(p).espectaculos.fin())//solo se inserta si no existe ya ese espectaculo
    {
        l.elemento(p).espectaculos.insertar(espectaculo,p_esp);
    }

}

void cartelera::eliminar_sala(sala s){
    auto p = l.buscar(s);
    
    if (p!= l.fin())
    {
        l.eliminar(p);
    }
    
}

void cartelera::eliminar_espectaculo(sala s, std::string e){
    auto p = l.buscar(s);
    assert(p != l.fin() && "Esa sala no existe");
    
    auto pos = l.elemento(p).espectaculos(e);

    if (pos != l.elemento(p).espectaculos.fin())
    {
        l.elemento(p).espectaculos.eliminar(pos);
    }
    

}

void cartelera::mostrar_espectaculos_conjunto_salas(sala v[]){

    assert(v != nullptr);//No puede ser un vector vacio

    for (size_t i = 0; i < sizeof(v); i++)
    {
        auto p = l.buscar(v[i]);//Buscamos la sala
        if (p == l.fin())
        {
            std::cout<<"Esa sala no existe, pasamos a la siguiente"<<std::endl;
        }
        else{

            auto pos = l.elemento(p).espectaculos.primera();
            std::cout<<"Mostrando la sala: "<<l.elemento(p).id_sala<<": "<<std::endl;
            while (pos != l.elemento(p).espectaculos.fin())
            {
                std::cout<< l.elemento(p).espectaculos.elemento(pos)<<", ";
                pos = l.elemento(p).espectaculos.siguiente(pos);
            }
            std::cout<<std::endl;
            
        }
    }
    

}

void cartelera::salas_ofrecen_espectaculo(std::string e){

    for (auto i = l.primera(); i != l.fin(); i= l.siguiente(i))
    {
        for (auto j = l.elemento(i).espectaculos.primera(); j !=l.elemento(i).espectaculos.fin() ; 
        j=l.elemento(i).espectaculos.siguiente(j))
        {
            if (e == l.elemento(i).espectaculos.elemento(j))
            {
                std::cout<<l.elemento(i).id_sala<<", ";
            }
            
        }
        
    }
    
    std::cout<<std::endl;
}