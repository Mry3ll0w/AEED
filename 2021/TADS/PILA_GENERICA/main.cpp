#include <iostream>
#include "PILA.h"
using namespace std;
int main() {
    PILA <int>ej(4);
    ej.push(6);
    cout<<ej.vacia()<<endl;
    ej.pop();
    cout<<ej.vacia()<<endl;
    return 0;
}
