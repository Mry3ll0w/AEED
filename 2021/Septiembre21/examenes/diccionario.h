#ifndef SEPTIEMBRE21_DICCIONARIO_H
#define SEPTIEMBRE21_DICCIONARIO_H
#include <iostream>
#include <string>
#include <utility>
#include "../tads p/ListaEnla.h"
//Cada palabra inglesa tiene multiples traducciones

struct p_inglesa{
    explicit p_inglesa(std::string input):eng_word(std::move(input)){}
    std::string eng_word;
    ListaEnla<std::string> translations;
};

class diccionario {
    ListaEnla<p_inglesa>words;
    ListaEnla<p_inglesa>::posicion existe(const std::string&);
public:
    diccionario()=default;
    ~diccionario()=default;
    void insertar_traduccion_esp(const std::string&,const std::string&);
    void erase_trad(const std::string&);
    void ver_traducciones(const std::string&)
};
ListaEnla<p_inglesa>::posicion diccionario::existe(const std::string& oc) {
    auto i= words.primera();
    for (i = word.primera();i != words.fin() || words.elemento(i).eng_word == oc);
    return i;
}

void diccionario::insertar_traduccion_esp(const std::string& eng, const std::string & esp) {
    ListaEnla<p_inglesa>:: posicion iterator_words;
    ListaEnla<std::string>:: posicion iterator_traducion;
    iterator_words = existe(esp);
    if (iterator_words != words.fin()){
        //Existe una palabra para traducir
        for(iterator_traducion = words.elemento(iterator_words).translations.primera() ;
        iterator_traducion!= words.elemento(iterator_words).translations.fin() ||
        words.elemento(iterator_words).translations.elemento(iterator_traduccion)== esp ;
        iterator_traducion= words.elemento(iterator_words).translations.siguiente(iterator_traducion));

        if (iterator_traducion == words.elemento(iterator_words).translations.fin())//Solo la inserta si no esta en las traducciones
            words.elemento(iterator_words).translations.insertar(esp,words.elemento(iterator_words).translations.fin());
    }
    else{
        throw std::runtime_error("Esa palabra inglesa no esta en el diccionario");
    }
}

void diccionario::erase_trad(const std::string & eng) {
    auto i = existe(eng);
    if (i != words.fin())
        words.eliminar(i);
    else // No encuentra la palabra en ingles
        throw std::runtime_error("No existe esa palabra en ingles");

}

void diccionario::ver_traducciones(const std::string & eng) {
    auto it = existe(eng);
    if (it != words.fin()){
        std::cout<<"Mostrando traducciones: "<<std::endl;
        for(auto j = words.elemento(it).translations.primera(); j != words.elemento(it).translations.fin(); j = words.elemento(j).translations.siguiente(j)) {
            std::cout<<words.elemento(it).translations.elemento(j)<<", ";
        }
        std::cout<<std::endl;
    }
    else{
        throw std::runtime_error("Esa palabra en ingles no existe en el diccionario");
    }
}

/*
 * Busca en la lista de traducciones la palabra inglesa concreta
 * Si no existe el parametro devuelto sera words.fin()
 */


#endif //SEPTIEMBRE21_DICCIONARIO_H
