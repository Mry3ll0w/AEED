#ifndef TAD_ESTACION_HPP
#define TAD_ESTACION_HPP
#include<iostream>
#include<string>
#include "tads implementados profesorado/Cola_Din.h"
#include "tads implementados profesorado/ListaEnla.h"
/**
 * ESPECIFICACION TAD TREN
 * El tad se usara para representar una estacion de tren con sus respectivas vias (transito,
 * muerta de estacionado y de maniobras)
 * 
 * ESPECIFICACION METODOS DE LAS CLASES
 * 
 * estacion(size_t n):
 *      -Precondicion==> Recibe una n con el numero de vias de transito
 *      -Postcondicion==> Construye una estacion con n vias de transito
 * 
 * llega_tren(ColaDin<tren>& v, const tren& t)
 *      -Precondicion==> Recibe una via donde va el tren (t) , la via de transito ha de estar libre
 *      -Postcondicion==> Add un tren a una via de transito
 * 
 * salida_tren(const tren& t)
 *      -Precondicion==> Debe existir el tren t en alguna de las vias
 *      -Postcondicion==> Saca el tren de la estacion
 * 
 * mover_tren(const tren& t, ColaDin<tren>& via_destino)
 *      -Precondicion==> Deben existir una via  y un tren en alguna de las vias de transito
 *      -Postcondicion==> Mueve el tren a la via destino especificada desde una via de movimiento
 * 
 * ColaDin<tren>& buscar_tren(const tren& t)
 *      -Precondicion==> Deben existir un tren en alguna de las vias
 *      -Postcondicion==> devuelve la via donde esta localizado el tren t 
 * 
 * codigo_tren_via(const tren& t, const ColaDin<tren>via)
 *      -Precondicion==> Deben existir una via con ese nombre y un tren en alguna de las vias de transito
 *      -Postcondicion==> Devuelve el codigo del tren con esa id en esa via
 *
 */

//Diseñe y defina una estructura de datos para almacenar informacion relativa al horario de llegada y salida de un tren
typedef struct hora{
    size_t horas,minutos;
};
typedef struct horario{
    hora llegada;
    hora salida;
};
typedef struct tren{
    std::string id;
    horario h;
};
//asumo que el private de la clase estacion de tren esta implementada con una lista estatica de n colas(vias)
ListaEnla<ColaDin<tren>>vias_transito;
ColaDin<tren>via_estacionamiento,via_maniobras;
//C) Funcion que muestre el estado de la estacion a una hora concreta
void estado_estacion(const hora& h){

    auto pos = vias_transito.primera();
    while (pos!=vias_transito.fin())//Recorremos las n vias de transito para ver el estado de cada tren
    {
        ColaDin<tren> temp_v=vias_transito.elemento(pos);
        while(temp_v.vacia()!=true){//Recorremos la via de transito para mostrar los trenes disponibles en ese horario
            if (temp_v.frente().h.llegada.horas>h.horas)
            {
                std::cout<<temp_v.frente().id<<std::endl;
            }
            else if(temp_v.frente().h.llegada.horas==h.horas){
                if (temp_v.frente().h.llegada.minutos>h.minutos)
                {
                    std::cout<<temp_v.frente().id<<std::endl;
                }
                
            }
            temp_v.pop();
        }
        
        pos=vias_transito.siguiente(pos);
    }
    //Mostramos indistintamente los trenes de la vias de maniobra y estacionamiento
    ColaDin<tren>temp_vias_estaticas;
    //Recorremos la pila de estacionamiento
    temp_vias_estaticas=via_estacionamiento;
    while (temp_vias_estaticas.vacia()!=true)
    {
        std::cout<<temp_vias_estaticas.frente().id<<std::endl;
        temp_vias_estaticas.pop();
    }
    //Mostramos Vias maniobra
    temp_vias_estaticas=via_maniobras;
    while (temp_vias_estaticas.vacia()!=true)
    {
        std::cout<<temp_vias_estaticas.frente().id<<std::endl;
        temp_vias_estaticas.pop();
    }
    
}

#endif