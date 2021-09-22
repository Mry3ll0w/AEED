#ifndef TAD_TEXTO_HPP
#define TAD_TEXTO_HPP
#include "tads implementados profesorado/ListaEnla.h"
#include <iostream>
#include <string>
using namespace std;

class texto
{
private:
    ListaEnla<string>lineas;
    bool elimina_linea(const string& l);

public:

    texto()=default;
    void insertar_linea(const string& l);
    void Mostrar_Texto();
    ~texto()=default;
};

bool texto::elimina_linea(const string& l){
    if (l.find('#')!=string::npos)
    {
        return true;
    }
    else
        return false;
}

void texto::insertar_linea(const string& l){
    string temp;
    if (elimina_linea(l)!=true)
    {
        for (size_t i = 0; i < l.size(); i++)
        {
            if (l.find('@')-1 != i && i!=l.find('@') )
            {
                temp+=l[i];
            }
            
        }
    }
    //Si se ha detectado la existencia de # la linea debe ser eliminada por tanto no se inserta
    lineas.insertar(temp,lineas.fin());
}

void texto::Mostrar_Texto(){
    for (auto i = lineas.primera(); i !=lineas.fin(); i=lineas.siguiente(i))
    {
        std::cout<<lineas.elemento(i)<<std::endl;
    }
}



#endif