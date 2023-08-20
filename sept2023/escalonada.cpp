#include <iostream>
#include "../Sept2022/tads/ListaEnla.h"

using namespace std; // Avoid using std:: ....

/**
 * Especificacion del TAD Escalonada
 * Resumen:Una funcion es escalonada cuando consiste en una sucesión
de funciones constantes definidas en intervalos disjuntos y contiguos, es decir, f puede
definirse mediante condiciones de la forma 𝑓(𝑥𝑥) = 𝑦𝑦𝑖𝑖 si 𝑥𝑥𝑖𝑖 ≤ 𝑥𝑥 ≤ 𝑥𝑥𝑖𝑖+1, donde los valores 𝑦𝑦𝑖𝑖
son distintos para intervalos adyacentes. Cada uno de los puntos (𝑥𝑥𝑖𝑖, 𝑦𝑦𝑖𝑖) en los que la función
cambia de valor se llama salto o escalón.
Operaciones

    Escalonada(const double x, const double y): Crea una funcion escalonada definida a partir de una funcion dada.

    void addFuncion(const double x, const double y): Agrega una funcion en el punto dado, en caso de existir se sustituye el por el salto nuevo en el eje x e y.

    void eraseFuncion(const double x): Elimina el salto de la funcion que viene definida por el salto en el punto x, en caso de no existir función con salto en x
    no hace nada.

    const double valorFuncion(const double x, const double y):Calcular el valor de la funcion escalonada en el punto dado, si la funcion no tiene saltos dentro de la misma
    lanzará una excepción, puesto que no existe ningún valor asociado a esa coordenada.

    const double valorMinimo(): Devuelve el valor minimo de la funcion escalonada, en caso de estar vacia lanza una excepción, puesto que no existe ningún valor dentro de la
    misma para devolver.

    const double valorMaximo(): Exactamente igual a la anterior, pero en este caso devuelve el valor maximo de la misma.

    void translacion(const double z,const double w): Desplaza la funcion escalonada z unidades verticalmente y w unidades de forma vertical, en caso de estar vacia
    dicha funcion se avisara al usuario mediante una excepción.
 */

struct Funcion
{
    double x, y;
    Funcion(const double i = 0, const double j = 0) : x(i), y(j) {}
    bool operator<(Funcion f)
    {
        return x < f.x;
    }
};

bool operator==(Funcion f1, Funcion f2)
{
    return f1.x == f2.x;
}

bool operator!=(Funcion f1, Funcion f2)
{
    return f1.x != f2.x;
}

class Escalonada
{
    ListaEnla<Funcion> lFunciones;

public:
    Escalonada(const double &x, const double &y)
    {
        lFunciones.insertar(Funcion(x, y), lFunciones.primera());
    }
    void addFuncion(const double x, const double y)
    {
        auto p = lFunciones.primera();
        Funcion fEntrada(x, y);
        while (p != lFunciones.fin() && lFunciones.elemento(p) < fEntrada)
        {
            p = lFunciones.siguiente(p);
        }

        if (p != lFunciones.fin())
        {
            // Caso que sean iguales
            if (lFunciones.elemento(p) == fEntrada)
            { // Las x coinciden
                lFunciones.elemento(p).y = fEntrada.y;
            }
            else // No son iguales, con lo cual insertamos en posicion
            {
                lFunciones.insertar(fEntrada, p);
            }
        }
        else
        {
            lFunciones.insertar(fEntrada, p);
        }
    }

    void eraseFuncion(const double x)
    {
        if (lFunciones.fin() == lFunciones.primera())
        {
            throw std::runtime_error("La funcion escalonada esta vacia, no hay nada por eliminar");
        }
        auto p = lFunciones.primera();
        Funcion fEntrada(x);
        while (p != lFunciones.fin() && lFunciones.elemento(p) != fEntrada)
        {
            p = lFunciones.siguiente(p);
        }
        if (p != lFunciones.fin())
            lFunciones.eliminar(p);
    }

    double valorFuncion(const double x)
    {
        if (lFunciones.fin() == lFunciones.primera())
        {
            throw std::runtime_error("La funcion escalonada esta vacia, no hay ningún valor en ella");
        }
        auto p = lFunciones.primera();
        Funcion fEntrada(x);
        while (p != lFunciones.fin() && lFunciones.elemento(p) < fEntrada)
        {
            p = lFunciones.siguiente(p);
        }

        if (p != lFunciones.fin())
        {
            // Caso que sean iguales
            if (lFunciones.elemento(p) == fEntrada)
            { // Las x coinciden
                return lFunciones.elemento(p).y;
            }
            else // No son iguales, con lo cual insertamos en posicion
            {
                return lFunciones.elemento(lFunciones.anterior(p)).y;
            }
        }
        else
        {
            return lFunciones.elemento(lFunciones.anterior(p)).y;
        }
    }

    // Valor minimo y maximo me dan pereza xd
};

int main()
{

    return 0;
}