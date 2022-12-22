#include <iostream>
#include <string>
#include "../Sept2022/tads/ListaEnla.h"
using namespace std; // Avoid using std:: ....

// Sabemos que en el texto no aparecen finales de linea, no hay /0

// En principio no se nos pide un TAD completo si no una funcion, por lo que definiremos un
// tipo texto, como una lista de lineas, que a su vez tiene una lista de palabras (string)
struct Line
{
    ListaEnla<string> aWords;
    Line(string palabras[] = nullptr, int iSize = 0)
    {
        for (int i = 0; i < iSize; ++i)
        {
            aWords.insertar(palabras[i], aWords.fin());
        }
    }
};

typedef ListaEnla<Line> Text;

void mostrarTexto(Text texto);

int main()
{
    string p1[] = {"Hola ", "que ", "tal#"}, p2[] = {"Yo ", "ess@@toy", "bii@en"};
    Line l1(p1, 3), l2(p2, 3);
    Text t;
    t.insertar(l1, t.fin());
    t.insertar(l2, t.fin());
    mostrarTexto(t);

    return 0;
}

void mostrarTexto(Text texto)
{
    Text textTrim; // Guardamos las lineas que no tengan #
    // buscamos si existen lineas con # ==> en caso afirmativo eliminamos la linea
    for (auto l = texto.primera(); l != texto.fin(); l = texto.siguiente(l))
    {
        bool bEliminated = false;
        for (
            auto p = texto.elemento(l).aWords.primera();
            p != texto.elemento(l).aWords.fin() && !bEliminated;
            p = texto.elemento(l).aWords.siguiente(p))
        {
            if (texto.elemento(l).aWords.elemento(p).find('#') != string::npos)
            {
                bEliminated = true;
            }
        }

        if (!bEliminated)
        {
            textTrim.insertar(texto.elemento(l), textTrim.fin());
        }
    }

    // Mostramos las lineas del texto limpias
    for (auto l = textTrim.primera(); l != textTrim.fin(); l = textTrim.siguiente(l))
    {
        for (auto p = textTrim.elemento(l).aWords.primera();
             p != textTrim.elemento(l).aWords.fin();
             p = textTrim.elemento(l).aWords.siguiente(p))
        {
            cout << textTrim.elemento(l).aWords.elemento(p);
        }
        cout << endl;
    }
}
