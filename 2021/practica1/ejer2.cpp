#include <iostream>
#include <cstdlib>
using namespace std;//Avoid using std:: ....
/*************************************
Escriba un programa que simule 10 000 000 de tiradas de un dado. 
Imprima las frecuencias relativas que se obtienen para cada una de las caras. 
Emplee la función del ejercicio anterior.
*************************************/
float frec(int);
int generador_tirada(int ,int );
void frecuencias_relativas( int );
int main(){
    frecuencias_relativas(1000);
  return 0;
}


/**********************************
Cabecera de funcion ==> int generador_tirada(int ,int );
Precondiciones ==> Recibe 2 numeros enteros que actuan como limite superior e inferior
Postcondiciones ==> Devuelve un numero entero entre el intervalo dado
**********************************/
int generador_tirada(int a,int b ){

  return (rand()%(b-a+1)+a);
  
}
/**********************************
Cabecera de funcion ==> void frecuencias_relativas( int );
Precondiciones ==> Recibe un entero que indica el numero de tiradas que se van a dar
Postcondiciones ==> Imprime por pantalla las frecuencias relativas de cada numero
**********************************/
void frecuencias_relativas( int tiradas ){
    float ap1=0,ap2=0,ap3=0,ap4=0,ap5=0,ap6=0;
    for (int i = 0; i < tiradas; i++)
    {
        switch (generador_tirada(1,6)){
            case 1:
                ap1++;
            break;

            case 2:
                ap2++;
            break;

            case 3:
                ap3++;
            break;

            case 4:
                ap4++;
            break;

            case 5:
                ap5++;
            break;
            
            case 6:
                ap6++;                
            break;
        }
    }
    cout<<"Frecuencia relativa de 1: "<<(ap1/tiradas)/6<<endl;
    cout<<"Frecuencia relativa de 2: "<<(ap2/tiradas)/6<<endl;
    cout<<"Frecuencia relativa de 3: "<<(ap3/tiradas)/6<<endl;
    cout<<"Frecuencia relativa de 4: "<<(ap4/tiradas)/6<<endl;
    cout<<"Frecuencia relativa de 5: "<<(ap5/tiradas)/6<<endl;
    cout<<"Frecuencia relativa de 6: "<<(ap6/tiradas)/6<<endl;
    

}