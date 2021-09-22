#ifndef PILAENLA_H_INCLUDED
#define PILAENLA_H_INCLUDED
#include <cassert>
#include <iostream>
using namespace std;
template <typename T>
class PilaEnla
{
public:
    PilaEnla(); // constructor
    PilaEnla(const PilaEnla<T>& P); //ctor. de copia
    PilaEnla<T>& operator =(const PilaEnla<T>& P); // asignacion
    bool vacia() const;
    const T& tope() const;
    void pop();
    void push(const T& x);
    ~PilaEnla(); // destructor
private:
    struct nodo
    {
        T elto;
        nodo* sig;
        nodo(const T& e, nodo* p = 0) : elto(e), sig(p) {}
    };
    nodo* tope_;
    void copiar(const PilaEnla<T>& P);
};

template <typename T>
inline PilaEnla<T>::PilaEnla() : tope_(0) {}

template <typename T>
PilaEnla<T>::PilaEnla(const PilaEnla<T>& P) : tope_(0)
{
    copiar(P);
}

template <typename T>
PilaEnla<T>& PilaEnla<T>::operator =(const PilaEnla<T>& P)
{
    if (this != &P)
    {
        this->~PilaEnla();
        copiar(P);
    }
    return *this;
}


template <typename T>
inline bool PilaEnla<T>::vacia() const
{
    return (!tope_);
}

template <typename T>
inline const T& PilaEnla<T>::tope() const
{
    assert(!vacia());
    return tope_->elto;
}

template <typename T>
inline void PilaEnla<T>::pop()
{
    assert(!vacia());
    nodo* p = tope_;
    tope_ = p->sig;
    delete p;
}

template <typename T>
inline void PilaEnla<T>::push(const T& x)
{
    tope_ = new nodo(x, tope_);
}

template <typename T>
PilaEnla<T>::~PilaEnla()
{
    nodo* p;
    while (tope_)
    {
        p = tope_->sig;
        delete tope_;
        tope_ = p;
    }
}

template <typename T>
void PilaEnla<T>::copiar(const PilaEnla<T>& P)
{
    if (!P.vacia())
    {
        tope_ = new nodo(P.tope());
        nodo* p = tope_;
        nodo* q = P.tope_->sig;
        while (q)
        {
            p->sig = new nodo(q->elto);
            p = p->sig;
            q = q->sig;
        }
    }
}
#endif // PILAENLA_H_INCLUDED