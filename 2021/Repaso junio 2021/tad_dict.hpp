#ifndef TAD_DICT_HPP
#define TAD_DICT_HPP
#include <iostream>
#include <string>
#include "tads implementados profesorado/ListaEnla.h"
using namespace std;


class dict
{
private:
    typedef struct {
        string word;
        string p_sp;
    }p_inglesa;
    ListaEnla<p_inglesa> traducciones;
public:
    dict()=default;
    ~dict()=default;
    void insert_traduccion(const string& p,const string& trad);
    void eliminar_traduccion(const string& p_esp, const string& trad);
    void consultar_traducciones(const string& p_esp);
};

void dict::insert_traduccion(const string& p_esp, const string& trad){
    p_inglesa t;
    t.p_sp=p_esp;t.word=trad;
    traducciones.insertar(t,traducciones.fin());
}

void dict::eliminar_traduccion(const string& p_esp, const string& trad){
    
    for (auto i = traducciones.primera(); i!=traducciones.fin(); i=traducciones.siguiente(i))
    {
        if (traducciones.elemento(i).p_sp==p_esp && trad==traducciones.elemento(i).word)
        {
            traducciones.eliminar(i);
            break;//Si encontramos la traduccion a eliminar salimos del bucle
        }
        
    }
    cout<<"Se ha eliminado la traduccion buscada"<<endl;
}

void dict::consultar_traducciones(const string& p_esp){
    cout<<"traducciones de: "<<p_esp<<endl;
    for (auto i = traducciones.primera(); i!=traducciones.fin(); i=traducciones.siguiente(i))
    {
        if (traducciones.elemento(i).p_sp==p_esp)
        {
            cout<<traducciones.elemento(i).word<<endl;
        }
    }
}

#endif