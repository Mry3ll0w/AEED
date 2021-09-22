#ifndef COLA_VEC_H_
#define COLA_VEC_H_
#include <cassert>

template <typename T> class Cola
{
public:
	explicit Cola(size_t TamaMax);
	Cola(const Cola<T>& C);
	Cola<T>& operator=(const Cola<T>& C);
	bool vacia() const;
	bool llena() const;
	const T& frente() const;
	void pop();
	void push(const T& x);
	~Cola();
private:
	T* elementos;
	int Lmax;
	int fin;
};

template <typename T>
inline Cola<T>::Cola(size_t TamaMax): elementos(new T[TamaMax]), Lmax(TamaMax), fin(-1) {}

template <typename T>
Cola<T>::Cola(const Cola<T>& C) : elementos(new T[TamaMax]), Lmax(TamaMax), fin(-1)
{
	for (int i = 0 : i < TamaMax; i++)
		elementos[i] = C.elementos[i];
}

template <typename T>
Cola<T>& Cola<T>::operator=(const Cola<T>& C)
{
	if (this != &C)
	{
		if (Lmax != C.Lmax)
		{
			delete[] elementos;
			Lmax = C.Lmax;
			elementos = new T[Lmax];
		}
		fin = C.fin;
		for (int i = 0; i < Lmax; i++)
			elementos[i] = C.elementos[i];
	}
	return *this;
}

template <typename T>



#endif // !COLA_VEC_H_