#include <iostream>
#include "../jun2022/tads/ListaEnla.h"
using namespace std; // Avoid using std:: ....

// En este caso la lista enlazada no es correcta pero no tengo implementada la lista pseudoestatica.
typedef void *Trama; // Cualquier informacion

typedef string PC;

class TokenRing
{
private:
    ListaEnla<PC> lsnetRing;
    ListaEnla<PC>::posicion tokenPlacement;
    int iInsertedPCs;
    const bool &hasToken(const string &pc)
    {
        if (lsnetRing.buscar(pc) == lsnetRing.fin())
            return false;
        else
            return lsnetRing.elemento(lsnetRing.buscar(pc)) == lsnetRing.elemento(tokenPlacement);
    }
    void processTrama(const string &pc, const Trama &t) {}

public:
    TokenRing(const string &pc) : iInsertedPCs(1)
    {
        auto psInsertion = lsnetRing.primera();
        lsnetRing.insertar((PC)pc, psInsertion);
        tokenPlacement = psInsertion;
    }
    ~TokenRing() = default;
    void addPC(const PC &pc);
    void popPC();
    void passToken();
    void sendData(const string &pcA, const string &pcb, const Trama &t);
    const string tokenLocation();
    void assingToken(const string &pc);
};

void TokenRing::addPC(const PC &pc)
{
    if (iInsertedPCs >= 25)
    {
        throw runtime_error("No caben mas ordenadores en la red anillo");
    }

    if (lsnetRing.buscar(pc) != lsnetRing.fin())
        throw runtime_error("Ese ordenador ya esta dentro de la red");

    lsnetRing.insertar(pc, lsnetRing.primera());
    iInsertedPCs++;
    if (iInsertedPCs == 1)
    { // Es el unico pc en la red anillo, por tanto tiene el token
        tokenPlacement = lsnetRing.primera();
    }
}

void TokenRing::popPC()
{
    if (iInsertedPCs == 0)
    {
        throw runtime_error("No hay pcs en la red anillo");
    }
    iInsertedPCs--;
    // Eliminamos el ultimo elemento que esta en la lista, es decir el anterior a la posicion fin
    lsnetRing.eliminar(lsnetRing.anterior(lsnetRing.fin()));
}

void TokenRing::sendData(const string &pcA, const string &pcB, const Trama &t)
{
    // Como no se que tipo de datos es trama no hago nada con el, lo mas optimo entiendo que seria que cada pc almacenara trama?
    //  Comprobamos que exista a y tenga el token
    if (!hasToken(pcA))
    {
        throw runtime_error("El ordenador= " + pcA + " no tiene el token");
    }
    // Comprobamos que existe el ordenador pcB dentro de la red
    if (lsnetRing.buscar(pcB) == lsnetRing.fin())
    {
        throw runtime_error("El ordenador destino no existe dentro de la red");
    }
    // Tal y como se mueve el token se asigna este al destino del pc
    processTrama(pcB, t);
    tokenPlacement = lsnetRing.buscar(pcB);
}

void TokenRing::passToken()
{
    if (tokenPlacement == lsnetRing.fin() || iInsertedPCs == 0)
        throw runtime_error("No hay ningun ordenador con el token");

    // Pasamos el token al siguiente, comprobamos casos de ultimo de la lista y primero
    auto itLs = tokenPlacement;
    if (lsnetRing.siguiente(itLs) == lsnetRing.fin())
    {
        tokenPlacement = lsnetRing.primera(); // si es el ultimo ordenador lo pasamos al primero
    }
    else
        tokenPlacement = lsnetRing.siguiente(tokenPlacement);
}

const string TokenRing::tokenLocation()
{
    if (tokenPlacement == lsnetRing.fin())
        return "No hay ordenadores con el token";
    else
        return lsnetRing.elemento(tokenPlacement);
}

void TokenRing::assingToken(const string &pc)
{
    if (iInsertedPCs == 0 || lsnetRing.buscar(pc) == lsnetRing.fin())
        throw runtime_error("No existen ordenadores en la red anillo o no existe el ordenador introducido");

    tokenPlacement = lsnetRing.buscar(pc);
}

int main()
{

    TokenRing Red("A");
    Red.addPC("B");
    Red.assingToken("B");
    Red.sendData("B", "B", (Trama)'a');
    Red.passToken();
    cout << Red.tokenLocation() << endl;
    return 0;
}