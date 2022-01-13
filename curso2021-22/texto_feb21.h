#ifndef CURSO2021_22_TEXTO_FEB21_H
#define CURSO2021_22_TEXTO_FEB21_H
#include "tads_profesorado/ListaEnla.h"
#include <iostream>
#include <string>
struct palabra{
    std::string p;
    bool cortada;
    palabra(std::string str=" ",bool c = false):cortada(c),p(std::move(str)){}
    palabra& operator = (const palabra& pal) = default;
    bool operator == (const palabra& pal) const{return pal.p == p;}
    bool operator == (const std::string& s) const{return s == p;}
};
struct tLinea{
    ListaEnla<palabra>palabras;
    tLinea()=default;
    tLinea& operator= (const tLinea& pal) = default;
};
struct tTexto{
    ListaEnla<tLinea>lineas;
    tTexto& operator = (const tTexto& t)= default;
};


class texto2{

private:
    tTexto t;
public:
    texto2()=default;
    ~texto2()=default;
    void insertar_linea(const tLinea& line);
    void show_texto();
    void substitute_word(const std::string& word,const std::string& new_word);
};

void texto2::insertar_linea(const tLinea &line) {
    auto final = t.lineas.fin();
    t.lineas.insertar(line,final);
}

void texto2::show_texto() {

    for(auto i= t.lineas.primera(); i != t.lineas.fin(); i=t.lineas.siguiente(i)){

        for(auto j = t.lineas.elemento(i).palabras.primera(); j !=t.lineas.elemento(i).palabras.fin();
        j = t.lineas.elemento(i).palabras.siguiente(j)){
            std::cout<< t.lineas.elemento(i).palabras.elemento(j).p <<" ";
        }
        std::cout<<std::endl;
    }

}

void texto2::substitute_word(const std::string &word,const string& new_word) {

    for(auto i= t.lineas.primera(); i != t.lineas.fin(); i=t.lineas.siguiente(i)){

        for(auto j = t.lineas.elemento(i).palabras.primera(); j !=t.lineas.elemento(i).palabras.fin();
            j = t.lineas.elemento(i).palabras.siguiente(j)){

            auto pos = t.lineas.elemento(i).palabras.buscar(word);

            //Si la búsqueda apunta al final entonces no existe ese elemento
            if( pos != t.lineas.elemento(i).palabras.fin()){
                t.lineas.elemento(i).palabras.elemento(pos)=new_word;
            }
        }

    }

}

#endif //CURSO2021_22_TEXTO_FEB21_H
