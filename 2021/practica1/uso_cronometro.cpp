#include <iostream>
#include "cronometro.hpp"
#include "alg_mios.h"
#include <algorithm>    // std::random_shuffle
#include <cstring>

void mide_permutas_vector(){
    int v[10000];
    int w[10000];
    cronometro c;
    size_t cont=0;
    double tiempo=0;
    const double e_abs = 0.01,  //Máximo error absoluto cometido
                 e_rel = 0.001; //Máximo error relativo aceptado
    
    for (size_t i = 0; i < 10000; i++)
    {
        v[i]=i+1;
    }//Initialize all the vectors with the n first numbers
    

    for(size_t j = 0; j < 1000; ++j)
    {
        memcpy(w, v, sizeof v);
      do
      {
        for(size_t aux = 0; aux < 50; ++aux)
        {
          // Realizo 50 permutaciones aleatorias
          std::random_shuffle(w, w+10000);
        }

        //Cronometro el tiempo que tardo en ordenar las permutaciones

        c.activar();
        orden_insercion(w, 10000);
        c.parar();
      }while (c.tiempo() < e_abs / (e_rel + e_abs));
        
    }
    std::cout<<c.tiempo()/1000<<std::endl;
} 

int main(){
    mide_permutas_vector();
    
}