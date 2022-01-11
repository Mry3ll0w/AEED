#ifndef CURSO2021_22_EJ4_PARCIAL2022_H
#define CURSO2021_22_EJ4_PARCIAL2022_H

#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include"tads_profesorado/cronometro.h"

//Usamos el metodo sort de list para no tener que implementar algoritmos de ordenacion

void caja_negra(){
    bool desordenado =false;
    cronometro c;
    //creamos el vector de 1 a n enteros
    std::vector<int> v,checker;
    size_t N = 10;
    double t = 0;
    long r = 0;
    const double e_abs = pow(10,-6);//10^-6
    const double e_rel = pow(10,-4);
    size_t repeticiones =0;

    while (N < 1000 && !desordenado){
        //Inicializa el vector de los N numeros naturales
        for (int i = 0; i < N; ++i)
            v.push_back(i+1);

        checker = v; //Se guarda el vector ordenado
        unsigned seed = 0;
        std::shuffle(v.begin(), v.end(),std::default_random_engine(seed));

        //Reordenamos el vector v
        std::list<int> l = std::list<int>(v.begin(),v.end());

        //Activamos el cronometro
        c.activar();
        do {
            l.sort();
            ++r;
        } while (c.tiempo() < e_abs / e_rel + e_abs);
        c.parar();
        t+=c.tiempo()/r;//Vamos guardando el tiempo en segundos

        v = std::vector<int>(v.begin(), v.end());
        //Comprobamos que este ordenado correctamente
        for(size_t i = 0; i < N;++i){
            if (v[i]!=checker[i])
                desordenado=true;
        }

        N+=10;//Se aumentan de 10 en 10
        repeticiones++;
    }
    std::cout<<"Tiempo promedio: "<<t/repeticiones<<std::endl;
}



#endif //CURSO2021_22_EJ4_PARCIAL2022_H
