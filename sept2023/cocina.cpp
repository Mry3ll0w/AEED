#include <iostream>
#include "../Sept2022/tads/ListaEnla.h"
using namespace std; // Avoid using std:: ....

/**
 * Enunciado de teoria
 * 1) Con la representaci ́on de colas mediante una estructura enlazada, con puntero al final y circular.
 *    ¿Cuántos elementos pueden almacenarse?
 *    La representacion de colas mediante una estructura enlazada no tiene limitaciones de espacio, más alla
 *    de la memoria del propio ordenador, puede almacenar n-1 elementos.
 *
 * 2)Comenta la siguiente afirmaci ́on: En la representaci ́on del TAD Cola Circular mediante una estructura enlazada,
 *  es necesario utilizar un nodo cabecera.
 *  No solo no es necesario si no que ademas entorpecería la eficiencia de la misma, puesto que el nodo cabecera surge para solucionar un problema de
 *  eficiencia y especificación del tad Lista, en este caso solo aportaría espacio, reduciendo su eficiencia, además el Tad Cola Circular no existe
 *  existe el tad cola con representación circular.
 *
 *  3)Qu ́e condici ́on deben cumplir los elementos de una lista para poder realizar b ́usquedas en orden cuadr ́atico?
 *  Ninguna, salvo que la implementación del algoritmo sea erronea las búsquedas serán de orden n, ya que hay que realizar la busqueda entre
 *  n elementos.
 */

/**
 * Apartado Practico: TAD Cocina
 *  Una empresa de muebles de cocina necesita un TAD para representar el conjunto de muebles colocados
    en la pared de una cocina. Una cocina se crea con una longitud positiva, y un mueble colocado en la pared
    se identifica con el par formado por su posici ́on (distancia desde su lateral izquierdo al extremo izquierdo
    de la pared) y su anchura (la profundidad y altura no tienen inter ́es, pues son iguales para todos los muebles).
    El TAD debe soportar las siguientes operaciones:
        • Crear una cocina vac ́ıa con una longitud dada.
        • Determinar si un mueble de una cierta anchura puede colocarse en una posici ́on dada.
        • A ̃nadir un mueble de una determinada longitud a una posici ́on dada.
        • Devolver el mueble i- ́esimo de la cocina empezando a contar por la izquierda.
        • Eliminar el mueble i- ́esimo de la cocina, si existe.
        • Mover el mueble i- ́esimo de la cocina (si existe) hacia la izquierda, hasta que se junte con el mueble
        (i - 1)  ́esimo o el extremo izquierdo de la pared.
        • Destruir la cocina.
    Se pide:
    a) Especificar el TAD Cocina (30 %).
    b) Dise ̃nar una estructura de datos adecuada para representar el TAD Cocina (10 %).
    c) Implementar las operaciones anteriormente descritas (
 */

// No voy a especificar el TAD lista poeque me puedo morir de algo malo

/**
 * Especificacion TAD Cocina
 *
 *
 * Resumen del TAD: Una empresa de muebles de cocina necesita un TAD para representar el conjunto de muebles colocados
 * en la pared de una cocina. Una cocina se crea con una longitud positiva, y un mueble colocado en la pared
 * se identifica con el par formado por su posici ́on (distancia desde su lateral izquierdo al extremo izquierdo
 * de la pared) y su anchura (la profundidad y altura no tienen inter ́es, pues son iguales para todos los muebles). //!Soy consciente de que he copiado y pegado, DLH lo pide asi.
 * Operaciones:
 *
 * 1) Cocina(const int& iLongitudCocina): Crea una cocina de una longitud dada, la longitud tiene que ser >0
 * 2) const bool colocarMueble(const iPosicion, const iAnchuraMueble)==> El mueble dado tiene que tener una posicion >= 0 y una anchura >= 1,
 * si cabe devuelve true si no false
 * 3) Mueble muebleIesimo(const int& i) ==> Devuelve el mueble en la posicion i dada (i >= 0), si no existe devuelve un mueble vacio.
 * 4) void eliminaMuebleIesimo(const int&i )==> Eliminar el mueble en la posicion dada ( i >= 0), si no existe no elimina nada.
 * 5) void desplazaMueble(const int& i) ==> Mueve el mueble Iesimo hacia la izquierda hasta que se junte con el mueble i-1, i >= 0, si no existiese mueble
 * i-1 se pega al extremo de la pared.
 */

struct Mueble
{
    int iPosicion;
    int iAnchura;
    Mueble(int pos = 0, int prof = 0) : iPosicion(pos), iAnchura(prof) {}
    bool operator<(const Mueble b)
    {
        return iPosicion < b.iPosicion;
    }
};

bool operator==(const Mueble a, const Mueble b)
{
    return a.iPosicion == b.iPosicion && a.iAnchura == b.iAnchura;
}

class Cocina
{
    ListaEnla<Mueble> lMuebles;
    ListaEnla<Mueble>::posicion posicionInsercion(const Mueble m, bool &bCabe);
    int iLongitudCocina;
    int iLongitudOcupada;
    int iMueblesColocados;

public:
    Cocina(const int &iLong) : iLongitudCocina(iLong), iLongitudOcupada(0), iMueblesColocados(0)
    {
        if (iLong <= 0)
            throw std::invalid_argument("La longitud de la cocina tiene que ser >= 1");
    }

    bool cabeMueble(const int iPosicion, const int iAnchura)
    {
        if (iPosicion < 0 || iAnchura <= 0)
            throw std::invalid_argument("El mueble dado esta incorrectamente construido");

        bool bCabe = false;
        posicionInsercion(Mueble(iPosicion, iAnchura), bCabe);
        return bCabe;
    }

    void colocarMueble(int iPosicion, const int iAnchura)
    {
        if (iPosicion < 0 || iAnchura <= 0)
            throw std::invalid_argument("El mueble dado esta incorrectamente construido");
        bool bCabe = false;
        auto pInsercion = posicionInsercion(Mueble(iPosicion, iAnchura), bCabe);
        if (bCabe)
        {
            lMuebles.insertar(Mueble(iPosicion, iAnchura), pInsercion);
        }
    }

    Mueble muebleIesimo(const int &i)
    {
        if (i < 0 || i > iMueblesColocados)
            throw std::invalid_argument("La posicion dada es incorrecta o supera el numero de muebles colocados en la cocina");
        int it = 0;
        auto p = lMuebles.primera();
        while (p != lMuebles.fin() && it < i)
        {
            it++;
            p = lMuebles.siguiente(p);
        }
        return lMuebles.elemento(p); // Nunca va a llegar a fin puesto que hay un numero de elementos en la lista <= i
    }

    void eliminarMuebleIesimo(const int &i)
    {
        if (i < 0 || i > iMueblesColocados)
            throw std::invalid_argument("La posicion dada es incorrecta o supera el numero de muebles colocados en la cocina");
        int it = 0;
        auto p = lMuebles.primera();
        while (p != lMuebles.fin() && it < i)
        {
            it++;
            p = lMuebles.siguiente(p);
        }
        lMuebles.eliminar(p);
    }

    void desplazarMuebleIesimo(const int i)
    {
        if (i < 0 || i > iMueblesColocados)
            throw std::invalid_argument("La posicion dada es incorrecta o supera el numero de muebles colocados en la cocina");
        if (i == 0)
        {
            lMuebles.elemento(lMuebles.primera()).iPosicion = 0;
        }
        else
        {
            auto p = lMuebles.primera();
            int it = 0;
            while (it < i)
            {
                p = lMuebles.siguiente(p);
                it++;
            }

            lMuebles.elemento(p).iPosicion = lMuebles.elemento(lMuebles.anterior(p)).iPosicion + lMuebles.elemento(lMuebles.anterior(p)).iAnchura;
        }
    }
};

ListaEnla<Mueble>::posicion Cocina::posicionInsercion(const Mueble muebleEntrada, bool &bCabe)
{
    ListaEnla<Mueble>::posicion p = lMuebles.primera();
    // Caso 1: La cocina esta vacia
    if (iLongitudOcupada == 0)
    {
        bCabe = muebleEntrada.iPosicion + muebleEntrada.iAnchura <= iLongitudCocina;
        return p;
    }
    else
    {
        if (iLongitudCocina - iLongitudOcupada < muebleEntrada.iAnchura + muebleEntrada.iPosicion) // Si no cabe en el espacio restante para que seguir.
        {
            bCabe = false;
            return p;
        }
        else
        {
            // La cocina no esta vacia, recorremos a ver donde va, mientras el mueble en la lista sea menor
            ListaEnla<Mueble>::posicion p = lMuebles.primera();
            while (p != lMuebles.fin() && lMuebles.elemento(p) < muebleEntrada)
            {
                p = lMuebles.siguiente(p);
            }

            // 2.1 El mueble va al final del todo
            if (p == lMuebles.fin())
            {
                // Pillamos el mueble anterior para comprobar que no se pise con el
                Mueble mAnterior = lMuebles.elemento(lMuebles.anterior(p));
                bCabe = (mAnterior.iPosicion + mAnterior.iAnchura <= muebleEntrada.iPosicion) && (muebleEntrada.iPosicion + muebleEntrada.iAnchura <= iLongitudCocina);
                // Si no se solapa con el anterior y no sobrepasa la longitud de la cocina entonces cabe.
            }
            else if (p == lMuebles.primera()) // 2.2 El mueble va en primera posicion.
            {
                // Pillamos el mueble siguiente
                Mueble mSiguiente = lMuebles.elemento(lMuebles.siguiente(p));
                bCabe = (muebleEntrada.iPosicion + muebleEntrada.iAnchura <= mSiguiente.iPosicion); // No tenemos que comprobar espacio disponible pq ya lo hemos hecho antes
            }
            else
            {
                // 2.3 El mueble va entre 2 muebles
                Mueble mAnterior = lMuebles.elemento(lMuebles.anterior(p));
                Mueble mSiguiente = lMuebles.elemento(lMuebles.siguiente(p));
                bCabe = (mAnterior.iPosicion + mAnterior.iAnchura <= muebleEntrada.iPosicion) && (muebleEntrada.iPosicion + muebleEntrada.iAnchura <= mSiguiente.iPosicion);
                // Si no se solapa ni con el anterior ni con el siguiente, cabe entre medio.
            }
        }
    }
    return p;
}

int main()
{

    return 0;
}