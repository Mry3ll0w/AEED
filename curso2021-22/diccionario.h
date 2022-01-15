#ifndef CURSO2021_22_DICCIONARIO_H
#define CURSO2021_22_DICCIONARIO_H

#include <cassert>
#include <iostream>
#include <string>
#include "tads_profesorado/ListaEnla.h"

struct traduccion{

    std::string p_ing;

    ListaEnla<std::string>trad_esp;

    traduccion(const std::string& a = "", const std::string& b = " "):p_ing(a){
        auto fin = trad_esp.fin();
        trad_esp.insertar(b,fin);
    }

    bool operator == (const traduccion& other) const{
        return p_ing == other.p_ing;
    }
};

class diccionario{
private:
    ListaEnla<traduccion> traducciones;
public:
    diccionario()=default;
    ~diccionario()=default;
    void insertar_traduccion(const std::string& p_ing, const std::string& p_esp);
    void eliminar_traduccion_al_esp(const std::string& p_ing, const std::string& p_esp);
    void show_trad(const std::string& p);
};

void diccionario::insertar_traduccion(const std::string &p_ing, const std::string &p_esp) {
    assert(p_ing != " " && p_esp != " ");

    //Buscamos si existe esa traduccion
    //1) Si no existe se inserta
    //2) Si existe se inserta traduccion
    auto p_word = traducciones.buscar((traduccion(p_ing,p_esp)));

    if(p_word == traducciones.fin()){//no existe la traduccion, la insertamos
        auto fin = traducciones.fin();
        traducciones.insertar(traduccion(p_ing,p_esp),fin);

    }
    else{//La palabra inglesa existe, se inserta la palabra en esp
        auto fin_traduccion = traducciones.elemento(p_word).trad_esp.fin();
        traducciones.elemento(p_word).trad_esp.insertar(p_esp,fin_traduccion);
    }

}

void diccionario::show_trad(const std::string &p) {

    //Comprobamos que exista esa traduccion al ingles
    auto pos = traducciones.buscar(traduccion(p));
    assert(pos != traducciones.fin());//Si fuese igual a fin no existe esa palabra en ingles

    //Mostramos las traducciones
    //Simplificamos la iteracion priorizando coste espacial sobre temporal
    ListaEnla<std::string> temporal = traducciones.elemento(pos).trad_esp;

    for(auto i = temporal.primera(); i!= temporal.fin() ;i = temporal.siguiente(i))
        std::cout<<temporal.elemento(i)<<", ";

    std::cout<<std::endl;

}

void diccionario::eliminar_traduccion_al_esp(const std::string &p_ing, const std::string &p_esp) {
    auto pos = traducciones.buscar(traduccion(p_ing));
    assert(pos != traducciones.fin());//Si fuese igual a fin no existe esa palabra en ingles

    auto pos_palabra = traducciones.elemento(pos).trad_esp.buscar(p_esp);

    //si la traduccion existe se elimina
    if ( pos_palabra != traducciones.elemento(pos).trad_esp.fin() ){
        traducciones.elemento(pos).trad_esp.eliminar(pos_palabra);
    }
    else{
        std::cout<<"Esta traduccion no tiene asociada la palabra esp: "<<p_esp<<std::endl;
    }

}


#endif //CURSO2021_22_DICCIONARIO_H
