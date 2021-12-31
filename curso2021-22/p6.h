//
// Created by @MrY3ll0w on 23/12/2021.
//

#ifndef CURSO2021_22_P6_H
#define CURSO2021_22_P6_H

#include "tads_profesorado/pila_enla.h"
#include <iostream>
#include "tads_profesorado/ListaEnla.h"

//Sobrecarga de operador de insercion en cout
template <class t>
std::ostream& operator<<(std::ostream& os,const ListaEnla<t>& l ){
    auto it = l.primera();
    while(it != l.fin()){
        os<<l.elemento(it)<<" ";
        it= l.siguiente(it);
    }
    return os;
}

//Rehacer la lista ordenada

/*
 * EJERCICIO 3
 * Implemente una función que tenga como entrada una lista de enteros y un entero x, de
 * forma que devuelva la lista modificada mediante la eliminación de todas las ocurrencias
 * de x en la lista.
 */
template <class t>
ListaEnla<t> p6_ej3(const ListaEnla<t>&input,const t& ocurrencia){

    ListaEnla<t> l;
    auto it = input.primera();
    auto it_l = l.fin();

    while (it != input.fin()){

        if(ocurrencia != input.elemento(it))
            l.insertar(input.elemento(it),it_l);

        it = l.siguiente(it);
    }

return l;

}

/*
 * EJERCICIO 4
 * Dadas dos listas de enteros ordenadas, implemente una función que devuelva una tercera
 * lista ordenada con la mezcla de las dos listas de entrada
 */
template <class t>
ListaEnla<t> p6_ej4(const ListaEnla<t>& a, const ListaEnla<t>& b){

    ListaEnla<t> destino;
    auto it_a= a.primera();
    auto it_b= b.primera();
    auto it_dest = destino.fin();//No sirve de mucho pero
    destino.insertar(a.elemento(a.primera()),it_dest);


    while (it_a != a.fin()){

        it_dest = destino.primera();
        for(;it_dest!= destino.fin() && destino.elemento(it_dest)<a.elemento(it_a);it_dest=destino.siguiente(it_dest));
        destino.insertar(a.elemento(it_a),it_dest);

        it_a = a.siguiente(it_a);
    }


    while (it_b != b.fin()){
        it_dest = destino.primera();
        for(;it_dest!= destino.fin() && destino.elemento(it_dest)<b.elemento(it_b);it_dest=destino.siguiente(it_dest));
        destino.insertar(a.elemento(it_b),it_dest);
        it_b = a.siguiente(it_b);
    }



return destino;
}

/*
 * EJERCICIO 5
 * Implemente una función ImprimeInverso() que imprima los elementos de una lista simplemente enlazada de enteros
 * en orden inverso a partir de la posición p.
 */
template <class t>
void p6_ej5(const ListaEnla<t>& l,typename ListaEnla<t>::posicion p){
    PilaEnla<t>pila;
    auto i = l.primera();

    while (i != p){

        std::cout<<l.elemento(i)<<" ";
        i=l.siguiente(i);
    }

    while(i!=l.fin()){
        pila.push(l.elemento(i));
        i=l.siguiente(i);
    }

    while(!pila.vacia()){
        std::cout<<pila.tope()<<" ";
        pila.pop();
    }
    std::cout<<std::endl;

}

/*
 * EJERCICIO 6
 * Se quiere representar el TAD Conjunto de tal forma que los elementos estén almacenados
 * en una secuencia de celdas enlazadas.
 * Especifique e implemenente el TAD Conjunto, representado mediante celdas enlazadas,
 * con las siguientes operaciones:
 *      - conjunto vacío
 *      - añadir un elemento al conjunto,
 *      - quitar un elemento si pertenece al conjunto
 *      - unión
 *      - intersección
 *      - diferencia de conjuntos
 */
template <class t>
class conjunto{
private:
    ListaEnla<t> c;
public:
    conjunto()=default;
    void add_elemento(const t& x);
    void conversion_conjunto_vacio();
    void eliminar_elemento_conj(const t& e);
    void union_(const conjunto& c);
    void interseccion(const conjunto& c);
    bool es_vacio(){return c.vacia();}

};

template<class t>
void conjunto<t>::add_elemento(const t &x) {
    auto fin= c.fin();
    c.insertar(x,fin);
}

template<class t>
void conjunto<t>::conversion_conjunto_vacio() {
    c = ListaEnla<t>();//Igualo el conjunto a una lista vacia
}

template<class t>
void conjunto<t>::eliminar_elemento_conj(const t &e) {
    auto pos_borrado = c.buscar(e);
    if(pos_borrado!=c.fin()){//Si es igual al fin no esta el elemento, por tanto no se elimina
        c.elemento(pos_borrado);
    }
}

template<class t>
void conjunto<t>::union_(const conjunto & conj) {
    auto it_c = conj.c.primera();
    auto it_insercion = c.fin();

    while(it_c != conj.c.fin()){
        c.insertar(conj.elemento(it_c),it_insercion);

        it_c = conj.c.siguiente(it_c);
    }
}

template<class t>
void conjunto<t>::interseccion(const conjunto &conj) {
    auto it_c = conj.c.primera();
    auto it_insercion = c.fin();

    while(it_c != conj.c.fin()){
       if( c.buscar(conj.c.elemento(it_c))!=c.fin() )
           c.insertar(conj.elemento(it_c),it_insercion);
        it_c = conj.c.siguiente(it_c);
    }
}

/*
 * EJERCICIO 7
 * Implemente una función que concatene una lista de listas (TAD Lista cuyo tipo de elementos es a su vez una lista
 * de elementos de cierto tipo T), de forma que a partir de la lista original, llamada LInic (lista de listas),
 * se obtenga una nueva lista, llamada LConcat (lista de elementos T)
 */
template<class t>
ListaEnla<t> p6_ej7(const ListaEnla<ListaEnla<t>>& l){

    ListaEnla<t> dest;
    for(auto it = l.primera(); it != l.fin();it=l.siguiente(it)){

        for(auto i = l.elemento(it).primera(); i != l.elemento(it).fin();i=l.elemento(it).siguiente(i)){
            dest.insertar(l.elemento(it).elemento(i),dest.fin());
        }
        
    }
return dest;
}

/*
 * EJERCICIO 8
 * TAD NUMERO BINARIO
 *
 * Constructor: Genera un número binario a partir de una cadena de caracteres con
 * ceros y unos.
 *      Precondicion==> Recibe una cadena de caracteres (std::string) compuesta por 0 y 1 y excepto NOT los numeros
 *      tienen que tener igual size.
 *      Postcondicion==> Inicializa el numero binario
 *
 * Operaciones lógicas de bits NOT, AND, OR inclusivo y OR exclusivo.
 *      Precondiciones==> Al tener todos un unico elemento como operador todos tienen la misma precondicion
 *
 * Desplazamiento a la izquierda n bits. Cada bit se desplaza n posiciones a la izquierda,
 * introduciendo ceros por la derecha y desechando los n bits de la izquierda.
 *
 * Desplazamiento a la derecha n bits. Se añaden n ceros por la izquierda y se desechan
 * los n bits de la derecha.
 */
class binario{
private:
    ListaEnla<char>num;
    size_t size;
public:
    explicit binario(const std::string & s=" ");
    void NOT();
    void OR(const binario & b);
    void AND(const binario & b);
    void OR_exclude(const binario & b);
    void desp_izq(const size_t& n);
    void desp_der(const size_t& n);

};

binario::binario(const string &s):size(s.size()) {

    auto final = num.fin();
    for(auto i : s){
        num.insertar(i,final);
    }

}

void binario::NOT() {
    for (auto i = num.primera(); i != num.fin() ; i=num.siguiente(i)) {
        if (num.elemento(i)=='1')
            num.elemento(i) = '0';
        else
            num.elemento(i) = '1';
    }
}

void binario::OR(const binario &b) {
    assert(size==b.size);
    auto it_a=num.primera();
    for (auto it_b =b.num.primera();it_b != b.num.fin();it_b=b.num.siguiente(it_b)) {

        if(num.elemento(it_a)=='0' && b.num.elemento(it_b)=='1')
            num.elemento(it_a)='1';

        it_a=num.siguiente(it_a);
    }

}

void binario::AND(const binario &b) {

    assert(size==b.size);
    auto it_a=num.primera();
    for (auto it_b =b.num.primera();it_b != b.num.fin();it_b=b.num.siguiente(it_b)) {

        if(num.elemento(it_a)!= b.num.elemento(it_b))
            num.elemento(it_a)='0';

        it_a=num.siguiente(it_a);
    }

}

void binario::OR_exclude(const binario &b) {
    assert(size==b.size);

    auto it_a=num.primera();
    for (auto it_b =b.num.primera();it_b != b.num.fin();it_b=b.num.siguiente(it_b)) {

        if(num.elemento(it_a)== b.num.elemento(it_b)==1)
            num.elemento(it_a)='0';

        it_a=num.siguiente(it_a);
    }

}

void binario::desp_izq(const size_t &n) {
    size+=n;//Aumenta
    auto p = num.primera();

    //Mete los distintos ceros a la izquierda
    for(size_t i=0; i< n && p!= num.fin() ; ++i){

        num.elemento(p)=0;

        p=num.siguiente(p);
    }

}

void binario::desp_der(const size_t &n) {
    size+=n;//Aumenta
    auto p = num.fin();

    //Mete los distintos ceros a la izquierda
    for(size_t i=0; i< n && p!= num.primera() ; ++i){

        num.elemento(p)=0;

        p=num.anterior(p);
    }

}


#endif //CURSO2021_22_P6_H
