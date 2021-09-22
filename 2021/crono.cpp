#include <iostream>
#include "cronometro.h"
#include <algorithm>    // std::random_shuffle
#include <cstring>
void initialize(int n, int *v){
        for (size_t i = 0; i < n; i++)
        {
            v[i]=i+1; // 1 2 3 .... 
        }
}

double func_suma_t(size_t n,int *v){ //funcion a cronometrar
    double sum =0;
    for (size_t i = 0; i < n; i++)
    {
            sum+=v[i];
    }
    return sum;
}
int main(){
    int n = 1000;
    int *v;
    cronometro c;
    
    while (n <= 20000)
    {
        //reserva y preparacion de V
        v = new int[n];
        initialize(n,v);
        //empezamos a contar con el cronometro
        c.activar();




        n+=1000;
        delete[] v; //eliminanos el esapcio reservado
    }
    
    return 0;
}