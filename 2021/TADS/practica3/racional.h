//
// Created by anton on 09/11/2020.
//
#ifndef TAD_RACIONAL_RACIONAL_H
#define TAD_RACIONAL_RACIONAL_H
#include <iostream>
#include <cassert>
using namespace std;
/*
 * Implementacion de la clase racional :
 * Como precondicion la clase no puede tener un denominador =0, ya que si no su resultado (a/b) sería infinito
 * Se implementarán las operaciones básicas:
 * suma,resta,multiplicacion y division
 * */
class racional{
    public:
        racional(int n,int d);
        long num() const {return numerador;}
        long den() const {return denominador;}
        friend racional operator + (const racional& a,const racional& b );//&==> Elemento racional
        friend racional operator - (const racional& a, const racional& b );
        friend racional operator * (const racional& a, const racional& b);
        friend racional operator / (const racional& a, const racional& b);
        //Sobrecarga de operadores para que realize de forma automática los operadores específicos
        ~racional() { };
        racional print_rac() const;

    private:
        static long int mcd(int,int);
        static long int mcm(int,int);
        long int numerador,denominador;


};

#endif //TAD_RACIONAL_RACIONAL_H
