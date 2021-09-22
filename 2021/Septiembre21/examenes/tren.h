#ifndef SEPTIEMBRE21_TREN_H
#define SEPTIEMBRE21_TREN_H
/*
 *       1 2
 *        ac   d
 * a. Construir un tren vacío.
 *
 * b. Desplazar tren a la izquierda (el vagón activo pasa a ser el de la derecha, si no hay vagón a la
 * derecha no se hace nada).
 *
 * c. Desplazar tren a la derecha (el vagón activo pasa a ser el de la izquierda, si no hay vagón a la
 * izquierda no se hace nada).
 *
 * d. Eliminar vagón activo: El vagón activo pasa a ser el de la derecha, si no hay vagón a la
 * derecha, pasa a ser el de la izquierda, si tampoco hay, el tren está vacío.
 *
 * e. Observar vagón activo: Devuelve cuál es el vagón activo. ok
 *
 * f. Comprobar si el tren está vacío.
 *
 * Nota 1: Prohibido hacer doble enlazada con coste independiente.
 * Nota 2: Definir los tipos usados y los prototipos de los TAD conocidos.
 */
#include <iostream>
#include "../tads p/pila_enla.h"
class tren{
    PilaEnla<size_t>izquierda,derecha;
    public:
    tren()=default;
    void insertar_v(size_t id){izquierda.push(id);}
    size_t vagon_activo(){return izquierda.tope();}
    bool tren_vacio(){return izquierda.vacia()&&derecha.vacia();}
    void desplazar_derecha();
    void desplazar_izquierda();
    void eliminar_activo();
};

/*
 *  Desplazar tren a la derecha (el vagón activo pasa a ser el de la izquierda, si no hay vagón a la
 * izquierda no se hace nada).
 */
void tren::desplazar_derecha() {
    if (!izquierda.vacia()){
        derecha.push(izquierda.tope());
        izquierda.pop();
    }
}

/*
 *  Desplazar tren a la izquierda (el vagón activo pasa a ser el de la derecha, si no hay vagón a la
 * derecha no se hace nada).
 */
void tren::desplazar_izquierda() {
    if (!derecha.vacia()){//Si la derecha no esta vacia entonces desplazamos
        izquierda.push(derecha.tope());
        derecha.pop();
    }
}

void tren::eliminar_activo() {
    assert(!izquierda.vacia());
    izquierda.pop();
}


#endif //SEPTIEMBRE21_TREN_H
