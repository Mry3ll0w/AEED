#include <iostream>
#include "../Sept2022/tads/ListaEnla.h"
using namespace std; // Avoid using std:: ....

class Symbol
{
    ListaEnla<char> lTraces;
    int iNumberOfTraces;

public:
    Symbol() : iNumberOfTraces(0) {}
    void addTrace(const char cTrace);
    void eraseTrace(const int iNTraces);
    void rotateSymbolX();
    void rotateSymbolY();
    void rotateSymbolXY();
};

int main()
{

    return 0;
}

void Symbol::addTrace(const char cTrace)
{
    if (cTrace != 'I' || cTrace != 'D' || cTrace != 'B' || cTrace != 'S')
        throw std::invalid_argument("Invalid trace");
    iNumberOfTraces++;
    lTraces.insertar(cTrace, lTraces.fin());
}

void Symbol::eraseTrace(int iNTraces)
{
    if (iNTraces > iNumberOfTraces || iNTraces < 0)
        throw std::invalid_argument("That number of traces is not correct");
    auto p = lTraces.anterior(lTraces.fin());
    while (iNTraces > 0)
    {
        iNTraces--;
        lTraces.eliminar(lTraces.anterior(lTraces.fin()));
    }
    iNumberOfTraces -= iNTraces;
}

void Symbol::rotateSymbolX()
{
    if (iNumberOfTraces == 0)
        throw runtime_error("There are no trace to rotate");
    for (auto p = lTraces.primera(); p != lTraces.fin(); p = lTraces.siguiente(p))
    {
        if (lTraces.elemento(p) == 'A')
            lTraces.elemento(p) = 'B';
        else if (lTraces.elemento(p) == 'B')
            lTraces.elemento(p) = 'A';
    }
}

void Symbol::rotateSymbolY()
{
    if (iNumberOfTraces == 0)
        throw runtime_error("There are no trace to rotate");
    for (auto p = lTraces.primera(); p != lTraces.fin(); p = lTraces.siguiente(p))
    {
        if (lTraces.elemento(p) == 'I')
            lTraces.elemento(p) = 'D';
        else if (lTraces.elemento(p) == 'D')
            lTraces.elemento(p) = 'I';
    }
}

void Symbol::rotateSymbolXY()
{
    rotateSymbolX();
    rotateSymbolY();
}
