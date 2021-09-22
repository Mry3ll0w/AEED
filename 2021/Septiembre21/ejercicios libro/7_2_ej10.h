
#ifndef SEPTIEMBRE21_7_2_EJ10_H
#define SEPTIEMBRE21_7_2_EJ10_H
#include <iostream>
#include "../tads p/pila_enla.h"
/** EJERCICIO 10
 * Considerese la siguiente red ferroviaria de intercambio de
 * vías.
 * Los vagones de la via derecha, numerados 1,2,n, tienen que ser
 * llevado a la via izquierda en orden inverso mediante el uso
 * de la via muerta.
 */
 struct tren{
     std::string id;
 };
 class via_tren{
     PilaEnla<tren> derecha,muerta,izquierda;
 public:
     void mover_muerta(const tren& t){
         muerta.push(derecha.tope());
         derecha.pop();
     }
     void mover_izquierda(const tren& t){
         izquierda.push(derecha.tope());
         derecha.pop();
     }
     void muerta_a_izquierda(const tren& t){
         izquierda.push(muerta.tope());
         muerta.pop();
     }
 };

#endif //SEPTIEMBRE21_7_2_EJ10_H
