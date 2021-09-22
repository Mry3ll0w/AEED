//ESTE PROYECTO NO HA SIDO IMPLEMENTADO POR MI SI NO POR EL USER DE GITHUB: ohVish's
// SIGUELE EN https://github.com/ohVish

/*
 ▄▄▄▄    ██▓ ▄████▄   ▒█████   ██▓    ▄▄▄
▓█████▄ ▓██▒▒██▀ ▀█  ▒██▒  ██▒▓██▒   ▒████▄
▒██▒ ▄██▒██▒▒▓█    ▄ ▒██░  ██▒▒██░   ▒██  ▀█▄
▒██░█▀  ░██░▒▓▓▄ ▄██▒▒██   ██░▒██░   ░██▄▄▄▄██
░▓█  ▀█▓░██░▒ ▓███▀ ░░ ████▓▒░░██████▒▓█   ▓██▒
░▒▓███▀▒░▓  ░ ░▒ ▒  ░░ ▒░▒░▒░ ░ ▒░▓  ░▒▒   ▓▒█░
▒░▒   ░  ▒ ░  ░  ▒     ░ ▒ ▒░ ░ ░ ▒  ░ ▒   ▒▒ ░
 ░    ░  ▒ ░░        ░ ░ ░ ▒    ░ ░    ░   ▒
 ░       ░  ░ ░          ░ ░      ░  ░     ░  ░
      ░     ░
*/

#include <cassert>
#include <iostream>

template <typename T>
class  Bicola
{
public:
    /* Constructor de la clase */
    Bicola();

    bool vacia()const noexcept;
    const T& frente()const;
    const T& fondo()const;
    void push(const T& x);
    void pushfrente(const T& x);
    void pop();
    void popfin();

    ~Bicola();

private:
    /*
       Estructura circular para representar la bicola lo que nos permite
       acceder al final de la cola con orden exacto 1 y al inicio/frente de la
       misma con orden exacto 2, ambas operaciones son de orden constante. Así nos
       ahorramos el hecho de utilizar una estructura con dos punteros(A inicio y fin)
       la cual gasta más memoria.
     */
    struct nodo
    {
        nodo*  sig;
        T elto;
        nodo(const T& x,nodo* q=0):elto(x),sig(q){}
    };

    nodo* fin;

    void copiar(const Bicola<T>& B);

};

template<typename T>
Bicola<T>::Bicola():fin(0)
{}

template<typename T>
const T& Bicola<T>::frente()const
{
    assert(fin!=0);
    return fin->sig->elto;
}

template<typename T>
const T& Bicola<T>::fondo()const
{
    assert(fin!=0);
    return fin->elto;
}

template<typename T>
void Bicola<T>::copiar(const Bicola<T>& B)
{
    fin = new nodo(B.fin->elto);
    nodo * q = B.fin->sig;
    nodo * p = fin;
    while(q!=B.fin)
    {
        p->sig=new nodo(q->elto);
        p=p->sig;
        q=q->sig;
    }
}

template<typename T>
bool Bicola<T>::vacia()const noexcept
{
    return (fin==0);
}

template<typename T>
void Bicola<T>::push(const T& x)
{
    nodo *q = new nodo(x);
    if(fin==0)
    {
        fin=q->sig=q;
    }
    else
    {
        q->sig = fin->sig;
        fin->sig=q;
        fin=q;
    }

}

template<typename T>
void Bicola<T>::pushfrente(const T& x)
{
    nodo *p = new  nodo(x);
    if(fin==0)
    {
        fin = p->sig=p;
    }
    else
    {
        p->sig=fin->sig;
        fin->sig=p;
    }

}

template<typename T>
void Bicola<T>::pop()
{
    assert(fin!=0);
    nodo *inicio = fin->sig;
    if(inicio==fin){
        delete inicio;
        fin=fin->sig=0;
    }
    else{
        fin->sig=inicio->sig;
        delete  inicio;
    }
}

template<typename T>
void Bicola<T>::popfin()
{
    assert(fin!=0);
    if(fin->sig==fin)
    {
        delete fin;
        fin=fin->sig=0;
    }
    else
    {
        nodo *q=fin->sig;
        while(q->sig!=fin)
            q=q->sig;
        q->sig=fin->sig;
        delete fin;
        fin=q;
    }


}

template<typename T>
Bicola<T>::~Bicola()
{
    nodo *q;
    if(fin)
    {
        while(fin!=fin->sig)
        {
            q=fin->sig;
            fin->sig=q->sig;
            delete q;
        }
        delete fin;
        fin = 0;
    }
}