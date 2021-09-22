#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;//Avoid using std:: ....
/*************************************
Escriba un programa que genere 10 000 000 de números 
pseudoaleatorios de precisión doble en el intervalo[0,1] e 
imprima la media de los valores y= 4·√(1−x²) correspondientes a 
cada número x.Emplee la función del ejercicio anterior.
*************************************/
float n_aleatorio(float , float );
void media(int n_veces);
int main(){
        media(1000);
  return 0;
}

float n_aleatorio(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}
void media(int n_total){
    float y,media=0,aux;
    for (size_t i = 0; i < n_total; i++)
    {
        aux=n_aleatorio(0,1);
        y=4*sqrt(1-(aux*aux));
        media+=y;
    }
    
    cout<<"La media es: "<<media<<endl;
}