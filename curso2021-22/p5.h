//
// Created by @mry3ll0w on 07/12/2021.
//
//PRACTICAS DE COLAS
#ifndef CURSO2021_22_P5_H
#define CURSO2021_22_P5_H

#include <iostream>
#include <string> //Para la matricula de la avioneta
#include <cassert>//Para assert()
#include "tads_profesorado/Cola_Din.h"
#include "tads_profesorado/Cola_Cir.h"
#include "tads_profesorado/pila_vec.h"
#include "tads_profesorado/pila_enla.h"

template <class t>
std::ostream& operator<<(std::ostream& stream, ColaDin<t> c){
    while(!c.vacia()){
        stream << c.frente()<<", ";
        c.pop();
    }
    return stream;
}



/* EJERCICIO 1
 * Se dice que una pila es isomórfica a una cola cuando los elementos situados en posiciones
 * pares de la pila coinciden con los situados en posiciones impares de la cola.
 * Usando los TAD Pila y Cola, implemente una función que determine y devuelva si una
 * pila y una cola dadas son isomórficas o no.
 */
template <class t>
bool p5_ej1(ColaDin<t>c, PilaEnla<t>p){
    bool isomorfica=true;
    size_t pos=0;
    ColaDin<t>cola_impares,cola_pares;//Para mantener la distribucion original

    //Metemos los elementos de la cola
    for (int i = 0; !c.vacia() ; ++i) {
        if(i%2!=0){//Si no es divisible entre dos es par por tanto es impar
            cola_impares.push(c.frente());
        }
        c.pop();
    }
    //EN la pila deberemos obtener las posiciones impares tambien ya que al estar invertidas las pares seran impares
    for (int i = 0; !p.vacia() ; ++i) {
        if(i%2!=0){//Si no es divisible entre dos es par por tanto es impar
            cola_pares.push(c.frente());
        }
        c.pop();
    }
    //Comprobamos si coinciden
    while(!cola_impares.vacia() && !cola_pares.vacia() && isomorfica){
        if(cola_pares.frente() != cola_impares.frente())
            isomorfica = false;
        cola_impares.pop();
        cola_pares.pop();
    }

    return isomorfica;
}

/*
 * Escriba una función que dada una cola y dos elementos a y b, invierta la secuencia delimitada
 * por ambos dentro de ella. Dado que la cola puede tener elementos repetidos, se invertirá
 * la secuencia delimitada por la primera ocurrencia de a y b.
 *
 */
template <class t>
void p5_ej2(ColaDin<t>& c, const t& a, const t& b){
    assert(!c.vacia());//La cola no puede estar vacia
    PilaEnla<t>p_aux;
    ColaDin<t>c_antes_a;

    //Recorremos la cola hasta llegar al elemento buscado o acabar la pila
    while(!c.vacia()&& c.frente() != a){
        c_antes_a.push(c.frente());
        c.pop();
    }

    //Comprobamos que c no este vacia tras est
    while (!c.vacia() && c.frente()!=b){
        p_aux.push(c.frente());//metemos en la pila el intevalo entre a y b para invertirlo
        c.pop();
    }
    //Comprobamos que c no este vacia para meter b en la pila tambien

    if(!c.vacia()){
        p_aux.push(c.frente());//metemos b
        c.pop();
    }
    //metemos en ina cola auxiliar tras b
    ColaDin<t>tras_b;
    while(!c.vacia()){
        tras_b.push(c.frente());
        c.pop();
    }

    //Por ultimo copiamos el resto de contenidos en c (con [a.....b] invertidos
    while(!c_antes_a.vacia()){
        c.push(c_antes_a.frente());
        c_antes_a.pop();
    }

    //copiamos la inversion (en la pila0
    while(!p_aux.vacia()){
        c.push(p_aux.tope());
        p_aux.pop();
    }
    //metemos el resto tras b
    while(!tras_b.vacia()){
        c.push(tras_b.frente());
        tras_b.pop();
    }



}

/*
 * EJERCICIO 3
 * Se define una bicola o cola doble como una cola en la cual se pueden hacer inserciones y
 * borrados en ambos extremos.
 * Realice la especificación e implementación (mediante una estructura enlazada) del TAD
 * Bicola.
 * implementación en hpp aparte
 */

/**
 * Pereza pq es literalemente crear una clase con bicola como atributo
 */

/*
 * EJERCICIO 5
 * El estacionamiento de las avionetas en un aeródromo es en línea, con capacidad para 12
 * avionetas. Las avionetas llegan por el extremo izquierdo y salen por el derecho. Cuando
 * llega un piloto a recoger su avioneta, si ésta no está justamente en el extremo de salida
 * (derecho), todas las avionetas a su derecha han de ser retiradas, sacar la suya y las retiradas
 * colocadas de nuevo en el mismo orden relativo en que estaban. La salida de una avioneta
 * supone que las demás se mueven hacia adelante, de tal forma que los espacios libres del
 * estacionamiento estén en la parte izquierda (entrada).
 * Implemente un subprograma que emule el estacionamiento. Este subprograma, además del
 * aeródromo, recibirá un código de acción sobre una avioneta, y la matrícula de la misma.
 * La acción puede ser entrada (E) o salida (S) de avioneta. En la llegada puede ocurrir que
 * el estacionamiento esté lleno; si es así, la avioneta espera hasta que se quede una plaza
 * libre o hasta que se le dé la orden de retirada (salida).

    Datos:
        -Aerodromo en linea en forma de cola de 12 elementos

        -A la hora de sacar el avion si no esta en el tope se deberan sacar todas las anteriores al mismo
        y entonces sacar el avion.

        - Tendra una funcion accion que dira que debe hacer , esta recibe 2 E o S y el id de la avioneta.

        -Existe una cola de espera, en caso de que este llena se va alli.

    Se necesita:
        - Struct avioneta
        - clase aerodromo
            ·Funcion de accion, cola aerodromo y cola de espera, ctor y destr
 */

typedef std::string avioneta;//Solo necesitamos almacenar la matricula

class aerodromo{
private:
    size_t ocupados;
    ColaCir<avioneta> pista;//Tamaño maximo 12
    ColaDin<avioneta> espera;//No especifica nada del tamaño asi que entiendo que ilimitado
public:
    aerodromo(const size_t& size_pista = 12):pista(ColaCir<avioneta>(size_pista)),ocupados(0){};
    //~aerodromo();
    void accion(const char& op,const avioneta& a);
    void print_aerodromo(){
        //std::cout<<pista<<std::endl;
    }
};

void aerodromo::accion(const char& op,const avioneta&a){
    assert(op == 'e' | op=='s');//Tiene que ser igual a alguna de las operaciones validas

    if(op == 's'){
        //1)Comprobamos aerodromo esta vacio
        assert(!pista.vacia());
        //2)Comprobamos que el avion este en la posicion de salida
        if(a == pista.frente()){

            pista.pop();
            std::cout<<"El avion con matricula "<<a<<" ha partido de pista"<<std::endl;
        }
        else{//El avion esta en la pista pero en otra posicion
            ColaCir<avioneta> parser = ColaCir<avioneta>(12);//En el peor caso el avion no esta
            ColaDin<avioneta> resto ;
            //Copiamos la pista hasta sacar el avion que toca
            while(!pista.vacia() && pista.frente()!=a){
                parser.push(pista.frente());
                pista.pop();
            }

            if(!pista.vacia()){
                pista.pop();
                std::cout<<"El avion con matricula "<<a<<" ha partido de pista"<<std::endl;
                ocupados --;//decrementamos ocupados
            }
            else{
                std::cout<<"El avion no esta en pista ";
            }
            //Copiamos lo que quede en la cola en otra
            while(!pista.vacia()){
                resto.push(pista.frente());
                pista.pop();
            }
            //Restauramos la cola original
            while(!parser.vacia()){
                pista.push(parser.frente());
                parser.pop();
            }

            while(!resto.vacia()){
                pista.push(resto.frente());
                resto.pop();
            }

        }
    }
    else if(op == 'e'){
        //Comprobamos que exista huecos libres en la pista, si no se va la cola de espera
        if(ocupados < 12){
            pista.push(a);
            std::cout<<"El avion "<<a<< " ha aterrizado en pista"<<std::endl;
        }
        else{
            espera.push(a);//Se mete en la lista de espera
            std::cout<<"Avion "<<a<<" se ha introducido en cola de espera"<<std::endl;
        }
    }

}



/*
 * Se reparten las cartas de la baraja española en diez montones de cuatro cartas cada uno.
 * Cada montón se corresponde con una de las diez figuras de la baraja. Se escoge uno de los
 * montones al azar y se extrae la carta de dicho montón que esté en la cima. Esta carta se
 * coloca al final del montón correspondiente a la figura que represente, extrayéndose ahora
 * la primera carta de este montón. Este ciclo se repite hasta llegar a un montón en el que
 * las cuatro cartas de la figura correspondiente han sido colocadas.
 * El juego se considera acabado con éxito si los cuatro reyes están en su montón.
 */
void solitario_reyes(){


    //Variables
    enum palo{basto, espada, copa, oro};
    string palos[] ={"basto","espada","copa","oro"};

    struct carta{
        int n;
        unsigned p;
        carta(int n_=0,unsigned p_=0):n(n_),p(p_) {}
    };

    std::vector<carta> baraja;
    PilaVec<carta>maze(48);


    //inicializamos la baraja
    for (int i = 0; i < 4 ; ++i) {//De cada palo
        for(int j = 1; j <=12 ; ++j){
            baraja.emplace_back(carta(j,i));
        }
    }
    //Hacemos un random shuffle a la baraja para mezclar las cartas (esta es la version mas segura de random shuffle)
    std::shuffle(baraja.begin(), baraja.end(), std::random_device());


    //Inicializar maze
    for(auto i:baraja)
        maze.push(i);



    //necesitamos una estructura monton
    struct monton{
        ColaCir<carta>m;
        size_t cont_cartas;
        monton():m(ColaCir<carta>(4)),cont_cartas(0){}

    };

    std::vector<monton>montones(12);//del as al 12

    //Inicializo los montones metiendo las cartas aleatorias de la baraja
    size_t it_montones = 0;
    while(!maze.vacia()){

        for(size_t i = 0; i < 4;++i){

            montones[it_montones].m.push(maze.tope());
            maze.pop();
        }

        ++it_montones;
    }

    //INICIO DEL ALGORITMO
    bool victoria = false;
    //1) Vemos que ya no exista 4 cartas en alguno de los montones

    //Algoritmo del juego
    //Empezamos con un numero aleatorio asi que seleccionamos el primer numero de la primera carta
    size_t selecciona_monton = baraja[0].n;

     while(!victoria){

         //Contamos las cartas para ver si se ha llegado
         for(auto i : montones){

             ColaCir<carta>temp=i.m;
             size_t cont_temp=0;
             size_t num_carta = temp.frente().n;
             //Contar cuantas cartas iguales hay
             while(!temp.vacia()){
                 std::cout <<temp.frente().n<<" de "<<palos[temp.frente().p]<<std::endl;
                 if(temp.frente().n==num_carta)
                     cont_temp++;

                 temp.pop();
             }
             std::cout<<std::endl;
             std::cout<<std::endl;
             i.cont_cartas = cont_temp;
             if (cont_temp==4){
                 victoria = true;
                 break;
             }

         }

         //Seleccion del monton
         //Correccion para no segmentation fault
         if (selecciona_monton == 12){
             selecciona_monton--;//Lo ponemos a 11 ya que falta
         }

        //Algoritmo de colocacion de carta
        carta parser_carta= montones[selecciona_monton].m.frente();
        montones[selecciona_monton].m.pop();//Sacamos la carta
        //metemos la carta en el monton
        montones[selecciona_monton].m.push(parser_carta);
        //actualizamos el selector de monton
        selecciona_monton = parser_carta.n;

     }



}


#endif //CURSO2021_22_P5_H
