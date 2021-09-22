#include <iostream>
#include <cstdlib>
using namespace std;
//Funciones usadas en la practica 1 (uso de rand)
void aleatorio_entero(int lim_inf,int lim_sup);
void aleatorio_flotante(float lim_inf,float lim_sup);

int main(){
    cout<<"Ejercicio 1"<<endl;
    for (int i = 0; i < 4 ; ++i)
    {
        aleatorio_entero(1,12);

    }
    cout<<"\nEjercicio 2"<<endl;
    for (int i = 0; i < 4 ; ++i)
    {
        aleatorio_flotante(1,12);

    }

    return 0;
}

void aleatorio_entero(int lim_inf,int lim_sup){
    //Muestra por pantalla un numero generado tal que a <= nº <= b
    cout<<rand()%(lim_sup-lim_inf+1)+lim_inf<<", ";
}

void aleatorio_flotante(float lim_inf,float lim_sup){
    //Muestra por pantalla un numero generado tal que a <= nº <= b
    float random=((float)rand())/((float)RAND_MAX);
    float diff = lim_sup-lim_inf;
    float r = random*diff;
    cout << lim_inf+r<<", ";

}


