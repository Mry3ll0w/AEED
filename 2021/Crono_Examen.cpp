/*Sea cierta funcion  llamada, funcion(int ini, int fin), que procesa un rango de un vector de enteros entre  los punteros
ini y fin (apuntara a la siguente posicion a la ultima del rango)Implemente un programa para analizar experimentalmente el tiempo
de ejecución en el caso promedio para permutaciones  aleatorias de un vector  de enteros que contenga los n primeros  numeros
naturales , desde n variará desde 1000 hasta 20 000 en incrementos de 1000 se asume que la resolución del cronometro es
0,01a y que el error relartivo máximo es de  0,5%*/

/*
v ->  1 8 6 9 4 
*/
#include<iostream>
#include<algorithm>
#include "cronometro.h"

#define N 20000
using namespace std;

void funcion(int *ini,int *fin);

int main()
{
	int v[N], w[N];
	const double e_abs = 0.01, e_rel = 0.005;
	double t =0, t_total=0; 
	cronometro c;
	for(n = 1000; n<=N; n+=1000)
	{
			for(i=0;i<n;i++)
				v[i]=i;

			random_shuffle(v,v+n);

			size_t it;

			c.activar();
			do
			{
				memcpy(v,w,sizeof(v));
				funcion(v,v+n);

				memcpy(w,v,sizeof(w));

			}while(c.tiempo()< e_abs/e_rel + e_abs);
			
			c.parar();

			t = c.tiempo()/it;
			t_total += t;

	}

		return 0;	
 
}


