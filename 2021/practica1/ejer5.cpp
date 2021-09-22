#include <iostream>
#include <algorithm>
using namespace std;//Avoid using std:: ....
/*************************************
Escriba un programa que genere 10 000 000 de permutaciones 
pseudoaleatorias de los 6 primeros números naturales e 
imprima cuántas de ellas están ordenadas.
*************************************/
void shuffler(int *,int size);
int ordenadas(int *,int);
int main(){
    int v[]={1,2,3,4,5,6};
    cout<<"El nº de permutaciones ordenadas es : "<<ordenadas(v,1000)<<endl;
  return 0;
}
/**********************************
Cabecera de funcion ==>void shuffler(int *v,int size)
Precondiciones ==> Recibe una vector de enteros a permutar y su 
Postcondiciones ==>
**********************************/
void shuffler(int *v,int size){
    int n=sizeof (v)/sizeof (*v);
    
    for ( int i=0; i<size ;i++ ){
        random_shuffle(v,v+n);
    }
    
}

int ordenadas(int *v,int reps){
    int n_ordenadas=0,token=0;
    for ( int i=0; i<reps ;i++ ){
        token=0;
        shuffler(v,sizeof(v)/sizeof(v[0]));
        for ( int j=0; j<sizeof(v)/sizeof(v[0]); j++ ){
          if (v[i]>v[i+1])
          {
              token=1;
          }
          
        }
        if (token==0)
        {
            n_ordenadas++;
        }
        
    }
    

    return n_ordenadas;
}