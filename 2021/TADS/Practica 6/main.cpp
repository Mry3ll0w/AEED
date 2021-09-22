#include <iostream>
#include <ctime>
#include "ListaEnla.h"
#include "numerobinario.h"
using namespace std;
//Devuelve un numero aleatorio dentro de un rango
int num_aleatorio(int a, int b){
    srand(time(NULL));
    return rand() % (b - a + 1) + a;
}
ListaEnla<int> ej2(ListaEnla<int>);
ListaEnla<int> ej3(int);
ListaEnla<int> ej4(ListaEnla<int>, ListaEnla<int>);
void ej5();
//void ej6();
void ej9();


int main() {
    ej9();
    return 0;
}

/* El ejercicio uno es de implementar una lista circular y no aparece en los examenes */

/*
 * Una lista ordenada es una lista en la cual los elementos están ordenados de forma ascendente según
 * la relación de orden definida entre ellos. Especifique e implemente el TAD Lista ordenada.
 */
ListaEnla<int> ej2(ListaEnla<int>l1) {

/*FORMA DE INSERTAR ELEMENTOS EN LA PILA*/
    int it=0,v[9];
    for (ListaEnla<int>::posicion pos = l1.primera(); pos != l1.fin() ; pos=l1.siguiente(pos)) {
        v[it]=l1.elemento(pos);
        it++;
    }
    //Comenzamos la copia de datos a un vector auxiliar para ordenarlos (Con selección directa)
    for ( int i=0; i<9 ;i++ ){
        for ( int j=i; j<9; j++){
            if (v[i]>v[j])
            {
                int aux=v[j];
                v[j]=v[i];
                v[i]=aux;
            }
        }
    }
    it=0;
    for (ListaEnla<int>::posicion pos = l1.primera(); pos != l1.fin() ; pos=l1.siguiente(pos)) {
        l1.elemento(pos)=v[it];
        it++;
    }
    ej5();
    return l1;
}

/*
* Implemente una función que tenga como entrada una lista de enteros y un entero x, de
* forma que devuelva la lista modificada mediante la eliminación de todas las ocurrencias
* de x en la lista.
*/
ListaEnla<int> ej3(int ocurrencia) {
    ListaEnla<int> l1,l2;
    //Introducimos los elementos a la lista
    for (int i = 0; i < 9 ; ++i) {
        l1.insertar(i+1,l1.fin());
    }
    while (l1.fin()!=l1.buscar(ocurrencia)){
        l1.eliminar(l1.buscar(ocurrencia)); //Elimina todas las ocurrencias en la posición
    }
    l2 = l1;
    return l1;
}

ListaEnla<int> ej4(ListaEnla<int> l1, ListaEnla<int>l2) {
    ListaEnla<int> l3;
    for(ListaEnla<int>::posicion pos = l1.primera(); pos != l1.fin() ; pos=l1.siguiente(pos)){
        l3.insertar(l1.elemento(pos),l3.fin());
    }
    for(ListaEnla<int>::posicion pos = l2.primera(); pos != l2.fin() ; pos=l2.siguiente(pos)){
        l3.insertar(l2.elemento(pos),l3.fin());
    }
    return l3;
}
/*
Implemente una función ImprimeInverso() que imprima los elementos de una lista simplemente enlazada de enteros
en orden inverso a partir de la posición p.
*/
void ej5() {
    ListaEnla<int> l;
    for (int i = 0; i < 7 ; ++i) {
        l.insertar(num_aleatorio(1,45), l.fin());
    }
    cout<<"Orden normal"<<endl;
    for (ListaEnla<int>::posicion pos = l.primera(); pos != l.fin() ; pos=l.siguiente(pos)) {
        cout<<l.elemento(pos)<<", ";
    }
    cout<<endl;
    cout<<"Orden iverso"<<endl;
    ListaEnla<int>::posicion pos_aux;
    for(ListaEnla<int>::posicion pos = l.anterior(l.fin()); pos != l.primera() ; pos = l.anterior(pos)){
        cout<<l.elemento(pos)<<", ";
        pos_aux = pos;
    }
    cout<<l.elemento(l.anterior(pos_aux))<<endl;
    l.~ListaEnla();
}

/*
 * Implemente una función que concatene una lista de listas (TAD Lista cuyo tipo de elementos es a su vez una lista
 * de elementos de cierto tipo T), de forma que a partir de la lista original, llamada LInic (lista de listas),
 *  se obtenga una nueva lista, llamada LConcat (lista de elementos T).
*/
/*
void ej6() {
    ListaEnla <ListaEnla<int>> l_concat,l_inic,l_l_aux;
    ListaEnla <int> l1,l2,l3,l4;
    //Rellenamos las 3 listas de ejemplo
    for (int i = 0; i < 7 ; ++i) {
        l1.insertar(i+1, l1.fin());
        l2.insertar(i+1, l2.fin());
        l3.insertar(i+1, l3.fin());
        l4.insertar(i+1, l4.fin());
    }
    l_inic.insertar(l1, l_inic.fin());
    l_inic.insertar(l2, l_inic.fin());
    l_inic.insertar(l3, l_inic.fin());
    l_l_aux.insertar(l4, l_l_aux.fin());

    //Iniciamos la concatenación de la primera
    for (ListaEnla<ListaEnla<int>>::posicion pos = l_inic.primera(); pos != l_inic.fin() ; pos=l_inic.siguiente(pos)) {
        l_concat.insertar(l_inic, pos);
    }
    for (ListaEnla<ListaEnla<int>>::posicion pos = l_l_aux.primera() ; pos != l_l_aux.fin() ; pos =l_l_aux.siguiente(pos) ) {
        l_concat.insertar(l_l_aux, l_concat.fin());
    }

}
*/ //Implementado pero falla en el constructor

void ej9() {
    //Definimos la estructura necesaria para implementar los jugadores
    typedef struct {
        int n_asociado;
    } player;
    typedef struct {
        ListaEnla<player> jugadores;
        int jugadores_en_partida = 6;
    } partida;
    partida game;
    player participantes[6];
    int i;
    ListaEnla<player>::posicion pos = game.jugadores.primera(); // Inicializamos el cursor de la lista en la primera posicion
    //Declaracion de variables,tipos, ...
    participantes[0].n_asociado =1;participantes[1].n_asociado =2;participantes[2].n_asociado =3;participantes[3].n_asociado =4;participantes[4].n_asociado =5;participantes[5].n_asociado =6;
    for (int j = 0; j < 6; ++j) {
        game.jugadores.insertar(participantes[j], game.jugadores.fin());
    }
    //Metemos los valores aleatorios de los jugadores y los insertamos en la lista par comenzar el juego
    //Cogemos un jugador al azar (el primero por comodidad)

    while (game.jugadores_en_partida > 1) {
        i = game.jugadores.elemento(pos).n_asociado;// salvamos el numero del jugador a eliminar
        game.jugadores.eliminar(pos); //eliminamos el jugador en esa posicion
        //Comprobamos que el numero sea par/impar
        if (!(i % 2)) {//si el modulo es 0 ==> el numero es par,desplazamiento a la derecha

            for (int j = 0; j < i ; ++j) {
                if (game.jugadores.siguiente(pos)==game.jugadores.fin())(pos=game.jugadores.primera());
                pos=game.jugadores.siguiente(pos);
            }
        } else {// es impar
            for (int j = 0; j < i ; ++j) {
                if (game.jugadores.siguiente(pos)==game.jugadores.primera())(pos=game.jugadores.anterior(game.jugadores.fin()));
                pos=game.jugadores.siguiente(pos);
            }
        }
        cout<<game.jugadores_en_partida-1<<endl;
        game.jugadores_en_partida--; //Cada vez que se ejecute un ciclo se elimina un jugador, por tanto iremos decrementando
    }
    //MUESTRA EL JUGADOR GANADOR
    cout << "Ha quedado un jugador con la posicion"<<game.jugadores.elemento(pos).n_asociado<<endl; //NO RECORRE TODA LA LISTA REPLANTEAR
}

!= ==> ->