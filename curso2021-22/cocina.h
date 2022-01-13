#ifndef CURSO2021_22_COCINA_H
#define CURSO2021_22_COCINA_H

#include <iostream>
#include "tads_profesorado/ListaEnla.h"
#include <cassert>
/*
 * ESPECIFICACION DEL TAD COCINA
 *      Este tad se usa para la representacion de una cocina, la cual posee una dimension x,
 *      donde se colocan una serie de muebles.
 *      Estos se caracterizan por tener una anchura y una posicion con respecto al lateral izquierdo
 *      de la pared.
 *
 *      OPERACIONES DEL TAD
 *           cocina(const float& d , const mueble& m)
 *              Precondicion==> Recibe una dimension (en punto flotante) mayor que 0 y el primer mueble a colocar
 *                              previamente inicializado.
 *              Postcondicion==> Crea una cocina con una dimension dada y un mueble previamente colocado
 *
            ~cocina()=default;
                Postcondicion==> Elimina la cocina creada

            bool cabe(const mueble& m);
                Precondicion==> Recibe un mueble previamente inicializado
                Postcondicion==> Devuelve true si el mueble cabe en la poicion que el mismo trae implicito.


            const mueble& devolver_mueble(const int n);
                Precondicion==> Recibe un entero > 0 que representa el mueble enesimo de la cocina
                Postcondicion==> Devuelve el mueble enesimo, si existiese.

            void eliminar_mueble(const int n);
                Precondicion==> Recibe un entero > 0 que representa el mueble enesimo de la cocina
                Postcondicion==> Elimina el mueble enesimo, si existiese.

            void pegar_mueble(const int n);
                Precondicion==> Recibe un entero > 0 que representa el mueble enesimo de la cocina
                Postcondicion==> Pega el mueble n al n-1, si este no existe se pega al lateral izquierdo
 */


struct mueble{

    float anchura;
    float posicion;//Con respecto al inicio de la pared dada
    mueble(const float a = 0, const float& p = 0):anchura(a),posicion(p) {}
    bool operator < (const mueble& a) const{ return posicion < a.posicion;}
    bool operator > (const mueble& a) const{ return posicion > a.posicion;}
    bool operator ==(const mueble& a) const {return anchura == a.anchura && posicion == a.posicion;}

};

class cocina{
private:

    ListaEnla<mueble>pared;
    float dimension;
    float ocupado;
    int muebles_colocados;//Para evitar buscar etc

public:
    cocina(const float& d , const mueble& m);
    ~cocina()=default;
    bool cabe(const mueble& m);
    const mueble& devolver_mueble(const int n);
    void eliminar_mueble(const int n);
    void pegar_mueble(const int n);
};

cocina::cocina(const float &d, const mueble &m):ocupado(m.anchura),muebles_colocados(1),dimension(d) {
    assert(d>0 && m.anchura > 0);

    auto final = pared.fin();//aunque innecesario se pide que se haga asi en las transparencias
    pared.insertar(m,final);

}

const mueble &cocina::devolver_mueble(const int n) {
    assert(n <= muebles_colocados);
    auto pos = pared.primera();
    for(size_t i = 0; i < n && pos != pared.fin();++i )
        pos = pared.siguiente(pos);

    return pared.elemento(pos);//simplemente sacamos el contenido en la posicion buscada

}

void cocina::eliminar_mueble(const int n) {

    assert(n <= muebles_colocados);
    auto pos = pared.primera();
    for(size_t i = 0; i < n && pos != pared.fin();++i )
        pos = pared.siguiente(pos);

    pared.eliminar(pos);//simplemente eliminamos el mueble en esa posicion

}

#endif //CURSO2021_22_COCINA_H
