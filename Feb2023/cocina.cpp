#include <iostream>
#include "../Sept2022/tads/ListaEnla.h"
using namespace std; // Avoid using std:: ....

typedef struct Mueble
{
    double dPosicion_;
    double dAnchura_;

    Mueble(const double p = 0, const double a = 0) : dPosicion_(p), dAnchura_(a) {}
    bool operator==(const Mueble &m) { return m.dPosicion_ == dPosicion_; }
    bool operator<(const Mueble &m) { return m.dPosicion_ < dPosicion_; }
};

class Cocina
{
    double dLongitudCocina_;
    double dLongitudOcupada_;
    int iNumeroMuebles;
    ListaEnla<Mueble> lMuebles;

public:
    Cocina(const double &l) : dLongitudCocina_(l), dLongitudOcupada_(0), iNumeroMuebles(0)
    {
        if (l <= 0)
            throw invalid_argument("el parametro l tiene que ser mayor que 0");
    }

    pair<bool, ListaEnla<Mueble>::posicion> cabeMueble(const double &pos, const double &anchura);

    void insertarMueble(const double &pos, const double &l)
    {
        if (pos < 0 && pos >= dLongitudCocina_)
            throw invalid_argument("Inserta una posicion valida");
        if (l <= 0)
            throw invalid_argument("La longitud tiene que ser > 0");

        pair<bool, ListaEnla<Mueble>::posicion> pairMueble = cabeMueble(pos, l);
        if (pairMueble.first)
            lMuebles.insertar(Mueble(pos, l), pairMueble.second);
        else
            throw runtime_error("El mueble no cabe en la posicion dada");
    }

    Mueble muebleIesimo(int i);

    void eliminarMuebleIesimo(int i);

    void desplazarMuebleIesimo(int i);
};

int main()
{

    return 0;
}

pair<bool, ListaEnla<Mueble>::posicion> Cocina::cabeMueble(const double &pos, const double &anchura)
{
    // Control de excepciones
    if (pos < 0 || pos > dLongitudCocina_)
        throw invalid_argument("La posicion dada no es valida");
    if (anchura <= 0 && anchura > dLongitudCocina_)
        throw invalid_argument("La anchura de un mueble tiene que ser > 0 y menor que la longitud de la cocina");

    // Cuerpo de la función
    bool bCabe = false;
    ListaEnla<Mueble>::posicion pMueble = lMuebles.primera();

    if (dLongitudOcupada_ == 0 && dLongitudCocina_ >= anchura)
        return make_pair(true, lMuebles.fin());
    else if (dLongitudCocina_ - dLongitudOcupada_ >= anchura && dLongitudOcupada_ > 0) // El mueble tiene espacio en la cocina
    {
        Mueble m(pos, anchura);
        while (pMueble != lMuebles.fin() && lMuebles.elemento(pMueble) < m)
        {
            pMueble = lMuebles.siguiente(pMueble);
        }
        // Caso la posicion del mueble es la ultima
        if (pMueble == lMuebles.fin())
        {
            Mueble muebleAnterior = lMuebles.elemento(lMuebles.anterior(pMueble));
            // Comprobamos que no se superponga
            if (muebleAnterior.dPosicion_ + muebleAnterior.dAnchura_ <= m.dPosicion_)
            {
                // No se superpone, comprobamos que exista espacio
                double dHueco = dLongitudCocina_ - (muebleAnterior.dPosicion_ + muebleAnterior.dAnchura_);

                if (dHueco >= m.dAnchura_ + m.dPosicion_)
                { // El hueco es suficiente
                    bCabe = true;
                }
            }
            else
            { // Se superpone o no cabe
                bCabe = false;
            }
        }
        else
        {                                      // La posicion del mueble no es la final
            if (pMueble == lMuebles.primera()) // el mueble va en primer lugar
            {
                if (lMuebles.elemento(pMueble).dPosicion_ >= m.dAnchura_ + m.dPosicion_)
                {
                    bCabe = true;
                }
            }
            else
            { // Esta entre muebles, ya que existe un mueble antes de m y despues de m
                Mueble muebleAnterior = lMuebles.elemento(lMuebles.anterior(pMueble));
                Mueble muebleSiguiente = lMuebles.elemento(lMuebles.siguiente(pMueble));
                double dHueco = (muebleAnterior.dAnchura_ + muebleAnterior.dPosicion_) - muebleSiguiente.dPosicion_;
                if (dHueco > m.dAnchura_ + m.dPosicion_ && m.dPosicion_ + m.dAnchura_ <= muebleSiguiente.dPosicion_)
                {
                    bCabe = true;
                }
            }
        }
        return make_pair(bCabe, pMueble);
    }
    else
    { // No hay espacio en la cocina por lo que no cabe
        return make_pair(false, lMuebles.fin());
    }
}

Mueble Cocina::muebleIesimo(int i)
{
    if (i < 0 || i > iNumeroMuebles)
        throw runtime_error("No hay tantos muebles en la cocina");

    ListaEnla<Mueble>::posicion pMueble = lMuebles.primera();
    while (i > 0 && pMueble != lMuebles.fin())
    {
        pMueble = lMuebles.siguiente(pMueble);
        i--;
    }
    return lMuebles.elemento(pMueble);
}

void Cocina::eliminarMuebleIesimo(int i)
{
    if (i < 0 || i > iNumeroMuebles)
        throw runtime_error("No hay tantos muebles en la cocina");

    ListaEnla<Mueble>::posicion pMueble = lMuebles.primera();
    while (i > 0 && pMueble != lMuebles.fin())
    {
        pMueble = lMuebles.siguiente(pMueble);
        i--;
    }
    lMuebles.eliminar(pMueble);
}

void Cocina::desplazarMuebleIesimo(int i)
{
    Mueble m = muebleIesimo(i);
    ListaEnla<Mueble>::posicion p = lMuebles.buscar(m);

    if (p == lMuebles.fin())
        throw runtime_error("No existe el mueble introducido");

    if (p == lMuebles.primera())
    { // El mueble es el primero, lo pegamos a la pared
        lMuebles.elemento(p).dPosicion_ = 0;
    }
    else
    {
        Mueble muebleAnterior = lMuebles.elemento(lMuebles.anterior(p));
        lMuebles.elemento(p).dPosicion_ = muebleAnterior.dAnchura_ + muebleAnterior.dPosicion_;
    }
}