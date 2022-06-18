#include <iostream>
#include "tads/ListaEnla.h"
#include <string>
#include <vector>

class texto{
private:
    ListaEnla<std::string> l;
    
public:
    void insertar_linea(std::string& s);
    std::string mostrar_texto();
};

void texto::insertar_linea(std::string& s){

    bool found = false;
    for(auto i : s){
        if (i == '#')
            found = true;break;
    }

    //No encuentra el # por tanto , no meto nada
    if (!found)
    {
        //Miramos las @
        for (int i = 0 ; i < s.size(); ++i)
        {
            if(s[i] == '@'){
                if (s[i] == s[i+1])//Si hay 2 seguidas solo borramos uno
                {
                    s.erase(s.find('@')-1,s.find('@'));
                    i+=1;
                }
                else
                    s.erase(s.find('@')-1,s.find('@'));
                
            }
                
        }

        l.insertar(s,l.fin());
    }

}

std::string texto::mostrar_texto(){

    std::string res=""; 
    for (auto p = l.primera(); p != l.fin() ; p = l.siguiente(p)){
        res+=", " + l.elemento(p);     
    }
    return res;
}