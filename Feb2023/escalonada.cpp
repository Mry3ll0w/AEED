#include <iostream>
#include "../Sept2022/tads/ListaEnla.h"
using namespace std; // Avoid using std:: ....

typedef struct Funcion
{
    double x, y;
    bool operator==(const Funcion &f) { return f.x == x; } // Caracterizado por la posicion x de cada trozo
    Funcion(const double &px = 0, const double &py = 0) : x(px), y(py) {}
};

class Escalonada
{

    ListaEnla<Funcion> lFunciones;

public:
    Escalonada(const double x, const double y)
    {
        lFunciones.insertar(Funcion(x, y), lFunciones.fin());
    }

    void addFunction(const double x, const double y)
    {
        // Comprobamos si existe una funcion con esa x
        auto p = lFunciones.primera();
        while (p != lFunciones.fin() && lFunciones.elemento(p).x != x)
            lFunciones.siguiente(p);
        // Si existe simplemente cambiamos la altura Y
        if (p != lFunciones.fin())
        {
            lFunciones.elemento(p).y = y;
        }
        else
            lFunciones.insertar(Funcion(x, y), p); // No existe ninguna funcion con esa x, por lo que simplemente agregamos la funcion.
    }

    void eraseFunction(const double &x)
    {
        auto p = lFunciones.buscar(Funcion(x));
        if (p != lFunciones.fin())
            throw invalid_argument("No existe ninguna funcion con el inicio en el punto x introducido");

        lFunciones.eliminar(p);
    }

    double valueOnPoint(const double &x)
    {
        // Comprobamos que la x no sea menor que la primera
        if (lFunciones.elemento(lFunciones.primera()).x > x)
            throw std::invalid_argument("No existe valor en esa funcion");

        auto p = lFunciones.primera();
        while (p != lFunciones.fin() && lFunciones.elemento(p).x < x)
            p = lFunciones.siguiente(p);

        if (p == lFunciones.fin()) // Si la x sale del ratio la Y es la anterior, ya que se extiende hasta el inf.
            return lFunciones.elemento(lFunciones.anterior(p)).y;
        else
            return lFunciones.elemento(p).y;
    }

    double minValue()
    {
        auto p = lFunciones.primera();
        double min = lFunciones.elemento(p).y;
        while (p != lFunciones.fin())
        {
            if (lFunciones.elemento(p).y < min)
                min = lFunciones.elemento(p).y;
            p = lFunciones.siguiente(p);
        }
        return min;
    }

    double maxValue()
    {
        auto p = lFunciones.primera();
        double max = lFunciones.elemento(p).y;
        while (p != lFunciones.fin())
        {
            if (lFunciones.elemento(p).y > max)
                max = lFunciones.elemento(p).y;
            p = lFunciones.siguiente(p);
        }
        return max;
    }

    void translation(const double &w, const double &z, const double &x)
    {
        auto p = lFunciones.buscar(Funcion(x));
        if (p == lFunciones.fin())
            throw std::invalid_argument("Ese fragmento de funcion no existe");

        lFunciones.elemento(p).x += w;
        lFunciones.elemento(p).y += z;
    }
};

double main()
{

    return 0;
}