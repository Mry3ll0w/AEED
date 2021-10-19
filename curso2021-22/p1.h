// Created by anton on 08/10/2021.
#ifndef CURSO2021_22_P1_H
#define CURSO2021_22_P1_H
#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>

int ej1(int l_superior, int l_inferior){

    return rand() % (l_superior - l_inferior + 1)+l_inferior;
}

//Tirada de dados 10 000 000, utilizando la funcion anterior (ej19
double ej2(long int N = 10000000){
    double ni;//Control de los numeros obtenidos en cada tirada
    ni=0;
    long int tamano_muestra;//Control del tamaño total de muestra
    tamano_muestra = N;
    //SIMULACION DE TIRADAS
    while (N>0){
        double t= ej1(6,1);
        ni+=t;//Entiendo que la tirada de un dado D6
        --N;
    }
    return (double)(ni/tamano_muestra); //devuelve la frecuencia relativa
}

/**
 *
 * @param a ==> limite superior del intervalo para generar el numero pseudo aleatorio
 * @param b ==> limite inferior del intervalo para generar el numero pseudo Aleatorio
 * @return numero generado por estos limites (double)
 */
double ej3(const double&a , const double& b){
    return b + ((double)rand() / RAND_MAX) * (a - b);
}
/**
 *
 * @return la media y = 4 ·√(1 − x^2)
 */
double ej4(const double N =10000000 ){
    double media;
    media=0;
    size_t it;
    it = 0;
    while(it < N){
        media+=4 * sqrt(1-pow(ej3(1,0),2));//4 ·√(1 − x^2)
        it++;
    }
    return media/N; //devuelve la media entre el numero de iteraciones
}

//ejercicio 5
size_t ej5(){
    std::vector<size_t>v={6,2,3,4,1,5};
    std::vector<size_t>v2= {1,2,3,4,5,6};
    size_t contador;
    contador = 0;
    size_t N = 10000000 ;
    //incio del algoritmo
    while(N>0){
        std::random_shuffle(v.begin(),v.end());
        if(v==v2)
            contador++;
        N--;
    }
    return contador;
}
#endif //CURSO2021_22_P1_H
