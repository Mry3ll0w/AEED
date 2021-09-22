#include <iostream>
#include "tads implementados profesorado/pila_enla.h"
#include "tads implementados profesorado/Cola_Din.h"
#include "tads implementados profesorado/ListaEnla.h"
using namespace std;//Avoid using std:: ....

int main(){
    /* ----------------------------- MANEJO DE PILA ----------------------------- */
    PilaEnla<int>p,q; 
    p.push(1);
    p.push(2);
    p.push(3);
    //COMO RECORREMOS EL CONTENIDO DE LA PILA
    PilaEnla<int>p_aux;
    p_aux=p;
    while (p_aux.vacia()!=true)
    {
        cout<<p_aux.tope()<<", ";
        p_aux.pop();
    }
    cout<<endl<<endl;
    
    /* ------------------------------- MANEJO COLA ------------------------------ */
    ColaDin<int>c,c2;

    c.push(1);
    c.push(2);
    c.push(3);
    //RECORRER COLA
    while (c.vacia()!=true)
    {
        cout<<c.frente()<<", ";
        c.pop();
    }
    cout<<endl<<endl;

    ListaEnla<int> l;
    
    l.insertar(1,l.fin());//Insertamos en el final de forma general (salvo excepciones)
    l.insertar(2,l.fin());//Insertamos en el final de forma general (salvo excepciones)
    l.insertar(3,l.fin());//Insertamos en el final de forma general (salvo excepciones)
    l.insertar(4,l.fin());//Insertamos en el final de forma general (salvo excepciones)
    
    auto pos = l.primera();
    while (pos!=l.fin())
    {
        cout<<l.elemento(pos)<<' ';
        pos=l.siguiente(pos);
    }

    bool temp = l.buscar(3)==l.fin();
    cout<<endl<<temp<<endl;
    l.eliminar(l.buscar(3));
    temp = l.buscar(3)==l.fin();
    cout<<temp<<endl;
    
    for (auto i = l.primera(); i !=l.fin(); i=l.siguiente(i))
    {
        cout<<l.elemento(i)<<' ';
    }
    
    return 0;
}