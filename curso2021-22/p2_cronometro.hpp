#include <iostream>
#include "tads_profesorado/cronometro.h"
#include "tads_profesorado/ordenacion.h"
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#define IT 20000


void inicializar_vec(int *v, int n){

    for(int i = 0; i < n; ++i){
        v[i]=i+1; // v[1, 2, 3, .. ]
    }
}



//mideme x algoritmo para x permutaciones
double tiempo_intercambio(){
    double t = 0;
    cronometro c;
    long r = 0;
    const double e_abs = pow(10,-6);//10^-6
    const double e_rel = pow(10,-4);
    int iterador = 1000;
    int *v;
    while(iterador < IT){
        v = new int[iterador];
        //inicializamos el vector
        inicializar_vec(v,iterador);
        std::random_shuffle(v,v+iterador);
        //iniciamos el cronometro y tal

        c.activar();
        do {

            ordenacion_intercambio(v+0, v + iterador);

            ++r;
        } while (c.tiempo() < e_abs / e_rel + e_abs);
        c.parar();
        t+=c.tiempo()/r;


        //iteramos
        iterador+=1000;
    }

return t;    
}

double tiempo_seleccion(){
    double t = 0;
    cronometro c;
    long r = 0;
    const double e_abs = std::pow(10,-6);
    const double e_rel = std::pow(10,-4);
    int iterador = 1000;
    int *v;
    while(iterador < 20000){
        v = new int [iterador];
        //inicializamos el vector
        inicializar_vec(v,iterador);
        std::random_shuffle(v,v+iterador);
        //iniciamos el cronometro y tal
        c.activar();
        do {
            ordenacion_seleccion(v+0, v + iterador);
            ++r;
        } while (c.tiempo() < e_abs / e_rel + e_abs);
        c.parar();
        t+=c.tiempo()/r;
        //iteramos
        iterador+=1000;
    }

    return t;
}

double tiempo_insercion(){
    double t = 0;
    cronometro c;
    long r = 0;
    const double e_abs = std::pow(10,-6);
    const double e_rel = std::pow(10,-4);

    int iterador = 1000;
    while(iterador < 20000){
        int v[iterador];
        //inicializamos el vector
        inicializar_vec(v,iterador);
        std::random_shuffle(v,v+iterador);
        //iniciamos el cronometro y tal
        c.activar();
        do {
            ordenacion_insercion(v+0, v + iterador);
            ++r;
        } while (c.tiempo() < e_abs / e_rel + e_abs);
        c.parar();
        t+=c.tiempo()/r;
        //iteramos
        iterador+=1000;
    }

    return t;
}

std::list<double> ordenaciones_total(){
    std::list<double>res;
    double t = 0,t2=0,t3=0;
    cronometro c1,c2,c3;
    long r = 0,r2=0,r3=0;
    const double e_abs = std::pow(10,-6);
    const double e_rel = std::pow(10,-4);

    int iterador = 1000;
    while(iterador < IT){
        int v[iterador];
        //inicializamos el vector
        inicializar_vec(v,iterador);
        std::random_shuffle(v,v+iterador);
        //iniciamos el cronometro y tal

        c1.activar();
        do {
            ordenacion_intercambio(v+0, v + iterador);
            ++r;
        } while (c1.tiempo() < e_abs / e_rel + e_abs);
        c1.parar();
        t+=c1.tiempo()/r;

        //ordenacion por insercion
        c2.activar();
        do {
            ordenacion_insercion(v+0, v + iterador);
            ++r2;
        } while (c2.tiempo() < e_abs / e_rel + e_abs);
        c2.parar();
        t2+=c2.tiempo()/r2;

        //ordenacion por seleccion
        c3.activar();
        do {
            ordenacion_seleccion(v+0, v + iterador);
            ++r3;
        } while (c3.tiempo() < e_abs / e_rel + e_abs);
        c3.parar();
        t3+=c3.tiempo()/r3;

        //iteramos
        iterador+=1000;
    }

    //metemos los tiempos totales en los algoritmos
    res.push_back(t);
    res.push_back(t2);
    res.push_back(t3);

return res;
}



