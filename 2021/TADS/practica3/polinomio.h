//
// Created by anton on 12/11/2020.
//
#ifndef PRACTICA3_POLINOMIO_H
/*
 * polinomio::polinomio (unsigned gradoMax)
 * Postcondiciones: Crea el polinomio nulo. El objetivo de este método es crear un objeto
 * polinomio, reservando el espacio necesario e inicializando con el valor nulo.
 *
 * unsigned polinomio::grado () const
 * Postcondiciones: Devuelve el grado de un polinomio.
 *
 * double polinomio::coeficiente (unsigned n) const
 * Postcondiciones: Devuelve el coeficiente correspondiente al monomio de grado n de
 * un polinomio. Si n > gradoM ax, devuelve 0.
 *
 * void polinomio::coeficiente (unsigned n, double c)
 * Precondiciones: n ≤ gradoMax
 * Postcondiciones: Asigna al monomio de grado n el coeficiente c.
 * */
#include <iostream>
#include <cassert>
using namespace std;
class polinomio{
    public:

        explicit polinomio(int grado,const double cocis[],const unsigned gs[]);//ok
        void print_pol() const;//ok
        unsigned grado () const{return grado_max; };//ok
        double coeficiente(int i) const{return cocientes[i];}//ok
        void coeficiente(unsigned n, double c);//ok
        friend polinomio  operator + (polinomio& a, polinomio& b);//kk
        friend polinomio  operator - (polinomio& a, polinomio& b);//kk
        friend polinomio operator * (polinomio& a, polinomio& b);
        ~polinomio();

    private:
        long grado_max;
        double *cocientes;
        unsigned *grados;


};
#define PRACTICA3_POLINOMIO_H

#endif //PRACTICA3_POLINOMIO_H
