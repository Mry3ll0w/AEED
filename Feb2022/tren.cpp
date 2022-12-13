#include <iostream>
#include <string>
#include "../jun2022/tads/pila_enla.h"
using namespace std; // Avoid using std:: ....

/**
 * TADS Implicados
 * Pila
 *  - Tipo abstracto de datos usado para reprensentar una secuencia de elementos ordenados mediante una estructura LIFO.
 *  - Al desconocerse el numero de trenes a almacenar dentro del tad se usara la pila con representacion enlazada.
 * Especificacion de la estructura de datos utilizada
 *  template <class t>
 *  class PilaEnla<t> {
 *      ...
 *      private:
 *          struct nodo{
 *              nodo* sig;
 *              t elto;
 *              nodo(nodo* s, t e = 0) : sig(s), elto(e){}
 *          }
 *          nodo *tope;
 *  }
 *
 *  Especificacion de las operaciones utilizadas => Insertar todas las operaciones de la clase implicada
 *
 *
 * Especificacion del TAD TREN
 *
 * Resumen
 *  Se nos pide representar una seria de vagones de un tren, los cuales se podran desplazar de multiples maneras mediante un robot que se encargara de
 *  la tarea.
 *
 * Especificacion de las operaciones => mucho texto
 */

typedef string Wagon;

class Tren
{
private:
    int elementsInsideStack(PilaEnla<Wagon> st)
    {
        int i = 0;
        while (!st.vacia())
        {
            st.pop();
            ++i;
        }
        return i;
    }
    PilaEnla<Wagon> stRight, stLeft;

public:
    Tren() = default;
    ~Tren() = default;
    void moveRight();
    void moveLeft();
    void deleteActiveWagon();
    void addActiveWagon(const Wagon &w);
    const Wagon &activeWagon();
    const bool &isEmpty();
};

int main()
{

    return 0;
}

void Tren::addActiveWagon(const Wagon &w)
{
    stRight.push(w);
}

const Wagon &Tren::activeWagon()
{
    return stRight.tope();
}

const bool &Tren::isEmpty()
{
    return !(stRight.vacia());
}

void Tren::deleteActiveWagon()
{
    // assert control
    if (isEmpty() && stLeft.vacia()) // En caso de no haber vagon activo y no haber vagon en la pila izquierda
    {
        throw runtime_error("El tren esta vacio y no puede eliminar el vagon activo");
    }

    // Si la pila izquierda esta vacia o hay mas de un elemento en la pila derecha solo interactuamos con la pila derecha
    if (stLeft.vacia() || elementsInsideStack(stRight) >= 2)
    {
        stRight.pop();
    }
    else
    { // Hay mas de dos elementos en el tren
        stRight.pop();
        const Wagon wTemp = stLeft.tope();
        stLeft.pop();
        stRight.push(wTemp);
    }
}

void Tren::moveRight()
{
    if (!stLeft.vacia())
    {
        const Wagon wTemp = stLeft.tope();
        stLeft.pop();

        if (stLeft.vacia())
        {
            stLeft.push(wTemp);
        }
        else
        { // Hay mas de 2 elementos en la pila derecha, por lo que se puede mover
            stRight.push(wTemp);
        }
    }
}

void Tren::moveLeft()
{
    if (!stRight.vacia())
    {
        const Wagon wTemp = stRight.tope();
        stRight.pop();
        if (stRight.vacia())
        {
            stRight.push(wTemp);
        }
        else
        {
            stLeft.push(wTemp);
        }
    }
}