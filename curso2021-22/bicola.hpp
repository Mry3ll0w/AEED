#include <iostream>
#include <cassert>
//Se define una bicola o cola doble como una cola en la cual se pueden hacer inserciones y
//borrados en ambos extremos.
//Realice la especificación e implementación (mediante una estructura enlazada) del TAD
//Bicola.
template <class t>
class Bicola{

private:

    struct nodo
    {
        t elto;
        nodo* sig;
        nodo(const t& e, nodo* p = 0) : elto(e), sig(p) {}
    };

    nodo* inicio, * fin; // extremos de la cola

public:
    Bicola():inicio(0), fin(0){}//Ctor de clase
    Bicola(const Bicola<t>& C); // ctor. de copia
    Bicola<t>& operator =(const Bicola<t>& C); // asignacion de colas
    bool vacia() const{
        return inicio == 0; //Si fin == inicio entonces la cola estara vacía
    }
    //Devuelve el inicio de la cola
    const t& frente() const;

    //Elimina el ultimo elemento de la cola (LIFO)
    void pop();

    //Elimina el primer elemento de la cola
    void pop_front();

    //Inserta el elemento por el principio de la cola
    void push(const t& x);

    //Inserta el elemeto por el final de la cola
    void push_back(const t& x);


    // destructor de clase
    ~Bicola();

};

template<class t>
Bicola<t>::~Bicola() {
    nodo *p;
    while (inicio!=NULL){
        p = inicio->sig; // metemos el
        delete inicio;
    }
    fin =0 ; //Un poco redundante pero por respetar la implementación original se usa
}

template<class t>
const t &Bicola<t>::frente() const {
    assert(inicio!=NULL);
    return inicio->elto;
}

template<class t>
void Bicola<t>::pop() {
    // a -> b -> c -> d
    assert(!vacia());//La cola no puede estar vacia
    nodo* p = inicio; // inicio se va desplazando en cada una de las inserciones
    inicio = inicio->sig;
    //Si inicio es null entonces el fin se pone a 0 para ser eliminado
    if(!inicio)
        fin = 0;
    //Se elimina p
    delete p;
}

template <class t>
void Bicola<t>::push(const t& x){

    nodo * p = nodo(x);
    //Cola vacia
    if(inicio == NULL){
        inicio = fin = p;
    }
    else{
        fin = fin->sig;//itero el fin
        fin = p; // apunto al ultimo elemento
    }

}

template<class t>
void Bicola<t>::pop_front() {
    assert(!vacia());//Para hacer pop no puede estar vacia

    nodo* p = fin;
    fin = fin->sig;

    delete p;
}

template<class t>
void Bicola<t>::push_back(const t &x) {

    nodo *p = nodo(x);
    if(inicio == NULL){//Cuando la cola esta vacia
        inicio = fin = p;
    }
    else{

        inicio= inicio->sig;
        inicio = p;

    }

}
