#include <iostream>
#include <cstdlib>
using namespace std;//Avoid using std:: ....
/*************************************
Utilizando rand(), escriba una función que genere un 
número pseudoaleatorio entero en el intervalo discreto[a, b].
*************************************/
void funct(int a, int b);
int main(){
    int min, max;
    cout <<"Introduce los limites discretos del intervalo(de limite inferior a superior)"<<endl;
    cin >> min;cin>> max;

    for (int i = 0; i < 4; i++)
    {
        funct(min,max);
    }
    
  return 0;
}
/**********************************
Cabecera ==>void funct(int a, int b)
Precondicion ==> Recibe dos enteros (a y b) inicializados 
Postcondicion ==> Muestra por pantalla un numero generado tal que a <= nº <= b
**********************************/
void funct(int a, int b){

  cout<<rand()%(b-a+1)+a<<endl;
  
}