// listavecvec.h
//
// clase listavec gen�rica: vector pseudo-est�tico (en
// memoria din�mica) cuyo tama�o (par�metro de entrada
// del constructor) puede ser distinto para cada
// objeto de la clase listavec.
// Las variables externas de tipo posici�n, posteriores
// a la posici�n p en la que se realiza una inserci�n
// o eliminaci�n, no cambian, pero s� los elementos
// que se encuentran en dichas posiciones.
#ifndef listavecVEC_H
#define listavecVEC_H
#include <cassert>

template <typename T>
class listavec {
    public:
        typedef int posicion; // posici�n de un elto
        explicit listavec(size_t TamaMax); // constructor
        listavec(const listavec<T>& l); // ctor. de copia
        listavec<T>& operator =(const listavec<T>& l); // asignaci�n entre listavecs
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const; // acceso a elto, lectura
        T& elemento(posicion p); // acceso a elto, lectura/escritura
        posicion buscar(const T& x) const; // requiere operador == para el tipo T
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        posicion primera() const;
        posicion fin() const; // posici�n despu�s del �ltimo
        ~listavec(); // destructor
    private:
        T *elementos; // vector de elementos
        int Lmax; // tama�o del vector
        int n; // longitud de la listavec
};
// clase listavec gen�rica: vector pseudo-est�tico.
// Una listavec de longitud n se almacena en celdas
// consecutivas del vector, desde 0 hasta n-1.
// La posici�n de un elemento es el �ndice de la celda
// en que se almacena.
//
// Implementaci�n de operaciones
template <typename T>
inline listavec<T>::listavec(size_t TamaMax) : elementos(new T[TamaMax]), Lmax(TamaMax), n(0) {}

template <typename T>
listavec<T>::listavec(const listavec<T>& l) : elementos(new T[l.Lmax]), Lmax(l.Lmax), n(l.n){
    for (listavec<T>::posicion p = 0; p < n; p++) // copiar el vector
    elementos[p] = l.elementos[p];
}

template <typename T>
listavec<T>& listavec<T>::operator =(const listavec<T>& l){
    if (this != &l) { // evitar autoasignaci�n
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
    assert(p >= 0 && p <= n); // posici�n v�lida
    assert(n < Lmax); // listavec no llena
    for (listavec<T>::posicion q = n; q > p; q--)
        // desplazar los eltos. en p, p+1, ...
        elementos[q] = elementos[q-1]; // a la siguiente posici�n
    elementos[p] = x;
    n++;
}

template <typename T>
void listavec<T>::eliminar(listavec<T>::posicion p){
    assert(p >= 0 && p < n); // posici�n v�lida
    n--;
    for (listavec<T>::posicion q = p; q < n; q++)
        //desplazar los eltos. en p+1, p+2, ...
        elementos[q] = elementos[q+1]; // a la posici�n anterior
}
template <typename T> inline
const T& listavec<T>::elemento(listavec<T>::posicion p) const {
    assert(p >= 0 && p < n); // posici�n v�lida
    return elementos[p];
}

template <typename T>
inline T& listavec<T>::elemento(listavec<T>::posicion p){
    assert(p >= 0 && p < n); // posici�n v�lida
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
    assert(p >= 0 && p < n); // posici�n v�lida
    return p+1;
}

template <typename T>
inline typename listavec<T>::posicion listavec<T>::anterior(listavec<T>::posicion p) const {
    assert(p > 0 && p <= n); // posici�n v�lida
    return p-1;
}

template <typename T>
inline typename listavec<T>::posicion listavec<T>::primera() const { return 0; }

template <typename T>
inline typename listavec<T>::posicion listavec<T>::fin() const { return n; }

template <typename T>
inline listavec<T>::~listavec() { delete[] elementos; }

#endif // listavecVEC_H
