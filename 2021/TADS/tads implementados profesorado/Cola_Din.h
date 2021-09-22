#ifndef COLADIN_H_INCLUDED
#define COLADIN_H_INCLUDED
#include <cassert>
#include <iostream>
using namespace std;
template <typename T> class ColaDin
{
public:
	ColaDin(); // constructor
	ColaDin(const ColaDin<T>& C); // ctor. de copia
	ColaDin<T>& operator =(const ColaDin<T>& C); // asignacion de colas
	bool vacia() const;
	const T& frente() const;
	void pop();
	void push(const T& x);
	~ColaDin(); // destructor
private:
	struct nodo
	{
		T elto;
		nodo* sig;
		nodo(const T& e, nodo* p = 0) : elto(e), sig(p) {}
	};
	nodo* inicio, * fin; // extremos de la cola
	void copiar(const ColaDin<T>& C);
};

//Metodo privado
template <typename T>
void ColaDin<T>::copiar(const ColaDin<T>& C)
{
	if (C.inicio) // C no esta vacia
	{
		//Copiar el primer elto
		inicio = fin = new nodo(C.inicio->elto);
		//Copiar el resto de elementos hasta el final
		for (nodo* p = C.inicio->sig; p; p = p->sig)
		{
			fin->sig = new nodo(p->elto);
			fin = fin->sig;
		}
	}
}

template <typename T>
inline ColaDin<T>::ColaDin() : inicio(0), fin(0) {}

template <typename T>
inline ColaDin<T>::ColaDin(const ColaDin<T>& C) : inicio(0), fin(0)
{
	copiar(C);
}

template <typename T>
inline ColaDin<T>& ColaDin<T>::operator =(const ColaDin<T>& C)
{
	if (this != &C) // evitar autoasignacion
	{
		this->~ColaDin(); // vaciar la cola actual
		copiar(C);
	}
	return *this;
}

template <typename T>
inline bool ColaDin<T>::vacia() const
{
	return (inicio == 0);
}
template <typename T>
inline const T& ColaDin<T>::frente() const
{
	assert(!vacia());
	return inicio->elto;
}
template <typename T>
inline void ColaDin<T>::pop()
{
	assert(!vacia());
	nodo* p = inicio;
	inicio = p->sig;
	if (!inicio) fin = 0;
	delete p;
}
template <typename T>
inline void ColaDin<T>::push(const T& x)
{
	nodo* p = new nodo(x);
	if (inicio == 0) // cola vacia
		inicio = fin = p;
	else
		fin = fin->sig = p;
}
template <typename T>
ColaDin<T>::~ColaDin()
{
	nodo* p;
	while (inicio)
	{
		p = inicio->sig;
		delete inicio;
		inicio = p;
	}
	fin = 0;
}
#endif // COLADIN_H_INCLUDED