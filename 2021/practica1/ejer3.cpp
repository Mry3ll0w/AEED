#include <iostream>
#include <cstdlib>
using namespace std;//Avoid using std:: ....
/*************************************
Utilizandorand(), escriba una función que 
genere un número pseudoaleatorio de coma flotante 
y precisión doble en el intervalo continuo[a, b].
*************************************/
float n_aleatorio(float , float );
int main(){
    for (int i = 0; i < 4; i++)
    {
       cout<< n_aleatorio(1.5,10.2)<<endl;
       
    }
    
  return 0;
}
float n_aleatorio(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}