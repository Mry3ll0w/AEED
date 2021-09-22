#include <iostream>
#include "tads implementados profesorado/pila_enla.h"
#include <string>
#include <algorithm>
//Asumimos que nos dan el volumen de los cubos (no tenemos otra para ver si son mas grandes que otros ya que largo no tiene pq ser = ancho)
typedef struct cubiletes
{   
    std::string orientacion;
    double volumen;    //Contiene la medida de los distintos lados
};
//Nos dicen que la solucion debe estar enteramente basada en el tad pila
/**
 * @brief Recibe una pila de cubos y los ordena en orden ascendente (de mayor a menor)
 * 
 * @param p E/S, la pila se recibira en un orden y se devolvera en el orden solicitado
 * @post Devuelve la pila ordenada
 */
void ordena(PilaEnla<cubiletes> &p){
    cubiletes* vec_cubiletes;
    PilaEnla<cubiletes> temp=p;//Copiamos los elementos del cubiletes
    size_t vec_size;
    size_t vec_iterator;
    while (p.vacia()!=true)
    {
        vec_size++;//Comprobamos el size de la pila para la reserva de memoria
    }
    vec_cubiletes = new cubiletes[vec_size];//Reservamos el espacio para almacenar los cubiletes
    
    while (temp.vacia()!=true)//Metemos los elementos de la pila en cualquier orden 
    {
        if (temp.tope().orientacion!=std::string("abajo"))
        {
            cubiletes t_cubilete;
            t_cubilete.orientacion="abajo";
            t_cubilete.volumen=temp.tope().volumen;
            //Al ser const el string tenemos que crear uno temporal para insertarlo en el vector
            vec_cubiletes[vec_iterator]=t_cubilete;
        }
        else{
            vec_cubiletes[vec_iterator]=temp.tope();
        }
        ++vec_iterator;
        temp.pop();//vamos iterando la pila y el vector
    }
    //Ordena en orden menor a mayor los cubiletes
    for (size_t i = 0; i <vec_size; i++)
    {

        for ( int j=0; j<vec_size-1; j++){
          if (vec_cubiletes[j].volumen > vec_cubiletes[j+1].volumen){
            std::swap(vec_cubiletes[j],vec_cubiletes[j+1]);
            } 
        }   
    }
    
    //Al estar en orden inverso cuando los metamos en la pila estaran de mayor a menor (como lo solicitan)
    for (size_t i = 0; i < vec_size; i++)
    {
        p.push(vec_cubiletes[i]);
    }//Metemos en la pila en el orden solicitado
    
}

