#ifndef PRACTICA5_HPP
#define PRACTICA5_HPP
#include "tads implementados profesorado/pila_enla.h"
#include "tads implementados profesorado/Cola_Din.h"
#include<iostream>
#include<cassert>
#include<string>
/** EJERCICIO 1 
 * @brief 
 * Se dice que una pila es isomórfica a una cola cuando los elementos situados en posiciones
 * pares de la pila coinciden con los situados en posiciones impares de la cola.
 * Usando los TAD Pila y Cola, implemente una función que determine y devuelva si una
 * pila y una cola dadas son isomórficas o no
 */
template<typename t>
bool ejercicio_1_p5( PilaEnla<t> p,  ColaDin<t> c){
    int pila_par=2;
    p.pop();//Empezamos por la posicion par de la pila
    while(p.vacia()!=true && c.vacia()!=true){//iteramos la pila y la cola hasta que una de los dos se vacie
        std::cout<<"p= "<<p.tope()<<"\t"<<"c= "<<c.frente()<<std::endl;
        if ( (pila_par%2) == 0  && p.tope()!=c.frente())//cuando la posicion de la pila sea par la cola sera impar ya que va n-1 
        {
            return false;//Si no es isomorfica no necesitamos nada mas, salimos de la ejecucion
        }
        p.pop();
        c.pop();
    }
    return true;//Si no se ha encontrado ninguna posicion
}

/** EJERCICIO 2
 * @brief 
 * Escriba una función que dada una cola y dos elementos a y b, invierta la secuencia delimitada por ambos 
 * dentro de ella.
 * Dado que la cola puede tener elementos repetidos, se invertirá la secuencia delimitada por
 * la primera ocurrencia de a y b.
 * Suponemos que los datos introducidos son numericos
 */
template<typename t>
ColaDin<t>& ejercicio_2_p5(t a, t b, ColaDin<t>&c){
    PilaEnla<t>inversora;ColaDin<t>c_final;
    if (a>b)//Ordenamos limite sup y limite inferior en caso de que esten invertidos
    {
        std::swap(a,b);//Para estar ordenados
    }

/* --------------------- copiamos la parte anterior de a -------------------- */
    while (c.frente()!=a&&c.vacia()!=true)//Si se encuentra a se para o si se ha recorrido toda la pila
    {
        
        c_final.push(c.frente());
        c.pop();
    }
/* ----------------- Copiamos la parte a invertir en la pila ---------------- */
    while (c.frente()!=b&&c.vacia()!=true)
    {
       inversora.push(c.frente());
       c.pop();
    }
    if (c.vacia()!=true)
    {
        inversora.push(c.frente());
        c.pop();
    }
    
/* ------------ copiamos la parte invertida en la pila a devolver ----------- */
    while (inversora.vacia()!=true)
    {
        c_final.push(inversora.tope());
        inversora.pop();
    }

/* -- si quedara algo mas de la pila original tras b lo copiamos en la cola - */
    while (c.vacia()!=true)
    {
        c_final.push(c.frente());
        c.pop();
    }
    
    c=c_final;//actualizamos c
    return c;
    
}

/**
 * @brief Se crea un string para simular un avion (pereza trabajar con structs)
 * 
 */
class aerodromo
{
private:
    ColaDin<string>pista;
    size_t size_;
    size_t ocupados;
public:
    aerodromo(size_t espacios=12):size_(espacios),ocupados(0){}
    ~aerodromo(){
        size_=0;ocupados=0;
    }
    void entrada(string a){
        assert(ocupados<12&&"La pista esta llena");
        pista.push(a);
    }

    const string salida(string s){
        string toreturn;
        ColaDin<string>temp=pista,parser;
        
        while (s!=temp.frente()&&temp.vacia()!=true)
        {
            parser.push(temp.frente());
            temp.pop();
        }
        if(temp.vacia()==true)
            return string("");//no se ha encontrado
        else{
            toreturn=temp.frente();
            temp.pop();//salta el elemento encontrado
            while (temp.vacia()!=true)
            {
                parser.push(temp.frente());
                temp.pop();
            }
            pista=temp;//actualizamos la pista
            
        }
        return toreturn;
    }
    void show(){
        ColaDin<string>temp{pista};
        int i=0;
        while (temp.vacia()!=true)
        {
            std::cout<<"Avion["<<i<<"]"<<": "<<temp.frente()<<std::endl;
            temp.pop();
            ++i;
        }
        
    }
};



#endif