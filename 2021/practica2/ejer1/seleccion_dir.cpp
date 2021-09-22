#include <iostream>
using namespace std;//Avoid using std:: ....
//Algoritmo seleccion directa
void seleccion_dir(int *,int);
int main(){
    int v[6]={64,9,12,11,8,5};
    seleccion_dir(v,6);
    for (int i = 0; i < sizeof(v)/sizeof(int); i++)
    {
        cout<<v[i]<<endl;
    }
    
  return 0;
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