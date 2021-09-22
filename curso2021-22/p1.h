// Created by anton on 08/10/2021.
#ifndef CURSO2021_22_P1_H
#define CURSO2021_22_P1_H
#include <iostream>
#include <ctime>

int ej1(int l_superior, int l_inferior){
    //inicializamos la seed de rand
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

#endif //CURSO2021_22_P1_H
