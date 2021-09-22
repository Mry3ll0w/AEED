#include <iostream>
#include <algorithm>
#include "cronometro.h"
using namespace std;//Avoid using std:: ....
//ejercicio 3 practica 2 
void seleccion_dir(int *v,int tam);
void orden_insercion(int v[], int size);
void rellena_v(int *v,int size);
void intercambio_dir(int *v,int tam);

int main(){
    cronometro c;
    int tam=100;
    
    float res=0;
    
    for (int j = 0; j < 2; j++)
    {   int v[tam];
        int n=sizeof (v)/sizeof (*v);
        rellena_v(v,tam);
        c.activar();
        for (int i = 0; i <10;i++){
        seleccion_dir(v,tam);
        random_shuffle(v,v+n);
        }
        tam*=2;
        c.parar(); 
        res=c.tiempo();
    }
    res/=2;
    cout<<"El tiempo que consume seleccion directa: "<<res<<endl;

    for (int j = 0; j < 2; j++)
    {   int v2[tam];
        int n=sizeof (v2)/sizeof (*v2);
        rellena_v(v2,tam);
        c.activar();
        for (int i = 0; i <10;i++){
        orden_insercion(v2,tam);
        random_shuffle(v2,v2+n);
        }
        tam*=2;
        c.parar(); 
        res=c.tiempo();
        
    }
    res/=2;
    cout<<"El tiempo que cons insercion es: "<<res<<endl;

    for (int j = 0; j < 2; j++)
    {   int v2[tam];
        int n=sizeof (v2)/sizeof (*v2);
        rellena_v(v2,tam);
        c.activar();
        for (int i = 0; i <10;i++){
        seleccion_dir(v2,tam);
        random_shuffle(v2,v2+n);
        }
        tam*=2;
        c.parar(); 
        res=c.tiempo();
        
    }
    res/=2;
    cout<<"El tiempo que cons insercion es: "<<res<<endl;
    
    

    return 0;
}

void orden_insercion(int v[], int size){
 int j,temp;
    for(int i=0; i<size; i++){
        temp=v[i];
        j=i-1;
        while(j>=0 && v[j] >temp){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = temp;
 }
}

void intercambio_dir(int *v,int tam){//burbuja
    int aux;
    
    for ( int i=0; i<tam;i++ ){
        for ( int j=0; j<tam-1; j++){
          if (v[j]>v[j+1]){
              aux=v[j];
              v[j]=v[j+1];
              v[j+1]=aux;
          }
          
        }
    }   
}

void seleccion_dir(int v[],int tam){
    int aux;
    for ( int i=0; i<tam ;i++ ){
        for ( int j=i; j<tam; j++){
          if (v[i]>v[j])
          {
            aux=v[j];
            v[j]=v[i];
            v[i]=aux;
          }
          
        }
        
    }
}

void rellena_v(int *v,int size){
    for (int i = 0; i < size; i++)
    {
        v[i]=i+1;
        
    }
    
    
}