#include <iostream>
#include <string>
#include "ListaEnla.h"
using namespace std;//Avoid using std:: ....

/**
 * ENUNCIADO:
 * Una estascion se compone de N vias para el transito de:
 * - trenes (solo puede haber un tren en cada 1)
 * - Una via muerta para estacionamiento de trenes ==> trenes sin salida inmmediata
 * - Via muerta de Maniobras => Solo para el movimiento de trenes dentro de la estación
 * cuando sea necesario (ambas de capacidad ilimitada).
 * 
 * Tren se indentifica con un codigo de tren.
 * 
 * Operaciones de tren:
 * Crear una estacion de n vias de transito.
 * Llegada de un tren a una via libre dada.
 * Salida de la estacion del tren situado en una vía dada.
 * Llevar un tren determinado desde la vía dada a la via de estacionamiento.
 * Llevar un tren determinado dese la via de estacionamiento a una via de tránsito.
 * Vía en la que se encuentra un tren.
 * 
 * Suponiendo que ya tenemos la implementación de todo el tad anterior (lo de arriba).
 * Diseña una función que averigue el estado en el que se encuentra la estación a una hora
 * determinada (que trenes se encuentran en que vías), a partir de la información relativa al
 * horario de salidas y llegadas del tren-
 * 
 * 1) Diseña una estructura para almacenar la información relativa al horario de salidas y 
 * llegadas de trenes.
 * 
 * 2) Dada una estación y el horario de trenes (en orden creciente de horas y minutos), 
 * implementa una función que devuelva el estado de la estación a una hora determinada.
 * 
 * Suponemos que todos los trenes parten de la estación estan en alguna via, ya sea porque han 
 * efectuado su llegada previamente o bien porque se encontraban en la estación desde el 
 * principio del dia.
 * 
 */

struct Tren{
    string Hora_llegada, Hora_Salida, id;
    Tren(string h_l = "", string h_s="", string id_=""):Hora_llegada(h_l), 
    Hora_Salida(h_s), id(id_){}
};

struct Via{
    size_t capacidad;
    bool ilimitada;
    ListaEnla<Tren> v;
    Via(size_t c = 0, bool lim = false):capacidad(c), ilimitada(lim){}
    bool operator ==(const Via& v){}
};

class Estacion{
    ListaEnla<Via> vias_transito;
    Via Muerta, Muerta_Maniobra;
    public:
        Estacion(size_t n_transito=1){}//Crea n vias vacias
        void inserta_tren(const Via& v, const Tren t){}
        void sacar_tren_via(const Via &v, const Tren t){}
        void sacar_tren_estacion(const Tren& t){}
        const Via muerta(){return Muerta;}
        const Via muerta_maniobra(){return Muerta_Maniobra;}
        const ListaEnla<Via> vias_de_transito(){return vias_transito;}
};

//Funcion auxiliar para ver la hora
bool hora_menor(string h1, string h2){}

/**
 * @brief Dada una estación y el horario de trenes (en orden creciente de horas y minutos),
 * implementa una función que devuelva el estado de la estación a una hora determinada.
 */
void estado_estacion(Estacion  E, ListaEnla<string> Horario){

    Via muerta, m_muerta;

    muerta = E.muerta();
    m_muerta = E.muerta_maniobra();

    ListaEnla<Tren> han_salido, no_han_salido;

    cout<<"En via muerta: "<<endl;
    for(auto i = muerta.v.primera(); i != muerta.v.fin(); i = muerta.v.siguiente(i)){
        cout << muerta.v.elemento(i).id <<", " <<endl;
    }

    cout<<"En vias de maniobra muerta: "<<endl;
    for (auto i = m_muerta.v.primera(); i != m_muerta.v.fin(); i = m_muerta.v.siguiente(i))
    {
        cout << m_muerta.v.elemento(i).id << ", " << endl;
    }

    //Recorremos el horario (lista de horas)
    for(auto it_h = Horario.primera(); it_h != Horario.fin(); it_h = Horario.siguiente(it_h)){

        // Vemos como estan las vias de transito
        for (auto i = E.vias_de_transito().primera(); i != E.vias_de_transito().fin();
            i = E.vias_de_transito().siguiente(i))
        {
            auto via_actual = E.vias_de_transito().elemento(i).v;
            for (auto it_actual = via_actual.primera(); it_actual != via_actual.fin();
            it_actual = via_actual.siguiente(it_actual))
            {
                //si la hora es menor ==> no han salido los trenes
                if (hora_menor(Horario.elemento(it_h), via_actual.elemento(it_actual).id))
                {
                    no_han_salido.insertar(via_actual.elemento(it_actual), no_han_salido.fin());
                }
                else{//han salido los trenes
                    han_salido.insertar(via_actual.elemento(it_actual), han_salido.fin());
                }
                
            }
            
        }
    }

    //Tras dividir en los trenes que han salido y los que no simplemente los mostramos por 
    //pantalla
    cout<< "Los trenes que ya han salido son : "<<endl;
    for(auto i = han_salido.primera(); i != han_salido.fin(); i = han_salido.siguiente(i)){
        cout<<"Tren: "<<han_salido.elemento(i).id<<endl;
    }
    
    cout<<"Trenes que quedan por salir: "<<endl;
    for (auto i = no_han_salido.primera(); i != no_han_salido.fin(); i = no_han_salido.siguiente(i))
    {
        cout << "Tren: " << no_han_salido.elemento(i).id << endl;
    }
}

int main(){
    
return 0;
}