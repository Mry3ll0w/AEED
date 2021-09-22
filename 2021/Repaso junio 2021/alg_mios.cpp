#include <iostream>
#include <cstdio>
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

void seleccion_dir(int *v,int tam){
    
    for ( int i=0; i<tam ;i++ ){
        for ( int j=i; j<tam; j++){
          if (v[i]>v[j])
          {
            int aux=v[j];
            v[j]=v[i];
            v[i]=aux;
          }
          
        }
        
    }
}

void rellena_v(int *v,int size){
    v=(int*)malloc(size*sizeof(int));
    for (int i = 0; i < size; i++)
    {
        v[i]=i+1;
    }
    
}