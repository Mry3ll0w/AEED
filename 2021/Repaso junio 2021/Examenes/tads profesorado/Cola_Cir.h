#ifndef COLA_CIR_H_
#define COLA_CIR_H_
#include <cassert>

template <typename T> class ColaCir
{
public:
	explicit ColaCir(size_t TamaMax); // constructor
	ColaCir(const ColaCir<T>& C); // ctor. de copia
	ColaCir<T>& operator =(const ColaCir<T>& C); // asig. colas
	bool vacia() const;
	bool llena() const;
	const T& frente() const;
	void pop();
	void push(const T& x);
	~ColaCir(); // destructor
private:
	T* elementos; // vector de elementos
	int Lmax; // tamaño del vector
	int inicio, fin; // posiciones de los extremos
};

template <typename T>
ColaCir<T>::ColaCir(size_t TamaMax) :
	elementos(new T[TamaMax + 1]), // +1 para detectar cola llena
	Lmax(TamaMax + 1),
	inicio(0),
	fin(TamaMax)
{}

template <typename T>
ColaCir<T>::ColaCir(const ColaCir<T>& C) :
	elementos(new T[C.Lmax]),
	Lmax(C.Lmax),
	inicio(C.inicio),
	fin(C.fin)
{
	if (!C.vacia()) // Copiar el vector
		for (int i = inicio; i != (fin + 1) % Lmax; i = (i + 1) % Lmax)
			elementos[i] = C.elementos[i];
}
template <typename T>
ColaCir<T>& ColaCir<T>::operator =(const ColaCir<T>& C)
{
	if (this != &C) // evitar autoasignacion
	{
		// Destruir el vector y crear uno nuevo si es necesario
		if (Lmax != C.Lmax)
		{
			delete[] elementos;
			Lmax = C.Lmax;
			elementos = new T[Lmax];
		}
		// Copiar el vector
		inicio = C.inicio;
		fin = C.fin;
		if (!C.vacia())
			for (int i = inicio; i != (fin + 1) % Lmax; i = (i + 1) % Lmax)
				elementos[i] = C.elementos[i];
	}
	return *this;
}
template <typename T>
inline bool ColaCir<T>::vacia() const
{
	return ((fin + 1) % Lmax == inicio);
}
template <typename T>
inline bool ColaCir<T>::llena() const
{
	return((fin + 2) % Lmax == inicio);
}
template <typename T>
inline const T& ColaCir<T>::frente() const
{
	assert(!vacia());
	return elementos[inicio];
}
template <typename T>
inline void ColaCir<T>::pop()
{
	assert(!vacia());
	inicio = (inicio + 1) % Lmax;
}
template <typename T>
inline void ColaCir<T>::push(const T& x)
{
	assert(!llena());
	fin = (fin + 1) % Lmax;
	elementos[fin] = x;
}
template <typename T>
inline ColaCir<T>::~ColaCir()
{
	delete[] elementos;
}
#endif // !COLA_CIR_H_

