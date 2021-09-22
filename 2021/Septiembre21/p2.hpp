#ifndef P2_HPP
#define P2_HPP	
#include <iostream>
#include "tads p/Cola_Din.h"
#include <cassert>
/* El estacionamiento de las avionetas en un aeródromo es en línea, con capacidad para 12
avionetas. Las avionetas llegan por el extremo izquierdo y salen por el derecho. Cuando
llega un piloto a recoger su avioneta, si esta no está justamente en el extremo de salida
(derecho), todas las avionetas a su derecha han de ser retiradas, sacar la suya y las retiradas
colocadas de nuevo en el mismo orden relativo en que estaban. La salida de una avioneta
supone que las demás se mueven hacia adelante, de tal forma que los espacios libres del
estacionamiento estén en la parte izquierda (entrada).
Implemente un subprograma que emule el estacionamiento. Este subprograma, además del
aeródromo, recibirá un código de acción sobre una avioneta, y la matrícula de la misma.
La acción puede ser entrada (E) o salida (S) de avioneta. En la llegada puede ocurrir que
el estacionamiento esté lleno; si es así, la avioneta espera hasta que se quede una plaza
libre o hasta que se le dé la orden de retirada (salida).
*/
struct avion {
    size_t matricula;
    bool espera;
};
class aerodromo
{
private:
    size_t size;
    ColaDin<avion>pista;  
public:
    aerodromo(size_t tam_):size(tam_){}
    ~aerodromo()=default; /* ya que no es necesario destructor para elementos de memoria dinamica  */
    void accion(char operacion,avion& a);
    void show_pista();
};

inline void aerodromo::accion(char operacion,avion& a) {
    assert(operacion=='s' || operacion=='e');
    if (operacion == 's')
    {
        ColaDin<avion>t1=pista;

        while(!pista.vacia()){
            if (pista.frente().matricula != a.matricula)
            {

                t1.push(pista.frente());
            }
            pista.pop();
        } 
        /* Sacamos el avion desado y lo guardamos t1 en pista */
        pista = t1;
        ++size; //l sacar un avion de la pista 
    }
    if (operacion == 'e') 
    {
        if (size > 0)
        {            pista.push(a);
            ++size;
        }
        else if (size <= 0){
            a.espera = true;
            std::cout<<"La cola esta llena"<<std::endl;
        }
    }    
}

void aerodromo::show_pista() {
    ColaDin<avion> temp = pista;
    while (!temp.vacia())
    {
        std::cout<<temp.frente().matricula<<std::endl;
        temp.pop();
    }
    std::cout<<std::endl;
}


#endif