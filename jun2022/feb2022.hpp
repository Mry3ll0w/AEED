#ifndef feb2022_h
#define feb2022_h

#include <iostream>
#include "tads/ListaEnla.h"
#include <string>
#include <cassert>
//Struct necesarias

struct traduccion{
    ListaEnla<std::string> p_esp;
    
    std::string p_ing;
    
   
    traduccion(std::string p=""):p_ing(p){}
};

bool operator == (std::string p , traduccion t){
    return t.p_ing == p;
}

bool operator == (traduccion t1, traduccion t2){
    return t2.p_ing == t1.p_ing;
}

class diccionario{
  
private:
    ListaEnla<traduccion> dict;
public:
    diccionario(){};
    ~diccionario(){};
    
    void insertar_palabra(const std::string& p, const std::string & w);
    ListaEnla<std::string> traducciones(const std::string& p);
    void erase_trad(const std::string& p, const std::string& w);
    
    const ListaEnla<traduccion>& diccionario_completo(){
        return dict;
    }
};

//Recibe la palabra en ingles y su traduccion al español
void diccionario::insertar_palabra(const std::string& w,const std::string& p){
    
    //La palabra no puede ser vacia
    assert(p != "" && w !="");
    
    auto pos = dict.buscar(traduccion(w));
    
    //No lo encuentra
    if(pos == dict.fin()){
        
        traduccion t(w);
        t.p_esp.insertar(p, t.p_esp.fin());
        
        dict.insertar(t, pos);//pos vale final, por tanto lo insertamos al final de la lista
    }
    else{
        
        auto fin = dict.elemento(pos).p_esp.fin();
        dict.elemento(pos).p_esp.insertar(p, fin);
        
    }
        
        

}

ListaEnla<std::string> diccionario::traducciones(const std::string& p){
    
    auto pos = dict.buscar(traduccion(p));
    
    if (pos == dict.fin()) {
        return ListaEnla<std::string>();
    }
    else
        return dict.elemento(pos).p_esp;
    
}

void diccionario::erase_trad(const std::string & p , const std::string& w){
    
    auto pos = dict.buscar(w);
    
    if(pos != dict.fin()){
        
        auto pos_p_esp = dict.elemento(pos).p_esp.buscar(p);
        
//       Si encuentra la traduccion la elimina, en caso contrario no lo hace
        if (pos_p_esp != dict.elemento(pos).p_esp.fin()) {
            dict.elemento(pos).p_esp.eliminar(pos_p_esp);
        }
        
    }
    else
        std::cout<<"Esa traduccion no existe"<<std::endl;
    
}


#endif /* feb2022_h */
