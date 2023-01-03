#include <iostream>
#include <string>
#include "../Sept2022/tads/ListaEnla.h"
using namespace std; // Avoid using std:: ....

typedef string Cajero;

typedef struct Caja
{
    Cajero cajeroAsignado;
    bool operator==(const Caja &c) { return c.iID_ == iID_; }
    double dFacturacion_;
    int iID_;
    bool bOpen;
    Caja(int id = 0) : iID_(id), cajeroAsignado(""), bOpen(true), dFacturacion_(0) {}
};

// Aunque el enunciado nos dice que las operaciones de cerrar, cobrar y sustituir tienen que ser de orden cte, las nuestras seran lineales
// ya que no tengo la implementacion vectorial pseudoestatica que seria la correcta y tampoco cambia practicamente nada las funciones.

class LineaCaja
{
    ListaEnla<Caja> lCajas;

public:
    // Inicializa las 50 cajas maximas asignando a cada una un ID
    LineaCaja()
    {
        for (int i = 0; i < 50; ++i)
        {
            lCajas.insertar(Caja(i + 1), lCajas.fin());
        }
    }

    // Se asume que la caja puede estar abierta sin Cajero
    void abrirCaja(int id)
    {
        auto posCaja = lCajas.buscar(Caja(id));

        if (posCaja == lCajas.fin())
            throw invalid_argument("Esa caja no existe");

        lCajas.elemento(posCaja).bOpen = true;
    }

    double cerrarCaja(int id)
    {
        auto posCaja = lCajas.buscar(Caja(id));

        if (posCaja == lCajas.fin())
            throw invalid_argument("Esa caja no existe");

        lCajas.elemento(posCaja).bOpen = false;
        double dFacturacion = lCajas.elemento(posCaja).dFacturacion_;
        lCajas.elemento(posCaja).dFacturacion_ = 0;
        return dFacturacion;
    }

    void cobrarCliente(double factura, int id)
    {
        auto posCaja = lCajas.buscar(Caja(id));

        if (posCaja == lCajas.fin())
            throw invalid_argument("Esa caja no existe");

        if (lCajas.elemento(posCaja).bOpen == false)
            throw invalid_argument("Esa caja esta cerrada");

        lCajas.elemento(posCaja).dFacturacion_ += factura;
    }

    void sustituirCajero(Cajero c, int id)
    {
        auto posCaja = lCajas.buscar(Caja(id));

        if (posCaja == lCajas.fin())
            throw invalid_argument("Esa caja no existe");

        if (lCajas.elemento(posCaja).bOpen == false)
            throw invalid_argument("Esa caja esta cerrada, no podemos sustituir al cajero");

        lCajas.elemento(posCaja).cajeroAsignado = c;
    }

    double cambiarTurno()
    {
        double dFacturacionTotal = 0;
        for (auto p = lCajas.primera(); p != lCajas.fin(); p = lCajas.siguiente(p))
        {
            if (lCajas.elemento(p).bOpen) // Solo sumamos a la facturacion aquellas cajas abiertas, las cerradas no suman nada
            {
                dFacturacionTotal += lCajas.elemento(p).dFacturacion_;
                lCajas.elemento(p).dFacturacion_ = 0;
                lCajas.elemento(p).cajeroAsignado = ""; // Cambiamos el turno y eliminamos al cajero asignado previamente
            }
        }
        return dFacturacionTotal;
    }

    double cerrarTienda()
    {
        double dFacturacionTotal = 0;
        for (auto p = lCajas.primera(); p != lCajas.fin(); p = lCajas.siguiente(p))
        {
            if (lCajas.elemento(p).bOpen) // Solo sumamos a la facturacion aquellas cajas abiertas, las cerradas no suman nada
            {
                dFacturacionTotal += lCajas.elemento(p).dFacturacion_;
                lCajas.elemento(p).dFacturacion_ = 0;
                lCajas.elemento(p).cajeroAsignado = ""; // Cambiamos el turno y eliminamos al cajero asignado previamente
                lCajas.elemento(p).bOpen = false;
            }
        }
        return dFacturacionTotal;
    }
};

int main()
{

    return 0;
}