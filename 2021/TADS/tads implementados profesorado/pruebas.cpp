#include <iostream>
#include "Cola_Din.h"
#include "pila_enla.h"
using namespace std;//Avoid using std:: ....

int main(){
    PilaEnla<int> p;
    for (int i = 0; i < 4; i++)
    {
        p.push(i+1);
    }
    cout <<p.tope()<<endl;
    for (int i = 0; i < 4; i++)
    {
        cout<<p.tope()<<endl;
        p.pop();
    }
    
     return 0;
}