#ifndef TEXTO_HPP
#define TEXTO_HPP
#include <iostream>
#include "tads profesorado/ListaEnla.h"
#include <string>
/*Tipos de datos necesarios para la realizacion correcta del ejercicio */
typedef struct palabra{
    std::string p_;
    bool cortada;    
    typename ListaEnla<linea>::posicion p_cortada; 
};

typedef struct linea{
    ListaEnla<palabra>palabras;
};
typedef struct texto
{
    ListaEnla<linea>lineas;
};

/* Apartado practico del examen, eliminar una palabra de un texto (no tiene porque estar en la misma linea) */
void erase_ocurrence(const std::string &ocurrencia,texto& t){
    auto p_linea = t.lineas.primera();
    auto p_palabra = t.lineas.elemento(t.lineas.primera()).palabras.primera();
    while (p_linea != t.lineas.fin())
    {
        while (p_palabra != t.lineas.elemento(p_linea).palabras.fin())
        {
            if (ocurrencia == t.lineas.elemento(p_linea).palabras.elemento(p_palabra).p_)
            {
                auto elimina_p = t.lineas.elemento(p_linea).palabras.elemento(p_palabra);
                if (t.lineas.elemento(p_linea).palabras.elemento(p_palabra).cortada == true)
                {
                    //si esta cortada eliminamos todas las palabras iguales que estan cortadas
                    t.lineas.elemento(t.lineas.elemento(p_linea).palabras.elemento(p_palabra).p_cortada).palabras.eliminar(t.lineas.elemento(p_linea).palabras.buscar(elimina_p));
                    //E;iminamos a los eliminados de la misma linea 
                    t.lineas.elemento(p_linea).palabras.eliminar(t.lineas.elemento(p_linea).palabras.buscar(elimina_p));
                }
                else{//Si no esta cortada se elimina y ya
                    t.lineas.elemento(p_linea).palabras.eliminar(t.lineas.elemento(p_linea).palabras.buscar(elimina_p));
                } 
            }
        }
    }
}


#endif