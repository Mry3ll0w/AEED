#include <iostream>
#include "../Sept2022/tads/ListaEnla.h"

using namespace std; // Avoid using std:: ....

class Simbolo
{
    ListaEnla<char> lTrazos;
    int iNumeroTrazos;

public:
    Simbolo() : iNumeroTrazos(0) {} // Crea un simbolo vacio, sin precondicion ni nada.

    // Pre: El simbolo tiene que ser d(derecha), i(izquierda),s(subir), b(bajar).
    // Post: Agrega el trazo al dibujo
    void addTrazo(const char &cTrazo)
    {
        if (cTrazo != 'd' || cTrazo != 'i' || cTrazo != 's' || cTrazo != 's' || cTrazo != 'b')
        {
            throw std::invalid_argument("El trazo introducido no es valido");
        }
        lTrazos.insertar(cTrazo, lTrazos.fin());
        iNumeroTrazos++;
    }

    // Pre:n >= 1 y tienen que existir en el dibujo al menos n trazos
    // Post: Elimina los n ultimos trazos del dibujo.
    void deshacerNTrazos(int n)
    {
        if (iNumeroTrazos < n || n < 1)
            throw std::invalid_argument("No hay tantos trazos en el dibujo, o la n es < 1");

        while (n > 0)
        {
            lTrazos.eliminar(lTrazos.anterior(lTrazos.fin()));
            n--;
        }
    }

    // Post: Realiza la simetria  del eje x, en caso de estar vacio no hace nada.
    void simetriaX()
    {
        if (iNumeroTrazos > 0)
        {
            auto p = lTrazos.primera();
            while (p != lTrazos.fin())
            {
                if (lTrazos.elemento(p) == 'i')
                    lTrazos.elemento(p) = 'd';
                else if (lTrazos.elemento(p) == 'd')
                    lTrazos.elemento(p) = 'i';

                p = lTrazos.siguiente(p);
            }
        }
    }
    // Lo mismo que la anterior pero con el eje Y
    void simetriaY()
    {
        if (iNumeroTrazos > 0)
        {
            auto p = lTrazos.primera();
            while (p != lTrazos.fin())
            {
                if (lTrazos.elemento(p) == 'a')
                    lTrazos.elemento(p) = 'b';
                else if (lTrazos.elemento(p) == 'b')
                    lTrazos.elemento(p) = 'a';

                p = lTrazos.siguiente(p);
            }
        }
    }

    // Exactamente igual que la anterior pero aplicando ambos ejes de simetria.
    void simetriaXY()
    {
        simetriaX();
        simetriaY();
    }
};

int main()
{

    return 0;
}