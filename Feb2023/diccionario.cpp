#include <iostream>
#include <string>
#include "../jun2022/tads/ListaEnla.h"

using namespace std; // Avoid using std:: ....

typedef struct Traduccion
{
    string strWord;
    ListaEnla<string> lPalabras;
    Traduccion(const string s = "") : strWord(s) {}
    ListaEnla<string>::posicion buscarPalabra(const string &s)
    {
        auto pos = lPalabras.primera();
        while (pos != lPalabras.fin() && lPalabras.elemento(pos) != s)
            pos = lPalabras.siguiente(pos);

        return pos;
    }
};

class Diccionario
{
    ListaEnla<Traduccion> lTraducciones;

    ListaEnla<Traduccion>::posicion buscarTraduccion(const string &strSearchedWord)
    {
        auto pos = lTraducciones.primera();
        while (pos != lTraducciones.fin() && lTraducciones.elemento(pos).strWord != strSearchedWord)
            pos = lTraducciones.siguiente(pos);

        return pos;
    }

public:
    void insertarTraduccion(const string &strWord, const string &strPalabra)
    {
        auto pos = buscarTraduccion(strWord);
        if (pos != lTraducciones.fin())
        {
            lTraducciones.elemento(pos).lPalabras.insertar(strPalabra, lTraducciones.elemento(pos).lPalabras.fin());
        }
        else
        {
            Traduccion t(strWord);
            t.lPalabras.insertar(strPalabra, t.lPalabras.fin());
            lTraducciones.insertar(t, lTraducciones.fin());
        }
    }
    void eliminarTraduccionESP(const string &strEng, const string &strEsp)
    {
        auto posTraduccionIngles = buscarTraduccion(strEng);

        if (posTraduccionIngles == lTraducciones.fin())
            throw invalid_argument("Esa palabra inglesa no existe");

        auto posListaEsp = lTraducciones.elemento(posTraduccionIngles).buscarPalabra(strEsp);
        if (posListaEsp == lTraducciones.elemento(posTraduccionIngles).lPalabras.fin())
        {
            throw invalid_argument("La traduccion al esp no se puede eliminar, ya que no existe");
        }
        lTraducciones.elemento(posTraduccionIngles).lPalabras.eliminar(posListaEsp);
    }

    void mostrarTraduccionesAlEsp(const string &strEng)
    {
        auto posTraduccionIngles = buscarTraduccion(strEng);

        if (posTraduccionIngles == lTraducciones.fin())
            throw invalid_argument("Esa palabra inglesa no existe");

        for (auto i = lTraducciones.elemento(posTraduccionIngles).lPalabras.primera();
             i != lTraducciones.elemento(posTraduccionIngles).lPalabras.fin(); i = lTraducciones.elemento(posTraduccionIngles).lPalabras.siguiente(i))
        {
            cout << lTraducciones.elemento(posTraduccionIngles).lPalabras.elemento(i) << ", ";
        }
        cout << endl;
    }
};

int main()
{

    return 0;
}