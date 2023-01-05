#include <iostream>
#include <string>
#include "../Sept2022/tads/ListaEnla.h"
/**
 * Una empresa ha robotizado su almacén.
 * Para ello lo ha dividido en 60 estantes de tres tamaños diferentes
 * (pequeño, mediano y grande) a partes iguales.
 * A cada estante se le asigna un elemento según su tamaño
 * (en cada estante solo hay elementos de un tipo, pero puede
 * haber hasta 50 elementos del mismo tipo).

Se pide diseñar un TAD para el funcionamiento del robot que i
ncluya las siguientes operaciones:

    1. Crear un almacén vacío.
    2. Insertar un elemento en un estante. Si ya hay un estante
    asignado,y el elemento cabe, se coloca en ese. Si no es así,
    se busca otro estante del mismo tamaño.
        Si no hay, se devuelve False.
        Si se puede colocar se devuelve True.
    3. Comprobar si hay elementos de un tipo determinado.
    4. Sacar un elemento de un tipo dado.
    5. Vaciar el almacén (destructor del TAD).
 */

typedef struct Objeto
{
    char cSizeEstante; // Small Medium Large
    int iID;
    Objeto(char estante = '#', int ID = 0) : iID(ID), cSizeEstante(estante) {}
    bool operator==(const Objeto &o) { return iID == o.iID; }
};

typedef struct Estante
{
    const int iCAPACIDAD = 50; // Fijo
    int iOcupados;
    char cType;
    bool lleno() { return iOcupados == 50; }
    void addObj(const Objeto o)
    {
        if (!lleno() && o.cSizeEstante == cType)
        {
            objetos.insertar(o, objetos.fin());
            iOcupados++;
        }
    }

    int iID;
    ListaEnla<Objeto> objetos;
    Estante(int ID = 0, char type = '#') : iID(ID), iOcupados(0) {}
};

class Almacen
{
    ListaEnla<Estante> lEstantes;

public:
    Almacen()
    {
        auto pos = lEstantes.fin();
        for (int i = 0; i < 60; ++i)
        {
            if (i < 20)
                lEstantes.insertar(Estante(i + 1, 's'), pos);
            else if (i >= 20 && i < 40)
                lEstantes.insertar(Estante(i + 1, 'm'), pos);
            else if (i >= 40)
                lEstantes.insertar(Estante(i + 1, 'l'), pos);
        }
    }

    bool addObject(const Objeto o)
    {
        if (o.cSizeEstante == '#')
            throw std::invalid_argument("El size del objeto no ha sido agregado");

        bool bNoCabe = false;

        // 1) Buscamos donde debe ir el objeto segun el size
        auto pEstante = lEstantes.primera();

        for (; pEstante != lEstantes.fin() && !bNoCabe; pEstante = lEstantes.siguiente(pEstante))
        {
            if (
                !lEstantes.elemento(pEstante).lleno() &&
                lEstantes.elemento(pEstante).cType == o.cSizeEstante)
                bNoCabe = true;
        }

        // Hay hueco para insertar
        if (bNoCabe == false)
        {
            lEstantes.elemento(pEstante).addObj(o);
        }

        return bNoCabe;
    }

    void popObj(const Objeto &o, const char &type)
    {
        bool bErased = false;
        for (auto pEstantes = lEstantes.primera(); pEstantes != lEstantes.fin() && !bErased; pEstantes = lEstantes.siguiente(pEstantes))
        {
            if (lEstantes.elemento(pEstantes).cType == type)
            {
                auto pObjects = lEstantes.elemento(pEstantes).objetos.buscar(o);
                if (pObjects != lEstantes.elemento(pEstantes).objetos.fin())
                {
                    lEstantes.elemento(pEstantes).objetos.eliminar(pObjects);
                    lEstantes.elemento(pEstantes).iOcupados--;
                }
            }
        }
    }

    bool existeTipo(const char cType)
    {
        if (cType != 's' && cType != 'm' && cType != 'l')
            throw std::invalid_argument("No existe ese tipo de elemento, tipos validos Small (s), Medium (m), Large (l)");
        bool bExists = false;

        auto p = lEstantes.primera();
        while (!bExists && p != lEstantes.fin())
        {
            if (lEstantes.elemento(p).iOcupados > 0)
                bExists = true;
            p = lEstantes.siguiente(p);
        }
        return bExists;
    }
};

int main()
{
    Almacen a;
    a.addObject(Objeto(1, 'm'));
    return 0;
}