#include <iostream>
using namespace std;//Avoid using std:: ....
//Algoritmo de intercambio por intercambio directo
void intercambio_dir(int *,int);
int main(){
    int v[6]={4,8,23,9,10,2};
    intercambio_dir(v,6);
    for (int i = 0; i < (sizeof(v)/sizeof(int)); i++)
    {
        cout<<"Valor de v["<<i+1<<"]: "<<v[i]<<endl;
    }
    
  return 0;
}

void intercambio_dir(int *v,int tam){//burbuja
    int aux;
    
    for ( int i=0; i<tam;i++ ){
        for ( int j=0; j<tam-1; j++){
          
          if (v[j]>v[j+1])
          {
              aux=v[j];
              v[j]=v[j+1];
              v[j+1]=aux;
          }
          
        }
    }
    
    
}