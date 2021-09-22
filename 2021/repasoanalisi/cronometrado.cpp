#include<iostream>
#include "cronometro.h"
#include "ordenes.h"
#include<algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;


//Forma de cronometrar los algoritmos EX analisis
int main(){
	cronometro c1,c2,c3;
	long int r=0;
	const double e_abs=0.01,e_rel=0.001;
	int v[9]={6,24,28,12,56,7,5,89},w[9],y[9],aux[9];
    memcpy(w, v, sizeof (v));
    memcpy(y, v, sizeof (v));
    memcpy(aux, v, sizeof (v));

	c1.activar();
    random_shuffle(v,v+9); // Se desordena el vector
	do{
        memcpy(w, v, sizeof (v));
		insertion_sort(w,9); //SE llama al algoritmo de orden
		memcpy(v,w, sizeof (v));
		r++;
	}while(c1.tiempo()<e_abs/e_rel+e_abs);
	c1.parar();
	double t1=c1.tiempo()/r;
	cout<<"El tiempo de insertion_sort es: "<<t1<<endl;

	

	return 0;
}


