#ifndef PRACTICA6_H
#define PRACTICA6_H
#include "tads implementados profesorado/ListaEnla.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

/* ------------------------------- EJERCICIO 1 ------------------------------ */
// Una lista ordenada es una lista en la cual los elementos están ordenados de forma 
// ascendente según la relación de orden definida entre ellos. Especifique e implemente el TAD
// Lista ordenada
template<typename t>
class ListaOrdenada{
    private:
       
        void ordernar_asc(){
            typename ListaEnla<t>::posicion p;
            for (p=list.primera();p!=list.anterior(list.fin());p=list.siguiente(p))
            {
                if (list.elemento(p)>list.elemento(list.siguiente(p)))
                {
                    t parser=list.elemento(list.siguiente(p));
                    list.elemento(list.siguiente(p)) = list.elemento(p);
                    list.elemento(p)=parser;
                }
                
            }
        }
    public:
        ListaEnla<t>list;
        ListaOrdenada(){};
        void insertar(typename ListaEnla<t>::posicion p, t elemento)noexcept {
            list.insertar(elemento, p);
            ordernar_asc();
        }    
        void eliminar(typename ListaEnla<t>::posicion p)noexcept;
        void show_list(){
            typename ListaEnla<t>::posicion p;
            for (p=list.primera();p!=list.fin();p=list.siguiente(p))
            {
                std::cout<<list.elemento(p)<<", "<<std::endl;
            }
            std::cout<<std::endl;
        }
        ~ListaOrdenada()=default;


};

/**
 * @brief Implemente una función que tenga como entrada una lista de enteros y un entero x, de
 * forma que devuelva la lista modificada mediante la eliminación de todas las ocurrencias
 * de x en la lista.
 * 
 */
template<typename t>
ListaEnla<t> ej2_p6(t ocurrencia,ListaEnla<t>&list){
    auto pos=list.primera();
    ListaEnla<t>temp;
    while (pos!=list.fin()){
        
        if (ocurrencia!=list.elemento(pos))
        {
            temp.insertar(list.elemento(pos),temp.fin());
        }
        pos = list.siguiente(pos);
    }
    list=temp;
    return list;
}

/* ------------------------------- EJERCICIO 4 ------------------------------ */
/**
 * @brief 
 * 4. Dadas dos listas de enteros ordenadas, implemente una función que devuelva una tercera
    lista ordenada con la mezcla de las dos listas de entrada.
 * 
 * @param a Recibe una lista no vacia de elementos tipo t
 * @param b Recibe una lista no vacia de elementos tipo t
 * @return ListaEnla<t> 
 */
template<typename t>
ListaEnla<t> ej4_p6(ListaEnla<t> &a, ListaEnla<t>&b){
    auto posa = a.primera();
    auto posb =b.primera();
    ListaEnla<t> temp_list;
    while (posa!=a.fin()&&posb!=b.fin())
    {
        temp_list.insertar(a.elemento(posa),temp_list.fin());
        temp_list.insertar(b.elemento(posb),temp_list.fin());
        posa=a.siguiente(posa);
        posb=b.siguiente(posb);
    }
    if (posa!=a.fin())
    {
        while (posa!=a.fin())
        {
            temp_list.insertar(a.elemento(posa),temp_list.fin());
            posa=a.siguiente(posa);
        
        }   
    }
    if (posb!=b.fin())
    {
        while (posb!=b.fin())
        {
            temp_list.insertar(b.elemento(posb),temp_list.fin());
            posb=b.siguiente(posb);
        }
    }
    return temp_list;
}

/* ------------------------------- EJERCICIO 5 ------------------------------ */
/**
 * @brief 
 * Implemente una función ImprimeInverso() que imprima los elementos de una lista 
 * simplemente enlazada de enteros en orden inverso a partir de la posición p.
 * @param p 
 * @param l 
 */
template <typename t>
void ej5_p6(typename ListaEnla<t>::posicion p,ListaEnla<t>& l){
    std::vector<int>reverse_data;
    while (p!=l.fin())
    {
        reverse_data.push_back(l.elemento(p) );
        p=l.siguiente(p);
    }
    reverse(reverse_data.begin(),reverse_data.end());
    for (auto i:reverse_data)
    {
        std::cout<<i<<" ";
    }
    
    std::cout<<std::endl;
    
}
/**
 * @brief
 * Implemente una función que concatene una lista de listas (TAD Lista cuyo tipo de elementos 
 * es a su vez una lista de elementos de cierto tipo T), de forma que a partir de lalista original, 
 * llamada LInic (lista de listas), se obtenga una nueva lista, llamada LConcat (lista de elementos T). 
 * @param origen 
 * @param destino 
 * @return ListaEnla<t> 
 */
template<typename t>
ListaEnla<t> ej7_p6(ListaEnla<ListaEnla<t>>& origen, ListaEnla<t>&destino){
    auto pos=origen.primera();
    while (pos!=origen.fin())
    {
        auto pos_interna=origen.elemento(pos)->primera();
        while (pos_interna!=origen.elemento(pos_interna).fin())
        {
            destino.insertar(origen.elemento(pos_interna).elemento(pos_interna));
            pos_interna = origen.elemento(pos_interna).siguiente(pos_interna);
        }
        
        pos=origen.siguiente(pos);
    }
    
}
/**
 * @brief ej8 
 * 
 */
class num_binario
{
private:
    ListaEnla<char>bin_char;
    size_t num_length;
public:
    num_binario(const char* input){
        
        for (size_t i=0;i<strlen(input);++i)
        {
            bin_char.insertar(input[i],bin_char.fin());
        }
        num_length=strlen(input);
        
    }
    ~num_binario()=default;

/* ------------------------------ observadores ------------------------------ */
    size_t length(){return num_length;}
    ListaEnla<char>& num_bin_getter(){return bin_char;}
/* --------------------------------- METODOS -------------------------------- */
    void show(){
        
        for (auto pos=bin_char.primera(); pos!=bin_char.fin(); pos=bin_char.siguiente(pos))
        {
            std::cout<<bin_char.elemento(pos);
        }
        std::cout<<std::endl;
    }
    void NOT(){
        
        for (auto i=bin_char.primera(); i !=bin_char.fin(); i=bin_char.siguiente(i))
        {
            if (bin_char.elemento(i)=='1')
            {
                bin_char.elemento(i)='0';
            }
            else{
                bin_char.elemento(i)='1';
            }
        }
        
    }
    void AND(num_binario b){
        assert(length()==b.length());
        auto j=b.num_bin_getter().primera();
        for (auto i = bin_char.primera();i!=bin_char.fin() ; i=bin_char.siguiente(i))
        {
            if (bin_char.elemento(i)!=b.num_bin_getter().elemento(j))
            {
                bin_char.elemento(i)='0';
            }
            j = b.num_bin_getter().siguiente(j);
        }
        
    }
    void OR( num_binario b){
        assert(length()==b.length());
        auto j=b.num_bin_getter().primera();
        for (auto i = bin_char.primera();i!=bin_char.fin() ; i=bin_char.siguiente(i))
        {
            if (bin_char.elemento(i)!=b.num_bin_getter().elemento(j) && b.num_bin_getter().elemento(j)=='1')
            {
                bin_char.elemento(i)='1';
            }
            j = b.num_bin_getter().siguiente(j);
        }
        
    }
    void shift_left(size_t desp){
       
        for (size_t i = 0; i < desp; i++)
        {
            ListaEnla<char>temp;
            temp.insertar(bin_char.elemento(bin_char.anterior(bin_char.fin())),temp.fin());//copiamos ultimo elemento
            char fin = bin_char.elemento(bin_char.anterior(bin_char.anterior(bin_char.fin())));
            for (auto i = bin_char.siguiente(bin_char.primera()); i!=bin_char.anterior(bin_char.fin()) ; i=bin_char.siguiente(i))
            {
                temp.insertar(bin_char.elemento(i),temp.fin());
            }
            temp.insertar(fin,temp.fin());
            bin_char=temp;
        }
        
    }

};


#endif