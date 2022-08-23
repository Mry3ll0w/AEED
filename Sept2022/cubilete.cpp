#include <iostream>
#include "tads/pila_enla.h"
#include <climits>
using namespace std;//Avoid using std:: ....

struct Cubilete{
    double largo;//Unico de cada Cubilete

    char posicion;//aBajo, de Lado, Arriba ==> La posicion buscada es abajo
    
    Cubilete(const double& l=.0, const char& pos='B'):largo(l),posicion(pos){}
    

};

/**
 * @brief Obtiene el Cubilete menor largo de la lista y lo poda de la pila de entrada
 * @param PilaEnla<Cubilete>
 * @return Cubilete
 */
Cubilete menor_cubilete(PilaEnla<Cubilete>& P){

    Cubilete menor (INT_MAX);

    //Copiamos en la pila auxiliar la pila de cubiletes para no modificar la de entrada
    auto p_aux = P;
    while (!p_aux.vacia()){

        if(p_aux.tope().largo < menor.largo){
            menor = p_aux.tope();
        }
        
        p_aux.pop();
    }

    //Podamos el elemento extraido de la pila

    p_aux = P;//Reestablecemos la pila

    PilaEnla<Cubilete> invierte, revierte;

    while (!p_aux.vacia())
    {

        if(p_aux.tope().largo != menor.largo ){
            invierte.push(p_aux.tope());
        }

        p_aux.pop();
    }

    //Al usar una pila los elementos estan en orden inverso, por tanto, usamos otra pila para recuperar
    //el orden inicial.
    while(!invierte.vacia()){

        revierte.push(invierte.tope());

        invierte.pop();
    } 

    //Tras corregir la inversion la asignamos a la pila original, la cual se queda podada
    P = revierte;

menor.posicion = 'B';//Corregimos la posicion
return menor;
}

/**
 * @brief Ordena los Cubiletes recibidos de la lista dada, haciendo unicamente uso del TAD PILA
 * @param 
 * @return PilaEnla<Cubilete> (Cubiletes ya en orden)
 */
PilaEnla<Cubilete>ordena_Cubiletes(PilaEnla<Cubilete>& P){

    auto p_aux = P;
    PilaEnla<Cubilete>resultado;

    while(!p_aux.vacia()){

        resultado.push(menor_cubilete(P));

    }
    
    return resultado;
}


int main(){

    Cubilete a(1234,'A'), b(23, 'B'), c(235, 'L');

    PilaEnla<Cubilete> p;
    p.push(a);
    p.push(b);
    p.push(c);

    auto r = ordena_Cubiletes(p);
    
    while(!r.vacia()){

        cout << r.tope().largo <<endl;

    r.pop();
    }

return 0;
}
