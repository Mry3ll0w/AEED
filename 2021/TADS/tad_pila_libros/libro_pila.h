//
// Created by anton on 15/11/2020.
//
#ifndef TAD_PILA_librosS_libros_PILA_H
#include <iostream>
#include <iostream>
#include <cassert>
using namespace std;
typedef struct {
    char titulo[100];
    char ISBN [20];
    char autor[30];
    long unsigned code;
}l;
class libros{
    public:
    explicit libros(int size);
    bool vacia()const;
    unsigned tope()const;
    void pop();
    void push(const l& x);
    void datos(int n){
        assert(!(n-1<desplazamiento));
        cout<<"Nombre :"<<libross[n-1].titulo<<endl;
        cout<<"Autor: "<<libross[n-1].autor<<endl;
        cout<<"ISBN: "<<libross[n-1].ISBN<<endl;
        cout<<"Codigo de la biblioteca: "<<libross[n-1].code<<endl;
        cout<<endl;

    }//ok
    ~libros(){delete []libross;}
private:
    int n_elementos;
    unsigned desplazamiento=0;
    l *libross;


};
#define TAD_PILA_librosS_libros_PILA_H

#endif //TAD_PILA_librosS_libros_PILA_H
