#ifndef PILA_VEC_H_
#define PILA_VEC_H_
#include <cassert>

template <typename tElemento> class PilaVec
{
public:
	explicit PilaVec(unsigned TamaMax);
	PilaVec(const PilaVec& P);
	PilaVec& operator=(const PilaVec& P);
	bool vacia() const;
	bool llena() const;
	const tElemento& tope() const;
	void pop();
	void push(const tElemento& x);
	~PilaVec();
private:
	tElemento* elementos; //Vector de elementos
	int Lmax; //Tamaño del vector
	int tope_; //Posicion del tope
};


template <typename tElemento>
inline PilaVec<tElemento>::PilaVec(unsigned TamaMax) : elementos(new tElemento[TamaMax]), Lmax(TamaMax), tope_(-1) {}

template<typename tElemento>
PilaVec<tElemento>::PilaVec(const PilaVec<tElemento>& P) : elementos(new tElemento[P.Lmax]), Lmax(P.Lmax), tope_(P.tope_)
{
	for (int i = 0; i <= tope_; i++)
		elementos[i] = P.elementos[i];
}

template <typename tElemento>
PilaVec <tElemento>& PilaVec<tElemento>::operator=(const PilaVec <tElemento>& P)
{
	int i;
	if (this != &P)
	{
		if (Lmax != P.Lmax)
		{
			delete[] elementos;
			Lmax = P.Lmax;
			elementos = new tElemento[Lmax];
		}
		tope_ = P.tope_;
		for (i = 0; i <= tope_; i++)
			elementos[i] = P.elementos[i];
	}
	return *this;
}

template <typename tElemento>
inline bool PilaVec<tElemento>::vacia()const
{
	return(tope_ == -1);
}

template <typename tElemento>
inline bool PilaVec<tElemento>::llena() const
{
	return (tope_ == Lmax - 1);
}

template <typename tElemento>
inline const tElemento& PilaVec<tElemento>::tope() const
{
	assert(!vacia());
	return elementos[tope_];
}
template <typename tElemento>
inline void PilaVec <tElemento>::pop()
{
	assert(!vacia());
	--tope_;
}

template <typename tElemento>
inline void PilaVec <tElemento>::push(const tElemento& x)
{
	assert(!llena());
	++tope_;
	elementos[tope_] = x;
}

template <typename tElemento>
inline PilaVec <tElemento>::~PilaVec()
{
	delete[] elementos;
}

#endif // !PILA_VEC_H

