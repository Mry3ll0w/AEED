// listavecvec.h
//
// clase listavec genérica: vector pseudo-estático (en
// memoria dinámica) cuyo tamaño (parámetro de entrada
// del constructor) puede ser distinto para cada
// objeto de la clase listavec.
// Las variables externas de tipo posición, posteriores
// a la posición p en la que se realiza una inserción
// o eliminación, no cambian, pero sí los elementos
// que se encuentran en dichas posiciones.
#ifndef listavecVEC_H
#define listavecVEC_H
#include <cassert>

template <typename T>
class listavec {
    public:
        typedef int posicion; // posición de un elto
        explicit listavec(size_t TamaMax); // constructor
        listavec(const listavec<T>& l); // ctor. de copia
        listavec<T>& operator =(const listavec<T>& l); // asignación entre listavecs
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const; // acceso a elto, lectura
        T& elemento(posicion p); // acceso a elto, lectura/escritura
        posicion buscar(const T& x) const; // requiere operador == para el tipo T
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        posicion primera() const;
        posicion fin() const; // posición después del último
        ~listavec(); // destructor
    private:
        T *elementos; // vector de elementos
        int Lmax; // tamaño del vector
        int n; // longitud de la listavec
};
// clase listavec genérica: vector pseudo-estático.
// Una listavec de longitud n se almacena en celdas
// consecutivas del vector, desde 0 hasta n-1.
// La posición de un elemento es el índice de la celda
// en que se almacena.
//
// Implementación de operaciones
template <typename T>
inline listavec<T>::listavec(size_t TamaMax) : elementos(new T[TamaMax]), Lmax(TamaMax), n(0) {}

template <typename T>
listavec<T>::listavec(const listavec<T>& l) : elementos(new T[l.Lmax]), Lmax(l.Lmax), n(l.n){
    for (listavec<T>::posicion p = 0; p < n; p++) // copiar el vector
    elementos[p] = l.elementos[p];
}

template <typename T>
listavec<T>& listavec<T>::operator =(const listavec<T>& l){
    if (this != &l) { // evitar autoasignación
        // Destruir el vector y crear uno nuevo si es necesario
        if (Lmax != l.Lmax) {
            delete[] elementos;
            Lmax = l.Lmax;
            elementos = new T[Lmax];
        }
        // Copiar el vector
        n = l.n;
        for (listavec<T>::posicion p = 0; p < n; p++)
            elementos[p] = l.elementos[p];
    }
    return *this;
}

template <typename T>
void listavec<T>::insertar(const T& x, listavec<T>::posicion p){
    assert(p >= 0 && p <= n); // posición válida
    assert(n < Lmax); // listavec no llena
    for (listavec<T>::posicion q = n; q > p; q--)
        // desplazar los eltos. en p, p+1, ...
        elementos[q] = elementos[q-1]; // a la siguiente posición
    elementos[p] = x;
    n++;
}

template <typename T>
void listavec<T>::eliminar(listavec<T>::posicion p){
    assert(p >= 0 && p < n); // posición válida
    n--;
    for (listavec<T>::posicion q = p; q < n; q++)
        //desplazar los eltos. en p+1, p+2, ...
        elementos[q] = elementos[q+1]; // a la posición anterior
}
template <typename T> inline
const T& listavec<T>::elemento(listavec<T>::posicion p) const {
    assert(p >= 0 && p < n); // posición válida
    return elementos[p];
}

template <typename T>
inline T& listavec<T>::elemento(listavec<T>::posicion p){
    assert(p >= 0 && p < n); // posición válida
    return elementos[p];
}

template <typename T>
typename listavec<T>::posicion listavec<T>::buscar(const T& x) const {
    listavec<T>::posicion q = 0;
    bool encontrado = false;
    while (q < n && !encontrado)
        if (elementos[q] == x)
            encontrado = true;
        else q++;
    return q;
}

template <typename T>
inline typename listavec<T>::posicion listavec<T>::siguiente(listavec<T>::posicion p) const {
    assert(p >= 0 && p < n); // posición válida
    return p+1;
}

template <typename T>
inline typename listavec<T>::posicion listavec<T>::anterior(listavec<T>::posicion p) const {
    assert(p > 0 && p <= n); // posición válida
    return p-1;
}

template <typename T>
inline typename listavec<T>::posicion listavec<T>::primera() const { return 0; }

template <typename T>
inline typename listavec<T>::posicion listavec<T>::fin() const { return n; }

template <typename T>
inline listavec<T>::~listavec() { delete[] elementos; }

#endif // listavecVEC_H
