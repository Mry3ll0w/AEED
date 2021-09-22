#ifndef EX_JUNIO_2021_HPP
#define EX_JUNIO_2021_HPP
#include<iostream>
#include<string>
#include "tads implementados profesorado/ListaEnla.h"
using namespace std;


typedef struct t_linea
{
    ListaEnla<string>palabras;
};

typedef struct t_texto
{
    ListaEnla<t_linea>lineas;    
};

void eliminar_ocurrencias_texto(const string ocurrencia, t_texto& texto){
    auto pos = texto.lineas.primera();
    while (pos!=texto.lineas.fin())
    {
        auto pos_oc=texto.lineas.elemento(pos).palabras.buscar(ocurrencia);
        if (pos_oc!=texto.lineas.elemento(pos).palabras.fin())
        {
            texto.lineas.elemento(pos).palabras.eliminar(pos_oc);//Si encuentra la ocurrencia eliminala
        }

        pos=texto.lineas.siguiente(pos);
    } 
}

#endif