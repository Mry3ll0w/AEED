// Created by anton on 17/11/2020
#ifndef PILA_GENERICA_PILA_H
#define PILA_GENERICA_PILA_H
#include <cassert>
#include <iostream>

using namespace std;
template <typename typo>
class PILA {
    public:
        explicit PILA(int size);
        void push (const typo& x);
        typo pop ();
        bool vacia()const;
        bool llena()const;
        void contenido()const;
        void contenido(unsigned)const;
        void copia(PILA& a,PILA& b);
        unsigned desp(){return desplazamiento;};
        unsigned tope(){return t_max;}
        void back_cursor();
        void push_cursor();
        void del_pos(unsigned);
        void del_prev_cursor();
        void mod_char_element(unsigned ,char);
        void overw_cursor_char(char);
        ~PILA(){delete []stack;}
    private:
        typo *stack;
        unsigned t_max, desplazamiento=-1,cursor=desplazamiento;
};

template<typename typo>
PILA<typo>::PILA(int size):t_max(size) {
    stack = new typo[t_max];
    desplazamiento=0;
}

template<typename typo>
void PILA<typo>::push(const typo &x) {

    stack[desplazamiento]=x;
    desplazamiento++;

}

template<typename typo>
typo PILA<typo>::pop() {
    assert(!(desplazamiento<0));
    desplazamiento--;
    return stack[desplazamiento];
}

template<typename typo>
bool PILA<typo>::vacia() const {
    if (desplazamiento<0){
        return true;
    }
    else{
        return false;
    }
}

template<typename typo>
bool PILA<typo>::llena() const {
    if (desplazamiento==t_max){
        return true;
    }
    else{
        return false;
    }
}
//Copia en b la pila a
template<typename typo>
void PILA<typo>::copia(PILA& a,PILA &b) {
    if (b.t_max!=a.t_max){
        b.t_max=a.t_max;
    }
    for (int i=0;i<b.t_max;i++)
        b.push(a.stack[i]);
    }

template<typename typo>
void PILA<typo>::contenido() const {
    for (int i = 0; i <t_max ; ++i) {
        cout<<stack[i]<<", ";
    }
    cout<<endl;
}

template<typename typo>
void PILA<typo>::contenido(unsigned int cursor) const {
    return stack[cursor];
}

template<typename typo>
void PILA<typo>::back_cursor()  {
    assert(!(cursor<=0));
    cursor-=1;
}

template<typename typo>
void PILA<typo>::push_cursor(){
    assert(!(cursor<desplazamiento-1));
    cursor+=1;
}

template<typename typo>
void PILA<typo>::del_pos(unsigned int pos) {
    stack[pos]=" ";
}

template<typename typo>
void PILA<typo>::del_prev_cursor() {
    assert(!(cursor<=0));
    stack[cursor-1]="";
}

template<typename typo>
void PILA<typo>::mod_char_element(unsigned int pos, char c) {
    assert(!(pos<desplazamiento));
    assert(!(pos>desplazamiento-1));
    stack[pos]=c;
}

template<typename typo>
void PILA<typo>::overw_cursor_char(char c) {
    stack[cursor]=c;
}

#endif //PILA_GENERICA_PILA_H
